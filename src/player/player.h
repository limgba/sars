#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "../hospital/hospital.h"
#include "../human/human.h"
#include "../client/client.h"
#include "question/question.h"


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
	void OnConfirm(int qa_index);
	
private:
	bool CheckWin();
	bool CheckLose();
public:
	Human human;
	Hospital hospital;
	Question question;
	EventBus event_bus;

private:
	int m_money;
	bool m_started;
};


#endif
