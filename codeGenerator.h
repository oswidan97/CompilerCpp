//
// Created by omar_swidan on 09/05/18.
//
#include <vector>
#include <string>

#ifndef COMPILER_CODEGENERATOR_H
#define COMPILER_CODEGENERATOR_H

#endif //COMPILER_CODEGENERATOR_H

using namespace std;
namespace codeGenerator{
//vector <string> temps;
    void readGen(vector<string>&,ofstream& assemblyFile);
    void writeGen(vector<string>&,ofstream& assemblyFile);
    void ProgNameGen(vector<string>&,ofstream& assemblyFile);
    void EndGEN(vector<string>&,ofstream& assemblyFile);
    void Tstore(string a);
    void assignGEN(string store,string assignment);
    void GETA(vector<pair<string,int>>::iterator&,ofstream& assemblyFile,string& REGA);
    void assgGen(vector<pair<string,int>>::iterator&,ofstream& assemblyFile,string& REGA);
    void expGenTermOnly(vector<pair<string,int>>::iterator&,string& REGA);
    void expGenExpPlusTerm(vector<pair<string,int>>::iterator&, ofstream& assemblyFile, string& REGA);


}