#include "player.h"

void Player::Update()
{
	clock_t c2 = clock();
	clock_t interval;
	clock_t interval_limit = 1 * CLOCKS_PER_SEC;
	while (true)
	{
		if (is_end)
		{
			break;
		}
		interval = clock() - c2;
		if (interval < interval_limit)
			continue;
		time_t t = time(NULL);
		this->Update(t, interval);
		c2 = clock();
	}
	std::cout << "重新开始" << std::endl;
}

void Player::Update(time_t now_sec, clock_t interval)
{
	hospital.Update(now_sec, interval);
	human.Update(now_sec, interval);
	if (this->CheckWin())
	{
		is_end = true;
		std::cout << "恭喜你获得了胜利" << std::endl;
	}
	if (this->CheckLose())
	{
		is_end = true;
		std::cout << "很遗憾， 游戏失败" << std::endl;
	}
}

bool Player::CheckWin()
{
	return human.sars.GetNum() < 1;
}


bool Player::CheckLose()
{
	return human.GetTotalNum() == human.GetInfectionNum();
}
