#include "zelva.hpp"

/*

class Projectile : public GameObject {

    int speed_x;
    int speed_y;

    public:

        void SetSpeed (int _sx, int _sy);
        virtual void Update ();
};

*/

void Projectile::SetSpeed (int _sx, int _sy) {
    speed_x = _sx;
    speed_y = _sy;
}

void Projectile::Update () {
    AddCoor (speed_x, speed_y);
}