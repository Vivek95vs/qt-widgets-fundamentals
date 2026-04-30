#ifndef VOLUMERENDERER_H
#define VOLUMERENDERER_H

#include <vtkSmartPointer.h>
#include <vtkRenderer.h>
#include <vtkGPUVolumeRayCastMapper.h>
#include <vtkVolume.h>
#include <vtkRenderWindow.h>

class VolumeRenderer
{
public:
    static void render(vtkRenderWindow *window);
};

#endif
