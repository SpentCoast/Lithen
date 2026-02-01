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
		if (Lithen::Input::IsKeyPressed(LN_KEY_TAB))
			LN_TRACE("Tab key is pressed!");
	}

	void OnEvent(Lithen::Event& event) override
	{
		if (event.GetEventType() == Lithen::EventType::KeyPressed)
		{
			Lithen::KeyPressedEvent& e = (Lithen::KeyPressedEvent&)event;
			LN_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox : public Lithen::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
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
