#pragma once
#include "Events/Event.h"

class EventListener
{
public:
	virtual void Receive(const Event& anEvent) = 0;
};