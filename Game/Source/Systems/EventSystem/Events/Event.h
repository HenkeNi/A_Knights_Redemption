#pragma once
#include "../Enums/Enumerations.h"

class Event
{
public:
	Event();


private:
	eEventType	m_eventType;
	bool		m_isHandled;

	// is repeating?!
};

