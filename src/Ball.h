//
// Created by Juan Valdez on 4/3/25.
//

#ifndef BALL_H
#define BALL_H
#include "SFML/Graphics.hpp"



class Ball : public sf::CircleShape
{
private:
    sf::Vector2f velocity = {1.f,1.f};
    //using sf::CircleShape::scale; //moves scale from public to private
public:
    /// moves parent constructors to child
    //using sf::CircleShape::CircleShape; ///one way to call all the constructors from circle shape instead of making own
    Ball(float radius);
    Ball();
    void bounce(const sf::Vector2u& winSize);

    const sf::Vector2f& getVelocity() const;

    void setVelocity(const sf::Vector2f& velocity);


};



#endif //BALL_H
