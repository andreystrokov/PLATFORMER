#ifndef WALLPAPER_H
#define WALLPAPER_H

#include "Vulkan/VulkanModel.h"


class wallpaperMainMenu : public VulkanObject
{
public:
    wallpaperMainMenu(std::vector<Vertex> _vertices,
               std::vector<uint32_t> _indices,
               std::string _texturePath,
               std::string _vertexShaderPath,
               std::string _fragmentShaderPath) : VulkanObject(_vertices,_indices,_texturePath,_vertexShaderPath,_fragmentShaderPath)
    {

    };
};

#endif // WALLPAPER_H
