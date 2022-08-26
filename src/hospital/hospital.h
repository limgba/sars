#ifndef HOSPITAL_H
#define HOSPITAL_H
#include <time.h>


class Hospital
{
public:
	Hospital() : money(0) {}
	void Update(time_t now_sec, clock_t interval);
	void Build(int money) { this->money += money; }
	void UseDrug();
	bool DevDrug();

private:
	int money;
};


#endif
