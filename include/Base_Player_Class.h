#pragma once
#include "Board.h"
#include "Tank_array.h"

class Base_Player_Class
{
    public:
        Base_Player_Class();
        virtual ~Base_Player_Class();

    protected:
        int guesses;
        int amount_of_tanks;

        virtual Tank_array get_tank_array();
        void collect_the_fallen();
        virtual void add_tank(int x, int y)=0;
        virtual Board get_board();

        Board board;
        Tank_array tanks;

    private:
};

