#pragma once
#include "aurorapch.h"
#include "Aurora/Core.h"
// todo: add comments explaining the code

namespace Aurora
{
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		// those enums receiving BIT values because we want to make them receive multiple categories
		// ex: a Keyboard event is also an Input event
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType getStaticType() { return EventType::##type; }\
								virtual EventType getEventType() const override { return getStaticType(); }\
								virtual const char* getName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlags() const override { return category; }

	class AURORA_API Event
	{
		friend class EventDispatcher;
	public:
		// todo: learn and check why the [[nodiscard]] is used and when it should be used
		// virtual functions that will be overriden by the events
		[[nodiscard]] virtual EventType getEventType() const = 0;
		[[nodiscard]] virtual const char* getName() const = 0;
		[[nodiscard]] virtual int getCategoryFlags() const = 0;
		[[nodiscard]] virtual std::string toString() const { return getName(); }

		// todo: check if those const aren't making the code not work
		[[nodiscard]] inline bool isInCategory(const EventCategory category) const
		{
			// if this returns 0 it means that the event is not in the category
			return getCategoryFlags() & category;
		}

	protected:
		// variable to check if the event has been handled
		bool m_Handled = false;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& event)
			: m_Event(event) {}

		template<typename T>
		bool dispatch(EventFn<T> func)
		{
			if (m_Event.getEventType() == T::getStaticType())
			{
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.toString();
	}

}