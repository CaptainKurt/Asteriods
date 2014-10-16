//
//  Scene.h
//  Asteriods
//
//  Created by Kurt Walker on 10/16/14.
//  Copyright (c) 2014 AIT. All rights reserved.
//

#ifndef Asteriods_Scene_h
#define Asteriods_Scene_h
//#include "Object.h"
#include <vector>

using namespace std;

class Scene
{
    std::vector<Object*> objects;
public:
    void addObject(Object* object) {
        objects.push_back(object);
    }
    ~Scene() {
        for(unsigned int i=0; i<objects.size(); i++)
            delete objects.at(i);
    }
    void draw() {
        for(unsigned int i=0; i<objects.size(); i++)
            objects.at(i)->draw();
    }
    void move(double t, double dt) {
        for(unsigned int i=0; i<objects.size(); i++)
            objects.at(i)->move(t, dt);
    }
};


#endif
