#pragma once
#include "Events/Event.h"

class EventListener
{
public:
	virtual void Receive(Event& anEvent) = 0;
};