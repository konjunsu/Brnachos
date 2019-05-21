#include "zelva.hpp"

bool LoadWorld (World* wld) {
    if (wld == NULL) return false;
    UnloadWorld (&current_world);
    current_world = *wld;
    if (wld->on_load != NULL) wld->on_load();
    return true;
}

bool UnloadWorld (World* wld) {
    for (int i=0; i<wld->vsi_objekti.size(); i++) {
        if (wld->vsi_objekti[i] != NULL) delete wld->vsi_objekti[i];
    }
    for (int i=0; i<wld->ves_tekst.size(); i++) {
        if (wld->ves_tekst[i] != NULL) delete wld->ves_tekst[i];
    }
    if (wld->current_cho != NULL) delete wld->current_cho;
    if (wld->main_player != NULL) delete wld->main_player;
    return true;
}