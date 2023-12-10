#include "Timer.h"


namespace CommonUtilities
{
	Timer::Timer()
		: myPreviousTimePoint{ std::chrono::high_resolution_clock::now() }, myDeltaTime { 0 }, myTotalTime{ 0 }
	{
	}

	void Timer::Update()
	{
		auto current = std::chrono::high_resolution_clock::now();
		auto elapsed = current - myPreviousTimePoint;

		myDeltaTime = elapsed;
		myTotalTime += elapsed;
		myPreviousTimePoint = current;

	
		// Calculate average fps
		++m_totalFrames;
		if ((m_elapsedTime += GetDeltaTime()) >= 1.f)
		{
			m_averageFPS = m_totalFrames / m_elapsedTime;
			m_totalFrames = 0;
			m_elapsedTime = 0.f;
		}
	}

	float Timer::GetDeltaTime() const
	{
		return myDeltaTime.count();
	}

	double Timer::GetTotalTime() const
	{
		return myTotalTime.count();
	}

	float Timer::GetAverageFPS() const
	{
		return m_averageFPS;
	}
}