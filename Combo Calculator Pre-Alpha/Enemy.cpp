/*
 * Enemy.cpp
 *
 *  Created on: Jan 7, 2016
 *      Author: James
 */
#include "Enemy.h"
#include <string>

Enemy::Enemy(std::string charName, int damage, float weight, float gravity, float termVel, bool crouching, bool inAir, bool charging){
	this->charName = charName;
	this->damage = damage;
	this->weight = weight;
	this->gravity = gravity;
	this->termVel = termVel;
	this->crouching = crouching;
	this->inAir = inAir;
	this->charging = charging;
}
std::string Enemy::getName(){
	return charName;
}
int Enemy::getDamage() const
{
	return damage;
}

void Enemy::setDamage(int damage)
{
	this->damage = damage;
}

float Enemy::getWeight() const
{
	return weight;
}

void Enemy::setWeight(float weight)
{
	this->weight = weight;
}

float Enemy::getGravity() const
{
	return gravity;
}

void Enemy::setGravity(float gravity)
{
	this->gravity = gravity;
}

float Enemy::getTermVel() const
{
	return termVel;
}

void Enemy::setTermVel(float termVel)
{
	this->termVel = termVel;
}

bool Enemy::isCrouching() const
{
	return crouching;
}

void Enemy::setCrouching(bool crouching)
{
	this->crouching = crouching;
}

bool Enemy::isInAir() const
{
	return inAir;
}

void Enemy::setInAir(bool inAir)
{
	this->inAir = inAir;
}

bool Enemy::isCharging() const
{
	return charging;
}

void Enemy::setIsCharging(bool charging)
{
	this->charging = charging;
}

