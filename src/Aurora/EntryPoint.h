#pragma once

#ifdef AURORA_PLATFORM_WINDOWS

extern aurora::Application* aurora::create_application();

int main(int argc, char** argv)
{
	printf("Aurora Engine\n");
	auto app = aurora::create_application();
	app->run();
	delete app;
}

#endif