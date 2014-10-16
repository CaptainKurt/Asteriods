//
//  Object.h
//  Asteriods
//
//  Created by Kurt Walker on 10/16/14.
//  Copyright (c) 2014 AIT. All rights reserved.
//

#ifndef Asteriods_Object_h
#define Asteriods_Object_h

class Object
{
protected:
    float2 scaleFactor;
    float2 position;
    float orientation;
public:
    Object():orientation(0.0f), scaleFactor(1.0,1.0){}
    virtual ~Object(){}
    
    Object* translate(float2 offset){
        position += offset;
        return this;
    }
    Object* scale(float2 factor){
        scaleFactor *= factor;
        return this;
    }
    Object* rotate(float angle){
        orientation += angle;
        return this;
    }
    
    virtual void draw()
    {
        // apply scaling, translation and orientation
        glPushMatrix();
        glTranslatef(position.x, position.y, 0.0f);
        glRotatef(orientation, 0.0f, 0.0f, 1.0f);
        glScalef(scaleFactor.x, scaleFactor.y, 1.0f);
        drawModel();
        glPopMatrix();
        
    }
    virtual void drawModel()=0;
    virtual void move(double t, double dt){}
};


#endif
