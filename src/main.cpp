#include "player/player.h"
//#include <pthread.h>
//#include <semaphore.h>
#include <thread>

int main(int argc, char **argv)
{
	//sem_t sem;
	//pthread_t tid;
	//sem_init(&sem, 0, 1);
	Player player;
	player.question.InitPlayer(&player);
	//pthread_create(&tid, NULL, p_input, &player);
	std::thread tr(p_input, &player);
	while (true)
	{
		player.Update();
	}
	tr.join();
	//pthread_join(tid, NULL);
	//sem_destroy(&sem);
	return 0;
}
