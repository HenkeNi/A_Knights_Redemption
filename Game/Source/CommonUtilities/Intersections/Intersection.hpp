#pragma once
#include "../Volumes/Volumes.hpp"
#include "../Math/Vectors/Vector.hpp"
#include "../Utility/UtilityFunctions.hpp"
#include <algorithm>

// Intersection Tests are a static vs static test. They check whether two static objects are overlapping. They have a boolean result (colliding or not), with a vector which

namespace CommonUtilities
{
#pragma region INTERSECTIONS_2D

	/***************************************************************************************************/
	/*										2D - Intersections   									   */
	/***************************************************************************************************/

	/* - AABB2D vs AABB2D - */
	template <typename T>
	bool Intersection_AABB2D_Vs_AABB2D(const AABB2D<T>& anAABB1, const AABB2D<T>& anAABB2)
	{
		if (anAABB1.GetMaxPoint().x < anAABB2.GetMinPoint().x) { return false; }
		if (anAABB1.GetMaxPoint().y < anAABB2.GetMinPoint().y) { return false; }

		if (anAABB1.GetMinPoint().x > anAABB2.GetMaxPoint().x) { return false; }
		if (anAABB1.GetMinPoint().y > anAABB2.GetMaxPoint().y) { return false; }

		return true;
	}

	/* - AABB2D vs Circle - */
	template <typename T>
	bool Intersection_AABB2D_Vs_Circle(const AABB2D<T>& anAABB, const Circle<T>& aCircle)
	{
		float deltaX = aCircle.GetCenterPosition().x - std::max(anAABB.GetMinPoint().x, std::min(aCircle.GetCenterPosition().x, anAABB.GetMaxPoint().x));
		float deltaY = aCircle.GetCenterPosition().y - std::max(anAABB.GetMinPoint().y, std::min(aCircle.GetCenterPosition().y, anAABB.GetMaxPoint().y));

		return ((deltaX * deltaX) + (deltaY * deltaY)) < (aCircle.GetRadius() * aCircle.GetRadius());
	}

	/* - AABB2D vs Point - */
	template <typename T>
	bool Intersection_AABB2D_Vs_Point(const AABB2D<T>& anAABB, const Vector2<T>& aPoint)
	{
		return anAABB.IsInside(aPoint);
	}

	/* - Circle vs Circle - */
	template <typename T>
	bool Intersection_Circle_Vs_Circle(const Circle<T>& aCircle1, const Circle<T>& aCircle2)
	{
		Vector2<T> distance = (aCircle2.GetCenterPosition() - aCircle1.GetCenterPosition());
		float length = distance.LengthSqr();

		return length <= (aCircle1.GetRadius() + aCircle2.GetRadius()) * (aCircle1.GetRadius() + aCircle2.GetRadius());
	}




	/* - AABB2D vs Ray -  */
	template <typename T>
	bool Intersection_AABB2D_Vs_Ray(const AABB2D<T>& anAABB, const Ray<T>& aRay)
	{
		CU::Vector2<T> tNear = { (anAABB.GetCenter().x - aRay.GetOrigin().x) / aRay.GetDirection().x,
								 (anAABB.GetCenter().y - aRay.GetOrigin().y) / aRay.GetDirection().y };

		CU::Vector2<T> tFar = { (anAABB.GetCenter().x + anAABB.GetWidth() - aRay.GetOrigin().x) / aRay.GetDirection().x,
								(anAABB.GetCenter().y + anAABB.GetHeight() - aRay.GetOrigin().y) / aRay.GetDirection().y };


		if (tNear.x > tFar.x) { std::swap(tNear.x, tFar.x); }
		if (tNear.y > tFar.y) { std::swap(tNear.y, tFar.y); }


		if (tNear.x > tFar.y || tNear.y > tFar.x)
			return false;

		return true;
	}

	/* TEST.. */
	//template <typename T>
	struct Hit
	{
		Vector3<float>	m_contactPoint;
		Vector3<float>	m_contactNormal;
		float			m_tHitNear = 0.f;
		bool			m_isColliding;
	};

	template <typename T>
	Hit/*<T>*/ Intersection_AABB2D_Vs_Ray_Hit(const AABB2D<T>& anAABB, const Ray<T>& aRay)
	{
		CU::Vector2<T> tNear = { (anAABB.GetMinPoint().x - aRay.GetOrigin().x) / aRay.GetDirection().x,
								 (anAABB.GetMinPoint().y - aRay.GetOrigin().y) / aRay.GetDirection().y };

		CU::Vector2<T> tFar = { (anAABB.GetMinPoint().x + anAABB.GetWidth() - aRay.GetOrigin().x) / aRay.GetDirection().x,
								(anAABB.GetMinPoint().y + anAABB.GetHeight() - aRay.GetOrigin().y) / aRay.GetDirection().y };


		if (tNear.x > tFar.x) { std::swap(tNear.x, tFar.x); }
		if (tNear.y > tFar.y) { std::swap(tNear.y, tFar.y); }


		Hit hit;

		if (tNear.x > tFar.y || tNear.y > tFar.x)
		{
			hit.m_contactPoint = { 0.f, 0.f, 0.f };
			hit.m_contactNormal = { 0.f, 0.f, 0.f };
			hit.m_tHitNear = 0.f;
			hit.m_isColliding = false;
		
			return hit;
			//return {};
		}


		T tHitNear	= std::max(tNear.x, tNear.y);
		T tHitFar	= std::max(tFar.x, tFar.y);

		if (tHitFar < 0)
		{
			hit.m_contactPoint = { 0.f, 0.f, 0.f };
			hit.m_contactNormal = { 0.f, 0.f, 0.f };
			hit.m_tHitNear = 0.f;
			hit.m_isColliding = false;

			return hit;
			//return {};
		}


		/*hit.m_contactPoint = { aRay.GetOrigin().x + tHitNear + aRay.GetDirection().x, 
								aRay.GetOrigin().y + tHitNear + aRay.GetDirection().y };*/

		hit.m_contactPoint = aRay.GetOrigin() + tHitNear * aRay.GetDirection();

		if (tNear.x > tNear.y)
		{
			if (aRay.GetDirection().x < 0)
				hit.m_contactNormal = CU::Vector3<float>{ 1, 0, 0 };
			else
				hit.m_contactNormal = CU::Vector3<float>{ -1, 0, 0 };
		}
		else if (tNear.x < tNear.y)
		{
			if (aRay.GetDirection().y < 0)
				hit.m_contactNormal = CU::Vector3<float>{ 0, 1, 0 };
			else
				hit.m_contactNormal = CU::Vector3<float>{ 0, -1, 0 };
		}

		hit.m_tHitNear = tHitNear;
		hit.m_isColliding = true;

		return hit;
	}



	template <typename T> 
	Hit Dynamic_Rect_Vs_Rect(const AABB2D<T>&anAABB1, const AABB2D<T>& anAABB2)
	{

	}




	/* - AABB2D vs Line Segment - */
	template <typename T>
	bool Intersection_AABB2D_Vs_LineSegment(const AABB2D<T>& anAABB, const LineSegment<T>& aLineSegment)
	{
		Vector2<T> normalized = Vector2<T>{ aLineSegment.myEndPoint - aLineSegment.myStartPoint }.GetNormalized();
		normalized.x = (normalized.x != 0) ? 1.f / normalized.x : 0; // NEEDED??
		normalized.y = (normalized.y != 0) ? 1.f / normalized.y : 0;

		//Vector2<T> min = 



		return false;
	}
	





	/* - AABB2D vs Line - */
	template <typename T>
	bool Intersection_AABB2D_Vs_Line(const AABB2D<T>& anAABB, const Line<T>& aLine) // TODO!
	{
		return false;
	}

	/* - Circle vs Line - */
	template <typename T>
	bool Intersection_Circle_Vs_Line(const Circle<T>& aCircle, const Line<T>& aLine) // TODO!
	{
		return false;
	}



	








	/* --------------------- AABB2D vs AABB2 Sweap --------------------- */
	template <typename T>
	bool Intersection_AABB2D_Vs_AABB2D_Sweap(const AABB2D<T>& anAABB1, const AABB2D<T>& anAABB2, const Vector2<float>& aVelocity)
	{
		return false;
	}

	/* --------------------- AABB2D vs AABB2 Sweap --------------------- */
	template <typename T>
	bool Intersection_AABB2D_Vs_AABB2D_SAT(const AABB2D<T>& anAABB1, const AABB2D<T>& anAABB2)
	{
		return false;
	}






	/* --------------------- Line vs Line --------------------- */
	template <typename T>
	bool Intersection_Line_Vs_Line(const Line<T>& aLine1, const Line<T>& aLine2)
	{
		// Since lines are endless, there are only two situations where lines don't collide. When they are parallel and not equivalent

		return false;
	}







	template <typename T>
	bool Intersection_Circle_Vs_LineSegment(const Circle<T>& aCircle, const LineSegment<T>& aLineSegment)
	{
		//Vector2<T> ab = aLineSegment.myEndPoint - aLineSegment.myStartPoint;
		//T t = { aCircle.myCenterPosition - aLineSegment.myStartPoint }.Dot(ab) - ab.Dot(ab);
		


		return false; 
	}






	// TODO: RAY? z == 0.f..

#pragma endregion INTERSECTIONS_2D


#pragma region INTERSECTIONS_3D

	/***************************************************************************************************/
	/*										3D - Intersections   									   */
	/***************************************************************************************************/

	/* ----------------------------- AABB3D vs AABB3D ---------------------------- */
	template <typename T>
	bool Intersection_AABB3D_Vs_AABB3D(const AABB3D<T>& aAABB3D1, const AABB3D<T>& aAABB3D2)
	{
		if (aAABB3D1.myMaxPoint.x < aAABB3D2.myMinPoint.x) { return false; }
		if (aAABB3D1.myMaxPoint.y < aAABB3D2.myMinPoint.y) { return false; }
		if (aAABB3D1.myMaxPoint.z < aAABB3D2.myMinPoint.z) { return false; }

		if (aAABB3D1.myMinPoint.x > aAABB3D2.myMaxPoint.x) { return false; }
		if (aAABB3D1.myMinPoint.y > aAABB3D2.myMaxPoint.y) { return false; }
		if (aAABB3D1.myMinPoint.z > aAABB3D2.myMaxPoint.z) { return false; }

		return true;
	}

	/* ----------------------------- Ray vs AABB3D ------------------------------- */
	template <typename T>
	bool Intersection_Ray_Vs_AABB3D(const Ray<T>& aRay, const AABB3D<T>& aAABB)
	{
		T tMin = (aAABB.GetMinPoint().x - aRay.GetOrigin().x) / aRay.GetDirection().x;
		T tMax = (aAABB.GetMaxPoint().x - aRay.GetOrigin().x) / aRay.GetDirection().x;

		if (tMin > tMax)
		{
			std::swap(tMin, tMax);
		}

		T tyMin = (aAABB.GetMinPoint().y - aRay.GetOrigin().y) / aRay.GetDirection().y;
		T tyMax = (aAABB.GetMaxPoint().y - aRay.GetOrigin().y) / aRay.GetDirection().y;

		if (tyMin > tyMax)
		{
			std::swap(tyMin, tyMax);
		}

		if (tyMin > tMin)
		{
			tMin = tyMin;
		}

		if (tyMax < tMax)
		{
			tMax = tyMax;
		}

		T tzMin = (aAABB.GetMinPoint().z - aRay.GetOrigin().z) / aRay.GetDirection().z;
		T tzMax = (aAABB.GetMaxPoint().z - aRay.GetOrigin().z) / aRay.GetDirection().z;

		if (tzMin > tyMax)
		{
			std::swap(tzMin, tzMax);
		}

		if ((tMin >= tzMax) || (tzMin >= tMax))
		{
			return false;
		}

		if (tzMax > tMin)
		{
			tMin = tzMin;
		}

		if (tzMax < tMax)
		{
			tMax = tzMax;
		}

		return true;
	}

	/* ----------------------------- Ray vs Sphere ------------------------------- */
	template <typename T>
	bool Intersection_Ray_Vs_Sphere(const Ray<T>& aRay, const Sphere<T>& aSphere)
	{
		Vector3<T> myClosestPoint = aRay.GetOrigin() + aRay.GetDirection() * ((aSphere.GetCenterPosition() - aRay.GetOrigin()).Dot(aRay.GetDirection()));
		return (myClosestPoint - aSphere.GetCenterPosition()).LengthSqr() <= aSphere.GetRadius() * aSphere.GetRadius();
	}

	/* ----------------------------- Ray vs Plane -------------------------------- */
	template <typename T>
	bool Intersection_Ray_Vs_Plane(const Ray<T>& aRay, const Plane<T>& aPlane, Vector3<T>& aOutIntersectionPoint)
	{
		T denom = aPlane.GetNormal().Dot(aRay.GetDirection().GetNormalized());
		if (std::abs(denom) > 0)
		{
			Vector3<T> point = aPlane.GetPoint() - aRay.GetOrigin();
			if (point.Dot(aPlane.GetNormal()) >= 0)
			{
				aOutIntersectionPoint = point;
				return true;
			}
		}
		return false;
	}

	/* ----------------------------- Ray vs Ray ---------------------------------- */
	template <typename T>
	bool Intersection_Ray_Vs_Ray(const Ray<T>& aRay1, const Ray<T>& aRay2)
	{
		return false;
	}

	/* ----------------------------- Sphere vs AABB3D ---------------------------- */
	template <typename T>
	bool Intersection_Sphere_Vs_AABB3D(const Sphere<T>& aSphere, const AABB3D<T>& aAABB3D)
	{
		return false;
	}

	/* ----------------------------- Sphere vs Sphere ---------------------------- */
	template <typename T>
	bool Intersection_Sphere_Vs_Sphere(const Sphere<T>& aSphere1, const Sphere<T>& aSphere2)
	{
		Vector3<T> distance = aSphere2.GetCenterPosition() - aSphere1.GetCenterPosition();
		return distance.LengthSqr() <= (aSphere1.GetRadius() + aSphere2.GetRadius());
	}

	/* ----------------------------- Point vs Sphere ----------------------------- */
	template <typename T>
	bool Intersection_Point_Vs_Sphere(const Vector3<T>& aPoint, const Sphere<T>& aSphere)
	{
		return aSphere.IsInside(aPoint);
	}

	/* ----------------------------- Point vs AABB ------------------------------- */
	template <typename T>
	bool Intersection_Point_Vs_AABB(const Vector3<T>& aPoint, const AABB3D<T>& aAABB3D)
	{
		return aAABB3D.IsInside(aPoint);
	}

	/* ----------------------------- Plane vs Sphere ----------------------------- */
	template <typename T>
	bool Intersection_Plane_Vs_Sphere(const Plane<T>& aPlane, const Sphere<T>& aSphere)
	{
		return false;

	}

#pragma endregion INTERSECTIONS_3D
}


/*
* template<typename T>
bool CommonUtilities::IntersectionPlaneRay(const Plane<T>&aPlane, const Ray<T>&aRay, Vector3<T>&aOutIntersectionPoint)
{
	Plane<T> plane = aPlane;
	Ray<T> ray = aRay;

	T denom = plane.GetNormal().Dot(ray.GetDirection());
	Vector3<T> distance = plane.GetPosition() - ray.GetOrigin();
	T pointLength;

	if (denom == 0) 
	{ 
		return (distance.Dot(plane.GetNormal()) == 0); 
	}
	else if (std::abs(denom) > std::numeric_limits<T>::epsilon())
	{
		pointLength = distance.Dot(plane.GetNormal()) / denom;

		aOutIntersectionPoint = ray.GetOrigin() + ray.GetDirection().GetNormalized() * pointLength;

		return (pointLength >= 0);
	}

	return false;
}
*/


/*
* template<typename T>
bool CommonUtilities::IntersectionAABBRay(const AABB3D<T>& aAABB, const Ray<T>& aRay)
{
	AABB3D<T> aabb = aAABB;
	Ray<T> ray = aRay;
	T pointLength = ray.GetDirection().Dot(aabb.GetPosition() - ray.GetOrigin());

	Vector3<T> point = ray.GetOrigin() + ray.GetDirection().GetNormalized() * pointLength;

	return aabb.IsInside(point);
}
*/


/*
* template<typename T>
bool CommonUtilities::IntersectionSphereRay(const Sphere<T>& aSphere, const Ray<T>& aRay)
{
	Sphere<T> sphere = aSphere;
	Ray<T> ray = aRay;
	T pointLength = ray.GetDirection().GetNormalized().Dot(sphere.GetPosition() - ray.GetOrigin());

	Vector3<T> point = ray.GetOrigin() + ray.GetDirection().GetNormalized() * pointLength;

	return sphere.IsInside(point);
}
*/








/* OTHER */

/*
template<typename T>
	bool IntersectionPlaneRay(const Plane<T>& aPlane, const Ray<T>& aRay, Vector3<T>& aOutIntersectionPoint)
	{
		const T denominator = aPlane.GetNormal().Dot(aRay.GetDirection());
		if (denominator < 0.0000001 && denominator > -0.0000001)
		{
			return false;
		}
		T t = Vector3<T>{ aRay.GetOrigin() - aPlane.GetPoint() }.Dot(aPlane.GetNormal());
		aOutIntersectionPoint = t < 0 ? aRay.GetOrigin() : aRay.GetOrigin() + (aRay.GetDirection() * t);
		return true;
	}

	template <typename T>
	bool IntersectionAABBRay(const AABB3D<T>& aAABB, const Ray<T>& aRay)
	{
		Plane<T> plane;
		Vector3<T> intersectionPoint;
		// front
		plane.InitWithPointAndNormal(aAABB.myMin, { 0, 0, T(-1) });
		if (IntersectionPlaneRay(plane, aRay, intersectionPoint))
		{
			if (aAABB.IsInside(intersectionPoint))
			{
				return true;
			}
		}
		// back
		plane.InitWithPointAndNormal(aAABB.myMax, { 0, 0, T(1) });
		if (IntersectionPlaneRay(plane, aRay, intersectionPoint))
		{
			if (aAABB.IsInside(intersectionPoint))
			{
				return true;
			}
		}
		// left
		plane.InitWithPointAndNormal(aAABB.myMin, { T(-1), 0, 0 });
		if (IntersectionPlaneRay(plane, aRay, intersectionPoint))
		{
			if (aAABB.IsInside(intersectionPoint))
			{
				return true;
			}
		}
		// right
		plane.InitWithPointAndNormal(aAABB.myMax, { T(1), 0, 0 });
		if (IntersectionPlaneRay(plane, aRay, intersectionPoint))
		{
			if (aAABB.IsInside(intersectionPoint))
			{
				return true;
			}
		}
		// top
		plane.InitWithPointAndNormal(aAABB.myMax, { 0, T(1), 0 });
		if (IntersectionPlaneRay(plane, aRay, intersectionPoint))
		{
			if (aAABB.IsInside(intersectionPoint))
			{
				return true;
			}
		}
		// bottom
		plane.InitWithPointAndNormal(aAABB.myMin, { 0, T(-1), 0 });
		if (IntersectionPlaneRay(plane, aRay, intersectionPoint))
		{
			if (aAABB.IsInside(intersectionPoint))
			{
				return true;
			}
		}
		return false;
	}

	template <typename T>
	bool IntersectionSphereRay(const Sphere<T>& aSphere, const Ray<T>& aRay)
	{
		Vector3<T> fromRayToSphere = { aSphere.GetCenter() - aRay.GetOrigin() };
		T projectOntoRayDir = fromRayToSphere.Dot(aRay.GetDirection());

		const T radiusSqrd = aSphere.GetRadius() * aSphere.GetRadius();
		const T aSqrd = projectOntoRayDir * projectOntoRayDir;

		const T intersectionSideSqrd = radiusSqrd - fromRayToSphere.LengthSqr() + aSqrd;
		return (intersectionSideSqrd >= 0);
	}
*/