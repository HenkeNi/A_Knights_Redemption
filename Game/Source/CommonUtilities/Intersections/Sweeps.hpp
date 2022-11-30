#pragma once
#include "Math/Vectors/Vector.hpp"

// #include "CollisionObject.h"

// Renamen folder CollisionTests?

namespace CommonUtilities
{
	template <typename T>
	struct Hit
	{
		CollisionObject*	myCollider;
		Vector2<T>			myPosition, myDelta, myNormal;
		T					myTime;
	};

	template <typename T>
	class Sweep
	{
		Hit<T>	myHit;
		Vector2 myPosition;
		T		myTime;
	};


#pragma region SWEEP_TESTS
#pragma endregion SWEEP_TESTS
}