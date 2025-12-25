#include "lnpch.h"
#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

#include <GLFW/glfw3.h>

namespace Lithen
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(0.1f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}
