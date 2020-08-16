#include "player/player.h"
#include <pthread.h>
#include <semaphore.h>

int main(int argc, char **argv)
{
	sem_t sem;
	pthread_t tid;
	sem_init(&sem, 0, 1);
	pthread_create(&tid, NULL, p_input, NULL);
	while (true)
	{
		Player player;
		player.Update();
	}
	pthread_join(tid, NULL);
	sem_destroy(&sem);
	return 0;
}
