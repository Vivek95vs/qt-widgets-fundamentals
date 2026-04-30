#ifndef DICOMREADER_H
#define DICOMREADER_H

#include <vtkSmartPointer.h>
#include <QString>
#include <vtkImageData.h>

class vtkDICOMReader;
class vtkDICOMDirectory;

class DicomReader
{
public:
    DicomReader();
    ~DicomReader();

    vtkSmartPointer<vtkImageData> readDicomSeries(const QString &folderPath);

//    int* getDimensions() const { return m_dimensions; }
//    double* getSpacing() const { return m_spacing; }
    QString getErrorMessage() const { return m_errorMessage; }

private:
    int m_dimensions[3] = {0, 0, 0};
    double m_spacing[3] = {1.0, 1.0, 1.0};
    QString m_errorMessage;
};

#endif // DICOMREADER_H
