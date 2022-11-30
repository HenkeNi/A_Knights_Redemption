#pragma once


enum class eEventType
{
	WindowClose, WindowResize, WindowLostFocus, WindowGainedFocus,
	KeyPressed, KeyReleased,
	MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
};

/* - Message for components - */
enum class eMessage // Fix ! (inheritance?) eNotification eMessageType
{
	PositionChanged,
	Colliding,

	Jump,
	Climb,
	Slide,
	MoveUp,
	MoveDown,
	MoveLeft,
	MoveRight,
	MoveUpLeft,
	MoveUpRight,
	MoveDownLeft,
	MoveDownRight,
};

enum class eSceneType
{
	Title, Loading, Menu, Settings, Game, Pause, GameOver, Count
};