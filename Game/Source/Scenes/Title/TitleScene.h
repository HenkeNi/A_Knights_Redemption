#pragma once
#include "Scene.h"

class TitleScene : public Scene
{
public:
	TitleScene(SharedContext aSharedContext);
	~TitleScene();

	void  ProcessEvents()				override;
	void  Update(float aDeltaTime)		override;
	void  LateUpdate(float aDeltaTime)	override;
	void  Draw()				  const override;

	void  OnEnter()						override;
	void  OnExit()						override;

private:
	bool  IsTimeUp()					   const;
	void  UpdateDuration(float aDeltaTime);

	float m_sceneDuration;
	bool  m_shouldSkip;
};