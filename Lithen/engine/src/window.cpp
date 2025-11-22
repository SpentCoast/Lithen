#include "engine/window.h"

#include <iostream>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace Lithen
{
	static int s_WindowCount = 0;

	Window::Window()
	{
	}

	Window::~Window()
	{
		Shutdown();
	}


	bool Window::Initialize(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;
		
		std::cout << "[Window] Initializing..." << std::endl;

		if (s_WindowCount == 0)
		{
			if (!glfwInit())
			{
				std::cerr << "[Window] Failed to initialize GLFW!" << std::endl;
				return false;
			}
		}

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		m_Window = glfwCreateWindow(static_cast<int>(props.Width), static_cast<int>(props.Height), m_Data.Title.c_str(), nullptr, nullptr);

		if (!m_Window)
		{
			std::cerr << "[Window] Failed to create GLFW window!" << std::endl;
			if (s_WindowCount == 0) glfwTerminate();
			return false;
		}

		s_WindowCount++;
		return true;
	}


	void Window::Shutdown()
	{
		if (m_Window)
		{
			glfwDestroyWindow(m_Window);
			m_Window = nullptr;
			s_WindowCount--;
		}

		if (s_WindowCount == 0)
		{
			glfwTerminate();
		}
	}

	void Window::OnUpdate()
	{
		glfwPollEvents();
	}

	bool Window::ShouldClose() const
	{
		return glfwWindowShouldClose(m_Window);
	}
}