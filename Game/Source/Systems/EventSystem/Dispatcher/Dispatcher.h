#pragma once
#include "Enumerations.h"

class Event;
class EventListener;


class Dispatcher
{
public:
	static Dispatcher& GetInstance();

	Dispatcher(const Dispatcher&) = delete;
	Dispatcher& operator=(const Dispatcher&) = delete;

	void Subscribe(const eEventType anEventType, EventListener* aSubscriber);
	void Unsubscribe(const eEventType anEventType, EventListener* aSubscriber);
	void SendEvent(const Event& anEvent);

private:
	Dispatcher() = default;

	std::unordered_map<eEventType, std::vector<EventListener*>> m_listeners; // TODO: replace array with Binary Search Tree Set or AVL or SPlay Tree? or map
};
