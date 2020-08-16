#ifndef __CLIENT_H__
#define __CLIENT_H__

#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <linux/input.h>
#include <fcntl.h>
#include <time.h>


extern int choose;
extern int game_status;

int GetChoose();
int GetGameStatus();
int mygetch();
void* p_input(void* arg);

#endif
