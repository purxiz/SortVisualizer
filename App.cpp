#include "App.h"
#include "shuffle.h"
#include "sorts.h"
#include <iostream>
#include <string>
#include <sstream>

// For srand and time
#include <cstdlib>
#include <ctime>

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h),quick(Replay(state, "Quick Sort")),heap(Replay(state, "Heap Sort")),insert(Replay(state, "Insertion Sort")),
                                                  shell(Replay(state, "Shell Sort")),bubble(Replay(state, "Bubble Sort")),comb(Replay(state, "Comb Sort")),slow(Replay(state, "Slow Sort")),speed(0),counter(0){
    // Initialize state variables
    std::srand(std::time(0));
    for(int i = 0; i < 50; i++){
      state.data.push_back(i+1);
    }
    shuffle(state.data);

    quick.getSteps().push_back(new Step());
    quickSort(Recorder(quick.getSteps(),state),0,state.data.size()-1);
    quick.gotoEnd();
    quick.reset();

    slow.getSteps().push_back(new Step());
    slowSort(Recorder(slow.getSteps(),state),0,state.data.size()-1);
    slow.gotoEnd();
    slow.reset();

    insert.getSteps().push_back(new Step());
    insertionSort(Recorder(insert.getSteps(),state),state.data.size());
    insert.gotoEnd();
    insert.reset();

    bubble.getSteps().push_back(new Step());
    bubbleSort(Recorder(bubble.getSteps(),state),state.data.size());
    bubble.gotoEnd();
    bubble.reset();

    comb.getSteps().push_back(new Step());
    combSort(Recorder(comb.getSteps(),state),state.data.size());
    comb.gotoEnd();
    comb.reset();

    shell.getSteps().push_back(new Step());
    shellSort(Recorder(shell.getSteps(),state),state.data.size());
    shell.gotoEnd();
    shell.reset();

    heap.getSteps().push_back(new Step());
    heapSort(Recorder(heap.getSteps(),state),state.data.size());
    heap.gotoEnd();
    heap.reset();

    rep = &quick;
}

void App::draw() {

    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //draw number
    glColor3f(1.0,1.0,1.0);
    glRasterPos2f( -.95, .9);
    //std::cout << state.step << std::endl;

    std::stringstream s;
    s <<  "step " << state.step << "/" << rep->getSteps().size() << "   " << rep->name << "   Speed " << speed;
    std::string pos = s.str();
    for(int i = 0; i < pos.length(); i++){
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, pos[i]);
    }

    float width = 2.0 / state.data.size();
    float spacing = 0.2*width;

    // Draw histogram
    for(int i = 0; i < state.data.size(); i++){
      switch(rep->step()->getColor(i)){
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
      glRectf(i*width-1+spacing/2, -1,  (i*width-1+spacing/2) + width-spacing, (float)state.data[i]/(float)state.data.size()*1.8-1);
    }

    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}

void App::keyPress(unsigned char key) {
    if(key == 'h'){
      rep->reset();
      rep = &heap;
    }else if(key == 's'){
      rep->reset();
      rep = &slow;
    }else if(key == 'q'){
      rep->reset();
      rep = &quick;
    }else if(key == 'i'){
      rep->reset();
      rep = &insert;
    }else if(key == 'l'){
      rep->reset();
      rep = &shell;
    }else if(key == 'b'){
      rep->reset();
      rep = &bubble;
    }else if(key == 'c'){
      rep->reset();
      rep = &comb;
    }else if(key == '['){
      speed--;
    }else if(key == ']'){
      speed++;
    }else if(key == '-'){
      speed-=10;
    }else if(key == '='){
      speed+=10;
    }else if(key == 'r'){
      speed = 0;
    }else if(key == 27){
        // Exit the app when Esc key is pressed
        exit(0);
    }else{
      return;
    }

    redraw();
}

void App::specialKeyPress(int key) {
  if (speed != 0) return;
  if(key == 103){
    ++(*rep);++(*rep);
    ++(*rep);++(*rep);
    ++(*rep);++(*rep);
    ++(*rep);
  }else if(key == 102){
    ++(*rep);
  }else if(key == 101){
    --(*rep);--(*rep);
    --(*rep);--(*rep);
    --(*rep);--(*rep);
    --(*rep);
  }else if(key == 100){
    --(*rep);
  }

  redraw();
}


void App::idle(){
  /*if(play && speed > 0 && (counter = (counter + 1) % speed) == 0) ++(*rep);
  if(play && speed < 0 && (counter = counter + 1) % -speed == 0) --(*rep);*/
if(speed != 0){
  counter+= speed;
  while(counter > 10){
    ++(*rep);
    counter -= 10;
  }
  while(counter < -10){
    --(*rep);
    counter += 10;
  }
  redraw();
}
}
