// Element.h
#ifndef STATUS_H
#define STATUS_H

#include <string>
#include "Phase.h"
using namespace std;

class Element {
	public:
		Element :: Element(string& name, string& symbol, string& type, int atomicNum, int group, double mass, Phase phase);
		Element() = default;
		
	    string getName();
	   	string getSymbol();
	   	string getType();
	   	int getAtomicNum();
	   	int getGroup();
	   	double getMass();
	   	Phase getPhase();

		void setName(string& ourName);
		void setSymbol(string& ourSymbol);
		void setType(string& ourType);
		void setAtomicNum(int ourAtomicNum);
		void setGroup(int ourGroup);
		void setMass(double ourMass);
		void setPhase(Phase ourPhase);

	private:
		string name;
		string symbol;
		string type;
		int atomicNum;
		int group;
		double mass;
		Phase phase;



};

#endif