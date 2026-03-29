#pragma once

#include "Layer.h"

#include <imgui.h>

#include <string>
#include <vector>
#include <memory>
#include <functional>

struct GLFWwindow;

namespace Lithen {

	struct ApplicationSpecification
	{
		std::string Name = "Lithen App";
		uint32_t Width = 1280;
		uint32_t Height = 720;
	};

	class Application
	{
	public:
		Application(const ApplicationSpecification& applicationSpecification = ApplicationSpecification());
		~Application();

		static Application& Get();

		void Run();
		void SetMenubarCallback(const std::function<void()>& menubarCallback) { m_MenubarCallback = menubarCallback; }

		template<typename T>
		void PushLayer()
		{
			static_assert(std::is_base_of<Layer, T>::value, "Pushed type is not subclass of layer!");
			m_LayerStack.emplace_back(std::make_shared<T>())->OnAttach();
		}

		void PushLayer(const std::shared_ptr<Layer>& layer)
		{
			m_LayerStack.emplace_back(layer);
			layer->OnAttach();
		}

		void Close();

		float GetTime();
		GLFWwindow* GetWindowHandle() const { return m_WindowHandle; }

	private:
		void Init();
		void Shutdown();
	private:
		ApplicationSpecification m_Specification;
		GLFWwindow* m_WindowHandle = nullptr;
		bool m_Running = false;

		float m_TimeStep = 0.0f;
		float m_FrameTime = 0.0f;
		float m_LastFrameTime = 0.0f;

		std::vector<std::shared_ptr<Layer>> m_LayerStack;
		std::function<void()> m_MenubarCallback;
	};

	Application* CreateApplication(int argc, char** argv);

}

