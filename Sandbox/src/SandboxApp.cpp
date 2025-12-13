#include <Lithen.h>

class Sandbox : public Lithen::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Lithen::Application* Lithen::CreateApplication()
{
	return new Sandbox();
}
