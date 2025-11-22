#include <iostream>

#include <engine/renderer.h>
#include <engine/window.h>

int main()
{
	std::cout << "Starting Game..." << std::endl;

	Lithen::Window window;
	if (!window.Initialize())
	{
		return -1;
	}

	Lithen::Renderer renderer;
	if (!renderer.Initialize(window))
	{
		return -1;
	}

	std::cout << "Game Loop Started." << std::endl;

	while (!window.ShouldClose())
	{
		window.OnUpdate();
	}

	renderer.Shutdown();

	return 0;
}