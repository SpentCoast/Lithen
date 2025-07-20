#pragma once

#ifdef LN_PLATFORM_WINDOWS

extern Lithen::Application* Lithen::CreateApplication();

int main(int argc, char** argv)
{
	std::cout << "Welcome to Lithen engine!" << std::endl;
	auto app = Lithen::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif // LN_PLATFORM_WINDOWS

