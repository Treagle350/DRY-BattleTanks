#include "player.h"

namespace BattlingTanks{
Player::Player()
{
    where_should_the_tanks_be_placed();
}
Player::~Player()
{
    //dtor
}
void Player::where_should_the_tanks_be_placed()
{
    get_board().display_grid();
    int x,y;
    for(int i = 0;i<amount_of_tanks;i++)
    {
        std::cout<<"Please enter the coordinates you would like tank #"<< i <<" to have :"<<std::endl;
        std::cout<<"x :";
        std::cin>>x;
        if(!(x>=0&&x<3)){
            std::cout<<"x should be between 0 and 2";
            std::cin>>x;
        }
        std::cout<<std::endl;
        std::cout<<"y :";
        std::cin>>y;
        if(!(y>=0&&y<3)){
            std::cout<<"y should be between 0 and 2";
            std::cin>>y;
        }
        std::cout<<std::endl;
        add_tank(x,y);
    }
}
void Player::add_tank(int x,int y)
{
    tanks.add_tank(x,y);
    player_board.change_tile(x,y,"[T]");
}
}
