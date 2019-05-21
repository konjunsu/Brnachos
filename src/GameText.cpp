#include "zelva.hpp"

/*
class GameText {

    sf::Text obj_text;

    public:

        GameText ();
        ~GameText ();

        void SetItem (sf::Text _obj);
        void SetCoor (int _x, int _y);
        bool Draw ();
        virtual void Update ();

};
*/

GameText::GameText () {
    enabled = true;
    obj_text.setPosition(sf::Vector2f(INVALID_XY, INVALID_XY));
    //current_world.ves_tekst.push_back (this);
}

GameText::~GameText () {
    //current_world.ves_tekst.erase(std::find(current_world.ves_tekst.begin(), current_world.ves_tekst.end(), this));
}

void GameText::SetItem (sf::Text _obj) {
    obj_text = _obj;
}

void GameText::SetCoor (int _x, int _y) {
    obj_text.setPosition(sf::Vector2f(_x, _y));
}

bool GameText::Draw () {
    if (!enabled) return false;
    if (obj_text.getPosition().x == INVALID_XY && obj_text.getPosition().y == INVALID_XY) return false;
    main_window.draw(obj_text);
}

void GameText::SetText (std::string txt) {
    obj_text.setString (txt);
}

void GameText::SetColor (const sf::Color & col) {
    obj_text.setColor (col);
}

void GameText::Update () {}