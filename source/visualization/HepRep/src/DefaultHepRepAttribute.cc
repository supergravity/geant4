
#include "DefaultHepRepAttribute.h"
#include "DefaultHepRepAttValue.h"

#include <iostream>
#include <algorithm>

using namespace std;
using namespace HEPREP;


DefaultHepRepAttribute::DefaultHepRepAttribute() {
}

DefaultHepRepAttribute::~DefaultHepRepAttribute() {
    for (map<string, HepRepAttValue*>::iterator i = attValues.begin(); i != attValues.end(); i++) {
        delete (*i).second;
    }
}

set<HepRepAttValue*> DefaultHepRepAttribute::getAttValuesFromNode() {
    set<HepRepAttValue*> attSet;
    for (map<string, HepRepAttValue*>::iterator i = attValues.begin(); i != attValues.end(); i++) {
        if ((*i).first != "layer") attSet.insert((*i).second);
    }
    return attSet;
}

void DefaultHepRepAttribute::addAttValue(HepRepAttValue* hepRepAttValue) {
    string lowerCaseName = hepRepAttValue->getLowerCaseName();
    if (attValues[lowerCaseName] != NULL) delete attValues[lowerCaseName];
    attValues[lowerCaseName] = hepRepAttValue;
}

void DefaultHepRepAttribute::addAttValue(string key, char *value, int showLabel) {
    addAttValue(key, (std::string)value, showLabel);
}

void DefaultHepRepAttribute::addAttValue(string key, string value, int showLabel) {
    addAttValue(new DefaultHepRepAttValue(key, value, showLabel));
}

void DefaultHepRepAttribute::addAttValue(string key, int value, int showLabel) {
    addAttValue(new DefaultHepRepAttValue(key, value, showLabel));
}

void DefaultHepRepAttribute::addAttValue(string key, double value, int showLabel) {
    addAttValue(new DefaultHepRepAttValue(key, value, showLabel));
}

void DefaultHepRepAttribute::addAttValue(string key, bool value, int showLabel) {
    addAttValue(new DefaultHepRepAttValue(key, value, showLabel));
}

void DefaultHepRepAttribute::addAttValue(string key, vector<double> value, int showLabel) {
    addAttValue(new DefaultHepRepAttValue(key, value, showLabel));
}

void DefaultHepRepAttribute::addAttValue(string key, double red, double green, double blue, double alpha, int showLabel) {
    vector<double> color;
    color.push_back(red);
    color.push_back(green);
    color.push_back(blue);
    color.push_back(alpha);
    addAttValue(new DefaultHepRepAttValue(key, color, showLabel));
}

HepRepAttValue* DefaultHepRepAttribute::getAttValueFromNode(string name) {
    string s = name;
    transform(s.begin(), s.end(), s.begin(), (int(*)(int)) tolower);
    return (attValues.count(s) > 0) ? attValues[s] : NULL;    
}

HepRepAttValue* DefaultHepRepAttribute::removeAttValue(string name) {
    string s = name;
    transform(s.begin(), s.end(), s.begin(), (int(*)(int)) tolower);
    HepRepAttValue* attValue = attValues[s];
    attValues.erase(s);
    return attValue;
}
