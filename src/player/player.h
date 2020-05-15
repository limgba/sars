#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "../hospital/hospital.h"
#include "../human/human.h"

class Player
{
public:
	Player() : money(0) {}
	void Update(time_t now_sec, clock_t interval);
	//bool BuildHospital();
	//bool DevDrug();
	//bool UseDrug();
	//bool KillHuman();
	//void ShowInFectionNum();
	//void ShowScore();
	//bool IsEnd();
	//bool IsWin();
	
public:
	Human human;
	Hospital hospital;

private:
	int money;
};


#endif
