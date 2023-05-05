#ifndef VULKANCHARACTERMODEL_H
#define VULKANCHARACTERMODEL_H

#pragma once
#include <vulkan/vulkan.h>
#include <stb/stb_image.h>
#include <vector>
#include <glm/glm.hpp>
#include <array>
#include "VulkanModel.h"

class VulkanCharacterObject
{
public:
    VulkanCharacterObject(std::vector<Vertex> _vertices,
                 std::vector<uint32_t> _indices,
                 std::vector<std::string> _texturePath,
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


    std::vector<std::string> texturePath;
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

    std::vector<stbi_uc*> pixels;

    std::vector<VkImage> textureImage;
    std::vector<VkImageView> imageView;
    std::vector<VkDeviceMemory> textureImageMemory;

    std::vector<VkSampler> textureSampler;
    uint8_t changed = 0;
};

#endif // VULKANCHARACTERMODEL_H
