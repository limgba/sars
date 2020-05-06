#ifndef SARS_H
#define SARS_H
#include <time.h>

class Drug;

class Sars
{
public:
	Sars() : contagion(0), toxicity(0), fertility(0), drug_resistance(0), num(0), last_contagion(0), last_fertility(0) {}
	void Update(time_t now_sec, clock_t interval);
	int Contagion();
	int Fertility();
	int GetToxicity();
	int GetDrugResistance();
	int GetNum();
	void BeKill(Drug &drug);
	
private:
	//Human *human;
	int contagion;			// 传染性
	int toxicity;			// 毒性
	int fertility;			// 繁殖力
	int drug_resistance;		// 耐药性
	int num;			// 数量
	time_t last_contagion;
	time_t last_fertility;
};

#endif
