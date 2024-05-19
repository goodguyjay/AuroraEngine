#pragma once

#ifdef AURORA_PLATFORM_WINDOWS

extern aurora::Application* create_application();

inline int main(int argc, char** argv)
{
	aurora::Log::init();

	AURORA_CORE_TRACE("TEST TEST 123");
	AURORA_CORE_WARN("ALOOOOOOOOOOOO BRASILLLLL");

	const auto app = aurora::create_application();
	app->run();
	delete app;
}

#endif
