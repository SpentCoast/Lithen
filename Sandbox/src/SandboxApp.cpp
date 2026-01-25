#include <Lithen.h>

class ExampleLayer : public Lithen::Layer
{
public:
	ExampleLayer()
		: Layer{ "Example" }
	{
	}

	void OnUpdate() override
	{
		LN_INFO("ExampleLayer::Update");
	}

	void OnEvent(Lithen::Event& event) override
	{
		LN_TRACE("{0}", event.ToString());
	}
};

class Sandbox : public Lithen::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Lithen::Application* Lithen::CreateApplication()
{
	return new Sandbox();
}
