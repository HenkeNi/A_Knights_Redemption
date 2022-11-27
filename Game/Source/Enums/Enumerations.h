#pragma once


enum class eEventType
{
	WindowClose, WindowResize, WindowLostFocus, WindowGainedFocus,
	KeyPressed, KeyReleased,
	MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
};