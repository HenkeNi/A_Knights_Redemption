#pragma once
#include "Scene.hpp"

class LoadingScene : public Scene
{
public:
	LoadingScene(SharedContext aSharedContext);
	~LoadingScene();

	void	Init()							override;
	void	Receive(Event& anEvent)	override;
	void	Update(float aDeltaTime)		override;
	void	LateUpdate(float aDeltaTime)	override;
	void	Draw()					  const override;

	void	OnEnter()						override;
	void	OnExit()						override;

private:
	bool	IsDoneLoading()					   const;
	void	LoadResources();

	float	m_sceneDuration, m_elapsedTime;
	bool	m_isDoneLoading;

};