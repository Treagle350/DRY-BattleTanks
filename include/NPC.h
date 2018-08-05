#pragma once
#include "Base_Player_Class.h"

namespace BattlingTanks{
class NPC:public Base_Player_Class
{
    public:
        NPC();
        virtual ~NPC();

        void generate_enemy_tank();
        void collect_the_fallen();

    protected:

    private:

        void add_tank(int x, int y);

        const int tank_amount = 2;
};
}
