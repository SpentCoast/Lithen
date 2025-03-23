#pragma once

#include "Core.h"

namespace Lithin
{
	class LITHIN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
