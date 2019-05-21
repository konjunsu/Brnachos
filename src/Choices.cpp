#include "zelva.hpp"

bool Choices::Draw () {

    GameText* gt = NULL;
    for (int i=0; i<vsi_cho.size(); i++) {
        gt = new GameText ();
        gt->SetItem (sf::Text (vsi_cho[i].choice_txt, arial_font, vsi_cho[i].font_size));
        gt->SetCoor (vsi_cho[i].x, vsi_cho[i].y);
        if (i == selected) gt->SetColor (selected_color);
        else gt->SetColor (normal_color);
        gt->Draw ();
        delete gt;
    }

}

void Choices::SelectUp () {
    selected = (selected+vsi_cho.size()-1) % vsi_cho.size();
}

void Choices::SelectDown () {
    selected = (selected+1) % vsi_cho.size();
}

void Choices::OnEnter () {
    vsi_cho[selected].ch_hand();
}
