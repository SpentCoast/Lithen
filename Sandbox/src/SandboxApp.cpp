#include <Lithen.h>

class TestLayer : public Lithen::Layer
{
public:
	TestLayer() : Layer("Test")
	{

	}

	void OnUpdate() override
	{
		LN_INFO("TestLayer::Update");
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
		PushLayer(new TestLayer());
		PushOverlay(new Lithen::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Lithen::Application* Lithen::CreateApplication()
{
	return new Sandbox();
}