#include "Pch.h"
#include "Event.h"


Event::Event(eEventType anEventType, const std::any& someData)
	: m_type{ anEventType }, m_data{ someData }, m_isHandled{ false }
{
}

eEventType Event::GetEventType() const
{
	return m_type;
}

const std::any& Event::GetData() const
{
	return m_data;
}

bool Event::IsHandled() const
{
	return m_isHandled;
}

void Event::HandleEvent()
{
	m_isHandled = true;
}