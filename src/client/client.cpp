#include "client.h"

int choose = 0;
int game_status = 0;
int GetChoose() { return choose; }
int GetGameStatus() { return game_status; }

int mygetch()
{
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

}


void* p_input(void* arg)
{
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
			choose -= 2;
		}
		break;
		case 'a':
		{
			choose -= 1;
		}
		break;
		case 's':
		{
			choose += 2;
		}
		break;
		case 'd':
		{
			choose += 1;
		}
		break;
		case 'f':
		{
			if (game_status == 0)
			{
				++game_status;
			}
		}
		break;
		}
		if (choose > 3)
		{
			choose = 3;
		}
		else if (choose < 0)
		{
			choose = 0;
		}
		c2 = clock();
	}
	return NULL;
}
