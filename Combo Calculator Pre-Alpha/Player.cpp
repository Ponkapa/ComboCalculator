/*
 * Player.cpp

 *
 *  Created on: Jan 15, 2016
 *      Author: James
 */

#include "Player.h"

		Player::Player(float gravity, float termVel, float jumpVel, float hopVel, float fastFallSpeed, float initDash, float maxDash, float accelDash, float lowTract, float maxWalkSpeed, int jumpSquat, int dashFrames){
			this->gravity = gravity;
			this->termVel = termVel;
			this->dashFrames = dashFrames;
			this->initDash = initDash;
			this->maxDash = maxDash;
			this->accelDash = accelDash;
			this->lowTract = lowTract;
			this->highTract = lowTract*2;
			this->maxWalkSpeed = maxWalkSpeed;
			this->jumpSquat = jumpSquat;
			this->fastFallSpeed = fastFallSpeed;
			this->jumpVel = jumpVel;
			this->hopVel = hopVel;
		}
		float Player::Gravity() const{
			return gravity;
		}
		void Player::setGravity(float gravity){
			this->gravity = gravity;
		}
		float Player::TermVel() const{
			return termVel;
		}
		void Player::setTermVel(float termVel){
			this->termVel = termVel;
		}
		float Player::JumpVel() const{
			return jumpVel;
		}
		void Player::setJumpVel(float jumpVel){
			this->jumpVel = jumpVel;
		}
		std::vector<Move> Player::getMoves(){
			return moveList;
		}
		void Player::addMove(Move m){
			moveList.push_back(m);
		}
		std::vector<float> Player::JumpTraj(){
			 std::vector<float> yTraj;
			 int i = 0;
			 float vel = jumpVel;
			 for (i = 0; i < jumpSquat; i++)
			 {
				 yTraj.push_back(0);
			 }
			 yTraj.push_back(vel);
			 while (yTraj[i] > 0){
				 if (vel > termVel){
					 vel -= gravity;
				 }
				 yTraj.push_back(yTraj[i] + vel);
				 i++;
			 }
			 return yTraj;
		}
		std::vector<float> Player::HopTraj(){
					 std::vector<float> yTraj;
					 int i = 0;
					 float vel = hopVel;
					 for (i = 0; i < jumpSquat; i++)
					 {
						 yTraj.push_back(0);
					 }
					 yTraj.push_back(vel);
					 while (yTraj[i] > 0){
						 if (vel > termVel){
							 vel -= gravity;
						 }
						 yTraj.push_back(yTraj[i] + vel);
						 i++;
					 }
					 return yTraj;
				}
