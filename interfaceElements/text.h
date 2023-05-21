#ifndef TEXT_H
#define TEXT_H

#include "Vulkan/VulkanModel.h"


class Text : public VulkanObject
{
public:
    Text(std::vector<Vertex> _vertices,
               std::vector<uint32_t> _indices,
               std::string _texturePath,
               std::string _vertexShaderPath,
               std::string _fragmentShaderPath) : VulkanObject(_vertices,_indices,_texturePath,_vertexShaderPath,_fragmentShaderPath)
    {

    }
};

#endif // TEXT_H
