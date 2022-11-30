#include "Pch.h"
#include "Dispatcher.h"
#include "Events/Event.h"
#include "Listeners/EventListener.h"


Dispatcher& Dispatcher::GetInstance()
{
	static Dispatcher instance;
	return instance;
}

void Dispatcher::Subscribe(const eEventType anEventType, EventListener* aSubscriber)
{
	assert(std::find(m_listeners[anEventType].begin(), m_listeners[anEventType].end(), aSubscriber) == m_listeners[anEventType].end());
	m_listeners[anEventType].push_back(aSubscriber);
}

void Dispatcher::Unsubscribe(const eEventType anEventType, EventListener* aSubscriber)
{
	auto it = std::find(m_listeners[anEventType].begin(), m_listeners[anEventType].end(), aSubscriber);
	assert(it != m_listeners[anEventType].end());

	m_listeners[anEventType].erase(it);
}

void Dispatcher::SendEvent(const Event& anEvent)
{
	for (auto listener : m_listeners[anEvent.GetEventType()])
	{
		// if event isn't handled...
		listener->Receive(anEvent);
	}
}