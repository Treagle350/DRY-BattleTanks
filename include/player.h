#pragma once
#include "Base_Player_Class.h"
#include <vector>

namespace BattlingTanks{
class Player:public Base_Player_Class
{
    public:
        Player();
        virtual ~Player();
        void add_tank(int x,int y);

    protected:

    private:
        void where_should_the_tanks_be_placed();
};
}
