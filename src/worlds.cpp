#include "zelva.hpp"

void wld_handler_1 () {
    Player* pl = new Player();
    pl->walk_speed = SPEED;
    pl->SetCoor(200, 100);
    pl->SetItem(ensprite);
    current_world.main_player = pl;
    current_world.main_player->SetCoor(200, 100);
    return;
}