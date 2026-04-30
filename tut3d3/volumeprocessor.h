#ifndef VOLUMEPROCESSOR_H
#define VOLUMEPROCESSOR_H

#include <vtkSmartPointer.h>
#include <vtkImageData.h>

class VolumeProcessor
{
public:
    VolumeProcessor();

    // Downsample volume to half resolution (256x256x256)
    vtkSmartPointer<vtkImageData> downsampleVolume(vtkImageData* input, int factor = 2);

    // Extract a subset of slices
    vtkSmartPointer<vtkImageData> extractSubset(vtkImageData* input, int maxSlices = 128);

    // Convert to 8-bit for rendering (reduces memory)
    vtkSmartPointer<vtkImageData> convertTo8Bit(vtkImageData* input);

private:
    vtkSmartPointer<vtkImageData> processVolume(vtkImageData* input);
};

#endif // VOLUMEPROCESSOR_H
