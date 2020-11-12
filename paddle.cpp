#include "paddle.h"
//constuctor, called when object is created
paddle::paddle(float startX, float startY)
{
    m_Position.x = startX;
    m_Position.y = startY;

    m_Shape.setSize(sf::Vector2f(50, 5));
    m_Shape.setPosition(m_Position);
}
//end of constructor
FloatRect paddle::getPosition()
{
    return m_Shape.getGlobalBounds();
}

RectangleShape paddle::getShape()
{
    return m_Shape;
}
void paddle::moveLeft()
{
    m_MovingLeft = true;
}
void paddle::moveRight()
{
    m_MovingRight = true;
}
void paddle::stopLeft()
{
    m_MovingLeft = false;
}
void paddle::stopRight()
{
    m_MovingRight = false;
}
void paddle::update(Time dt)
{
    if (m_MovingLeft) {
        m_Position.x -= m_Speed * dt.asSeconds();
    }
    if (m_MovingRight) {
        m_Position.x += m_Speed * dt.asSeconds();
    }
    m_Shape.setPosition(m_Position);
}