/*
 * Hitbox.cpp
 *
 *  Created on: Jan 6, 2016
 *      Author: James
 */
#include "Hitbox.h"
#include <iostream>
using namespace std;
		Hitbox::Hitbox (std::string name, int frame, float damage, float direction, float baseKnockBack, float knockBackGrowth){
				this->name = name;
				this->frame = frame;
				this->damage = damage;
				this->direction = direction;
				this->baseKnockBack = baseKnockBack;
				this->knockBackGrowth = knockBackGrowth;
		}

		float Hitbox::getDamage() const
		{
			return damage;
		}
		void Hitbox::setDamage(float damage)
		{
			this->damage = damage;
		}
		float Hitbox::getBaseKnockBack() const
		{
			return baseKnockBack;
		}

		void Hitbox::setBaseKnockBack(float baseKnockBack)
		{
			this->baseKnockBack = baseKnockBack;
		}

		float Hitbox::getDirection() const
		{
			return direction;
		}

		void Hitbox::setDirection(float direction)
		{
			this->direction = direction;
		}

		int Hitbox::getFrame() const
		{
			return frame;
		}

		void Hitbox::setFrame(int frame)
		{
			this->frame = frame;
		}

		float Hitbox::getKnockBackGrowth() const
		{
			return knockBackGrowth;
		}

		void Hitbox::setKnockBackGrowth(float knockBackGrowth)
		{
			this->knockBackGrowth = knockBackGrowth;
		}
		std::ostream& operator<< (std::ostream& out, const Hitbox& o)
		{
			out << "Frame: " << o.frame << ", Damage: " << o.damage <<
					", Direction: " << o.direction << ", BKB: " << o.baseKnockBack << ", KBG: " << o.knockBackGrowth;
			return out;
		}
		std::string Hitbox::getName(){
			return name;
		}
