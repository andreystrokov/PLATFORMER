#ifndef VULKANMODEL_H
#define VULKANMODEL_H

#pragma once
#include <vulkan/vulkan.h>
#include <stb/stb_image.h>
#include <vector>
#include <glm/glm.hpp>
#include <array>


struct Vertex {

    glm::vec3 pos;
    glm::vec3 color;
    glm::vec2 texCoord;


    static VkVertexInputBindingDescription getBindingDescription() {
        VkVertexInputBindingDescription bindingDescription{};
        bindingDescription.binding = 0;
        bindingDescription.stride = sizeof(Vertex);
        bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;
        return bindingDescription;
    }

    static std::array<VkVertexInputAttributeDescription, 3> getAttributeDescriptions() {
        std::array<VkVertexInputAttributeDescription, 3> attributeDescriptions{};

        attributeDescriptions[0].binding = 0;
        attributeDescriptions[0].location = 0;
        attributeDescriptions[0].format = VK_FORMAT_R32G32B32_SFLOAT;
        attributeDescriptions[0].offset = offsetof(Vertex, pos);

        attributeDescriptions[1].binding = 0;
        attributeDescriptions[1].location = 1;
        attributeDescriptions[1].format = VK_FORMAT_R32G32B32_SFLOAT;
        attributeDescriptions[1].offset = offsetof(Vertex, color);

        attributeDescriptions[2].binding = 0;
        attributeDescriptions[2].location = 2;
        attributeDescriptions[2].format = VK_FORMAT_R32G32_SFLOAT;
        attributeDescriptions[2].offset = offsetof(Vertex, texCoord);

        return attributeDescriptions;
    }
};

struct COORDS_UBO
{
    glm::vec2 coordsUnit;
    glm::vec2 texCoord;
    glm::int32 currentFrame;
    glm::int32 currentAction;
};
class VulkanObject
{
public:
    VulkanObject(std::vector<Vertex> _vertices,
                 std::vector<uint32_t> _indices,
                 std::string _texturePath,
                 std::string _vertexShaderPath,
                 std::string _fragmentShaderPath)
    {
        vertices = _vertices;
        indices = _indices;
        texturePath = _texturePath;
        vertexShaderPath = _vertexShaderPath;
        fragmentShaderPath = _fragmentShaderPath;
    }
    std::vector<Vertex> vertices;
    std::vector<uint32_t> indices;


    std::string texturePath;
    std::string vertexShaderPath;
    std::string fragmentShaderPath;
    VkBuffer vertexBuffer;
    VkDeviceMemory vertexBufferMemory;
    VkBuffer indexBuffer;
    VkDeviceMemory indexBufferMemory;
    VkPipeline ObjPipeline;

    VkPipelineLayout pipelineLayout;
    VkDescriptorSetLayout descLayout;
    VkDescriptorPool descPool;

    std::vector<VkDescriptorSet> descSets;
    std::vector<VkBuffer> uniformBuffers;
    std::vector<VkDeviceMemory> uniformBuffersMemory;
    std::vector<void*> uniformBuffersMapped;

    stbi_uc* pixels = nullptr;

    VkImage textureImage = VK_NULL_HANDLE;
    VkImageView imageView = VK_NULL_HANDLE;
    VkDeviceMemory textureImageMemory = VK_NULL_HANDLE;




    VkSampler textureSampler = VK_NULL_HANDLE;
    uint8_t changed = 0;
};

#endif // VULKANMODEL_H
