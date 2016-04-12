/*
 * Function.cpp
 *
 *  Created on: Jan 7, 2016
 *      Author: James
 */
#include "Function.h"
#include "Hitbox.h"
#include "Enemy.h"
#include "Player.h"
#include "Move.h"
#include <vector>
#include <cmath>
#include <string>
#define PI 3.14159265

float Function::Knockback(Enemy e, Hitbox h){
	float totalDamage = h.getDamage()+e.getDamage();
	float X = h.getDamage()*totalDamage*0.05;
	float Y = totalDamage*0.1;
	float W = 200/(e.getWeight()+100);
	float knockback = (h.getBaseKnockBack()+h.getKnockBackGrowth()*0.01*(18+(1.4*W*(X+Y))));
	if (e.isCrouching()){
		knockback = knockback * 2/3;
	}
	if (e.isCharging()){
		knockback = knockback*1.2;
	}
	// std::cout << "totalDamage: " << totalDamage << " X: " << X << " Y: " << Y << " W: " << W << std::endl;
	return knockback;
}

std::vector<float> Function::Knockback(Enemy e, Move m){
	std::vector<float> moveVector;
	for (unsigned int i=0; i < m.getHitboxes().size(); i++){
		moveVector.push_back(Function::Knockback(e, m.getHitboxes()[i]));
	}
	return moveVector;
}

void Function::TumbleMoveset(Enemy e, Player p){
	std::cout << "Character: " << e.getName() << std::endl;
	for (unsigned int i=0; i < p.getMoves().size(); i++){
		std::cout << "Move: " << p.getMoves()[i].getName() << std::endl;
		for(unsigned int j=0; j < p.getMoves()[i].getHitboxes().size(); j++){
			std::cout << p.getMoves()[i].getHitboxes()[j].getName() << ": " << Function::TumblePercent(e, p.getMoves()[i].getHitboxes()[j]) << std::endl;
		}
		std::cout << std::endl;
	}
}
 int Function::Hitstun(Enemy e, Hitbox h){
	 float knockback = Function::Knockback(e,h);
	 int hitstun = knockback*0.4;
	 return hitstun;
}

 std::vector<float> Function::XTraj(Enemy e, Hitbox h){
	 std::vector<float> xTraj;
	 float speed = Knockback(e,h)*0.03;
	 float xSpeed = speed*cos(h.getDirection()*PI/180);
	 float xFric = cos(h.getDirection()*PI/180)*0.051;
	 xTraj.push_back(0);
	 int i = 0;
	 float nextKB = xSpeed;
	 while (nextKB > 0){
		  nextKB -= xFric;
		  if (nextKB < 0){
			  nextKB = 0;
		  }
		  float nextTraj = xTraj[i] + nextKB;
		  xTraj.push_back(nextTraj);
		  i++;
	 }
	 return xTraj;
 }

 std::vector<float> Function::YTraj(Enemy e, Hitbox h){
	 std::vector<float> yTraj;
	 float speed = Knockback(e,h)*0.03;
	 float ySpeed = speed*sin(h.getDirection()*PI/180);
	 float yFric = sin(h.getDirection()*PI/180)*0.051;
	 yTraj.push_back(0);
	 int i = 0;
	 float nextKB = ySpeed;
	 float gravity = e.getGravity();
	 while (nextKB > 0){
		  nextKB = nextKB - yFric;
		  if (nextKB < 0){
			  nextKB = 0;
		  }
		  float nextTraj = yTraj[i] + nextKB - gravity;
		  if (gravity < e.getTermVel())
		  {
			  gravity += e.getGravity();
		  }
		  if (gravity > e.getTermVel())
		  {
			  gravity = e.getTermVel();
		  }
		  yTraj.push_back(nextTraj);
		  i++;
	 }
	 return yTraj;
 }

 std::vector<float> Function::Jump(Player p){
	 std::vector<float> yTraj;
	 return yTraj;
 }

 bool Function::Tumble(Enemy e, Hitbox h){
	 float knockback = Function::Knockback(e,h);
	 if (knockback > 80){
		 return true;
	 }
	 else{
		 return false;
	 }
 }

int Function::TumblePercent(Enemy e, Hitbox h){
	e.setDamage(0);
	while (!Function::Tumble(e,h))
	{
		e.setDamage(e.getDamage()+1);
	}
	return e.getDamage();
}

void Function::TumbleAll(Hitbox h){
	std::vector<Enemy> enemyList;
	enemyList.push_back(Enemy("Bowser",0,118,0,0,false,false,false));
	enemyList.push_back(Enemy("Captain Falcon",0,104,0,0,false,false,false));
	enemyList.push_back(Enemy("Charizard",0,110,0,0,false,false,false));
	enemyList.push_back(Enemy("Dedede",0,112,0,0,false,false,false));
	enemyList.push_back(Enemy("Diddy Kong",0,85,0,0,false,false,false));
	enemyList.push_back(Enemy("Donkey Kong",0,114,0,0,false,false,false));
	enemyList.push_back(Enemy("Falco",0,80,0,0,false,false,false));
	enemyList.push_back(Enemy("Fox",0,75,0,0,false,false,false));
	enemyList.push_back(Enemy("Game & Watch",0,75,0,0,false,false,false));
	enemyList.push_back(Enemy("Ganondorf",0,109,0,0,false,false,false));
	enemyList.push_back(Enemy("Ice Climbers",0,88,0,0,false,false,false));
	enemyList.push_back(Enemy("Ike",0,105,0,0,false,false,false));
	enemyList.push_back(Enemy("Ivysaur",0,85,0,0,false,false,false));
	enemyList.push_back(Enemy("Jigglypuff",0,60,0,0,false,false,false));
	enemyList.push_back(Enemy("Kirby",0,74,0,0,false,false,false));
	enemyList.push_back(Enemy("Link",0,104,0,0,false,false,false));
	enemyList.push_back(Enemy("Lucario",0,100,0,0,false,false,false));
	enemyList.push_back(Enemy("Lucas",0,80,0,0,false,false,false));
	enemyList.push_back(Enemy("Luigi",0,100,0,0,false,false,false));
	enemyList.push_back(Enemy("Mario",0,100,0,0,false,false,false));
	enemyList.push_back(Enemy("Marth",0,87,0,0,false,false,false));
	enemyList.push_back(Enemy("Meta Knight",0,79,0,0,true,false,false));
	enemyList.push_back(Enemy("Mewtwo",0,97,0,0,false,false,false));
	enemyList.push_back(Enemy("Ness",0,94,0,0,false,false,false));
	enemyList.push_back(Enemy("Olimar",0,90,0,0,false,false,false));
	enemyList.push_back(Enemy("Peach",0,90,0,0,false,false,false));
	enemyList.push_back(Enemy("Pikachu",0,80,0,0,false,false,false));
	enemyList.push_back(Enemy("Pit",0,80,0,0,false,false,false));
	enemyList.push_back(Enemy("ROB",0,106,0,0,false,false,false));
	enemyList.push_back(Enemy("Roy",0,85,0,0,false,false,false));
	enemyList.push_back(Enemy("Samus",0,110,0,0,false,false,false));
	enemyList.push_back(Enemy("Sheik",0,90,0,0,false,false,false));
	enemyList.push_back(Enemy("Snake",0,105,0,0,false,false,false));
	enemyList.push_back(Enemy("Sonic",0,82,0,0,false,false,false));
	enemyList.push_back(Enemy("Squirtle",0,82,0,0,false,false,false));
	enemyList.push_back(Enemy("Toon Link",0,85,0,0,false,false,false));
	enemyList.push_back(Enemy("Wario",0,107,0,0,false,false,false));
	enemyList.push_back(Enemy("Wolf",0,85,0,0,false,false,false));
	enemyList.push_back(Enemy("Yoshi",0,108,0,0,false,false,false));
	enemyList.push_back(Enemy("Zelda",0,90,0,0,false,false,false));
	enemyList.push_back(Enemy("Zero Suit",0,85,0,0,false,false,false));

	std::cout << h.getName() << std::endl;
	for (int i = 0; i<41; i++)
	{
		std::cout << enemyList[i].getName() <<  ": " << Function::TumblePercent(enemyList[i],h) << "%"<< std::endl;
	}
}
