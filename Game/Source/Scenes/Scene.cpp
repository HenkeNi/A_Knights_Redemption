#include "Pch.h"
#include "Scene.h"


Scene::Scene(SharedContext aSharedContext) 
	: m_sharedContext{ aSharedContext }
{
	m_sceneObjects.reserve(16);
}

bool Scene::IsOverlay() const 
{ 
	return false; 
}