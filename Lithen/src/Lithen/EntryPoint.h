#pragma once

#ifdef LN_PLATFORM_WINDOWS

extern Lithen::Application* Lithen::CreateApplication();

int main(int argc, char** argv)
{
	Lithen::Log::Init();
	LN_CORE_WARN("Initialized Log!");
	int a = 5;
	LN_INFO("Hello! Var={0}", a);

	auto app = Lithen::CreateApplication();
	app->Run();
	delete app;
}

#endif
