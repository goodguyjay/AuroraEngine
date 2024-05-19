#include <Aurora.h>

class Sandbox : public aurora::Application
{
public:
	Sandbox() = default;

	~Sandbox() = default;
};

aurora::Application* aurora::create_application()
{
	return new Sandbox();
}