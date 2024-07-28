#include <Aurora.h>

class ExampleLayer : public Aurora::Layer
{
public:
	ExampleLayer()
		: Layer("Example") {}

	void onUpdate() override
	{
		//AURORA_INFO("ExampleLayer::Update");
		if (Aurora::Input::isKeyPressed(AURORA_KEY_TAB))
			AURORA_TRACE("Tab key is pressed (poll)!");
	}

	void onEvent(Aurora::Event& event) override
	{
		//AURORA_TRACE("{0}", event);
	}
};

class Sandbox : public Aurora::Application
{
public:
	Sandbox()
	{
		pushLayer(new ExampleLayer());
		pushOverlay(new Aurora::ImGuiLayer());
	}

	~Sandbox() = default;
};

Aurora::Application* Aurora::createApplication()
{
	return new Sandbox();
}
