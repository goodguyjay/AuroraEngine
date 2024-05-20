#include <Aurora.h>

class Sandbox : public Aurora::Application
{
public:
	Sandbox() = default;

	~Sandbox() = default;
};

Aurora::Application* Aurora::create_application()
{
	return new Sandbox();
}