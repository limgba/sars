#ifndef DRUG_H
#define DRUG_H
#include <time.h>


class Drug
{
public:
	Drug() : treat(0), num(0) {}
	void Update(time_t now_sec, clock_t interval);
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
