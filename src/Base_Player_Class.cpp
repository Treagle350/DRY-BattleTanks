#include "Base_Player_Class.h"

namespace BattlingTanks{
Base_Player_Class::Base_Player_Class()
{

}

Base_Player_Class::~Base_Player_Class()
{
    //dtor
}
void Base_Player_Class::collect_the_fallen(){
    for(unsigned int i=0; i<tanks.tanks.size(); i++ ){
        if(tanks.tanks.at(i)->get_health() == 0){
            tanks.tanks.erase(tanks.tanks.begin()+(i-1));
        }
    }
}
Board Base_Player_Class::get_board()
{
    return board;
}
Tank_array Base_Player_Class::get_tank_array()
{
    return tanks;
}
}

