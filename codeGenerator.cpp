//
// Created by omar_swidan on 09/05/18.
//
#include <fstream>
#include "codeGenerator.h"
using namespace std;
void ::codeGenerator::readGen(vector<string> &idNames,ofstream& assemblyFile) {


    assemblyFile<<"+JSUB XREAD\n";
    assemblyFile<<"WORD "<<idNames.size()<<"\n";
    for (auto && s:idNames ) {
        assemblyFile<<"WORD "<<idNames.at(idNames.size()-1)<<"\n";
        idNames.pop_back();
    }
    idNames.clear();

}
