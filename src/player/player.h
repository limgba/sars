#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "../hospital/hospital.h"
#include "../human/human.h"
#include "../client/client.h"
#include "question/question.h"

enum GAME_STATUS
{
	GAME_STATUS_START,
	GAME_STATUS_GAMING,
	GAME_STATUS_WIN,
	GAME_STATUS_LOSE,
};

class Player
{
public:
	Player();
	void Update();
	void Update(time_t now_sec, clock_t interval);
	//bool BuildHospital();
	//bool DevDrug();
	//bool UseDrug();
	//bool KillHuman();
	//void ShowInFectionNum();
	//void ShowScore();
	//bool IsEnd();
	//bool IsWin();
	
private:
	bool CheckWin();
	bool CheckLose();
public:
	Human human;
	Hospital hospital;
	Question question;

private:
	int game_status;
	int money;
	int choose;
};


#endif
