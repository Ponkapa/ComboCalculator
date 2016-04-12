/*
 * Move.cpp
 *
 *  Created on: Jan 7, 2016
 *      Author: James
 */

#include <vector>
#include "Hitbox.h"
#include "Move.h"
#include "Function.h"

		Move::Move (std::string name, int endFrame, bool aerial) {
			this->name = name;
			this->endFrame = endFrame;
			this->aerial = aerial;
			this->landLag = 0;
		}

		std::string Move::getName(){
			return name;
		}
		void Move::landingLag(int landLag){
			this->landLag = landLag;
		}
		void Move::addHitbox(const Hitbox& hitbox){
			hitboxes.push_back(hitbox);
			/*
			if (hitboxes.size() == 0){
				hitboxes.push_back(hitbox);
			}else {
				if (hitboxes[hitboxes.size()-1].getFrame() <= hitbox.getFrame()){
					hitboxes.push_back(hitbox);
				} else if (hitboxes[0].getFrame() > hitbox.getFrame()){
					hitboxes.insert(hitboxes.begin(),hitbox);
				} else{
					int index = 1;
					if (hitboxes.size()<=4){
						index = 1;
						while(!hitboxes[index].getFrame() > hitbox.getFrame()){
							index++;
						}
					} else{
						int start = 0;
						int end = hitboxes.size();
						while (hitboxes[index].getFrame() != hitbox.getFrame() && !(hitboxes[index-1].getFrame() < hitbox.getFrame() && hitboxes[index].getFrame() > hitbox.getFrame())){
							index = start+(end-start)/2;
							if (hitboxes[index].getFrame() > hitbox.getFrame()){
								end = index;
							} else if (hitboxes[index].getFrame() < hitbox.getFrame()){
								start = index;
							}
						}
					}
					hitboxes.insert(hitboxes.begin()+index,hitbox);
				}
			}
			*/
		}


		std::vector<Hitbox> Move::getHitboxes(){
			return hitboxes;
		}
		bool Move::isAerial(){
			return aerial;
		}

		void Move::printData(){
			bool hasHitbox = false;
			for(int i=1; i<=endFrame; i++)
			{
				hasHitbox = false;
				for(unsigned int a=0; a<hitboxes.size(); a++){
					if(i == hitboxes[a].getFrame()){
						std::cout << hitboxes[a] << std::endl;
						hasHitbox = true;
					}
				}
				if (!hasHitbox){
					std::cout << "Frame: " << i << std::endl;
				}
			}
		}
		void Move::printHitboxes(){
			for(unsigned int a=0; a<hitboxes.size(); a++){
					std::cout << hitboxes[a] << std::endl;
			}
		}
		int Move::endLag(Hitbox hitbox){
			if (aerial){
				return landLag+1;
			} else{
				return endFrame - hitbox.getFrame();
			}
		}
		int Move::followUpFrames(Enemy enemy, Hitbox hitbox){
			return Function::Hitstun(enemy, hitbox) - endLag(hitbox);
		}
