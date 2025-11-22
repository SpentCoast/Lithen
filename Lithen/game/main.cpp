#include <iostream>

#include <engine/renderer.h>
#include <engine/window.h>

int main()
{
	std::cout << "Starting Game..." << std::endl;

	Lithen::Window window;
	if (!window.Inititalize())
		return -1;

	Lithen::Renderer renderer;
	if (!renderer.Initialize(window))
		return -1;

	std::cout << "Game Loop Started. Press Enter to exit." << std::endl;
	std::cin.get();
	return 0;
}