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
   

}

void App::draw() {
    TexRect("./bg.png", 2, 2, 0.5, 0.5);

}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
    }
}

App::~App(){
    std::cout << "Exiting..." << std::endl;
}
