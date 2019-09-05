#pragma once

#include "hzpch.h"

#include "Hazel/Core.h"
#include "Hazel/Events/Event.h"

namespace Hazel {

	struct WindowProps {

		std::string Title;
		uint Width;
		uint Height;
		
		WindowProps(const std::string& title = "Hazel Engine", uint width = 1280, uint height = 720) : Title(title), Width(width), Height(height) {};

	};

	//Interface based on window

	class HAZEL_API Window {
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual void OnUpdate() = 0;
		virtual uint GetWidth() const = 0;
		virtual uint GetHeight() const = 0;

		//
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVsync(bool enabled) = 0;
		virtual bool isVsync()const = 0;


		static Window* Create(const WindowProps& props = WindowProps());

	};



}