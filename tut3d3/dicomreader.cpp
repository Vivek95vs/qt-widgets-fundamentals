#include "dicomreader.h"
#include <vtkDICOMReader.h>
#include <vtkDICOMDirectory.h>
#include <vtkStringArray.h>
#include <vtkImageShiftScale.h>
#include <vtkImageCast.h>
#include <QDebug>

DicomReader::DicomReader()
{
}

DicomReader::~DicomReader()
{
}

vtkSmartPointer<vtkImageData> DicomReader::readDicomSeries(const QString &folderPath)
{
    m_errorMessage.clear();

    qDebug() << "Reading DICOM from:" << folderPath;

    vtkSmartPointer<vtkDICOMDirectory> dicomDir =
        vtkSmartPointer<vtkDICOMDirectory>::New();
    dicomDir->SetDirectoryName(folderPath.toStdString().c_str());

    try {
        dicomDir->Update();
    } catch (...) {
        m_errorMessage = "Exception reading DICOM directory";
        qDebug() << m_errorMessage;
        return nullptr;
    }

    int numSeries = dicomDir->GetNumberOfSeries();
    qDebug() << "Number of series found:" << numSeries;

    if (numSeries == 0) {
        m_errorMessage = "No DICOM series found";
        qDebug() << m_errorMessage;
        return nullptr;
    }

    // Get first series
    vtkStringArray *fileNames = dicomDir->GetFileNamesForSeries(0);
    if (!fileNames || fileNames->GetNumberOfValues() == 0) {
        m_errorMessage = "No files in DICOM series";
        qDebug() << m_errorMessage;
        return nullptr;
    }

    qDebug() << "Number of DICOM files:" << fileNames->GetNumberOfValues();

    // Create reader
    vtkSmartPointer<vtkDICOMReader> reader =
        vtkSmartPointer<vtkDICOMReader>::New();
    reader->SetFileNames(fileNames);
    reader->SetMemoryRowOrderToFileNative();

    try {
        reader->Update();
        qDebug() << "DICOM reader update successful";
    } catch (...) {
        m_errorMessage = "Exception reading DICOM files";
        qDebug() << m_errorMessage;
        return nullptr;
    }

    // Get image data
    vtkImageData *imageData = reader->GetOutput();
    if (!imageData) {
        m_errorMessage = "Failed to get image data";
        qDebug() << m_errorMessage;
        return nullptr;
    }

    // Store dimensions and spacing
    imageData->GetDimensions(m_dimensions);
    imageData->GetSpacing(m_spacing);

    qDebug() << "DICOM loaded - Dimensions:"
             << m_dimensions[0] << m_dimensions[1] << m_dimensions[2]
             << "Spacing:"
             << m_spacing[0] << m_spacing[1] << m_spacing[2];

    // Check if image data is valid
    if (m_dimensions[0] <= 0 || m_dimensions[1] <= 0 || m_dimensions[2] <= 0) {
        m_errorMessage = "Invalid DICOM dimensions";
        qDebug() << m_errorMessage;
        return nullptr;
    }

    qDebug() << "DICOM data valid, returning image data";
    return imageData;
}
