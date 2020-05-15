#include "player.h"

void Player::Update(time_t now_sec, clock_t interval)
{
	hospital.Update(now_sec, interval);
	human.Update(now_sec, interval);
}
