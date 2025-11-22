#pragma once

#include "engine/window.h"

#include <vector>

#include <vulkan/vulkan_core.h>

namespace Lithen
{
	class Renderer
	{
	public:
		Renderer();
		~Renderer();

		bool Initialize(Window& window);
		void Shutdown();

	private:
		bool CreateInstance();
		bool CheckValidationLayerSupport();
		std::vector<const char*> GetRequiredExtensions() const;

	private:
		VkInstance m_Instance;

#ifdef NDEBUG
		const bool m_EnableValidationLayers = false;
#else
		const bool m_EnableValidationLayers = true;
#endif

		const std::vector<const char*> m_ValidationLayers = {
			"VK_LAYER_KHRONOS_validation"
		};
	};
}