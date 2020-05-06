#ifndef DRUG_H
#define DRUG_H

#include "human.h"

class Drug
{
public:
	Drug() : treat(0), num(0) {}
	bool Treat(Human &human);
	bool AddTreatValue(int value);
	int GetTreatValue();
	int GetNum();
	bool DecNum(int num);
	bool AddNum(int num);

private:
	int treat;
	int num;
};
#endif
