#include <iostream>

#include <engine/renderer.h>

int main()
{
	std::cout << "Starting Game..." << std::endl;

	Lithen::Renderer renderer;
	renderer.Initialize();

	std::cout << "Game Loop Started. Press Enter to exit." << std::endl;
	std::cin.get();
	return 0;
}