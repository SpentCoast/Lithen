#include "Lithen/Application.h"
#include "Lithen/EntryPoint.h"

#include "Lithen/Image.h"

using namespace Lithen;

class TestLayer : public Lithen::Layer
{
public:
	virtual void OnUIRender() override
	{
		ImGui::ShowDemoWindow();
	}
};

Lithen::Application* Lithen::CreateApplication(int argc, char** argv)
{
	Lithen::ApplicationSpecification appSpec;

	Lithen::Application* app = new Lithen::Application(appSpec);
	app->PushLayer<TestLayer>();
	app->SetMenubarCallback([app]()
		{
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("Exit"))
				{
					app->Close();
				}
				ImGui::EndMenu();
			}
		});
	
	return app;
}
