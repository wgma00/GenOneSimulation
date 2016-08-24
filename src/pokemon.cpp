#include "../include/pokemon.h"
#include <vector>
#include <algorithm>

Pokemon::Pokemon(Pkmn name, std::vector<Type> types, std::vector<Move*> moves,
        std::vector<int> stats, std::vector<int> mods, Status status,
        int baseSpe) {
    this->types_.resize(2);
    this->moves_.resize(4);
    this->setName(name);
    // accounting for multiple types
    if((int)types.size() == 2){
        this->setType1(types[TYPE1]);
        this->setType2(types[TYPE2]);
    }
    else{
        this->setType1(types[TYPE1]);
    }
    // setting up moves, no need to error check since it should always be
    // four moves, right?
    this->setMove1(moves[MOVE1]);
    this->setMove2(moves[MOVE2]);
    this->setMove3(moves[MOVE3]);
    this->setMove4(moves[MOVE4]);
    // same deal wit these
    this->setHP(stats[HP]);
    this->setCurrentHP(stats[HP]);
    this->setAtk(stats[ATK]);
    this->setDef(stats[DEF]);
    this->setSpc(stats[SPC]);
    this->setSpe(stats[SPE]);
    // same deal with these
    this->setAtkMod(mods[MODATK]);
    this->setDefMod(mods[MODDEF]);
    this->setSpcMod(mods[MODSPC]);
    this->setSpeMod(mods[MODSPE]);
    this->setStatus(status);
    this->setBaseSpe(baseSpe);
    // these are just misceallanous intializations
    this->setConfusion(false);
    this->setRested(false);
    this->setParaMod(false);
    this->setClampTurns(0);
    this->setSleepTurns(0);
    this->setCounterDamage(0);
}

/**
 * Here we will parse a string in the following format: 
 * "Name,Type(s),HP,Attack,Defense,Special,Speed,Basespeed"
 **/
Pokemon::Pokemon(std::string data, std::vector<Move*>moves){
    std::stringstream ss(data);
    std::string field;
    Pkmn name = NULL_PKMN;
    std::vector<Type>types;
    std::vector<int>stats;
    std::vector<int>mods = {0,0,0,0};
    Status status = NONE;
    int baseSpe = 0;
    // here we will parse the 7 fields, taking into account fields with 
    // multiple paramaters like Type 
    for(int i = 0;i < 8;i++){
        getline(ss, field, ',');
        if(i == 0)
            name = to_pokemon(field);
        if(i == 1){
           if(field.find('|') == std::string::npos)
              types.push_back(to_type(field)); 
           else{
              int idx = field.find('|');
              std::cout << field.substr(0,idx) << std::endl;
              std::cout << field.substr(idx+1,field.size()-idx) << std::endl;
              types.push_back(to_type(field.substr(0,idx))); 
              types.push_back(to_type(field.substr(idx+1, field.size()-idx)));
           }
        }
        // HP, ATK, DEF, SPC, SPE
        if(i >= 2 && i <= 6)
            stats.push_back(atoi(field.c_str()));
        if(i ==  7)
            baseSpe = atoi(field.c_str()); 
    }
    Pokemon(name, types, moves, stats, mods, status, baseSpe);
}

Pokemon::~Pokemon() {

}

Type Pokemon::type1() {
    return this->types_[TYPE1];
}

Type Pokemon::type2() {
    return this->types_[TYPE2];
}

Move* Pokemon::move1() {
    return this->moves_[MOVE1];
}

Move* Pokemon::move2() {
    return this->moves_[MOVE2];
}

Move* Pokemon::move3() {
    return this->moves_[MOVE3];
}

Move* Pokemon::move4() {
    return this->moves_[MOVE4];
}

std::vector<Move*> Pokemon::getMoves() {
    return this->moves_;
}

int Pokemon::getHP() {
    return this->stats_[HP];
}

int Pokemon::getCurrentHP() {
    return this->currentHP_;
}

int Pokemon::getAtk() {
    return this->stats_[ATK];
}

int Pokemon::getDef() {
    return this->stats_[DEF];
}

int Pokemon::getSpc() {
    return this->stats_[SPC];
}

int Pokemon::getSpe() {
    return this->stats_[SPE];
}

int Pokemon::getAtkmod() {
    return this->mods_[ATK];
}

int Pokemon::getDefmod() {
    return this->mods_[DEF];
}

int Pokemon::getSpcmod() {
    return this->mods_[SPC];
}

int Pokemon::getSpemod() {
    return this->mods_[SPE];
}

Pkmn Pokemon::getName(){
    return this->name_;
}

Status Pokemon::getCondition() {
    return this->condition_;
}

bool Pokemon::isConfused() {
    return this->confused_;
}

bool Pokemon::isRested() {
    return this->rested_;
}

bool Pokemon::getParamod() {
    return this->paraMod_;
}

int Pokemon::getBasespe() {
    return this->baseSpe_;
}

int Pokemon::getClampturns() {
    return this->clampTurns_;
}

int Pokemon::getSleepturns() {
    return this->sleepTurns_;
}

int Pokemon::getCounterDamage() {
    return this->counterDamage_;
}

void Pokemon::setType1(Type newType) {
    this->types_[TYPE1] = newType;
}

void Pokemon::setType2(Type newType) {
    this->types_[TYPE2] = newType;
}

void Pokemon::setMove1(Move* newMove) {
    this->moves_[MOVE1] = newMove;
}

void Pokemon::setMove2(Move* newMove) {
    this->moves_[MOVE2] = newMove;
}

void Pokemon::setMove3(Move* newMove) {
    this->moves_[MOVE3] = newMove;
}

void Pokemon::setMove4(Move* newMove) {
    this->moves_[MOVE4] = newMove;
}

void Pokemon::setHP(int newHP) {
    this->stats_[HP] = newHP;
}

void Pokemon::setCurrentHP(int newCurrentHP) {
    this->currentHP_ = newCurrentHP;
}

void Pokemon::setAtk(int newAtk) {
    this->stats_[ATK] = newAtk;
}

void Pokemon::setDef(int newDef) {
    this->stats_[DEF] = newDef;
}

void Pokemon::setSpc(int newSpc) {
    this->stats_[SPC] = newSpc;
}

void Pokemon::setSpe(int newSpe) {
    this->stats_[SPE] = newSpe;
}

void Pokemon::setAtkMod(int newModAtk) {
    this->mods_[MODATK] = newModAtk;
}

void Pokemon::setDefMod(int newModDef) {
    this->mods_[MODDEF] = newModDef;
}

void Pokemon::setSpcMod(int newModSpc) {
    this->mods_[MODSPC] = newModSpc;
}
void Pokemon::setSpeMod(int newModSpe) {
    this->mods_[MODSPE] = newModSpe;
}

void Pokemon::setName(Pkmn name){
    this->name_ = name;
}

void Pokemon::setStatus(Status newStatus) {
    this->condition_ = newStatus;
}

void Pokemon::setConfusion(bool newConfusion) {
    this->confused_= newConfusion;
}

void Pokemon::setRested(bool newRested) {
    this->rested_ = newRested;
}

void Pokemon::setParaMod(bool newParaMod) {
    this->paraMod_ = newParaMod;
}

void Pokemon::setClampTurns(int newClampTurns) {
    this->clampTurns_ = newClampTurns;
}

void Pokemon::setSleepTurns(int newSleepTurns) {
    this->sleepTurns_ = newSleepTurns;
}

void Pokemon::setCounterDamage(int newCounterDamage) {
    this->counterDamage_ = newCounterDamage;
}

void Pokemon::setBaseSpe(int newBaseSpe) {
    this->baseSpe_ = newBaseSpe;
}

