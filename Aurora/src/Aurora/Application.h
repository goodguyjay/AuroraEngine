#pragma once

#include "Core.h"

namespace aurora
{
	class AURORA_API Application
	{
	public:
		Application();
		virtual ~Application();

		[[noreturn]] void run();
	};

	// To de defined in CLIENT
	Application* create_application();
}