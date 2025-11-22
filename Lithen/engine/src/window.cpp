#include "engine/window.h"

#include <iostream>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace Lithen
{
	Window::Window()
	{
	}

	Window::~Window()
	{
		Shutdown();
	}


	bool Window::Inititalize(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;
		
		std::cout << "[Window] Initializing..." << std::endl;

		if (!glfwInit())
		{
			std::cerr << "[Window] Failed to initialize GLFW!" << std::endl;
			return false;
		}

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		m_Window = glfwCreateWindow(static_cast<int>(props.Width), static_cast<int>(props.Height), m_Data.Title.c_str(), nullptr, nullptr);

		if (!m_Window)
		{
			std::cerr << "[Window] Failed to create GLFW window!" << std::endl;
			glfwTerminate();
			return false;
		}

		return true;
	}


	void Window::Shutdown()
	{
		if (m_Window)
		{
			glfwDestroyWindow(m_Window);
		}
		glfwTerminate();
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