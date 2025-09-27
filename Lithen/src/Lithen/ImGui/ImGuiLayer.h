#pragma once

#include "Lithen/Layer.h"

#include "Lithen/Events/KeyEvent.h"
#include "Lithen/Events/MouseEvent.h"
#include "Lithen/Events/ApplicationEvent.h"

namespace Lithen
{
	class LITHEN_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
	private:
		float m_Time = 0.0f;
	};
}
