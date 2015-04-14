#include "Human.h"
#include "ofMain.h"

void Human::setup(){
	setScale(1.0);

	initPositions(1.0);
	
	head.set(1,36,OF_PRIMITIVE_TRIANGLE_STRIP);
	
	lUpArm.set(1);
	lLowArm.set(1);
	rUpArm.set(1);
	rLowArm.set(1);
	lUpLeg.set(1);
	lLowLeg.set(1);
	rUpLeg.set(1);
	rLowLeg.set(1);
	
}

void Human::setScale(GLfloat newScale){
	head.setScale(newScale*0.5, newScale*0.5, newScale*0.25);
	torse.setScale(newScale*1.0, newScale*1.25, newScale*0.25);
	lUpArm.setScale(newScale*0.65, newScale*0.25, newScale*0.25);
	lLowArm.setScale(newScale*0.65, newScale*0.25, newScale*0.25);
	rUpArm.setScale(newScale*0.65, newScale*0.25, newScale*0.25);
	rLowArm.setScale(newScale*0.65, newScale*0.25, newScale*0.25);
	lUpLeg.setScale(newScale*0.25, newScale*0.75, newScale*0.25);
	lLowLeg.setScale(newScale*0.25, newScale*0.75, newScale*0.25);
	rUpLeg.setScale(newScale*0.25, newScale*0.75, newScale*0.25);
	rLowLeg.setScale(newScale*0.25, newScale*0.75, newScale*0.25);
}

void Human::initPositions(GLfloat newPosition){
	torse.setPosition(0,0.0,0);
	head.setPosition(0.0,400.0,0);
	lUpArm.setPosition(0.75,0.75,0.0);
	lLowArm.setPosition(0.75+0.75,0.75,0.0);
	rUpArm.setPosition(-0.75,0.75,0.0);
	rLowArm.setPosition(-0.75-0.75,0.75,0.0);
	lUpArm.setPosition(0.75,0.75,0.0);
	lLowArm.setPosition(0.75+0.75,0.75,0.0);
	rUpArm.setPosition(-0.75,0.75,0.0);
	rLowArm.setPosition(-0.75-0.75,0.75,0.0);
	
}
void Human::update(){

}

void Human::draw(){
	head.draw();
	torse.draw();
	lUpArm.draw();
	lLowArm.draw();
	rUpArm.draw();
	rLowArm.draw();
	lUpLeg.draw();
	lLowLeg.draw();
	rUpLeg.draw();
	rLowLeg.draw();
}