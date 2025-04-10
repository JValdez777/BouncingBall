//
// Created by Juan Valdez on 4/3/25.
//

#include "Paddle.h"


// Paddle::Paddle()
// {
//
// }
//
// Paddle::Paddle(const sf::Vector2f& size)
// :sf::RectangleShape(size)
//
// {
//     setPosition({1.f,1.f});
// }
Paddle::Paddle()
{
    setSize({25.f,100.f});
}

///Event handler for paddle object, checking for window boundries and events
/// will move the paddle object up and down only
/// param: window and event
///
///
void Paddle::handleEvent(const sf::RenderWindow& window,const sf::Event& event)
{

}

void Paddle::handleEvent(const sf::RenderWindow& window)
{

        if (sf::Keyboard::isKeyPressed(_key1))
        {
            if (getPosition().y > 0)
                move({0.f,-7.f});
        }
        else if (sf::Keyboard::isKeyPressed(_key2))
        {
            if (getPosition().y + getGlobalBounds().size.y < window.getSize().y)
                move({0.f,7.f});
        }

}

///getting the velocity
const sf::Vector2f& Paddle::getVelocity() const
{
    return velocity;
}

///setting our paddles velocity
void Paddle::setVelocity(const sf::Vector2f& velocity)
{
    Paddle::velocity = velocity;
}
///setting key inputs for each player
///param: 2 keys that you want to correspond ot up and down respectively
/// sets the private variables in class to these keys for later use
void Paddle::setKeys(sf::Keyboard::Key key1,sf::Keyboard::Key key2)
{
    _key1 = key1;
    _key2 = key2;
}
