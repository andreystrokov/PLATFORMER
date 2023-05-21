#ifndef MAINACTOR_H
#define MAINACTOR_H

#pragma once
#include "Vulkan/VulkanCharacterModel.h"


//struct COORDS_UBO
//{
//    glm::vec2 coords;
//    glm::vec2 texCoord;
//};

const std::vector<Vertex> verticesMainActor = {
    {{-0.24f, -0.24f,0.1f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},  // 0
    {{0.24f, -0.24f,0.1f},  {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f}},  // 1
    {{0.24f, 0.24f,0.1f},   {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f}},  // 2
    {{-0.24f, 0.24f,0.1f},  {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}}   // 3
};

const std::vector<uint32_t> indicesMainActor = {
    0, 1, 2, 2, 3, 0
};

class MainActor : public VulkanCharacterObject
{
public:
    MainActor(std::vector<Vertex> _vertices,
              std::vector<uint32_t> _indices,
              std::vector<std::string> _texturePath,
              std::string _vertexShaderPath,
              std::string _fragmentShaderPath) : VulkanCharacterObject(_vertices,_indices,_texturePath,_vertexShaderPath,_fragmentShaderPath){

    }
    enum Actions
    {
        IDLE = 0,
        RUN,
        JUMP,
        ATTACK,
        DEATH
    };
    friend class GameRenderer;
    void runRight();
    void computeXY();
    void stay();
    void jump();
    void attack();
    bool getJumpState() const { return onFlight;}
    bool getAttackState() const { return isAttack; }
    glm::vec3 getCoords() const { return coords; };
private:
    int currentFrameRun = 0;
     int currentFrameAttack = 0;
    int currentFrameJump = 0;
    int currentFrameIdle = 0;
    bool onFlight = false;
    bool isIdle = true;
    bool isRun = false;
    bool isOnGround = true;
    bool isAttack = false;
    const float ground = 0.5f;

    const float GRAVITY = 0.05f;
    const float JUMP_VELOCITY = -0.2f;

    float velocityY = 0;

    glm::vec3 coords{-0.7,ground,0.0};

};

#endif // MAINACTOR_H
