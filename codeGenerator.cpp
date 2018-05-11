//
// Created by omar_swidan on 09/05/18.
//
#include <fstream>
#include <map>
#include <iostream>
#include <stack>
#include <sstream>
#include "codeGenerator.h"

vector<string> temp;
using namespace std;

void ::codeGenerator::readGen(vector<string> &idNames, ofstream &assemblyFile) {


    assemblyFile << "+JSUB XREAD\n";
    assemblyFile << "WORD " << idNames.size() << "\n";
    for (auto &&s:idNames) {
        assemblyFile << "WORD " << idNames.at(idNames.size() - 1) << "\n";
        idNames.pop_back();
    }
    idNames.clear();

}

void codeGenerator::GETA(vector<pair<string, int>>::iterator &it, ofstream &assemblyFile, string &REGA) {

    if (REGA.empty())
        assemblyFile << "LDA " << it->first << endl;
    else if (REGA != it->first) {
        //string T;
        //TODO add RESW T in the end of the program
        assemblyFile << "STA " << "T";
        //REGA = T;
        // TODO the token specifier of the previous value in REGA should now be "T"
        assemblyFile << "LDA " + it->first << endl;
    }
    REGA = it->first;

}

void codeGenerator::writeGen(vector<string> &idNames, ofstream &assemblyFile) {

    assemblyFile << "+JSUB XWRITE\n";
    assemblyFile << "WORD " << idNames.size() << "\n";
    for (auto &&s:idNames) {
        assemblyFile << "WORD " << idNames.at(idNames.size() - 1) << "\n";
        idNames.pop_back();
    }
    idNames.clear();
}

void codeGenerator::ProgNameGen(vector<string> &idNames, ofstream &assemblyFile) {
    assemblyFile << "START 0" << endl;
    assemblyFile << "EXTREF XREAD,XWRITE" << endl;
    assemblyFile << "STL RETADR" << endl;
    assemblyFile << "J BEGIN" << endl;
    while (!idNames.empty()) {
        assemblyFile << idNames.at(idNames.size() - 1) << " RESW 1" << endl;
        idNames.pop_back();
    }
    assemblyFile << "BEGIN " << endl;
//idNames.clear();
}

void codeGenerator::EndGEN(vector<string> &idNames, ofstream &assemblyFile) {
    assemblyFile << "LDL RETADR" << endl;
    assemblyFile << "RSUB" << endl;
    for (auto &&s:idNames) {
        assemblyFile << idNames.at(idNames.size() - 1) << " RESW 1" << "\n";
        idNames.pop_back();
    }
    assemblyFile << "END";
}

void codeGenerator::Tstore(string a) {
    int i = 0;
    int f = 0;
//cout<<temp.at(0);
    while (i < temp.size() && temp.at(i) == a) {

        f = 1;
        i++;
    }
    if (f == 0) {
        cout << "888";
    }

}

void codeGenerator::assignGEN(string store, string assignment) {
    string number1, number2, acc = "";
    int count = 0;
    stringstream ss(assignment);
    char sep = '+';
    int i = 0;

    istringstream iss(assignment);
    char subs[1000];
    do {

        iss >> subs;
        cout << "Substring: " << subs[i] << endl;
    } while (iss);


    stack<string> stack;
}

void ::codeGenerator::assgGen(vector<pair<string, int>>::iterator &it, ofstream &assemblyFile, string &REGA) {

    codeGenerator::GETA(it,assemblyFile,REGA);
    assemblyFile<<"STA "<<it->first;
    REGA.clear();

}





