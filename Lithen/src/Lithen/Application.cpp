#include "lnpch.h"
#include "Application.h"

#include "Lithen/Events/ApplicationEvent.h"
#include "Lithen/Log.h"

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
			m_Window->OnUpdate();
		}
	}
}
