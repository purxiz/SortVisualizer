#include "App.h"
#include "shuffle.h"
#include "sorts.h"
#include <iostream>

// For srand and time
#include <cstdlib>
#include <ctime>

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h),quick(Replay(state)),heap(Replay(state)),insert(Replay(state)),
                                                  shell(Replay(state)),bubble(Replay(state)),comb(Replay(state)),slow(Replay(state)){
    // Initialize state variables
    std::srand(std::time(0));
    for(int i = 0; i < 40; i++){
      state.push_back(i+1);
    }
    shuffle(state);
    
    quick.getSteps().push_back(new Step());
    quickSort(Recorder(quick.getSteps(),state),0,state.size()-1);
    quick.gotoEnd();
    quick.reset();
    
    slow.getSteps().push_back(new Step());
    slowSort(Recorder(slow.getSteps(),state),0,state.size()-1);
    slow.gotoEnd();
    slow.reset();
    
    insert.getSteps().push_back(new Step());
    insertionSort(Recorder(insert.getSteps(),state),state.size());
    insert.gotoEnd();
    insert.reset();
    
    bubble.getSteps().push_back(new Step());
    bubbleSort(Recorder(bubble.getSteps(),state),state.size());
    bubble.gotoEnd();
    bubble.reset();
    
    comb.getSteps().push_back(new Step());
    combSort(Recorder(comb.getSteps(),state),state.size());
    comb.gotoEnd();
    comb.reset();
    
    shell.getSteps().push_back(new Step());
    shellSort(Recorder(shell.getSteps(),state),state.size());
    shell.gotoEnd();
    shell.reset();
    
    heap.getSteps().push_back(new Step());
    heapSort(Recorder(heap.getSteps(),state),state.size());
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
    
    
    float width = 2.0 / state.size();
    float spacing = 0.2*width;
    
    // Draw histogram
    for(int i = 0; i < state.size(); i++){
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
      glRectf(i*width-1+spacing/2, -1,  (i*width-1+spacing/2) + width-spacing, (float)state[i]/(float)state.size()*1.98-1);
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
    }else if(key == 27){
        // Exit the app when Esc key is pressed
        exit(0);
    }else{return;}
    redraw();
}

void App::specialKeyPress(int key) {
  if(key == 102){
    ++(*rep);
  }else if(key == 100){
    --(*rep);
  }
  redraw();
}
