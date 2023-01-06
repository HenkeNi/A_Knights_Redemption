#pragma once
#include "Scene.h"

class LoadingScene : public Scene
{
public:
	LoadingScene(SharedContext aSharedContext);
	~LoadingScene();

	void	ProcessEvents()					override;
	void	Update(float aDeltaTime)		override;
	void	LateUpdate(float aDeltaTime)	override;
	void	Draw()					  const override;

	void	OnEnter()						override;
	void	OnExit()						override;

private:
	bool	IsDoneLoading()					   const;
	void	UpdateElapsedTime(float aDeltaTime);

	float	m_sceneDuration, m_elapsedTime;
	bool	m_isDoneLoading;

};