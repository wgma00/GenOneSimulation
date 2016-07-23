#include "pokemon.h"

Pokemon::Pokemon() {

}

Pokemon::Pokemon(Type *types, Move *moves, int *stats, int *mods,
        Status status) {

}

Pokemon::~Pokemon() {

}

Type Pokemon::type1() {
    return type1;
}

Type Pokemon::type2() {
    return type2;
}

Move Pokemon::move1() {
    return moves[0];
}

Move Pokemon::move2() {
    return moves[1];
}

Move Pokemon::move3() {
    return moves[2];
}

Move Pokemon::move4() {
    return moves[3];
}

int Pokemon::hp() {
    return hp;
}

int Pokemon::atk() {
    return atk;
}

int Pokemon::def() {
    return def;
}

int Pokemon::spc() {
    return spc;
}

int Pokemon::spe() {
    return spe;
}

int *Pokemon::mods() {
    return mods;
}

Status Pokemon::status() {
    return status;
}

bool Pokemon::confused() {
    return isConfused;
}

void Pokemon::setType1(Type newType) {
    type1 = newType;
}

void Pokemon::setType2(Type newType) {
    type2 = newType;
}

void Pokemon::setHP(int newHP) {
    stats[regStat.HP] = newHP;
}

void Pokemon::setAtk(int newAtk) {
    stats[regStat.ATK] = newHP;
}

void Pokemon::setDef(int newDef) {
    stats[regStat.DEF] = newHP;
}

void Pokemon::setSpc(int newSpc) {
    stats[regStat.SPC] = newHP;
}

void Pokemon::setSpe(int newSpe) {
    stats[regStat.SPE] = newHP;
}

void Pokemon::setAtkMod(int newMod) {
    stats[modStat.ATK] = newHP;
}

void Pokemon::setDefMod(int newMod) {
    stats[modStat.DEF] = newHP;
}

void Pokemon::setSpcMod(int newMod) {
    stats[modStat.SPC] = newHP;
}

void Pokemon::setSpeMod(int newMod) {
    stats[modStat.SPE] = newHP;
}

void Pokemon::setStatus(Status newStatus) {
    status = newStatus;
}

void Pokemon::Attack(Pokemon pokemon, Move move) {
    
}

std::string Pokemon::ToString() {

}