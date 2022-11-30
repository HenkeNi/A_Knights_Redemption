#pragma once
#include "../Enums/Enumerations.h"

class Event
{
public:
	Event(eEventType anEventType, const std::any& someData);
	virtual	~Event() = default;

	eEventType			GetEventType()	const;
	const std::any&		GetData()		const;
	std::any			GetData();
private:
	std::any			m_data;
	eEventType			m_type;
	bool				m_isHandled;

	// is repeating?!
};

