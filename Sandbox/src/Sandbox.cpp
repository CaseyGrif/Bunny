#define B_PLATFORM_WINDOWS
#include <Bunny.h>


class Sandbox : public Bunny::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}


};

Bunny::Application* Bunny::CreateApplication()
{
	return new Sandbox();
}