#pragma once


enum class eEventType
{
	WindowResize, WindowLostFocus, WindowGainedFocus,
	Attack,
	Jump,
	OpenInventory,
	MoveUp,
	MoveDown,
	MoveLeft,
	MoveRight,
	Pause,
	Accept,
	Reject,

	/*KeyPressed, KeyReleased,
	MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled*/
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

enum class eInput
{
	Key_Space,
	Key_Escape,
	Key_P,
	Key_Enter,
	Key_W,
	Key_A,
	Key_S,
	Key_D,
	ArrowKeyUp,
	ArrowKeyDown,
	ArrowKeyRight,
	ArrowKeyLeft,
	LeftMouseButton,
	RightMouseButton,
	MouseMoved,
	Count
};

enum class eSceneType
{
	Title, Loading, Menu, Settings, Game, Pause, GameOver, Count
};