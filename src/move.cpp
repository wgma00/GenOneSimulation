#include "../include/move.h"

Move::Move(){}

Move::Move(std::string data){
    std::stringstream ss(data);
    std::string str;
    for(int i = 0;i < 11;i++){
        std::getline(ss, str, ',');
        switch(i){
            case 0:this->set_name(str); break; 
            case 1:this->set_accuracy(atoi(str.c_str())); break; 
            case 2:this->set_base_power(atoi(str.c_str())); break; 
            case 3:this->set_category(str); break; 
            case 4:this->set_pp(atoi(str.c_str())); break; 
            case 5:this->set_self_inflected_status(str); break; 
            case 6:this->set_volatile_status(str); break; 
            case 7:this->set_volatile_status_chance(str); break; 
            case 8:this->set_boosts(str); break; 
            case 9:this->set_heal(str); break; 
            case 10:this->set_type(str); break; 
        } 
    }
}
Move::~Move(){

}

std::string Move::get_name(){
    return this->name;
}
void Move::set_name(std::string name){
    this->name = name;
}

int Move::get_accuracy(){
    return this->accuracy;
}
void Move::set_accuracy(int accuracy){
    this->accuracy = accuracy;
}

int Move::get_base_power(){
    return this->base_power;
}
void Move::set_base_power(int base_power){
    this->base_power = base_power;
}

std::string Move::get_category(){
    return this->category;
}
void Move::set_category(std::string category){
    this->category = category;
}

int Move::get_pp(){
    return this->pp;
}
void Move::set_pp(int pp){
    this->pp = pp;
}

std::string Move::get_self_inflected_status(){
    return this->self_inflected_status;
}
void Move::set_self_inflected_status(std::string self_inflected_status){
    this->self_inflected_status = self_inflected_status;
}

std::string Move::get_volatile_status(){
    return this->volatile_status;
}
void Move::set_volatile_status(std::string volatile_status){
    this->volatile_status = volatile_status;
}

std::string Move::get_volatile_status_chance(){
    return this->volatile_status_chance;
}
void Move::set_volatile_status_chance(std::string volatile_status_chance){
    this->volatile_status_chance = volatile_status_chance;
}

std::string Move::get_boosts(){
    return this->boosts;
}
void Move::set_boosts(std::string boosts){
    this->boosts = boosts;
}


std::string Move::get_heal(){
    return this->heal;
}
void Move::set_heal(std::string heal){
    this->heal = heal;
}

std::string Move::get_type(){
    return this->type;
}
void Move::set_type(std::string type){
    this->type = type;
}
