//
// Created by omar_swidan on 09/05/18.
//
#include <fstream>
#include <map>
#include <iostream>
#include <stack>
#include <sstream>
#include "codeGenerator.h"
#include "expEvaluator.h"

vector<string> temp;
using std::string;
using std::pair;
using std::ofstream;
using std::iostream;
using std::endl;
using std::cout;
using std::stringstream;
using std::stack;
using std::istringstream;

void ::codeGenerator::readGen(vector<string> &idNames, ofstream &assemblyFile) {


    assemblyFile << "+JSUB XREAD\n";
    assemblyFile << "WORD " << idNames.size() << "\n";
    for (auto &&s:idNames) {
        assemblyFile << "WORD " << idNames.at(idNames.size() - 1) << "\n";
        idNames.pop_back();
    }
    idNames.clear();

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

void ::codeGenerator::assgGen(vector<pair<string, int>>::iterator &it, ofstream &assemblyFile, vector<string> &expression,
                         int &Tcount, string &REGA) {

    expEvaluator::EvaluatePostfix(expression, Tcount, REGA, assemblyFile);

}


void ::codeGenerator::assembleExp(string operand1, string operand2, string oper, string &REGA,
                                  ofstream &assemblyFile,int& TLocaCount) {

//code generation of different operations with different possibilities of the contents of register A

    if (REGA == "") {
        assemblyFile << "LDA " << operand2 << endl;
        if (oper == "*")
            assemblyFile << "MUL " << operand1 << endl;
        else if (oper == "+")
            assemblyFile << "ADD " << operand1 << endl;
        else if(oper=="-")
            assemblyFile<<"SUB "<<operand1<<endl;
        else if (oper=="DIV")
            assemblyFile<<"DIV "<<operand1<<endl;
    } else if (REGA == operand1) {

        if (oper == "*")
            assemblyFile << "MUL " << operand2 << endl;
        else if (oper == "+")
            assemblyFile << "ADD " << operand2 << endl;
        else if(oper=="-"){
            assemblyFile<<"STA "<<operand1;
            assemblyFile<<"LDA "<<operand2;
            assemblyFile<<"SUB "<<operand1;

        }
        else if (oper=="DIV"){
            assemblyFile<<"STA "<<operand1;
            assemblyFile<<"LDA "<<operand2;
            assemblyFile<<"DIV "<<operand1;
        }



    }else if (REGA == operand2) {
        if (oper == "*")
            assemblyFile << "MUL " << operand1 << endl;
        else if (oper == "+")
            assemblyFile << "ADD " << operand1 << endl;
        else if(oper=="-")
            assemblyFile<<"SUB "<<operand1<<endl;
        else if (oper=="DIV")
            assemblyFile<<"DIV "<<operand1<<endl;

    }else{  //Store the variable currently in register A if not needed in the current computation

        assemblyFile<<"STA T"<<TLocaCount++<<endl;
        assemblyFile << "LDA " << operand2 << endl;
        if (oper == "*")
            assemblyFile << "MUL " << operand1 << endl;
        else if (oper == "+")
            assemblyFile << "ADD " << operand1 << endl;
        else if(oper=="-")
            assemblyFile<<"SUB "<<operand1<<endl;
        else if (oper=="DIV")
            assemblyFile<<"DIV "<<operand1<<endl;
    }

    REGA = "T" + std::to_string(TLocaCount);


}








