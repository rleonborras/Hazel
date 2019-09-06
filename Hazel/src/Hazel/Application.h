#pragma once
#include "Core.h"
#include "Hazel/LayerStack.h"
#include "Events/Event.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "Window.h"


namespace Hazel {

	class HAZEL_API Application
	{
	public:

		Application();
		virtual ~Application();

		void Run();
		
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

	private:

		bool OnWindowClose(WindowCloseEvent& e);
		bool m_Running = true;
		std::unique_ptr<Window>m_Window;
		LayerStack m_LayerStack;
	};

	//  To define in client
	Application* CreateApplication();
}
