#include "player/player.h"


int main(int argc, char **argv)
{
	Player player;
	clock_t c2 = clock();
	clock_t interval;
	clock_t interval_limit = 1 * CLOCKS_PER_SEC;
	while (true)
	{
		interval = clock() - c2;
		if (interval < interval_limit)
			continue;
		time_t t = time(NULL);
		player.Update(t, interval);
		c2 = clock();
	}
	return 0;
}
