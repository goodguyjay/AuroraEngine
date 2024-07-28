#include "aurorapch.h"
#include "Application.h"

#include "Aurora/Log.h"

#include <GLAD/glad.h>

#include "Input.h"

namespace Aurora
{
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		AURORA_CORE_ASSERT(s_Instance == nullptr, "Application already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::create());
		m_Window->setEventCallback(BIND_EVENT_FN(onEvent));
	}

	Application::~Application()
	{
	}

	void Application::pushLayer(Layer* layer)
	{
		m_LayerStack.pushLayer(layer);
		layer->onAttach();
	}

	void Application::pushOverlay(Layer* layer)
	{
		m_LayerStack.pushOverlay(layer);
		layer->onAttach();
	}

	void Application::onEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClose));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->onEvent(e);
			if (e.getHandled())
			{
				break;
			}
		}
	}

	void Application::run()
	{
		WindowResizeEvent e(1280, 720);

		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
			{
				layer->onUpdate();
			}

			auto [x, y] = Input::getMousePosition();
			AURORA_CORE_TRACE("{0}, {1}", x, y);

			m_Window->onUpdate();
		}
	}

	bool Application::onWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}
