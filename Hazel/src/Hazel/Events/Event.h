#pragma once

#include "Hazel/Core.h"

#include <string>
#include <functional>

namespace Hazel {

	enum class EventType {

		None = 0,
		WindowClose,WindowResize, WindowFocus, WindowLostFocus,WindowsMoved,
		AppTick,AppUpdate,AppRender,
		KeyPressed,KeyReleased,
		MouseButtonPressed,MouseButtonReleased,MouseMoved,MouseScrolled

	};

	enum EventCategory {

		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4),
		
	};

	class HAZEL_API Event {
	public:

		virtual EventType GetEventType() const = 0 ;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool isInCategory(EventCategory category) {
			return GetCategoryFlags()& category;
		}
		
	protected:
		bool m_Handled = false;
	};

	class EventDispatcher {
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event) : m_Event(event){}

		template<typename T>
		bool Dispatch(EventFn<T> func) {
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
		

	private:
		Event& m_Event;
	};
}