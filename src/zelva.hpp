#ifndef ZELVA
#define ZELVA

#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

#define INVALID_XY -99999
#define WND_WIDTH 544
#define WND_HEIGHT 416
#define DEFAULT_FONT "terminus.ttf"

#define SPEED 4

typedef void (*choice_handler)();
typedef void (*load_handler)();

enum GameObjectType {
    OBJECT_PLAYER,
    OBJECT_ENEMY,
    OBJECT_PLAYER_PROJECTILE
};

class GameObject {

    sf::Sprite obj_drawable;

    public:
        GameObjectType tip_objekta;
        

        GameObject ();
        ~GameObject ();

        void SetItem (sf::Sprite _obj);
        void SetCoor (int _x, int _y);
        void AddCoor (int _x, int _y);
        bool Draw ();
        virtual void Update ();

};

class GameText {

    sf::Text obj_text;

    public:

        bool enabled;

        GameText ();
        ~GameText ();

        void SetText (std::string txt);
        void SetItem (sf::Text _obj);
        void SetCoor (int _x, int _y);
        void SetColor (const sf::Color & col);
        bool Draw ();
        virtual void Update ();

};


struct EinChoice {
    char choice_txt[512];
    unsigned int x;
    unsigned int y;
    unsigned int font_size;
    choice_handler ch_hand;
};

class Choices {

    public:
        std::vector<EinChoice> vsi_cho;
        unsigned int selected;


        bool Draw ();
        void SelectUp ();
        void SelectDown ();
        void OnEnter ();
};

class Player : public GameObject {
    public:
        int walk_speed;
        bool can_move = true;
};

class World {

    public:
        std::vector<GameObject*> vsi_objekti;
        std::vector<GameText*> ves_tekst;
        Choices* current_cho;
        load_handler on_load;
        Player* main_player;


};

class Projectile : public GameObject {

    int speed_x;
    int speed_y;

    public:

        void SetSpeed (int _sx, int _sy);
        virtual void Update ();
};


bool LoadWorld (World*);
bool UnloadWorld (World*);

extern World current_world;
extern sf::RenderWindow main_window;
extern sf::Font arial_font;
extern sf::Color selected_color;
extern sf::Color normal_color;
extern sf::Sprite ensprite;

void wld_handler_1 ();

#endif //ZELVA