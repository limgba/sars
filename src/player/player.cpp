#include "player.h"
#include <iostream>
#include "../other/event/event.h"
#include "../other/event/eventdef.h"

Player::Player() : m_money(0), m_started(0)
{
	{
		std::function<void(const gamestatus_change&)> f = [this](const auto& e)
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
				question.display(GetChoose());

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

	{
		std::function<void(const question_choose&)> f = [this](const auto& e)
		{
			question.display(e.qa_choose);
		};
		event_bus.listen(f);
	}
}


void Player::Update()
{
	clock_t c2 = clock();
	clock_t interval;
	clock_t interval_limit = 0.5 * CLOCKS_PER_SEC;
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
		SetGameStatus(this, GAME_STATUS_WIN);
		m_started = false;
	}
	else if (this->CheckLose())
	{
		SetGameStatus(this, GAME_STATUS_LOSE);
		m_started = false;
	}
	else
	{
		if (!m_started && GetGameStatus() == GAME_STATUS_START)
		{
			std::cout << "按f开始游戏" << std::endl;
			m_started = true;
		}
		hospital.Update(now_sec, interval);
		human.Update(now_sec, interval);
	}
}

bool Player::CheckWin()
{
	return false;
	return human.sars.GetNum() < 1;
}


bool Player::CheckLose()
{
	return false;
	return human.GetTotalNum() == human.GetInfectionNum();
}
