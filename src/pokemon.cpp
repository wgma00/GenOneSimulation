#include "pokemon.h"
#include <vector>
#include <algorithm>

Pokemon::Pokemon(std::vector<Type*> types, std::vector<Move*> moves,
        std::vector<int*> stats, std::vector<int*> mods, Status status) {
    status_ = status;

    for (int i = 0; i < 5; i++) {
        types_.at(std::min(i, 1)) = types.at(std::min(i, 2));
        moves_.at(std::min(i, 3)) = moves.at(std::min(i, 3));
        mods_.at(std::min(i, 3)) = mods.at(std::min(i, 3));
        stats_.at(std::min(i, 4)) = stats.at(std::min(i, 4));
    }
}

Pokemon::~Pokemon() {

}

Type Pokemon::type1() {
    return types_.at(typeOrder.TYPE1);
}

Type Pokemon::type2() {
    return types_.at(typeOrder.TYPE2);
}

Move Pokemon::move1() {
    return moves_.at(moveOrder.MOVE1);
}

Move Pokemon::move2() {
    return moves_.at(moveOrder.MOVE2);
}

Move Pokemon::move3() {
    return moves_.at(moveOrder.MOVE3);
}

Move Pokemon::move4() {
    return moves_.at(moveOrder.MOVE4);
}

int Pokemon::hp() {
    return stats_.at(regStat.HP);
}

int Pokemon::atk() {
    return stats_.at(regStat.ATK);
}

int Pokemon::def() {
    return stats_.at(regStat.DEF);
}

int Pokemon::spc() {
    return stats_.at(regStat.SPC);
}

int Pokemon::spe() {
    return stats_.at(regStat.SPE);
}

int Pokemon::atkmod() {
    return mods_.at(modStat.ATK)
}

int Pokemon::defmod() {
    return mods_.at(modStat.DEF);
}

int Pokemon::spcmod() {
    return mods_.at(modStat.SPC);
}

int Pokemon::spemod() {
    return mods_.at(modStat.SPE);
}

Status Pokemon::status() {
    return status_;
}

bool Pokemon::confused() {
    return isConfused_;
}

void Pokemon::setType1(Type newType) {
    types_.at(typeOrder.TYPE1) = newType;
}

void Pokemon::setType2(Type newType) {
    types_.at(typeOrder.TYPE2) = newType;
}

void Pokemon::setMove1(Move newMove) {
    moves_.at(moveOrder.MOVE1) = newMove;
}

void Pokemon::setMove2(Move newMove) {
    moves_.at(moveOrder.MOVE2) = newMove;
}

void Pokemon::setMove3(Move newMove) {
    moves_.at(moveOrder.MOVE3) = newMove;
}

void Pokemon::setMove4(Move newMove) {
    moves_.at(moveOrder.MOVE4) = newMove;
}

void Pokemon::setHP(int newHP) {
    stats_.at(regStat.HP) = newHP;
}

void Pokemon::setAtk(int newAtk) {
    stats_.at(regStat.ATK) = newAtk;
}

void Pokemon::setDef(int newDef) {
    stats_.at(regStat.DEF) = newDef;
}

void Pokemon::setSpc(int newSpc) {
    stats_.at(regStat.SPC) = newSpc;
}

void Pokemon::setSpe(int newSpe) {
    stats_.at(regStat.SPE) = newSpe;
}

void Pokemon::setAtkMod(int newModAtk) {
    mods_.at(modStat.ATK) = newModAtk;
}

void Pokemon::setDefMod(int newModDef) {
    mods_.at(modStat.DEF) = newModDef;
}

void Pokemon::setSpcMod(int newModSpc) {
    mods_.at(modStat.SPC) = newModSpc;
}

void Pokemon::setSpeMod(int newModSpe) {
    mods_.at(modStat.SPE) = newModSpe;
}

void Pokemon::setStatus(Status newStatus) {
    status_ = newStatus;
}

void Pokemon::setConfusion(bool confusion) {
    isConfused_ = confusion;
}

void Pokemon::Attack(Pokemon pokemon, Move move) {
    
}

std::string Pokemon::ToString() {

}