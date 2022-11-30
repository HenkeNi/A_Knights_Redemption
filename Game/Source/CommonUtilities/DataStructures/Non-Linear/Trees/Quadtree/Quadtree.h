//#pragma once
//#include "Vector.hpp"
//#include "2D/AABB2D.hpp"
//#include "C_Collider.h"
//
//namespace CommonUtilities
//{
//	// TODO: Use QuadtreeNode??
//
//	class Quadtree
//	{
//	public:
//		Quadtree();
//		//Quadtree(int aMaxObjects, );
//		
//
//		void Insert(C_Collider* aObject);
//		void Remove(C_Collider* aObject);
//		void Clear();
//
//
//
//
//
//	private:
//		void			Split();
//		void			Search();
//		int				GetIndex() const; 
//		AABB2D<float>	GetBounds() const;
//
//
//		Quadtree*						m_parent;
//		std::vector<C_Collider*>	m_objects;
//		std::array<Quadtree*, 4>		m_childNodes;
//		AABB2D<float>					m_bounds;
//		int								m_depthLevel;
//
//		//const int m_maxLevels;
//		//const int m_maxObjects;
//
//		
//
//		//std::vector<Objects> m_objects;
//		//Rectangle m_bounds;
//		//Quadtree[] m_nodes;
//
//	};
//}
//
