#pragma once

#ifdef LN_PLATFORM_WINDOWS

extern Lithen::Application* Lithen::CreateApplication(int argc, char** argv);
bool g_ApplicationRunning = true;

namespace Lithen {

	int Main(int argc, char** argv)
	{
		while (g_ApplicationRunning)
		{
			Lithen::Application* app = Lithen::CreateApplication(argc, argv);
			app->Run();
			delete app;
		}

		return 0;
	}

}

#ifdef LN_DIST

#include <Windows.h>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	return Lithen::Main(__argc, __argv);
}

#else

int main(int argc, char** argv)
{
	return Lithen::Main(argc, argv);
}

#endif // LN_DIST

#endif // LN_PLATFORM_WINDOWS
