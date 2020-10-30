#include "Item.h"
#include<iostream>
Item::Item(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y) :
    animation(texture, imageCount, switchTime)
{
    row = 0;
    body.setSize(sf::Vector2f(35.0f, 44.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(x, y);
    body.setTexture(texture);

}

Item::~Item()
{
}

void Item::update(float deltaTime, Player player)
{
    animation.UpdateItem(row, deltaTime, faceRight);
    body.setTextureRect(animation.uvRect);

    if (player.GetCollision().CheckCollision(this->GetCollider())) {
        //Cstar++;
        body.setPosition(-1000.0f, 350.0f);
    }
}

void Item::draw(sf::RenderWindow& window)
{
    window.draw(body);
}