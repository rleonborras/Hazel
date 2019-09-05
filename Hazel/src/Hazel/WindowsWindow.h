#pragma once
#include "Window.h"

#include "GLFW/glfw3.h"

namespace Hazel {


	class WindowsWindow : public Window {
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline uint GetWidth() const override { return m_Data.Width; }
		inline uint GetHeight() const override { return m_Data.Height; }

		//WindowAttributes 

		virtual void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; };
		virtual void SetVsync(bool enabled) override;
		virtual bool isVsync()const override ;
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		GLFWwindow* m_Window;

		struct WindowData {

			std::string Title;
			uint  Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;

	};

}