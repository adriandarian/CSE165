#include <iostream>
#include "App.h"

App* singleton;

void timer(int id){
    // This will get called every 16 milliseconds after
    // you call it once
    
    // If you want to manipulate the app in here
    // do it through the singleton pointer
    
    glutTimerFunc(16, timer, id);
}


App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){
    
    background = new TexRect("/Users/adarian/CSE165/Lab5/bg.png", -2, 1, 4, 2);
    background2 = new TexRect("/Users/adarian/CSE165/Lab5/bg.png", 2, 1, 4, 2);
    bobcat = new AnimatedRect("/Users/adarian/CSE165/Lab5/cat.png", 4, 2, 100, true, false, -0.04, -0.25, 0.8, 0.5);
    bobcat->playLoop();
    
    currentX = background->getX(), newX = currentX, diff = currentX;
}

void App::draw() {
    
    background->draw(0.0);
    background2->draw(0.0);
    bobcat->draw(1.0);
    
   // std::cout << "diff 1: " << newX_1 << "::: 2: " << newX_2 << std::endl;
   // std::cout << "newX 1: " << diff_1 << "::: 2: " << diff_2 << std::endl;
    
    float modi = 0.14;
    
    newX -= modi;
    diff += modi;
    background->setX(newX);
    background2->setX(0 - diff);
    
    if (!(diff < 2)) {
        background->setX(-2.0);
        background2->setX(0.0);
        diff = -2.0;
        newX = -2.0;
    }
}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
    }
}

App::~App(){
    std::cout << "Exiting..." << std::endl;
}
