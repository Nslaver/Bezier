#include "Human.h"
#include "ofMain.h"

void Human::setup(){
	setScale(1.0);
			
	torse.set(1);

	head.set(1,36,OF_PRIMITIVE_TRIANGLE_STRIP);

	lUpArm.set(1);
	lLowArm.set(1);

	rUpArm.set(1);
	rLowArm.set(1);

	lUpLeg.set(1);
	lLowLeg.set(1);

	rUpLeg.set(1);
	rLowLeg.set(1);	


	head.setScale(0.3, 0.3, 0.3);
	
	rUpArm.setScale(0.65, 0.25, 0.25);
	rLowArm.setScale(0.65, 0.25, 0.25);

	lUpArm.setScale(0.65, 0.25, 0.25);
	lLowArm.setScale(0.65, 0.25, 0.25);
	
	rUpLeg.setScale(0.25, 0.75, 0.25);
	rLowLeg.setScale(0.25, 0.75, 0.25);

	lUpLeg.setScale(0.25, 0.75, 0.25);
	lLowLeg.setScale(0.25, 0.75, 0.25);

	
	head.setPosition(0.0, 1.0, 0);
	
	rUpArm.setPosition(0.75, 0.55, 0.0);
	rLowArm.setPosition(1.5, 0.55, 0.0);

	lUpArm.setPosition(-0.75, 0.55, 0.0);
	lLowArm.setPosition(-1.5, 0.55, 0.0);

	rUpLeg.setPosition(0.55, -0.75, 0.0);
	rLowLeg.setPosition(0.55, -1.50, 0.0);
		
	lUpLeg.setPosition(-0.55, -0.75, 0.0);
	lLowLeg.setPosition(-0.55, -1.50, 0.0);

	head.setParent(torse);
	lUpArm.setParent(torse);
	lLowArm.setParent(torse);
	rUpArm.setParent(torse);
	rLowArm.setParent(torse);
	lUpLeg.setParent(torse);
	lLowLeg.setParent(torse);
	rUpLeg.setParent(torse);
	rLowLeg.setParent(torse);
}

void Human::setScale(GLfloat newScale){
	
	torse.setScale(newScale*1.0, newScale*1.25, newScale*0.25);
	setParts(newScale);
}

void Human::setParts(GLfloat newPosition){
	torse.setPosition(newPosition*0, newPosition*0.0, newPosition*0);

}

void Human::update(){

}


void Human::setPosition(ofVec3f newPosition){
	torse.setPosition(newPosition.x, newPosition.y, newPosition.z);
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