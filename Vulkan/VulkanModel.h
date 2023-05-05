#ifndef VULKANMODEL_H
#define VULKANMODEL_H

#pragma once
#include <vulkan/vulkan.h>
#include <stb/stb_image.h>
#include <vector>
#include <Vulkan/VulkanTypes.h>


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
