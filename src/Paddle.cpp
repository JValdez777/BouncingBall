//
// Created by Juan Valdez on 4/3/25.
//

#include "Paddle.h"


Paddle::Paddle()
{

}

Paddle::Paddle(const sf::Vector2f& size)
:sf::RectangleShape(size)

{
    setPosition({1.f,1.f});
}

///Event handler for paddle object, checking for window boundries and events
/// will move the paddle object up and down only
/// param: window and event
///
void Paddle::handleEvent(const sf::RenderWindow& window,const sf::Event& event)
{

        if (event.is<sf::Event::KeyPressed>())
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
            {
                move(sf::Vector2f(0.f,-5.f));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
            {
                move(sf::Vector2f(0.f,5.f));
            }
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