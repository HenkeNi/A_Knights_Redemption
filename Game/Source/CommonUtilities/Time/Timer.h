#pragma once
#include <chrono>

namespace CommonUtilities
{
	class Timer
	{
	public:
		Timer();

		Timer(const Timer&)				= delete;
		Timer& operator=(const Timer&)	= delete;

		void	Update();

		float	GetDeltaTime() const;
		double	GetTotalTime() const;
		float		GetAverageFPS()					const;

	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> myPreviousTimePoint;
		std::chrono::duration<double>						   myDeltaTime, myTotalTime;


		float	m_averageFPS = 0.f;
		int		m_totalFrames = 0;
		float	m_elapsedTime = 0.f; // rename TotalTim
	};
}