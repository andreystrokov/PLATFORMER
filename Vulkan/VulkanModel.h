#ifndef VULKANMODEL_H
#define VULKANMODEL_H

#pragma once
#include <vulkan/vulkan.h>
#include <stb/stb_image.h>
#include <vector>
#include <Vulkan/VulkanTypes.h>
#include "GameRenderer.h"


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
    void createObject()
    {
//        createTextureImageCharacter(std::vector<std::string>{this->texturePath},this->pixels,this->textureImage,this->textureImageMemory);
//        createTextureImageViewCharacher(this->textureImage,this->imageView);
//        createTextureSamplersCharacter(this->textureSampler,this->texturePath);
//        createVertexBuffer(this->vertices, this->vertexBuffer, this->vertexBufferMemory);
//        createIndexBuffer(this->indices, this->indexBuffer, this->indexBufferMemory);
//        createDescriptorSetLayoutCharacter(this->descLayout);
//        createPipelineLayoutObj(this->descLayout,this->pipelineLayout);
//        createGraphicsPipeline(this->vertexShaderPath, this->fragmentShaderPath, this->ObjPipeline,this->pipelineLayout);
//        createUniformBuffersObj(this->uniformBuffers,this->uniformBuffersMemory,this->uniformBuffersMapped);
//        createDescriptorPoolCharacter(this->descPool);
//        createDescriptorSetsCharacter(this->uniformBuffers,
//                                this->descPool,
//                                this->descLayout,
//                                this->descSets,
//                                this->imageView,
//                                      this->textureSampler);
    };


    virtual void createTextureImages(std::vector<std::string> _paths, std::vector<stbi_uc *> _pixels, std::vector<VkImage> &_textureImage, std::vector<VkDeviceMemory> &_textureImageMemory);
    virtual void createTextureImageViews(std::vector<VkImage> &_textureImages, std::vector<VkImageView> &_imageViews);
    virtual void createTextureSamplers(std::vector<VkSampler> &_samplers, std::vector<std::string> _paths);
    virtual void createVertexBuffer(std::vector<Vertex> _vertices, VkBuffer& _vertexBuffer, VkDeviceMemory& _vertexBufferMemory);
    virtual void createIndexBuffer(std::vector<uint32_t> _indices, VkBuffer &_indexBuffer, VkDeviceMemory &_indexBufferMemory);
    virtual void createDescriptorSetLayout(VkDescriptorSetLayout& _descLayout);
    virtual void createPipelineLayout(VkDescriptorSetLayout& _descLayout,VkPipelineLayout& _layout);
    virtual void createGraphicsPipeline(const std::string &_vertShader, const std::string &_fragShader, VkPipeline &_pipeline, VkPipelineLayout &_layout);
    virtual void createUniformBuffers(std::vector<VkBuffer>& _uniformBuffers,
                                 std::vector<VkDeviceMemory>& _uniformBuffersMemory,
                                 std::vector<void*>& _uniformBuffersMapped);
    virtual void createDescriptorPool(VkDescriptorPool &_descPool);
    virtual void createDescriptorSets(std::vector<VkBuffer> &_uniformBuffers, VkDescriptorPool &_descPool, VkDescriptorSetLayout &_descLayout, std::vector<VkDescriptorSet> &_descSets, std::vector<VkImageView> &_imageView, std::vector<VkSampler> &_sampler);

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
