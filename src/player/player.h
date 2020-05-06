#ifndef PLAYER_H
#define PLAYER_H
#include <time.h>
#include <iostream>
//#include "hospital.h"

class Player
{
public:
	Player() : money(0) {}
	void Update(time_t now_sec, clock_t interval);
	//void Update(int now_sec, int interval);
	//bool BuildHospital();
	//bool DevDrug();
	//bool UseDrug();
	//bool KillHuman();
	//void ShowInFectionNum();
	//void ShowScore();
	//bool IsEnd();
	//bool IsWin();

private:
	int money;
	//Hospital hospital;
};


#endif
