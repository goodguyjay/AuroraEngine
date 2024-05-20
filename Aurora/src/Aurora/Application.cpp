#include "aurorapch.h"
#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Aurora/Log.h"

namespace Aurora
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::run()
	{
		WindowResizeEvent e(1280, 720);

		// todo: test this
		if (e.isInCategory(EventCategoryApplication))
		{
			AURORA_TRACE("Event is in Application category");
			AURORA_TRACE(e.toString());
		}

		while (true);
	}

}
