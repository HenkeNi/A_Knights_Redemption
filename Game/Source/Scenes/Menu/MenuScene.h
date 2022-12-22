#pragma once
#include "Scene.hpp"

class MenuScene : public Scene
{
public:
	MenuScene(SharedContext aSharedContext);
	~MenuScene();

	void	Init()							  override;
	void	Receive(Event& anEvent)	  override;
	void	Update(float aDeltaTime)		  override;
	void	LateUpdate(float aDeltaTime)	  override;
	void	Draw()						const override;

	void	OnEnter()						  override;
};