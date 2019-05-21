#include "zelva.hpp"

World current_world;


void GameObject::SetCoor (int _x, int _y) {
    obj_drawable.setPosition(sf::Vector2f(_x, _y));
    //obj_sprite.getPosition().y = _y;
}

GameObject::GameObject () {
    obj_drawable.setPosition(sf::Vector2f(INVALID_XY, INVALID_XY));
    //current_world.vsi_objekti.push_back(this);
}

GameObject::~GameObject () {
    //current_world.vsi_objekti.erase(std::find(current_world.vsi_objekti.begin(), current_world.vsi_objekti.end(), this));
}


bool GameObject::Draw () {
    if (obj_drawable.getPosition().x == INVALID_XY && obj_drawable.getPosition().y == INVALID_XY) return false;
    main_window.draw(obj_drawable);
}

void GameObject::SetItem (sf::Sprite _obj) {
    obj_drawable = _obj;
}

void GameObject::Update () {} //Default object has no specific update function

void GameObject::AddCoor (int _x, int _y) {
    sf::Vector2f cr = obj_drawable.getPosition();
    cr.x += _x;
    cr.y += _y;
    obj_drawable.setPosition(cr);
}