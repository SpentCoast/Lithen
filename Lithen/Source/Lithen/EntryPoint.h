#pragma once

bool g_ApplicationRunning = true;

#ifdef LN_PLATFORM_WINDOWS

int main(int argc, char** argv)
{
	while (g_ApplicationRunning)
	{
		Lithen::Application* app = Lithen::CreateApplication(argc, argv);
		app->Run();
		delete app;
	}
}

#endif // LN_PLATFORM_WINDOWS
