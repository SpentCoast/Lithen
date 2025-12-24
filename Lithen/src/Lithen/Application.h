#pragma once

#include "Core.h"

namespace Lithen
{
	class LITHEN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}
