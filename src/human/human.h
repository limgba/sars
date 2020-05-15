#ifndef HUMAN_H
#define HUMAN_H
#include "../sars/sars.h"
#include "../drug/drug.h"

class Human
{
public:
	Human() : total_num(0), infection_num(0), satisfaction(0) {}
	void Update(time_t now_sec, clock_t interval);
	void Infection(int num);
	void Die(int num);
	void Treat(int num);
	int GetTotalNum();
	int GetInfectionNum();
	int GetHealthyNum();
	int GetSatisfaction();
	
public:
	Sars sars;
	Drug drug;
private:
	int total_num;			// 总数
	int infection_num;		// 感染数量
	int satisfaction;		// 满意度
};
#endif
