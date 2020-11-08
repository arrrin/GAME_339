#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
    animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    row = 0;
    faceRight = true;

    body.setSize(sf::Vector2f(100.0f, 100.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(67.0f, 872.0f);
    body.setTexture(texture);
}

Player::~Player()
{

}

void Player::Update(float deltaTime)
{
    sf::Vector2f movement(0.0f, 0.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        movement.x -= speed * deltaTime*5;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        movement.x += speed * deltaTime*5;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        movement.y -= speed * deltaTime*5;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        movement.y += speed * deltaTime*5;

    if (movement.x == 0 && movement.y == 0)
    {
        row = 0;
    }
    else
    {
        if (movement.y != 0)
        {
            row = 0;
            if (movement.y > 0.0f)
            {
                faceTop = false;
            }
            if (movement.y < 0.0f)
            {
                faceTop = true;
                row = 2;
            }
        }
        if (movement.x > 0.0f && movement.y == 0.0f)
        {
            row = 3;
            faceRight = true;
        }
        if (movement.x < 0 && movement.y == 0.0f)
        {
            row = 1;
            faceRight = true;
        }
    }
    animation.Update(row, deltaTime, faceRight);
    body.setTextureRect(animation.uvRect);
    body.move(movement);
}
void Player::Setposition(float x, float y) {
    body.setPosition(x, y);
}
void Player::Draw(sf::RenderWindow& window)
{
    window.draw(body);
}