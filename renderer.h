#ifndef RENDERER_H
#define RENDERER_H
#include <stb/stb_image.h>
#define GLFW_INCLUDE_VULKAN

#include "controller.h"

#include <GLFW/glfw3.h>
#include <shaderLoader.h>
#include <stdexcept>
#include <vector>
#include <cstring>
#include <iostream>
#include <optional>
#include <set>
#include <cstdint> // Necessary for uint32_t
#include <limits> // Necessary for std::numeric_limits
#include <algorithm> // Necessary for std::clamp

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <QObject>


#include "VulkanModel.h"
#include "VulkanCharacterModel.h"
//#include <QKeyEvent>


const uint32_t WIDTH = 1200;
const uint32_t HEIGHT = 800;

const std::vector<const char*> validationLayers = {
    "VK_LAYER_KHRONOS_validation"
};
const std::vector<const char*> deviceExtensions = {
    VK_KHR_SWAPCHAIN_EXTENSION_NAME
};
struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;
    bool isComplete() {
           return graphicsFamily.has_value() && presentFamily.has_value();
       }
};
struct SwapChainSupportDetails {
    VkSurfaceCapabilitiesKHR capabilities;
    std::vector<VkSurfaceFormatKHR> formats;
    std::vector<VkPresentModeKHR> presentModes;
};
static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,[[maybe_unused]]VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,[[maybe_unused]]void* pUserData)
{

    if (messageSeverity >= VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT) {
        std::cout << "validation layer: " << pCallbackData->pMessage << std::endl;
    }

    return VK_FALSE;
}

struct ObjectBuffer
{
    ~ObjectBuffer()
    {
    }
    int idObject;
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

struct UniformBufferObject {
    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 proj;
};


//#define NDEBUG

#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif

class renderer : public QObject
{
    Q_OBJECT
public:
    renderer();
    void init();
    void setObjectsPtr(std::vector<VulkanObject *> *_ptr,std::vector<VulkanCharacterObject *> * _characters);
    void run()
    {
        mainLoop();
        cleanup();
    }
    void drawFrame();
    void createCharacter(VulkanCharacterObject* object);
private:
    void initWindow();
        static void framebufferResizeCallback(GLFWwindow* window,[[maybe_unused]] int width,[[maybe_unused]] int height) {
            auto app = reinterpret_cast<renderer*>(glfwGetWindowUserPointer(window));
                app->framebufferResized = true;
        }
    void initVulkan();
        void createInstance();
        void pickPhysicalDevice();
            bool isDeviceSuitable(VkPhysicalDevice device);
            VkFormat findSupportedFormat(const std::vector<VkFormat>& candidates, VkImageTiling tiling, VkFormatFeatureFlags features);
            VkFormat findDepthFormat();
            bool hasStencilComponent(VkFormat format);
            QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
            bool checkDeviceExtensionSupport(VkPhysicalDevice device);
            SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
            uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
        void createSwapChain();
            VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
            VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
            VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
        void createLogicalDevice();
        void createSurface();
        void createImageViews();
        void createPipelineLayout();
        void createRenderPass();
        void createFramebuffers();
        void createCommandPool();
        void createCommandBuffer();
        void createDescriptorSetLayout();
        void createDescriptorPool();
        void createDescriptorSets();
        void createUniformBuffers();
        void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);
        void createSyncObjects();
        void cleanupSwapChain();
        void recreateSwapChain() {
            int width = 0, height = 0;
            glfwGetFramebufferSize(window, &width, &height);
            while (width == 0 || height == 0) {
                glfwGetFramebufferSize(window, &width, &height);
                glfwWaitEvents();
            }

            vkDeviceWaitIdle(device);

            cleanupSwapChain();

            createSwapChain();
            createImageViews();
            createFramebuffers();
        }

        void createTextureImageCharacter(std::vector<std::string> _paths, std::vector<stbi_uc *> _pixels, std::vector<VkImage> &_textureImage, std::vector<VkDeviceMemory> &_textureImageMemory);
        void createTextureImageViewCharacher(std::vector<VkImage> &_textureImages, std::vector<VkImageView> &_imageViews);
        void createTextureSamplersCharacter(std::vector<VkSampler> &_samplers, std::vector<std::string> _paths);
        void createDescriptorSetLayoutCharacter(VkDescriptorSetLayout& _descLayout);
        void createDescriptorPoolCharacter(VkDescriptorPool &_descPool);
        void createDescriptorSetsCharacter(std::vector<VkBuffer> &_uniformBuffers, VkDescriptorPool &_descPool, VkDescriptorSetLayout &_descLayout, std::vector<VkDescriptorSet> &_descSets, std::vector<VkImageView> &_imageView, std::vector<VkSampler> &_sampler);



        void createImage(uint32_t width, uint32_t height,
                         VkFormat format, VkImageTiling tiling, VkImageUsageFlags usage,
                         VkMemoryPropertyFlags properties, VkImage& image, VkDeviceMemory& imageMemory);
        void createVertexBuffer(std::vector<Vertex> _vertices, VkBuffer& _vertexBuffer, VkDeviceMemory& _vertexBufferMemory);
        void createIndexBuffer(std::vector<uint32_t> _indices, VkBuffer &_indexBuffer, VkDeviceMemory &_indexBufferMemory);
        void createGraphicsPipeline(const std::string &_vertShader, const std::string &_fragShader, VkPipeline &_pipeline, VkPipelineLayout &_layout);




        void createObject(VulkanObject* object)
        {
//            ObjectBuffer object;

            createTextureImageObj(object->texturePath,object->pixels,object->textureImage,object->textureImageMemory);
            createTextureImageView(object->textureImage,object->imageView);
            createTextureSampler(object->textureSampler);
            createVertexBuffer(object->vertices, object->vertexBuffer, object->vertexBufferMemory);
            createIndexBuffer(object->indices, object->indexBuffer, object->indexBufferMemory);
            createDescriptorSetLayoutObj(object->descLayout);
            createPipelineLayoutObj(object->descLayout,object->pipelineLayout);
            createGraphicsPipeline(object->vertexShaderPath, object->fragmentShaderPath, object->ObjPipeline,object->pipelineLayout);
            createUniformBuffersObj(object->uniformBuffers,object->uniformBuffersMemory,object->uniformBuffersMapped);
            createDescriptorPoolObj(object->descPool);
            createDescriptorSetsObj(object->uniformBuffers,
                                    object->descPool,
                                    object->descLayout,
                                    object->descSets,
                                    object->imageView,
                                    object->textureSampler);
        }


        void createDescriptorSetLayoutObj(VkDescriptorSetLayout& _descLayout);
        void createPipelineLayoutObj(VkDescriptorSetLayout& _descLayout,VkPipelineLayout& _layout);

        void createUniformBuffersObj(std::vector<VkBuffer>& _uniformBuffers,
                                     std::vector<VkDeviceMemory>& _uniformBuffersMemory,
                                     std::vector<void*>& _uniformBuffersMapped);
        void createDescriptorPoolObj(VkDescriptorPool& _descPool);
        void createDescriptorSetsObj(std::vector<VkBuffer>& _uniformBuffers,
                                     VkDescriptorPool& _descPool,
                                     VkDescriptorSetLayout& _descLayout,
                                     std::vector<VkDescriptorSet>& _descSets,
                                     VkImageView& _imageView,
                                     VkSampler& _sampler);
        void createDepthResources();

        void createTextureImageObj(std::string _path,stbi_uc* pixels,VkImage& _textureImage,VkDeviceMemory& _textureImageMemory);

        void createTextureImageView(VkImage& _textureImage, VkImageView& _imageView);

        VkImageView createImageView(VkImage image, VkFormat format,VkImageAspectFlags aspectFlags);

        void createTextureSampler(VkSampler& _sampler);

        void createBuffer(VkDeviceSize size, VkBufferUsageFlags usage,
                          VkMemoryPropertyFlags properties, VkBuffer& buffer,
                          VkDeviceMemory& bufferMemory);
        void endSingleTimeCommands(VkCommandBuffer commandBuffer);
        VkCommandBuffer beginSingleTimeCommands();

        void transitionImageLayout(VkImage image, VkFormat format, VkImageLayout oldLayout, VkImageLayout newLayout);
        void copyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width, uint32_t height);
        void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);
    void mainLoop();
    void cleanup();

    // Vk Objects
    GLFWwindow* window;
    VkInstance instance;
    VkSurfaceKHR surface;
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkDevice device;
    VkQueue graphicsQueue;
    VkQueue presentQueue;
    VkSwapchainKHR swapChain;
    std::vector<VkImage> swapChainImages;
    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;
    std::vector<VkImageView> swapChainImageViews;
    VkRenderPass renderPass = VK_NULL_HANDLE;
    VkDescriptorSetLayout descriptorSetLayout;
    VkPipelineLayout pipelineLayout;
    std::vector<VkFramebuffer> swapChainFramebuffers;
    VkCommandPool commandPool;
    std::vector<VkCommandBuffer> commandBuffers;
    std::vector<VkSemaphore> imageAvailableSemaphores;
    std::vector<VkSemaphore> renderFinishedSemaphores;
    std::vector<VkFence> inFlightFences;
    const size_t MAX_FRAMES_IN_FLIGHT = 2;
    uint32_t currentFrame = 0;
    bool framebufferResized = false;

    VkImage depthImage = VK_NULL_HANDLE;
    VkDeviceMemory depthImageMemory = VK_NULL_HANDLE;
    VkImageView depthImageView = VK_NULL_HANDLE;


    ObjectBuffer exampleObject;




    std::vector<VulkanObject*>* _gameObjects;
    std::vector<VulkanCharacterObject*>* _gameCharacters;
//    std::vector<VkBuffer> uniformBuffers;
//    std::vector<VkDeviceMemory> uniformBuffersMemory;
//    std::vector<void*> uniformBuffersMapped;
//    VkDescriptorPool descriptorPool;
//    std::vector<VkDescriptorSet> descriptorSets;
    //--------

    // Debug funcs
    VkDebugUtilsMessengerEXT debugMessenger;
    void setupDebugMessenger();
    bool checkValidationLayerSupport();
    VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger) {
        auto func = (PFN_vkCreateDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
        if (func != nullptr) {
            return func(instance, pCreateInfo, pAllocator, pDebugMessenger);
        } else {
            return VK_ERROR_EXTENSION_NOT_PRESENT;
        }
    }
    void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator) {
        auto func = (PFN_vkDestroyDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT");
        if (func != nullptr) {
            func(instance, debugMessenger, pAllocator);
        }
    }
    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo) {
        createInfo = {};
        createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
        createInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
        createInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
        createInfo.pfnUserCallback = debugCallback;
    }
    std::vector<const char*> getRequiredExtensions();
    //------------
};

#endif // RENDERER_H
