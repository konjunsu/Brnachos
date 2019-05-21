#include "zelva.hpp"

sf::RenderWindow main_window(sf::VideoMode(WND_WIDTH, WND_HEIGHT), "Zelva");
sf::Font arial_font;
float fps;


//Directions
sf::Vector2f up(0, 1), down(0, -1), left(-1, 0), right(1, 0);


World new_world;    
sf::Sprite ensprite;
GameText* fps_counter;
GameObject* player;
GameText* game_text;// = new GameText();
sf::Color selected_color = sf::Color(175, 0, 0);
sf::Color normal_color = sf::Color(255, 255, 255);

void title_start ();
void title_load ();
void title_end ();

void MainGameThread () {
    sf::Event mainwnd_event;

    while (main_window.isOpen()) {
        


        while (main_window.pollEvent (mainwnd_event)) {
            if (mainwnd_event.type == sf::Event::Closed) main_window.close();
            if (mainwnd_event.type == sf::Event::KeyPressed) {

                switch (mainwnd_event.key.code) {

                    case sf::Keyboard::Up: {
                        if (current_world.current_cho != NULL) {
                            current_world.current_cho->SelectUp();
                            break;
                        }
                        /*if (current_world.main_player != NULL) {
                            current_world.main_player->AddCoor(0, -current_world.main_player->walk_speed);
                            break;
                        }*/
                        break;
                    }

                    case sf::Keyboard::Down: {
                        if (current_world.current_cho != NULL) {
                            current_world.current_cho->SelectDown();
                            break;
                        }
                        /*if (current_world.main_player != NULL) {
                            current_world.main_player->AddCoor(0, current_world.main_player->walk_speed);
                            break;
                        }       */                 
                        break;
                    }

                    case sf::Keyboard::Return: {
                        if (current_world.current_cho != NULL) {
                            current_world.current_cho->OnEnter();
                            break;
                        }
                        break;
                    }

                    /*case sf::Keyboard::Left: {
                        if (current_world.main_player != NULL) {
                            current_world.main_player->AddCoor(-current_world.main_player->walk_speed, 0);
                            break;
                        }
                        break;
                    }

                    case sf::Keyboard::Right: {
                        if (current_world.main_player != NULL) {
                            current_world.main_player->AddCoor(current_world.main_player->walk_speed, 0);
                            break;
                        }
                        break;
                    }
                    /*case sf::Keyboard::Escape: {
                        fps_counter->enabled = !fps_counter->enabled;
                        break;
                    }

                    case sf::Keyboard::Space: {
                        GameObject* proj = new GameObject ();
                        proj->SetItem()
                        break;
                    }

                    case sf::Keyboard::Left: {
                        player->AddCoor (-SPEED, 0);
                        break;
                    }

                    case sf::Keyboard::Right: {
                        player->AddCoor (SPEED, 0);
                        break;
                    }*/
                }

            }
                
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            if (current_world.main_player != NULL && current_world.main_player->can_move) {
                current_world.main_player->AddCoor(-current_world.main_player->walk_speed, 0);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            if (current_world.main_player != NULL && current_world.main_player->can_move) {
                current_world.main_player->AddCoor(current_world.main_player->walk_speed, 0);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            if (current_world.main_player != NULL && current_world.main_player->can_move) {
                current_world.main_player->AddCoor(0, -current_world.main_player->walk_speed);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            if (current_world.main_player != NULL && current_world.main_player->can_move) {
                current_world.main_player->AddCoor(0, current_world.main_player->walk_speed);
            }
        }


        main_window.clear();

        if (current_world.current_cho != NULL) current_world.current_cho->Draw();
        if (current_world.main_player != NULL) current_world.main_player->Draw();
        //Loop
        for (int i=0; i<current_world.vsi_objekti.size(); i++) {
            //current_world.vsi_objekti[i]->SetCoor(rand() % 400 + 50, rand() % 350 + 50);            
            current_world.vsi_objekti[i]->Draw();
        }
        for (int i=0; i<current_world.ves_tekst.size(); i++) {
            current_world.ves_tekst[i]->Draw();
        }


        main_window.display();
        sf::sleep (sf::milliseconds(20));
    }

}

/*void MovingThread () {
    sf::Clock clock;
    float lastTime;
    char strps[16];
    while (true) {
        /*for (int i=0; i<current_world.vsi_objekti.size(); i++) {
            current_world.vsi_objekti[i]->SetCoor(rand() % 400 + 50, rand() % 350 + 50);            
        }
        float currentTime = clock.restart().asSeconds();
        //printf ("Diff is %f, %f\n", currentTime, lastTime);
        fps = 60.0f - ((currentTime - 1.0f)*60);
        if (fps < 0.0f) fps = 0.0f;
        lastTime = currentTime;
        sprintf (strps, "%.2f FPS", fps);
        fps_counter->SetText (strps);

        sf::sleep (sf::seconds(1));
    }
}*/

int main () {

    printf ("Initializing objects ... \n");
    sf::Texture tex;
    tex.loadFromFile ("brnachos.png");
    ensprite.setTexture (tex);
    /*GameObject* game_object = new GameObject ();
    GameObject *g1, *g2, *g3, *g4, *g5;
    game_object->SetItem (ensprite);*/
    //game_object->SetCoor (200, 200);
    printf ("Initializing graphics ... \n");
    /*g1 = new GameObject ();
    g2 = new GameObject ();
    g3 = new GameObject ();
    g4 = new GameObject ();
    g5 = new GameObject ();
    g1->SetItem (ensprite);
    g2->SetItem (ensprite);
    g3->SetItem (ensprite);
    g4->SetItem (ensprite);
    g5->SetItem (ensprite);*/
    /*player = new GameObject ();
    player->SetItem (ensprite);
    player->SetCoor ((WND_WIDTH - 32) / 2, WND_HEIGHT - 32);
    fps_counter = new GameText ();
    fps_counter->SetItem (sf::Text ("FPS", arial_font, 16));
    fps_counter->SetCoor (0, 0);*/
    if (!arial_font.loadFromFile("terminus.ttf")) {
        printf ("err\n");
    }
    game_text = new GameText();
    game_text->SetItem (sf::Text ("", arial_font, 16));
    game_text->SetCoor (0, 350);
    game_text->SetColor (sf::Color (255, 0, 0));
    current_world.ves_tekst.push_back (game_text);

    GameObject* brnachos_pic = new GameObject();
    brnachos_pic->SetItem(ensprite);
    brnachos_pic->SetCoor(150, 100);
    current_world.vsi_objekti.push_back(brnachos_pic);


    //Title screen
    GameText* title_txt = new GameText();
    title_txt->SetItem (sf::Text ("Brnachos", arial_font, 32));
    title_txt->SetCoor (200, 10);
    title_txt->SetColor (sf::Color (0, 175, 0));
    current_world.ves_tekst.push_back (title_txt);


    Choices* cho = new Choices ();
    EinChoice ec = {"Start", 100, 100, 16, title_start};
    cho->vsi_cho.push_back (ec);
    ec = (EinChoice){"Load", 100, 150, 16, title_load};
    cho->vsi_cho.push_back (ec);
    ec = (EinChoice){"End", 100, 200, 16, title_end};
    cho->vsi_cho.push_back (ec);
    current_world.current_cho = cho;

    //fps_counter->enabled = false;

    //sf::Thread* moving_thread = new sf::Thread(MovingThread);
    sf::Thread* main_game_thread = new sf::Thread(MainGameThread);
    main_game_thread->launch();
    //moving_thread->launch();
    main_game_thread->wait();
    //moving_thread->terminate();
    return 0;
}

void title_end () {
    exit (0);
}

void title_start () {
    //game_text->SetText ("No game to start!");
    new_world.on_load = wld_handler_1;
    LoadWorld (&new_world);
    return;
}

void title_load () {
    game_text->SetText ("No file to load!");
}