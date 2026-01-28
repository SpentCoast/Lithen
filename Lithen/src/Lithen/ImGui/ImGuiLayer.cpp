#include "lnpch.h"
#include "ImGuiLayer.h"

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>

#include "Platform/OpenGL/ImGuiOpenGLRenderer.h"
#include "Platform/Windows/WindowsWindow.h"

#include "Lithen/Application.h"

// Temporary
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Lithen
{
	ImGuiLayer::ImGuiLayer()
		: Layer{ "ImGuiLayer" }
	{
	}

	ImGuiLayer::~ImGuiLayer()
	{
	}

	void ImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		GLFWwindow* nativeWindow = (GLFWwindow*)Application::Get().GetWindow().GetNativeWindow();
		ImGui_ImplGlfw_InitForOpenGL(nativeWindow, true);
		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiLayer::OnDetach()
	{
	}

	void ImGuiLayer::OnUpdate()
	{
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

		float time = (float)glfwGetTime();
		io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0f / 60.0f);
		m_Time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImGuiLayer::OnEvent(Event& event)
	{
		
	}
}
