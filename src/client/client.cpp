#include "client.h"
#include "../other/event/event.h"
#include "../player/player.h"

int choose = 0;
int game_status = 0;
int GetChoose() { return choose; }
int GetGameStatus() { return game_status; }
void SetChoose(Player* player, int _choose)
{
	if (nullptr == player)
	{
		return;
	}
	const size_t MAX_SIZE = player->question.GetChooseSize();
	if (MAX_SIZE == 0)
	{
		return;
	}
	if (_choose < 0)
	{
		_choose = 0;
	}
	else if ((size_t)_choose >= MAX_SIZE)
	{
		_choose = MAX_SIZE - 1;
	}
	choose = _choose;
	question_choose qc;
	qc.qa_choose = choose;
	player->event_bus.notify(qc);
}

void SetGameStatus(Player* player, int status)
{
	if (nullptr == player)
	{
		return;
	}
	gamestatus_change gc;
	gc.old_status = game_status;
	game_status = status;
	gc.cur_status = game_status;
	player->event_bus.notify<gamestatus_change>(gc);
}

int mygetch()
{
#ifdef _WIN32
	return _getch();
#else
	struct termios oldt,
	newt;
	int ch;
	tcgetattr( STDIN_FILENO, &oldt );
	newt = oldt;
	newt.c_lflag &= ~( ICANON | ECHO );
	tcsetattr( STDIN_FILENO, TCSANOW, &newt );
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
	return ch;
#endif
}


void* p_input(void* arg)
{
	Player* player = (Player*)arg;
	if (nullptr == player)
	{
		return nullptr;
	}
	clock_t c2 = clock();
	while (true)
	{
		char ch = mygetch();
		if (clock() - c2 < static_cast<clock_t>(0.01 * CLOCKS_PER_SEC))
			continue;
		switch (ch)
		{
		case 'w':
		{
			SetChoose(player, choose - 1);
		}
		break;
		case 'a':
		{
			SetChoose(player, choose - 2);
		}
		break;
		case 's':
		{
			SetChoose(player, choose + 1);
		}
		break;
		case 'd':
		{
			SetChoose(player, choose + 2);
		}
		break;
		case 'f':
		{
			if (game_status == 0)
			{
				SetGameStatus(player, GAME_STATUS_GAMING);
			}
			else if (game_status == 1)
			{
				player->question.confirm(choose);
			}
		}
		break;
		}
		c2 = clock();
	}
	return NULL;
}
