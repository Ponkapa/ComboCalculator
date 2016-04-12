/*
 * Move.h
 *
 *  Created on: Jan 7, 2016
 *      Author: James
 */

#ifndef MOVE_H_
#define MOVE_H_


#include <vector>
#include "Hitbox.h"
#include "Enemy.h"

class Move {
		std::vector<Hitbox> hitboxes;
		std::string name;
		int endFrame;
		int landLag;
		bool aerial;
	public:
		Move (std::string, int, bool);
		std::string getName();
		void landingLag(int);
		void addHitbox(const Hitbox&);
		void printHitboxes();
		bool isAerial();
		void printData();
		int endLag(Hitbox);
		int followUpFrames(Enemy, Hitbox);
		std::vector<Hitbox> getHitboxes();
};




#endif /* MOVE_H_ */
