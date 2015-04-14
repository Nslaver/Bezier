#include "Human.h"

void Human::setup(){
	torse.setScale(1,0.5,0.5);
	head.setParent(torse);
	lUpArm.setParent(torse);
    lLowArm.setParent(lUpArm);
	rUpArm.setParent(torse);
    rLowArm.setParent(rUpArm);
	lUpLeg.setParent(torse);
    lLowLeg.setParent(lUpLeg);
	rUpLeg.setParent(torse);
    rLowLeg.setParent(lLowLeg);
}

void Human::update(){
}

void Human::draw(){
}