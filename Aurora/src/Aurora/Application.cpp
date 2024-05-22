#include "aurorapch.h"
#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Aurora/Log.h"

namespace Aurora
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::create());
	}

	Application::~Application()
	{

	}

	void Application::run()
	{
		WindowResizeEvent e(1280, 720);

		while (m_Running)
		{
			m_Window->onUpdate();
		}
	}

}