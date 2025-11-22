#include "engine/renderer.h"

#include <ostream>
#include <iostream>
#include <cstdint>

#include <vulkan/vulkan_core.h>

namespace Lithen
{
	void Renderer::Initialize()
	{
		uint32_t extensionCount = 0;
		vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

		std::cout << "Lithen Initialized." << std::endl;
		std::cout << "Vulkan extensions available: " << extensionCount << std::endl;
	}
}