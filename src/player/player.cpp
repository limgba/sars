#include "player.h"

Player::Player() : game_status(0), money(0), choose(0)
{}


void Player::Update()
{
	if (game_status == GAME_STATUS_START)
	{
		std::cout << "按f开始游戏" << std::endl;
	}
	else if (game_status == GAME_STATUS_GAMING)
	{
		clock_t c2 = clock();
		clock_t interval;
		clock_t interval_limit = 1 * CLOCKS_PER_SEC;
		while (true)
		{
			interval = clock() - c2;
			if (interval < interval_limit)
			{
				continue;
			}
			time_t t = time(NULL);
			this->Update(t, interval);
			c2 = clock();
		}
	}
	else
	{
		std::cout << "按f键重新开始" << std::endl;
	}
}

void Player::Update(time_t now_sec, clock_t interval)
{
	if (this->CheckWin())
	{
		game_status = GAME_STATUS_WIN;
		std::cout << "恭喜你获得了胜利" << std::endl;
	}
	else if (this->CheckLose())
	{
		game_status = GAME_STATUS_LOSE;
		std::cout << "很遗憾， 游戏失败" << std::endl;
	}
	else
	{
		//question.Update(now_sec, interval);
		hospital.Update(now_sec, interval);
		human.Update(now_sec, interval);
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
