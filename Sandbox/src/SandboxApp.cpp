#include <Lithin.h>

class Sandbox : public Lithin::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Lithin::Application* Lithin::CreateApplication()
{
	return new Sandbox();
}