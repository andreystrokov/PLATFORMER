#ifndef GROUND_H
#define GROUND_H

#include "Vulkan/VulkanModel.h"
#include <string.h>

const std::vector<Vertex> verticesGround = {
    {{-1.0f, 0.735f,0.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f}},
    {{1.0f, 0.735,0.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}},
    {{1.0f, 1.0f,0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 1.0f}},
    {{-1.0f, 1.0f,0.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f}}
};
const std::vector<uint32_t> indicesGround = {
    0, 1, 2, 2, 3, 0
};

class Ground : public VulkanObject
{
public:
    Ground(std::vector<Vertex> _vertices,
               std::vector<uint32_t> _indices,
               std::string _texturePath,
               std::string _vertexShaderPath,
               std::string _fragmentShaderPath) : VulkanObject(_vertices,_indices,_texturePath,_vertexShaderPath,_fragmentShaderPath){

     }
    void move();
    void stay();
    glm::vec2 coords{0.0,0.0};
};

#endif // GROUND_H
