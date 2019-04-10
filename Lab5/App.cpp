#include <iostream>
#include "App.h"

App* singleton;

void timer(int id){
    // This will get called every 16 milliseconds after
    // you call it once
    
    // If you want to manipulate the app in here
    // do it through the singleton pointer
    
    singleton->background->setX(singleton->background->getX() + 0.01);
    singleton->redraw();
    glutTimerFunc(16, timer, id);
}


App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){
   background = new TexRect("./bg.png", -2, 1, 4, 2);
   bobcat = new AnimatedRect("./cat.png", 4, 2, 150, true, true, -0.04, -0.25, 0.8, 0.5);
}

void App::draw() {
    background->draw(0.0);
    bobcat->draw(1.0);
}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
    }
}

App::~App(){
    std::cout << "Exiting..." << std::endl;
}
