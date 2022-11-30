#include "Pch.h"
#include "Event.h"


Event::Event(eEventType anEventType, const std::any& someData)
	: m_type{ anEventType }, m_data{ someData }, m_isHandled { false }
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

std::any Event::GetData()
{
	return m_data;
}