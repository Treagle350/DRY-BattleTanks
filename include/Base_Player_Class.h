#pragma once
#include "Board.h"
#include "Tank_array.h"

namespace BattlingTanks{
class Base_Player_Class
{
    public:
        Base_Player_Class();
        virtual ~Base_Player_Class();
        //protected ?
        virtual Tank_array get_tank_array();
        void collect_the_fallen();
        virtual Board get_board();

    protected:
        int guesses;
        const int amount_of_tanks = 2;

        virtual void add_tank(int x, int y)=0;

        Board board;
        Tank_array tanks;

    private:
};
}

