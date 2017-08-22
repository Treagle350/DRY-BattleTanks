#include "NPC.h"
#include <stdlib.h>

namespace BattlingTanks{
NPC::NPC()
{
    std::cout<<"Constructing npc"<<std::endl;
    for(int i = 0;i<tank_amount;i++){
        generate_enemy_tank();
        std::cout<<"Generating enemy tank #"<<i<<std::endl;
    }
}
NPC::~NPC()
{
    //dtor
}
void NPC::generate_enemy_tank()
{
    int subX = 0 + ((rand()*10) % 3);
    int subY = 0 + ((rand()*10) % 3);
    std::cout<<"x:"<<subX<<"y:"<<subY<<std::endl;
    add_tank(subX,subY);
}
void NPC::add_tank(int x,int y){
    tanks.add_tank(x,y);
    npc_board.change_tile(x,y,"[.]");
}
}
