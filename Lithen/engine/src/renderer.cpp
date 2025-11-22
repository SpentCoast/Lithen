#include "engine/renderer.h"
#include "engine/window.h"

#include <iostream>
#include <cstring>
#include <vector>
#include <cstdint>

#include <vulkan/vulkan_core.h>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define VK_CHECK(x) \
	do { \
		VkResult err = x; \
		if (err) { \
			std::cerr << "[Renderer] Vulkan Error: " << err << " at " << __FILE__ << ":" << __LINE__ << std::endl; \
			return false; \
		} \
	} while (0)

namespace Lithen
{
	Renderer::Renderer() : m_Instance{ VK_NULL_HANDLE }
	{
	}

	Renderer::~Renderer()
	{
		Shutdown();
	}

	bool Renderer::Initialize(Window& window)
	{
		(void)window;

		std::cout << "[Renderer] Initializing Vulkan..." << std::endl;

		if (m_EnableValidationLayers && !CheckValidationLayerSupport())
		{
			std::cerr << "[Renderer] Validation layers requested, but not available!" << std::endl;
			return false;
		}

		if (!CreateInstance())
		{
			return false;
		}

		std::cout << "[Renderer] Initialization Complete." << std::endl;
		return true;
	}

	void Renderer::Shutdown()
	{
		if (m_Instance != VK_NULL_HANDLE)
		{
			vkDestroyInstance(m_Instance, nullptr);
			m_Instance = VK_NULL_HANDLE;
		}
	}

	bool Renderer::CreateInstance()
	{
		VkApplicationInfo appInfo{};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pApplicationName = "Lithen App";
		appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.pEngineName = "Lithen Engine";
		appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.apiVersion = VK_API_VERSION_1_3;

		VkInstanceCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pApplicationInfo = &appInfo;

		auto extensions = GetRequiredExtensions();
		createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
		createInfo.ppEnabledExtensionNames = extensions.data();

		if (m_EnableValidationLayers)
		{
			createInfo.enabledLayerCount = static_cast<uint32_t>(m_ValidationLayers.size());
			createInfo.ppEnabledLayerNames = m_ValidationLayers.data();
		}
		else
		{
			createInfo.enabledLayerCount = 0;
		}

		VK_CHECK(vkCreateInstance(&createInfo, nullptr, &m_Instance));

		return true;
	}

	std::vector<const char*> Renderer::GetRequiredExtensions() const
	{
		uint32_t glfwExtensionCount = 0;
		const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

		std::vector<const char*> extensions{ glfwExtensions, glfwExtensions + glfwExtensionCount };

		if (m_EnableValidationLayers)
		{
			extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
		}

		return extensions;
	}

	bool Renderer::CheckValidationLayerSupport()
	{
		uint32_t layerCount;
		vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

		std::vector<VkLayerProperties> availableLayers{ layerCount };
		vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

		for (const char* layerName : m_ValidationLayers)
		{
			bool layerFound = false;

			for (const auto& layerProperties : availableLayers)
			{
				if (strcmp(layerName, layerProperties.layerName) == 0)
				{
					layerFound = true;
					break;
				}
			}

			if (!layerFound)
			{
				return false;
			}
		}

		return true;
	}
}