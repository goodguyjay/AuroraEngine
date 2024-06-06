#pragma once

#ifdef AURORA_PLATFORM_WINDOWS

// todo: change this snake_case stuff to camelCase
extern Aurora::Application* create_application();

inline int main(int argc, char** argv)
{
	Aurora::Log::init();

	AURORA_CORE_TRACE("disgrama o console ta colorido");
	AURORA_CORE_INFO("que massa");
	AURORA_INFO("corzinha pspsps");
	AURORA_CORE_WARN("gatinho ei gatinho pspspspsps");
	AURORA_CORE_ERROR("COWABUNGA");

	const auto app = Aurora::createApplication();
	app->run();
	delete app;
}

#endif