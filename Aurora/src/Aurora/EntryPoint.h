#pragma once

#ifdef AURORA_PLATFORM_WINDOWS

// todo: change this snake_case stuff to camelCase
extern Aurora::Application* create_application();

inline int main(int argc, char** argv)
{
	Aurora::Log::init();

	AURORA_CORE_TRACE("TEST TEST 123");
	AURORA_CORE_INFO("TEST2");
	AURORA_INFO("LALALAL");

	const auto app = Aurora::create_application();
	app->run();
	delete app;
}

#endif