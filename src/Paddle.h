//
// Created by Juan Valdez on 4/3/25.
//

#ifndef PADDLE_H
#define PADDLE_H
#include "SFML/Graphics.hpp"



class Paddle : public sf::RectangleShape
{
private:
    sf::Keyboard::Key _key1,_key2;
    sf::Vector2f velocity = {1.f,1.f};

public:
    using sf::RectangleShape::RectangleShape;
    Paddle();
    // Paddle(const sf::Vector2f& size);
    void handleEvent(const sf::RenderWindow& window,const sf::Event& event);
    void handleEvent(const sf::RenderWindow& window);
    const sf::Vector2f& getVelocity() const;
    void setVelocity(const sf::Vector2f& velocity);

    //setter for keys
    void setKeys(sf::Keyboard::Key key1,sf::Keyboard::Key key2);
};



#endif //PADDLE_H
