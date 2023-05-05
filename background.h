#ifndef BACKGROUND_H
#define BACKGROUND_H
#pragma once

#include "Vulkan/VulkanModel.h"

const std::vector<Vertex> verticesWall = {
    {{-1.0f, -1.0f,0.99f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f}},
    {{1.0f, -1.0f,0.99f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}},
    {{1.0f, 1.0f,0.99f}, {0.0f, 0.0f, 1.0f}, {0.0f, 1.0f}},
    {{-1.0f, 1.0f,0.99f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f}}
};
const std::vector<uint32_t> indicesWall = {
    0, 1, 2, 2, 3, 0
};

const std::vector<Vertex> verticesFarTrees = {
    {{-1.0f, -1.0f,0.90f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f}},
    {{1.0f, -1.0f,0.90f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}},
    {{1.0f, 1.0f,0.90f}, {0.0f, 0.0f, 1.0f}, {0.0f, 1.0f}},
    {{-1.0f, 1.0f,0.90f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f}}
};
const std::vector<Vertex> verticesMidTrees = {
    {{-1.0f, -1.0f,0.80f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f}},
    {{1.0f, -1.0f,0.80f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}},
    {{1.0f, 1.0f,0.80f}, {0.0f, 0.0f, 1.0f}, {0.0f, 1.0f}},
    {{-1.0f, 1.0f,0.80f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f}}
};
const std::vector<Vertex> verticesCloseTrees = {
    {{-1.0f, -1.0f,0.70f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f}},
    {{1.0f, -1.0f,0.70f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}},
    {{1.0f, 1.0f,0.70f}, {0.0f, 0.0f, 1.0f}, {0.0f, 1.0f}},
    {{-1.0f, 1.0f,0.70f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f}}
};

const std::vector<uint32_t> indicesClouds = {
    0, 1, 2, 2, 3, 0
};
class Background : public VulkanObject
{
public:
    Background(std::vector<Vertex> _vertices,
               std::vector<uint32_t> _indices,
               std::string _texturePath,
               std::string _vertexShaderPath,
               std::string _fragmentShaderPath) : VulkanObject(_vertices,_indices,_texturePath,_vertexShaderPath,_fragmentShaderPath){

     };
     void run();
     void runFar();
     void runMid();
     void runClose();
     void stay();
     glm::vec2 coords{0.0,0.0};
private:
};

#endif // BACKGROUND_H
