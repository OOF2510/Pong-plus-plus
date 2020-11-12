#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class ball
{
private:
    Vector2f m_Position;
    RectangleShape m_Shape;

    float m_Speed = 1000.0f;
    float m_DirectionX = .2f;
    float m_DirectionY = .2f;

public:
    ball(float startX, float startY);
    FloatRect getPosition();
    RectangleShape getShape();
    float getXVelocity();
    void reboundSides();
    void reboundTop();
    void reboundPaddle();
    void reboundBottom();
    void update(Time dt);
};