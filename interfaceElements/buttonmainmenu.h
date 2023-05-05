#ifndef BUTTONMAINMENU_H
#define BUTTONMAINMENU_H

#include "Vulkan/VulkanModel.h"

class buttonMainMenu : public VulkanObject
{
public:
    buttonMainMenu(std::vector<Vertex> _vertices,
               std::vector<uint32_t> _indices,
               std::string _texturePath,
               std::string _vertexShaderPath,
               std::string _fragmentShaderPath) : VulkanObject(_vertices,_indices,_texturePath,_vertexShaderPath,_fragmentShaderPath)
    {

    };

};

#endif // BUTTONMAINMENU_H
