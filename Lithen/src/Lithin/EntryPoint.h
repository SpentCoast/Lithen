#pragma once

#ifdef LN_PLATFORM_WINDOWS

extern Lithin::Application* Lithin::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Lithin::CreateApplication();
	app->Run();
	delete app;
}

#endif
