#include "volumeprocessor.h"
#include <vtkImageResample.h>
#include <vtkImageShiftScale.h>
#include <vtkImageCast.h>
#include <vtkExtractVOI.h>
#include <QDebug>

VolumeProcessor::VolumeProcessor()
{
}

vtkSmartPointer<vtkImageData> VolumeProcessor::downsampleVolume(vtkImageData* input, int factor)
{
    if (!input) return nullptr;

    vtkSmartPointer<vtkImageResample> resample =
        vtkSmartPointer<vtkImageResample>::New();
    resample->SetInputData(input);
    resample->SetAxisMagnificationFactor(0, 1.0/factor);
    resample->SetAxisMagnificationFactor(1, 1.0/factor);
    resample->SetAxisMagnificationFactor(2, 1.0/factor);
    resample->Update();

    vtkImageData* output = resample->GetOutput();
    qDebug() << "Downsampled from"
             << input->GetDimensions()[0] << "x"
             << input->GetDimensions()[1] << "x"
             << input->GetDimensions()[2]
             << "to"
             << output->GetDimensions()[0] << "x"
             << output->GetDimensions()[1] << "x"
             << output->GetDimensions()[2];

    return output;
}

vtkSmartPointer<vtkImageData> VolumeProcessor::extractSubset(vtkImageData* input, int maxSlices)
{
    if (!input) return nullptr;

    int dims[3];
    input->GetDimensions(dims);

    if (dims[2] <= maxSlices) {
        return input;
    }

    // Extract middle slices
    int startSlice = (dims[2] - maxSlices) / 2;

    vtkSmartPointer<vtkExtractVOI> extract =
        vtkSmartPointer<vtkExtractVOI>::New();
    extract->SetInputData(input);
    extract->SetVOI(0, dims[0]-1, 0, dims[1]-1, startSlice, startSlice + maxSlices - 1);
    extract->Update();

    qDebug() << "Extracted slices" << startSlice << "to" << startSlice + maxSlices - 1;
    return extract->GetOutput();
}

vtkSmartPointer<vtkImageData> VolumeProcessor::convertTo8Bit(vtkImageData* input)
{
    if (!input) return nullptr;

    // First shift/scale to 0-255 range
    vtkSmartPointer<vtkImageShiftScale> shiftScale =
        vtkSmartPointer<vtkImageShiftScale>::New();
    shiftScale->SetInputData(input);
    shiftScale->SetShift(-1000);  // CT data adjustment
    shiftScale->SetScale(0.1);    // Reduce range
    shiftScale->SetOutputScalarTypeToUnsignedChar();
    shiftScale->ClampOverflowOn();
    shiftScale->Update();

    return shiftScale->GetOutput();
}
