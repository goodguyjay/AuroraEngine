#pragma once

#include "Core.h"

namespace Aurora
{
	class AURORA_API Application
	{
	public:
		Application();
		virtual ~Application();

		[[noreturn]] void run();
	};

	// To de defined in CLIENT
	// todo: change this
	Application* create_application();
}