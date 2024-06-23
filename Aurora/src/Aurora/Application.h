#pragma once

#include "Aurora/Core.h"

#include "Window.h"
#include "Aurora/LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

namespace Aurora
{
	class AURORA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();

		void onEvent(Event& e);

		void pushLayer(Layer* layer);
		void pushOverlay(Layer* layer);

		inline static Application& get() { return *s_Instance; }
		inline Window& getWindow() { return *m_Window; }
	private:
		bool onWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

		static Application* s_Instance;
	};

	// To de defined in CLIENT
	Application* createApplication();
}
