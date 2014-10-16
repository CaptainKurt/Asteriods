//
//  main.cpp
//  Asteriods
//
//  Created by Kurt Walker on 10/16/14.
//  Copyright (c) 2014 AIT. All rights reserved.
//

#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
// Download glut from:
// http://www.opengl.org/resources/libraries/glut/
#include <GLUT/glut.h>
#include <OpenGL/OpenGL.h>
#include "float2.h"
#include "Asteroid.h"
#include "Object.h"
#include "Scene.h"
#include <vector>

Scene scene;

void onReshape(int winWidth0, int winHeight0)
{
    glViewport(0, 0, winWidth0, winHeight0);
}

void onIdle()
{
    // time elapsed since program started, in seconds
    double t = glutGet(GLUT_ELAPSED_TIME) * 0.001;
    // variable to remember last time idle was called
    static double lastTime = 0.0;
    // time difference between calls: time step
    double dt = t - lastTime;
    // store time
    lastTime = t;
    
    scene.move(t,dt);
    
    // show
    glutPostRedisplay();
}

void onDisplay( )
{
    glClearColor(0.11, 0.11, 0.2, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    
    scene.draw();
    
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Asteroids");
    
    for (int i=0; i < 10; i++)
    {
        scene.addObject((new Asteroid())
                    ->scale(float2(0.1f, 0.1f))
                    ->rotate(45.0f)
                    ->translate(float2::random()) );
    }
    
    // Register event handlers here
    glutReshapeFunc(onReshape);
    glutDisplayFunc(onDisplay);
    
    glutIdleFunc(onIdle);
    glutMainLoop();
    return 0;
}
