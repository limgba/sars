#ifndef HUMAN_H
#define HUMAN_H
#include "sars.h"

class Human
{
public:
	Human() : total_num(0), infection_num(0), satisfaction(0) {}
	void Infection(int num);
	void Die(int num);
	void Treat(int num);
	int GetTotalNum();
	int GetInfectionNum();
	int GetHealthyNum();
	int GetSatisfaction();
	
public:
	Sars sars;
private:
	int total_num;
	int infection_num;
	int satisfaction;	// 满意度
	
};
#endif
