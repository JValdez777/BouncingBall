//
// Created by Juan Valdez on 4/3/25.
//

#include "Ball.h"

Ball::Ball(float radius)
    : sf::CircleShape(radius)
{
    setPosition({1.f,1.f});
}
///Bounce function for object ball
/// param: takes in window size
/// will make sure to keep ball within given window size
void Ball::bounce(const sf::Vector2u &winSize)
{
    sf::Vector2f pos = getPosition();

    if (pos.x <= 0 || pos.x + getRadius() * 2 >= winSize.x)
    {
        velocity.x = -velocity.x;
    }
    if (pos.y <= 0 || pos.y + getRadius() * 2 >= winSize.y)
    {
        velocity.y = -velocity.y;
    }
    move(velocity);
}

///returns the ball objects velocity
const sf::Vector2f& Ball::getVelocity() const
{
    return velocity;
}

///sets the velocity for the ball object
void Ball::setVelocity(const sf::Vector2f& velocity)
{
    Ball::velocity = velocity;
}

