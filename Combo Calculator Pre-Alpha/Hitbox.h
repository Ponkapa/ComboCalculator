/*
 * Hitbox.h
 *
 *  Created on: Jan 6, 2016
 *      Author: James
 */

#ifndef HITBOX_H_
#define HITBOX_H_

#include <iostream>
class Hitbox{
	private:
		int frame;
		std::string name;
		float damage;
		float direction;
		float baseKnockBack;
		float knockBackGrowth;
		friend std::ostream& operator<< (std::ostream& out, const Hitbox& o);
	public:
		Hitbox (std::string, int, float, float, float, float);
		float getDamage() const;
		void setDamage(float);
		float getBaseKnockBack() const;
		void setBaseKnockBack(float);
		float getDirection() const;
		void setDirection(float);
		int getFrame() const;
		void setFrame(int);
		float getKnockBackGrowth() const;
		void setKnockBackGrowth(float);
		std::string getName();
		};



#endif /* HITBOX_H_ */
