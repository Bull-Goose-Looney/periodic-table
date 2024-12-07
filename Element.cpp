//Element.cpp
#include <string>

#include "Element.h"

using namespace std;

//constructor
Element :: Element(string& name, string& symbol, string& type, int atomicNum, int group, double mass, Phase phase) {
    this-> name = name;
    this-> symbol = symbol;
    this-> type = type;
    this-> atomicNum = atomicNum;
    this-> group = group;
    this-> mass = mass;
    this-> phase = phase;

}

//getters
string Element :: getName() {
    return name;
}
string Element :: getSymbol() {
    return symbol;
}
string Element :: getType() {
    return type;
}
int Element :: getAtomicNum() {
    return atomicNum;
}
int Element :: getGroup() {
    return group;
}
double Element ::  getMass() {
    return mass;
}
Phase Element ::  getPhase() {
    return phase;
}

//setters
void Element :: setName(string& ourName) {
    name = ourName;
}
void Element ::  setSymbol(string& ourSymbol) {
   symbol = ourSymbol;
}
void Element :: setType(string& ourType) {
    type = ourType;
}
void Element :: setAtomicNum(int ourAtomicNum) {
    atomicNum = ourAtomicNum;
}
void Element :: setGroup(int ourGroup) {
    group = ourGroup;
}
void Element :: setMass(double ourMass) {
    mass = ourMass;
}
void Element :: setPhase(Phase ourPhase) {
    phase = ourPhase;
}