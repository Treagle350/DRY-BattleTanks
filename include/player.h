#pragma once
#include "Board.h"
#include "Tank_array.h"
#include "Base_Player_Class.h"
#include <vector>

namespace BattlingTanks{
class Player:public Base_Player_Class
{
    public:
        Player();
        virtual ~Player();
        void add_tank(int x,int y);
        Tank_array get_tank_array();
        void collect_the_fallen();

        Board get_board();

    protected:

    private:
        void where_should_the_tanks_be_placed();
};
}
