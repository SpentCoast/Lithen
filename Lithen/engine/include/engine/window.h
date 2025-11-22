#pragma once

#include <string>
#include <cstdint>

struct GLFWwindow;

namespace Lithen
{
	struct WindowProps
	{
		std::string Title;
		uint32_t Width;
		uint32_t Height;

		WindowProps(
			const std::string& title = "Lithen Engine",
			uint32_t width = 1280,
			uint32_t height = 720)
			: Title{ title }, Width{ width }, Height{ height }
		{
		}
	};

	class Window
	{
	public:
		Window();
		~Window();

		bool Initialize(const WindowProps& props = WindowProps());

		void OnUpdate();

		uint32_t GetWidth() const { return m_Data.Width; }
		uint32_t GetHeight() const { return m_Data.Height; }
		bool ShouldClose() const;

		GLFWwindow* GetNativeWindow() const { return m_Window; }

	private:
		void Shutdown();

	private:
		GLFWwindow* m_Window = nullptr;

		struct WindowData
		{
			std::string Title;
			uint32_t Width = 0;
			uint32_t Height = 0;
		};

		WindowData m_Data;
	};
}
