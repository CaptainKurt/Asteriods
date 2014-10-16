//
//  Asteroid.h
//  Asteriods
//
//  Created by Kurt Walker on 10/16/14.
//  Copyright (c) 2014 AIT. All rights reserved.
//

#ifndef Asteriods_Asteroid_h
#define Asteriods_Asteroid_h
#include "Object.h"

using namespace std;

class Asteroid : public Object
{
public:
    float2 velocity;
    Asteroid(){
        velocity = float2::random();
    }
    void drawModel()
    {
        glColor3d(1.0, 0.5, 0.0);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2d(0.0, 0.0);
        for(double phi=0.0; phi<6.5; phi+=0.32)
            glVertex2d(
                       cos(phi)*(0.8 + 0.2*sin(phi*7) ),
                       sin(phi)*(0.8 + 0.2*sin(phi*7) ));
        glEnd();
    }
    void move(double t, double dt)
    {
        orientation += 50.0*dt;
        
        if (position.x > 1) {
            position = float2(-1, position.y);
        }
        else if (position.x < -1) {
            position = float2(1, position.y);
        }
        
        if (position.y > 1) {
            position = float2(position.x, -1);
        }
        else if (position.y < -1) {
            position = float2(position.x, 1);
        }
        
        position += velocity*dt;
    }
};

#endif
