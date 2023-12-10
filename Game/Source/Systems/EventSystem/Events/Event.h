#pragma once
#include "DataTypes/Enumerations.h"

class Event
{
public:
	Event(eEventType anEventType, const std::any& someData);
	virtual	~Event() = default;

	eEventType			GetEventType()	const;
	const std::any&		GetData()		const;
	bool				IsHandled()		const;
	void				HandleEvent();

private:
	std::any			m_data;
	eEventType			m_type;
	bool				m_isHandled;

	// is repeating?!
};

