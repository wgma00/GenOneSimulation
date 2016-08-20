#include "../include/pokemon.h"
#include <vector>
#include <algorithm>

Pokemon::Pokemon(Pkmn name, std::vector<Type> types, std::vector<Move> moves,
        std::vector<int> stats, std::vector<int> mods, Status status) {
    this->condition = status;
    this->name = name;

    for (int i = 0; i < 5; i++) {
        this->types.at(std::min(i, 1)) = types.at(std::min(i, 2));
        this->moves.at(std::min(i, 3)) = moves.at(std::min(i, 3));
        this->mods.at(std::min(i, 3)) = mods.at(std::min(i, 3));
        this->stats.at(std::min(i, 4)) = stats.at(std::min(i, 4));
    }
}

Pokemon::~Pokemon() {

}

Type Pokemon::type1() {
    return this->types.at(TYPE1);
}

Type Pokemon::type2() {
    return this->types.at(TYPE2);
}

Move Pokemon::move1() {
    return this->moves.at(MOVE1);
}

Move Pokemon::move2() {
    return this->moves.at(MOVE2);
}

Move Pokemon::move3() {
    return this->moves.at(MOVE3);
}

Move Pokemon::move4() {
    return this->moves.at(MOVE4);
}

int Pokemon::hp() {
    return this->stats.at(HP);
}

int Pokemon::atk() {
    return this->stats.at(ATK);
}

int Pokemon::def() {
    return this->stats.at(DEF);
}

int Pokemon::spc() {
    return this->stats.at(SPC);
}

int Pokemon::spe() {
    return this->stats.at(SPE);
}

int Pokemon::atkmod() {
    return this->mods.at(ATK);
}

int Pokemon::defmod() {
    return this->mods.at(DEF);
}

int Pokemon::spcmod() {
    return this->mods.at(SPC);
}

int Pokemon::spemod() {
    return this->mods.at(SPE);
}

Status Pokemon::status() {
    return this->condition;
}

Pkmn Pokemon::name(){
    return this->name;
}

bool Pokemon::confused() {
    return this->isConfused;
}

void Pokemon::setType1(Type newType) {
    this->types.at(TYPE1) = newType;
}

void Pokemon::setType2(Type newType) {
    this->types.at(TYPE2) = newType;
}

void Pokemon::setMove1(Move newMove) {
    this->moves.at(MOVE1) = newMove;
}

void Pokemon::setMove2(Move newMove) {
    this->moves.at(MOVE2) = newMove;
}

void Pokemon::setMove3(Move newMove) {
    this->moves.at(MOVE3) = newMove;
}

void Pokemon::setMove4(Move newMove) {
    this->moves.at(MOVE4) = newMove;
}

void Pokemon::setHP(int newHP) {
    this->stats.at(HP) = newHP;
}

void Pokemon::setAtk(int newAtk) {
    this->stats.at(ATK) = newAtk;
}

void Pokemon::setDef(int newDef) {
    this->stats.at(DEF) = newDef;
}

void Pokemon::setSpc(int newSpc) {
    this->stats.at(SPC) = newSpc;
}

void Pokemon::setSpe(int newSpe) {
    this->stats.at(SPE) = newSpe;
}

void Pokemon::setAtkMod(int newModAtk) {
    this->mods.at(MODATK) = newModAtk;
}

void Pokemon::setDefMod(int newModDef) {
    this->mods.at(MODDEF) = newModDef;
}

void Pokemon::setSpcMod(int newModSpc) {
    this->mods.at(MODSPC) = newModSpc;
}

void Pokemon::setSpeMod(int newModSpe) {
    this->mods.at(MODSPE) = newModSpe;
}

void Pokemon::setStatus(Status newStatus) {
    this->condition = newStatus;
}

void Pokemon::setConfusion(bool confusion) {
    this->isConfused = confusion;
}

void Pokemon::setName(Pkmn name){
    this->name = name;
}

std::string Pokemon::ToString() {

}
