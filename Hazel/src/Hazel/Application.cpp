#include "hzpch.h"
#include "Application.h"
#include "Events/Event.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "Log.h"


namespace Hazel {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		HZ_TRACE(e);
		while (true);
	}
}