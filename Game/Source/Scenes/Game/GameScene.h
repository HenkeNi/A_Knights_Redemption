#pragma once
#include "Scene.hpp"

class GameScene : public Scene
{
public:
	GameScene(SharedContext aSharedContext);
	~GameScene();

	void				Init()								override;
	void				Receive(Event& anEvent)				override;
	void				Update(float aDeltaTime)			override;
	void				LateUpdate(float aDeltaTime)		override;
	void				Draw()						  const override;

	void				OnEnter()						    override;
	void				OnExit()					   	    override;

private:
	void				RegisterLevels();
	bool				IsPauseEnabled()					   const;
	void				PauseGame();

	//CollisionManager	m_collisionManager;
	//LevelManager		m_levelManager;
	//float				m_pauseDelay, m_elapsedTime;
	//eGameStatus			m_gameStatus;
};