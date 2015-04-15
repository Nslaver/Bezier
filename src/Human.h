#pragma once
#include "ofMain.h"

class Human {

public:
    
    ofVec2f pos, vel;
	ofColor my;

	ofBoxPrimitive torse;
	ofSpherePrimitive head;
	ofBoxPrimitive lUpArm;
    ofBoxPrimitive lLowArm;
	ofBoxPrimitive rUpArm;
    ofBoxPrimitive rLowArm;
	ofBoxPrimitive lUpLeg;
    ofBoxPrimitive lLowLeg;
	ofBoxPrimitive rUpLeg;
    ofBoxPrimitive rLowLeg;

	void setup();

    void update();
    
    void draw();

	void setScale(GLfloat newScale);
	void setParts(GLfloat newScale);

	void setPosition(ofVec3f newPosition);

	void lookAt(ofVec3f newPosition);
    
};