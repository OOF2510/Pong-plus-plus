#include "paddle2.h"
//constuctor, called when object is created
paddle2clockpaddle2(float startX, float startY)
{
    m_Position.x = startX;
    m_Position.y = startY;

    m_Shape.setSize(sf::Vector2f(50, 5));
    m_Shape.setPosition(m_Position);
}
//end of constructor
FloatRect paddle2::getPosition()
{
    return m_Shape.getGlobalBounds();
}

RectangleShape paddle2::getShape()
{
    return m_Shape;
}
void paddle2::moveLeft()
{
    m_MovingLeft = true;
}
void paddle2::moveRight()
{
    m_MovingRight = true;
}
void paddle2::stopLeft()
{
    m_MovingLeft = false;
}
void paddle2::stopRight()
{
    m_MovingRight = false;
}
void paddle2::update(Time dt)
{
    if (m_MovingLeft) {
        m_Position.x -= m_Speed * dt.asSeconds();
    }
    if (m_MovingRight) {
        m_Position.x += m_Speed * dt.asSeconds();
    }
    m_Shape.setPosition(m_Position);
}