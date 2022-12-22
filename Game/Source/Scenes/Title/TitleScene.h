#pragma once
#include "Scene.hpp"

class TitleScene : public Scene
{
public:
	TitleScene(SharedContext aSharedContext);
	~TitleScene();

	void  Init()						 override;
	void  Receive(Event& anEvent)	 override;
	void  Update(float aDeltaTime)		 override;
	void  LateUpdate(float aDeltaTime)	 override;
	void  Draw()				   const override;

	void  OnEnter()						 override;
	void  OnExit()						 override;

private:
	bool  IsTimeUp()						const;
	void  UpdateDuration(float aDeltaTime);

	float m_sceneDuration;
	bool  m_shouldSkip;
};