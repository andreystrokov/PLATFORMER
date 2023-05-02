#ifndef MAINACTOR_H
#define MAINACTOR_H

#pragma once
#include "VulkanModel.h"


//struct COORDS_UBO
//{
//    glm::vec2 coords;
//    glm::vec2 texCoord;
//};

const std::vector<Vertex> verticesMainActor = {
    {{-0.1f, -0.25f,0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
    {{0.1f, -0.25f,0.0f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f}},
    {{0.1f, 0.25f,0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f}},
    {{-0.1f, 0.25f,0.0f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}}
};

const std::vector<uint32_t> indicesMainActor = {
    0, 1, 2, 2, 3, 0
};



class MainActor : public VulkanObject
{
public:
    MainActor(std::vector<Vertex> _vertices,
              std::vector<uint32_t> _indices,
              std::string _texturePath,
              std::string _vertexShaderPath,
              std::string _fragmentShaderPath) : VulkanObject(_vertices,_indices,_texturePath,_vertexShaderPath,_fragmentShaderPath){

    }
    friend class renderer;
    void runRight();
    void stay();
    void jump();
    bool getJumpState() const { return onFlight;}

    glm::vec3 getCoords() const { return coords; };
private:
    int currentFrameRun = 0;
    int currentFrameJump = 0;
    bool onFlight = false;
    const float ground = 0.7f;
    glm::vec3 coords{-0.7,ground,0.0};
};

#endif // MAINACTOR_H
