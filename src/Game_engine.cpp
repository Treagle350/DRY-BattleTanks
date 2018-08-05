#include "Game_engine.h"
#include <iostream>
#include <stdlib.h>
namespace BattlingTanks{

Game_engine::Game_engine()
{
    turns = 0;
    info_screen();
    Player *player = new Player();
    NPC *computer = new NPC();
}
Game_engine::~Game_engine()
{
    //dtor
}
void Game_engine::info_screen()
{
    std::cout << std::endl;
    std::cout << "Coordinates on the board range from 0 to 2" << std::endl;
    std::cout << "Coordinates are entered as following :" << std::endl;
    std::cout << "x : 2" << std::endl;
    std::cout << "y : 0" << std::endl;
    std::cout << "Whereas x represents the vertical columns of the board" << std::endl;
    std::cout << "And y represents the horizontal rows of the board" << std::endl;
    std::cout << std::endl;
}
void Game_engine::receive_damage(Projectile projectile,Base_Player_Class* entity)
{
    bool shot = false;
    int x = projectile.get_x();
    int y = projectile.get_y();
    for(int i = 0;i<entity->get_tank_array().tanks.size();i++){
        shot = entity->get_tank_array().tanks.at(i)->get_shot(x,y);
        if(shot){
            entity->collect_the_fallen();
            entity->get_board().change_tile(x,y,"[X]");
        }
    }
}
void Game_engine::win_screen()
{
    std::cout << "You won after " << turns << " turns ! " << std::endl;
}
void Game_engine::game_over()
{
    std::cout << "Game over, the battle lasted " << turns << " turns ! " << std::endl;
}
bool Game_engine::end_game()
{
    bool ended = false;
    if(player.get_tank_array().tanks.size()==0||computer.get_tank_array().tanks.size()==0){
        if(player.get_tank_array().tanks.size()==0){
            game_over();
            ended = true;
        }else{
            win_screen();
            ended = true;
        }
    }
    return ended;
}
void Game_engine::player_guess()
{
    turns = turns + 1;
    int x,y;
    for (int i = 0;i<player.get_tank_array().tanks.size();i++){
        std::cout<<"Please enter the coordinates you would like tank #"<< i <<" to fire at :"<<std::endl;
        std::cout<<"x :";
        std::cin>>x;
        if(!(x>=0&&x<3)){
            std::cout<<"x should be between 0 and 2"<<std::endl;
            std::cin>>x;
        }
        std::cout<<std::endl;
        std::cout<<"y :";
        std::cin>>y;
        if(!(y>=0&&y<3)){
            std::cout<<"y should be between 0 and 2"<<std::endl;
            std::cin>>y;
        }
        std::cout<<"Displaying computer's board"<<std::endl;
        guess(&computer,&player,x,y,i);
    }
}
void Game_engine::npc_guess()
{
    for (int i = 0;i<computer.get_tank_array().tanks.size();i++){
        int x = (rand()*10) % 3;
        int y = (rand()*10) % 3;
        std::cout<<"Displaying player's board"<<std::endl;
        guess(&player,&computer,x,y,i);
    }
}
void Game_engine::guess(Base_Player_Class* entity,Base_Player_Class* receiving_entity, int x, int y, int i)
{
    receiving_entity->get_board().change_tile(x,y,"[O]");
    receive_damage(entity->get_tank_array().tanks.at(i)->shoot(x,y),receiving_entity);
}
}
