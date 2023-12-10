#pragma once
#include "DataTypes/Enumerations.h"

class Event;
class EventListener;

// Rename: Event Dispacther instead?? - SubscribeToEvent()? UnsubscribeFromEvent()?
class Dispatcher
{
public:
	Dispatcher(const Dispatcher&)			 = delete;
	Dispatcher& operator=(const Dispatcher&) = delete;
	
	static Dispatcher&	GetInstance();

	void				Subscribe(const eEventType anEventType, EventListener* aSubscriber); 
	void				Unsubscribe(const eEventType anEventType, EventListener* aSubscriber);
	void				SendEvent(Event anEvent);

private:
	Dispatcher() = default;

	std::unordered_map<eEventType, std::vector<EventListener*>> m_listeners; // TODO: replace array with Binary Search Tree Set or AVL or SPlay Tree? or map
};
