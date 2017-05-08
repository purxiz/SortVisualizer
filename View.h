#ifndef ELEMENT_H
#include <vector>
#include <iostream>
#include "steps.h"
#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

class View{
private:
  int size;
  float width, spacing;
public:
  View(const std::vector<int> &state){
    size = state.size();
    spacing = .1;
    width = 2 / (size + spacing * size * 2);
    spacing = width * spacing * 2;
  }
  void draw(const std::vector<int> &state, Step * step){
    for(int i = 0; i < size; i++){
      switch(step->getColor(i)){
        case WHITE:
          glColor3f(1.0, 1.0, 1.0);
        break;
        case GREEN:
          glColor3f(0.0, 1.0, 0.0);
        break;
        case YELLOW:
          glColor3f(0.0, 1.0, 1.0);
        break;
        case BLUE:
          glColor3f(0.0, 0.0, 1.0);
        break;
      }
      glRectf((i+1)*spacing + i*width - 1, -1,  (i+1)*spacing + i * width-1 + width, (float)state[i]/(float)size * 1.98);
    }
  }
};


#endif
