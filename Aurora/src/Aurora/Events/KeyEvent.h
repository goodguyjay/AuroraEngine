#pragma once

#include "Event.h"

#include <sstream>

namespace Aurora
{
	class AURORA_API KeyEvent : public Event
	{
	public:
		[[nodiscard]] inline int getKeSyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	protected:
		// protected constructor because we don't want to directly create a KeyEvent object
		// dangerous const here, but I believe its fine
		KeyEvent(const int keycode)
			: m_KeyCode(keycode) {}

		// todo: fix naming rules to stop resharper from complaining
		int m_KeyCode;
	};

	class AURORA_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), m_RepeatCount(repeatCount) {}

		[[nodiscard]] inline int getRepeatCount() const { return m_RepeatCount; }

		[[nodiscard]] std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			// todo: research why the .str is necessary in this case and also, research more about stringstream
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		int m_RepeatCount;
	};

	class AURORA_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {}

		[[nodiscard]] std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}