#pragma once

#include "Window.h"
#include "Aurora/Core.h"
#include "Events/Event.h"

namespace Aurora
{
	class AURORA_API Application
	{
	public:
		Application();
		virtual ~Application();

		[[noreturn]] void run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To de defined in CLIENT
	// todo: change this
	Application* create_application();
}