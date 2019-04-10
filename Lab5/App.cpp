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
    
    currentX_1 = background->getX(), newX_1 = currentX_1, diff_1 = currentX_1;
    currentX_2 = background2->getX(), newX_2 = currentX_2, diff_2 = currentX_2;
    
}

void App::draw() {
    background->draw(0.0);
    background2->draw(0.0);
    bobcat->draw(1.0);
    
    std::cout << diff_1 << std::endl;
    float modi = 0.14;
    
    if (diff_1 < 1.92 - 0.14) {
        newX_1 -= modi;
        background->setX(newX_1);
        diff_1 += modi;
        
        newX_2 -= modi;
        background2->setX(newX_2);
        diff_2 += modi;
    } else {
        background->setX(2.0);
        diff_1 = -2.0;
        newX_1 = 2.0;
        
        if (diff_2 > 1.92) {
            diff_2 = -2.0;
            newX_2 = 2.0;
            background2->setX(2.0);
        }
    }
}

App::~App(){
    std::cout << "Exiting..." << std::endl;
}
