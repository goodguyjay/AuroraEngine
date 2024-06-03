#include "aurorapch.h"
#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Aurora/Log.h"

// i forgot why is this included here, i'll look at it later
#include <GLFW/glfw3.h>

namespace Aurora
{
#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::create());
		m_Window->setEventCallback(BIND_EVENT_FN(Application::onEvent));
	}

	Application::~Application()
	{

	}

	void Application::onEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		//dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::onWindowClose));

		AURORA_CORE_TRACE("{0}", e);
	}

	void Application::run()
	{
		WindowResizeEvent e(1280, 720);

		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->onUpdate();
		}
	}

}