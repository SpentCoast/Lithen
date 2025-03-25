#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Lithen
{
	Lithen::Application::Application()
	{
	}

	Lithen::Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			LN_TRACE(e.ToString());
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			LN_TRACE(e.ToString());
		}

		while (true);
	}
}
