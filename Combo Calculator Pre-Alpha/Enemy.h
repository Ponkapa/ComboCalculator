/*
 * Enemy.h
 *
 *  Created on: Jan 7, 2016
 *      Author: James
 */

#ifndef ENEMY_H_
#define ENEMY_H_
#include <string>
class Enemy{
		std::string charName;
		int damage;
		float weight;
		float gravity;
		float termVel;
		bool crouching;
		bool inAir;
		bool charging;
	public:
		Enemy(std::string, int, float, float, float, bool, bool, bool);
		int getDamage() const;
		void setDamage(int);
		float getWeight() const;
		void setWeight(float);
		float getGravity() const;
		void setGravity(float);
		float getTermVel() const;
		void setTermVel(float);
		bool isCrouching() const;
		void setCrouching(bool);
		bool isInAir() const;
		void setInAir(bool);
		bool isCharging() const;
		void setIsCharging(bool);
		std::string getName();
};

#endif /* ENEMY_H_ */
