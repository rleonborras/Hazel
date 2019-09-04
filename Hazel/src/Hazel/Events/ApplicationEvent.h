#pragma once

#include "Event.h"
#include <sstream>

namespace Hazel {

	class HAZEL_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(uint Height, uint Width) : m_Height(Height), m_Width(Width) {};

		inline uint GetWidth() const { return m_Height; }
		inline uint GetHeight() const { return m_Width; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowsResizeEvent : " << m_Height, "," < m_Width;
			return ss.str();
		}
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowResize)
	private:
		unsigned int m_Height, m_Width;
	};

	class HAZEL_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {};

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowClose)
	};

	class HAZEL_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() {};

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(AppTick)
	};

	class HAZEL_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {};

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(AppUpdate)
	};

	class HAZEL_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {};

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(AppRender)
	};



}