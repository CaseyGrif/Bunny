#pragma once
#ifdef B_PLATFORM_WINDOWS
	#ifdef B_BUILD_DLL
		#define BUNNY_API __declspec(dllexport)
		#else
			#define BUNNY_API __declspec(dllimport)
		#endif
	#else
		#error Hazel only supports Windows!
#endif // B_PLATFORM_WINDOWS



using namespace std;

extern Bunny::Application* Bunny::CreateApplication();

int main(int argc, char* argv)
{
	Bunny::Log::init();
	B_CORE_WARN("Initialized Core Logger");
	B_INFO("Initialized Client Logger");


	auto app = Bunny::CreateApplication();
	app->Run();
	delete app;
}


