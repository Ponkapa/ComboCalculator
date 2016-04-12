/*
 * Functions.h
 *
 *  Created on: Jan 7, 2016
 *      Author: James
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <vector>

class Enemy;
class Hitbox;
class Player;
class Move;

class Function{
	public:
		static float Knockback(Enemy, Hitbox);
		static std::vector<float> Knockback(Enemy, Move);
		static int Hitstun(Enemy, Hitbox);
		static std::vector<float> XTraj(Enemy, Hitbox);
		static std::vector<float> YTraj(Enemy, Hitbox);
		static std::vector<float> Jump(Player);
		static bool Tumble(Enemy, Hitbox);
		static int TumblePercent(Enemy, Hitbox);
		static void TumbleAll(Hitbox);
		static void TumbleMoveset(Enemy, Player);
};


#endif /* FUNCTIONS_H_ */
