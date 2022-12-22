#pragma once
#include "Scene.hpp"

// TODO: remove delay?? use message handled instead?? (dont pass it any further)

class PauseScene : public Scene
{
public:
	PauseScene(SharedContext aSharedContext);

	void	Init()							  override;
	void	Receive(Event& anEvent)	  override;
	void	Update(float aDeltaTime)		  override;
	void	LateUpdate(float aDeltaTime)	  override;
	void	Draw()						const override;

	void	OnEnter()						  override;

private:
	bool	IsResumeEnabled()					 const;
	void	ResumeGame()						 const;

	float	m_unpauseDelay, m_elapsedTime;
	bool	m_shouldResume;
};