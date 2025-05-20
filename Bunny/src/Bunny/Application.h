#pragma once

#include "Core.h"

namespace  Bunny
{
	class BUNNY_API Application
	{
	public:

		Application();

		virtual ~Application();

		void Run();
	};


	Application* CreateApplication();
}


