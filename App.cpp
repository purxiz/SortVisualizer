#include "App.h"
#include <iostream>

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    state.push_back(1);
    state.push_back(2);
    state.push_back(3);
    state.push_back(4);
    state.push_back(5);
    state.push_back(6);
    state.push_back(7);
    state.push_back(8);
    state.push_back(9);
    
    step = new Step();
}

void App::draw() {

    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    
    float width = 2.0 / state.size();
    float spacing = 0.2*width;
    
    // Draw histogram
    for(int i = 0; i < state.size(); i++){
      switch(step->getColor(i)){
        case WHITE:
          glColor3f(1.0, 1.0, 1.0);
        break;
        case GREEN:
          glColor3f(0.0, 1.0, 0.0);
        break;
        case RED:
          glColor3f(1.0,0.0,0.0);
        break;
        case BLUE:
          glColor3f(0.0, 0.0, 1.0);
        break;
      }
      glRectf(i*width-1+spacing/2, -1,  (i*width-1+spacing/2) + width-spacing, (float)state[i]/(float)state.size()*1.98-1);
    }
    
    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}

void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        exit(0);
    }
}

void App::specialKeyPress(int key) {
    std::cout << "Pressed " << key << std::endl;
}
