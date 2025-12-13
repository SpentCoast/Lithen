#pragma once

#ifdef LN_PLATFORM_WINDOWS

extern Lithen::Application* Lithen::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Lithen::CreateApplication();
	app->Run();
	delete app;
}

#endif
