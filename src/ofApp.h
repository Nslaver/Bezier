#pragma once

#include "ofMain.h"
#include "ofRay.h"
#include "Human.h"

#define kBezierPoints 4
#define floorLimits 300.0
#define bezierLineSubDiv 100
#define bezierMovSubDiv 100

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void drawBezierLine();

		ofPlanePrimitive floor;
		ofCamera cam;
		ofNode camObjective;

		ofNode actorNode;
		int currentStep;
		int actorDirection;

		ofNode bzNodes[kBezierPoints];
		ofSpherePrimitive bzPoints[kBezierPoints];
		float nearestDistance;
		ofVec2f nearestVertex;
		int nearestIndex;

		ofSpherePrimitive daWorld;

		Human myHuman;

		ofLight pointLight;
		ofLight pointLight2;
		ofLight pointLight3;
		
};
