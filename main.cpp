#include "paddle.h"
#include "paddle.cpp"
#include "ball.h"
#include "ball.cpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;
//main function
int main()
{
    //create video mode
    VideoMode vm(1366, 768);

    //create window
    RenderWindow window(vm, "Pong++", Style::Fullscreen);


    int score = 0;
    int hiScore;
    int lives = 3;

    //create paddle at bottom center
    paddle paddle(1366 / 2, 768 - 20);

    //create ball
    ball ball(1366 / 2, 0);

    //prepare sound
    SoundBuffer musicBuffer;
    musicBuffer.loadFromFile("assets/sounds/music.wav");
    Sound music;
    music.setBuffer(musicBuffer);

    SoundBuffer lostlifeBuffer;
    lostlifeBuffer.loadFromFile("assets/sounds/lostlife.wav");
    Sound lostlife; 
    lostlife.setBuffer(lostlifeBuffer);
    
    SoundBuffer farBuffer;
    farBuffer.loadFromFile("assets/sounds/Far.wav");
    Sound far;
    far.setBuffer(farBuffer);

    //create text object named hud
    Text hud;

    //select font
    Font font;
    font.loadFromFile("assets/fonts/DS-DIGI.TTF");
    hud.setFont(font);

    //make text big
    hud.setCharacterSize(75);

    //choose a color
    hud.setFillColor(Color::Blue);

    //set position of text
    hud.setPosition(20, 20);

    //Load high score from file
    std::ifstream inputFile("data/highscore.txt");
    if (inputFile.is_open())
    {
        // >> reads data
        inputFile >> hiScore;
        inputFile.close();
    }
    
    
    //clock
    Clock clock;

    //window loop
    while (window.isOpen())
    {
        /*
        Handle the player input
        ****************************
        ****************************
        ****************************
        */
       Event event;
       while (window.pollEvent(event))
       {
           if (event.type == Event::Closed)
           //quit game when window closed
           window.close();
       }
       //quit
       if (Keyboard::isKeyPressed(Keyboard::Escape))
       {
           //update high score
            // << writes data
            //set outputfile
            std::ofstream outputFile("data/highscore.txt");
            outputFile << hiScore;
            outputFile.close();
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
       //music
       if (Keyboard::isKeyPressed(Keyboard::M))
       {
           far.setVolume(0);
           far.stop();
           music.setVolume(100);
           music.setLoop(true);
           music.play();
       }
       if (Keyboard::isKeyPressed(Keyboard::F2))
       {
           music.setVolume(0);
           music.stop();
           far.setVolume(100);
           far.setLoop(true);
           far.play();
       }
       if (Keyboard::isKeyPressed(Keyboard::F3))
       {
           music.setVolume(50);
           music.setLoop(true);
           music.play();
           far.setVolume(50);
           far.setLoop(true);
           far.play();
       }
       if (Keyboard::isKeyPressed(Keyboard::N))
       {
           music.setVolume(0);
           music.stop();
           far.setVolume(0);
           far.stop();
       }

       /*
       Update the paddle, the ball and HUD
       ****************************
       ****************************
       ****************************
       */
        //Update the delta time
        Time dt = clock.restart();
        paddle.update(dt);
        ball.update(dt);
        //Update the HUD text
        std::stringstream ss;
        ss << "Score:" << score << " Lives:" << lives << " Highscore:" << hiScore;
        hud.setString(ss.str());

        //ball collisions
        if (ball.getPosition().top > window.getSize().y)
        {
            //reverse
            ball.reboundBottom();

            //remove life
            lives--;

            //zero lives?
            if (lives < 1) {
                //reset score
                score = 0;
                lives = 3;
                //set high score back to file
            inputFile >> hiScore;
            inputFile.close();
            }
        }
        if (ball.getPosition().top < 0)
        {
            ball.reboundTop();
        }
        if (ball.getPosition().left < 0 ||
            ball.getPosition().left + ball.getPosition().width > window.getSize().x)
            {
                ball.reboundSides();
            }
            if (ball.getPosition().intersects(paddle.getPosition()))
            {
                //reverse ball and score point
                ball.reboundPaddle();
                score++;
            }
            if (score >= hiScore)
            {
                hiScore = score;
            }
            
      /*
      Draw the paddle, the ball and the HUD
      ****************************
      ****************************
      ****************************
      */
     window.clear();
     window.draw(hud);
     window.draw(paddle.getShape());
     window.draw(ball.getShape());
     window.display();
    }
    return 0;
}
