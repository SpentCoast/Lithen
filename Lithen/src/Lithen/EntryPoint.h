#pragma once

#ifdef LN_PLATFORM_WINDOWS

extern Lithen::Application* Lithen::CreateApplication();

int main(int argc, char** argv)
{
	Lithen::Log::Init();

	LN_CORE_WARN("Initialized Log!");
	LN_INFO("Hello, world!");

	auto app = Lithen::CreateApplication();
	app->Run();
	delete app;
}

#endif
