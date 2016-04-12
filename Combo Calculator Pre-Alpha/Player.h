/*
 * Player.h
 *
 *  Created on: Jan 15, 2016
 *      Author: James
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include <vector>
#include "Move.h"

class Player{
		float gravity;
		float termVel;
		float jumpVel;
		float hopVel;
		int dashFrames;
		float initDash;
		float maxDash;
		float accelDash;
		float lowTract;
		float highTract;
		float maxWalkSpeed;
		int jumpSquat;
		float fastFallSpeed;
		std::vector<Move> moveList;
	public:
		Player(float gravity, float termVel, float jumpVel, float hopVel, float fastFallSpeed, float initDash, float maxDash, float accelDash, float lowTract, float maxWalkSpeed, int jumpSquat, int dashFrames);
		float Gravity() const;
		void setGravity(float);
		float TermVel() const;
		void setTermVel(float);
		float JumpVel() const;
		void setJumpVel(float);
		std::vector<Move> getMoves();
		void addMove(Move);
		std::vector<float> JumpTraj();
		std::vector<float> HopTraj();
		std::vector<float> RunTraj();
		std::vector<float> AirTraj();
};



#endif /* PLAYER_H_ */
