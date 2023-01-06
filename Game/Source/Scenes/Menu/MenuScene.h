#pragma once
#include "Scene.h"

class MenuScene : public Scene
{
public:
	MenuScene(SharedContext aSharedContext);
	~MenuScene();

	void ProcessEvents()				  override;
	void Update(float aDeltaTime)		  override;
	void LateUpdate(float aDeltaTime)	  override;
	void Draw()						const override;

	void OnEnter()						  override;
	void OnExit()						  override;
};