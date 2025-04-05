//
// Created by Juan Valdez on 4/3/25.
//

#ifndef PADDLE_H
#define PADDLE_H
#include "SFML/Graphics.hpp"



class Paddle : public sf::RectangleShape
{
private:
    sf::Vector2f velocity = {1.f,1.f};

public:
    Paddle();
    Paddle(const sf::Vector2f& size);
    void handleEvent(const sf::RenderWindow& win,const sf::Event& event);
    const sf::Vector2f& getVelocity() const;
    void setVelocity(const sf::Vector2f& velocity);
};



#endif //PADDLE_H
