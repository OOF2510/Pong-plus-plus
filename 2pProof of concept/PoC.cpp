#include "paddle.h"
#include "paddle2.h"
#include "paddle.cpp"
#include "paddle2.cpp"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;
//main function
int main()
{
    //create video mode
    VideoMode vm(480, 480);

    //create window
    RenderWindow window(vm, "2pPoC", Style::Fullscreen);
    
    //position paddles
    paddle paddle(480 / 2, 460);
    paddle2 paddle2(480 / 2, 20);
    
    //window loop
    while (window.isOpen())
    {
      /*
      ***************************
      *       Handle input      *
      ***************************
      */
      Event event;
       while (window.pollEvent(event))
       {
           if (event.type == Event::Closed)
           //quit game when window closed
           window.close();
       }
       //close window
       if (Keyboard::isKeyPressed(Keyboard::Escape))
       {
           window.close();
       }
       //move
       if (Keyboard::isKeyPressed(Keyboard::Left))
       {
           paddle.moveLeft();
       }
       else
       {
           paddle.stopLeft();
       }

       if (Keyboard::isKeyPressed(Keyboard::Right))
       {
           paddle.moveRight();
       }
       else
       {
           paddle.stopRight();
       }
       //p2move
       if (Keyboard::isKeyPressed(Keyboard:D))
       {
         paddle2.moveLeft();
       }
       else
       {
         paddle2.stopLeft();
       }
       
       if (Keyboard::isKeyPressed(Keyboard::A))
       {
         paddle2.moveRight();
       }
       else
       {
         paddle2.stopRight();
       }
       /*
       ***************************
       *          Update         *
       ***************************
       */
        //Update the delta time
        Time dt = clock.restart();
        paddle.update(dt);
        paddle2.update(dt);
        ball.update(dt);
        /*
        **************************
        *         Render         *
        **************************
        */
        window.clear();
        window.draw(paddle.getShape());
        window.draw(paddle2.getShape());
        window.display();
    }
    return 0;
}