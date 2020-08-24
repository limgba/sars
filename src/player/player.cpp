#include "player.h"
#include <iostream>
#include "../other/event/event.h"
#include "../other/event/eventdef.h"

Player::Player() : game_status(0), money(0), choose(0)
{
	{
		std::function<void(const gamestatus_change&)> f = [](const auto& e)
		{
			if (e.old_status == e.cur_status)
			{
				return;
			}
			switch (e.cur_status)
			{
			case 0:
			{
				std::cout << "start game" << std::endl;
			}
			break;
			case 1:
			{
				std::cout << "question anwser" << std::endl;

			}
			break;
			case 2:
			{
				std::cout << "you win" << std::endl;
			}
			break;
			case 3:
			{
				std::cout << "you lose" << std::endl;
			}
			break;
			}
		};
		event_bus.listen(f);
	}
}


void Player::Update()
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

void Player::Update(time_t now_sec, clock_t interval)
{
	if (this->CheckWin())
	{
		game_status = GAME_STATUS_WIN;
	}
	else if (this->CheckLose())
	{
		game_status = GAME_STATUS_LOSE;
	}
	else
	{
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
