#include "ofApp.h"

GLfloat ctrlpoints[4][3] = {{0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}};
int circ = 0;
int cicl = 200;
//--------------------------------------------------------------
void ofApp::setup(){
	
	//
	ofSetVerticalSync(true);
	ofBackground(255);

	// Setup floor

	floor.set(floorLimits*10, floorLimits*10);
	floor.setPosition(ofVec3f(0,0,0));
	floor.setOrientation(ofVec3f(90,0,0));

	// Setup Human

	myHuman.setup();
	myHuman.setScale(50);


	// Setup da World

	daWorld.set(floorLimits*4,10,OF_PRIMITIVE_TRIANGLE_STRIP);
	daWorld.setPosition(ofVec3f(0,0,0));


	
	
	// Light

	ofSetSmoothLighting(true);
    pointLight.setDiffuseColor(  ofFloatColor(1,1,1) );
    pointLight.setSpecularColor(  ofFloatColor(1,1,1) );
	pointLight.setPosition(floorLimits,0,floorLimits);
    
    pointLight2.setDiffuseColor(  ofFloatColor(1,1,1) );
    pointLight2.setSpecularColor( ofFloatColor(1,1,1) );
	pointLight2.setPosition(-floorLimits,0,floorLimits);
    
    pointLight3.setDiffuseColor( ofFloatColor(1,1,1) );
    pointLight3.setSpecularColor( ofFloatColor(1,1,1) );
	pointLight3.setPosition(floorLimits,0,-floorLimits);


	// Simple pick variables

	nearestDistance = 0;
	nearestIndex = 0;

	// Objective movement
	currentStep = 0;
	actorDirection = 1;


	//ofBackground(255,255,255);

    //some model / light stuff
    //ofEnableDepthTest();
    //glShadeModel (GL_SMOOTH);


	// Link bzpoints...
	//for(int i=0; i<kBezierPoints; i++) {
		//if(i>0) bzNodes[i].setParent(bzNodes[i-1]);
	//}

	
	cam.setPosition(floorLimits,floorLimits,floorLimits);
	// Setup camObjective

	//camObjective.setPosition(ofVec3f(floorLimits,floorLimits,floorLimits));

	//Random initial control points

	for(int i=0; i<kBezierPoints; i++) {
			bzNodes[i].setPosition(ofVec3f(ofRandom(-floorLimits,floorLimits*0.7),0,ofRandom(-floorLimits,floorLimits*0.7)));
			ctrlpoints[i][0]=bzNodes[i].getX();
			ctrlpoints[i][1]=bzNodes[i].getY();
			ctrlpoints[i][2]=bzNodes[i].getZ();
		}

	// Translation with opengl
	//glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints[0][0]);
	//glEnable(GL_MAP1_VERTEX_3);
	
}

//--------------------------------------------------------------
void ofApp::update(){

	pointLight.setOrientation(ofVec3f(0,0,180));
	pointLight2.setOrientation(ofVec3f(0,0,180));
	pointLight3.setOrientation(ofVec3f(0,0,180));

	pointLight.setPosition(
		cos(ofGetElapsedTimef()*.5)*floorLimits*0.7, 
		floorLimits/4, 
		sin(ofGetElapsedTimef()*.5)*floorLimits*0.7);
    pointLight2.setPosition(
		sin(ofGetElapsedTimef()*.5)*floorLimits*0.5, 
		floorLimits/3, 
		cos(ofGetElapsedTimef()*.5)*floorLimits*0.5);
    pointLight3.setPosition(
		floorLimits/2, 
		floorLimits/2, 
		-floorLimits/2);

	
		
	//Cam test
	//camObjective.setPosition(ofVec3f(0,(floorLimits/2)-ofGetElapsedTimef()*10,0));

	//Test random controlPoints
	/*circ++;

	if(circ%cicl == 0){
		for(int i=0; i<kBezierPoints; i++) {
			bzNodes[i].setPosition(ofVec3f(ofRandom(-floorLimits,floorLimits),20,ofRandom(-floorLimits,floorLimits)));
			ctrlpoints[i][0]=bzNodes[i].getX();
			ctrlpoints[i][1]=bzNodes[i].getY();
			ctrlpoints[i][2]=bzNodes[i].getZ();
		}
		glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints[0][0]);
		glEnable(GL_MAP1_VERTEX_3);
	}
	if(circ > cicl){
		circ = 0;
	}*/

	//Update control points
	for(int i=0; i<kBezierPoints; i++) {
		ctrlpoints[i][0]=bzNodes[i].getX();
		ctrlpoints[i][1]=bzNodes[i].getY();
		ctrlpoints[i][2]=bzNodes[i].getZ();
	}

	actorNode.setPosition(bzNodes[0].getGlobalPosition());
	
	GLfloat b2 = (cos(ofGetElapsedTimef()*.5) + 1) / 2;
	GLfloat a1 = GLfloat(1.0-b2);
		
	//Draw actor node
	ofVec3f lastPosition = actorNode.getPosition();

	ofVec3f nextPosition = ofVec3f(
		bzNodes[0].getX()*a1*a1*a1 + bzNodes[1].getX()*3*a1*a1*b2 + bzNodes[2].getX()*3*a1*b2*b2 + bzNodes[3].getX()*b2*b2*b2,
		bzNodes[0].getY()*a1*a1*a1 + bzNodes[1].getY()*3*a1*a1*b2 + bzNodes[2].getY()*3*a1*b2*b2 + bzNodes[3].getY()*b2*b2*b2,
		bzNodes[0].getZ()*a1*a1*a1 + bzNodes[1].getZ()*3*a1*a1*b2 + bzNodes[2].getZ()*3*a1*b2*b2 + bzNodes[3].getZ()*b2*b2*b2);

	actorNode.setPosition(nextPosition);
	myHuman.lookAt(nextPosition);
	myHuman.setPosition(actorNode.getGlobalPosition());
	

	//Update current steo and actor direction
	if(int(ofGetElapsedTimef())% 3 == 0 ){
		currentStep += actorDirection;
		
		if(0>currentStep || currentStep>bezierMovSubDiv){
			actorDirection*=-1;
		}
	}
	
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofEnableDepthTest();
    
    ofEnableLighting();
    pointLight.enable();
    pointLight2.enable();
    pointLight3.enable();

	
	cam.lookAt(camObjective);

	//Cam setup
	cam.begin();
	//cam.draw();
	ofSetColor(0, 255, 0);
	camObjective.draw();
	ofDrawAxis(floorLimits);

	//Bezier line with evaluator
	ofFill();
    ofSetColor(pointLight.getDiffuseColor());
    //pointLight.draw();
    ofSetColor(pointLight2.getDiffuseColor());
    //pointLight2.draw();
    ofSetColor(pointLight3.getDiffuseColor());
    //pointLight3.draw();


	ofSetColor(ofColor::indianRed);
	drawBezierLine();	

	
  
	ofSetColor(ofColor::mediumPurple);
	actorNode.draw();
	
	ofSetColor(ofColor::yellow);
	myHuman.draw();
		
	
	//daWorld

	//ofSetColor(0, 15, 250);
	//daWorld.draw();

	//Floor

	
	//ofSetColor(0, 100, 25);
	//floor.draw();

    /* Quad Floor
	glBegin(GL_QUADS);	
        glVertex3f( floorLimits, 0.0,  floorLimits);
		glVertex3f( floorLimits, 0.0, -floorLimits);
		glVertex3f(-floorLimits, 0.0, -floorLimits);
        glVertex3f(-floorLimits, 0.0,  floorLimits);
    glEnd();
	*/
	

	// draw bzNodes
	for(int i=0; i<kBezierPoints; i++) {
		ofSetColor(255, 128, 255);
		bzNodes[i].draw();
		if(i == 0 || i == 2){
			ofSetColor(255, 255, 0);
			ofVec3f v1 = bzNodes[i].getGlobalPosition();
			ofVec3f v2 = bzNodes[i+1].getGlobalPosition();
			ofLine(v1,v2);
		}
	}

	//glPushMatrix();

		
    //glPopMatrix();
	cam.end();

	//Calculate and edit current bezir point
	ofVec2f mouse(mouseX, mouseY);
	for(int i = 0; i < kBezierPoints; i++) {
		ofVec3f cur = cam.worldToScreen(bzNodes[i].getGlobalPosition());
		float distance = cur.distance(mouse);
		if(i == 0 || distance < nearestDistance) {
			nearestDistance = distance;
			nearestVertex = cur;
			nearestIndex = i;
		}
	}
	
	ofSetColor(ofColor::gray);
	ofLine(nearestVertex, mouse);
	
	ofNoFill();
	ofSetColor(ofColor::yellow);
	ofSetLineWidth(2);
	ofCircle(nearestVertex, 4);
	ofSetLineWidth(1);

	// Test Mouse Picker
	/*ofVec3f cur2 = cam.worldToScreen(bzNodes[nearestIndex].getGlobalPosition());
	ofVec3f cur1 = cam.screenToWorld(ofVec3f(mouse.x,mouse.y, cur2.z));
	ofVec3f cur3 = cam.screenToWorld(ofVec3f(mouse.x,mouse.y, 1));	
		bool t = false;

		string s2 = string("Cursor") + 
		""+ ofToString(mouse)+
		"\n"+ ofToString(cur1)+
		"\n"+ ofToString(cur2)+
		"\n"+ ofToString(cur3);
	
	

	glDisable(GL_CULL_FACE);
	ofSetColor(255,0,0);
	ofDisableLighting();
	ofDrawBitmapString(s2, ofPoint(20, 40));
	glEnable(GL_CULL_FACE);*/

	

	//MSG

	string s = string("BZ Point: P") + 
		""+ ofToString(nearestIndex+1) + 
		"("+ ofToString(bzNodes[nearestIndex].getGlobalPosition()) + ")";

	ofDrawBitmapString(s, ofPoint(20, 20));	
}

/*

*/



void ofApp::drawBezierLine(){
	// Points on the curve
	GLfloat X;
	GLfloat Y;
	GLfloat Z;

	// Variable
	GLfloat a = 1.0;
	GLfloat b = 1.0 - a;

	/* We will not actually draw a curve, but we will divide the curve into small
	points and draw a line between each point. If the points are close enough, it
	will appear as a curved line. 20 points are plenty, and since the variable goes
	from 1.0 to 0.0 we must change it by 1/20 = 0.05 each time */

	glBegin(GL_LINE_STRIP);
	for(int i = 0; i <= bezierLineSubDiv; i++)
	{
		// Get a point on the curve
		X = bzNodes[0].getX()*a*a*a + bzNodes[1].getX()*3*a*a*b + bzNodes[2].getX()*3*a*b*b + bzNodes[3].getX()*b*b*b;
		Y = bzNodes[0].getY()*a*a*a + bzNodes[1].getY()*3*a*a*b + bzNodes[2].getY()*3*a*b*b + bzNodes[3].getY()*b*b*b;
		Z = bzNodes[0].getZ()*a*a*a + bzNodes[1].getZ()*3*a*a*b + bzNodes[2].getZ()*3*a*b*b + bzNodes[3].getZ()*b*b*b;
  
		// Draw the line from point to point (assuming OGL is set up properly)
		glVertex3d(X, Y, Z);

		// Change the variable
		a -= 1.0/bezierLineSubDiv;
		b = 1.0 - a;
	}
		
	glEnd();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch(key) {
		case 'f':
			ofToggleFullscreen();
			break;
		default:
			break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	
	
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	ofVec3f screenToWorld = cam.screenToWorld(ofVec3f(x,y,0.0));
    ofRay ray(cam.getPosition(),screenToWorld - cam.getPosition());
    bool intersection = false;
    float t = 0;
    intersection = ray.calcPlaneIntersection(ofVec3f(0,0,0), ofVec3f(0,1,0), &t);
	bzNodes[nearestIndex].setPosition(ray.calcPosition(t));
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
