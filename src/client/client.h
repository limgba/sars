#ifndef __CLIENT_H__
#define __CLIENT_H__

#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <linux/input.h>
#include <fcntl.h>
#include <time.h>

class Player;

enum GAME_STATUS
{
	GAME_STATUS_START,
	GAME_STATUS_GAMING,
	GAME_STATUS_WIN,
	GAME_STATUS_LOSE,
};

extern int choose;
extern int game_status;

int GetChoose();
int GetGameStatus();
void SetChoose(Player* player, int _choose);
void SetGameStatus(Player* player, int status);
int mygetch();
void* p_input(void* arg);

#endif
