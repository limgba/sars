#ifndef HOSPITAL_H
#define HOSPITAL_H
#include "drug.h"
#include <random>


class Hospital
{
public:
	Hospital() : money(0) {}
	void Build(int money) { this->money += money; }
	void UseDrug();
	bool DevDrug();

private:
	Human human;
	Drug drug;
	int money;
};


#endif
