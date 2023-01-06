#pragma once
#include "Scene.h"

// TODO: remove delay?? use message handled instead?? (dont pass it any further)

class PauseScene : public Scene
{
public:
	PauseScene(SharedContext aSharedContext);
	~PauseScene();

	void	ProcessEvents()					  override;
	void	Update(float aDeltaTime)		  override;
	void	LateUpdate(float aDeltaTime)	  override;
	void	Draw()						const override;

	void	OnEnter()						  override;
	void	OnExit()						  override;

private:
	void	ResumeGame()						 const;

private:
	bool	m_shouldResume;
};