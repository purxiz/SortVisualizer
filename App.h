#ifndef App_hpp
#define App_hpp

#include "GlutApp.h"
#include "steps.h"
#include <vector>

class App: public GlutApp {
    // Maintain app state here
    std::vector<int> state;
    Step* step;
public:
    // Constructor, to initialize state
    App(const char* label, int x, int y, int w, int h);
    
    // These are the events we want to handle
    void draw();
    void keyPress(unsigned char key);
    void specialKeyPress(int key);
};

#endif
