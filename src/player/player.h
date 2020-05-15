#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "../hospital/hospital.h"
#include "../human/human.h"

class Player
{
public:
	Player() : money(0), is_end(false) {}
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

private:
	int money;
	bool is_end;
};


#endif
