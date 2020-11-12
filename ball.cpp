#include "ball.h"
//consturctor
ball::ball(float startX, float startY)
{
    m_Position.x = startX;
    m_Position.y = startY;
    
    m_Shape.setSize(sf::Vector2f(10, 10));
    m_Shape.setPosition(m_Position);
}
//end of constructor
FloatRect ball::getPosition()
{
    return m_Shape.getGlobalBounds();
}
RectangleShape ball::getShape()
{
    return m_Shape;
}
float ball::getXVelocity()
{
    return m_DirectionX;
}
void ball::reboundSides()
{
    m_DirectionX = -m_DirectionX;
}
void ball::reboundTop()
{
    m_DirectionY = -m_DirectionY;
}
void ball::reboundPaddle()
{
    m_Position.y = 728;
    m_DirectionY = -m_DirectionY;
}
void ball::reboundBottom()
{
    m_Position.y = 0;
    m_Position.x = 500;
    m_DirectionY = -m_DirectionY;
}
void ball::update(Time dt)
{
    //update position
    m_Position.y += m_DirectionY * m_Speed * dt.asSeconds();
    m_Position.x += m_DirectionX * m_Speed * dt.asSeconds();

    //move ball
    m_Shape.setPosition(m_Position);
}