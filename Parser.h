//
// Created by omar_swidan on 29/04/18.
//

#ifndef COMPILER_PARSER_H
#define COMPILER_PARSER_H

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
namespace Parser{

    bool read(vector<pair<string, int>>::iterator&,ofstream& assemblyFile,vector<string>&);
    bool write(vector<pair<string, int>>::iterator&,ofstream& assemblyFile,vector<string>&);
    bool idList(vector<pair<string, int>>::iterator&,vector<string>&);
    bool assign(vector<pair<string, int>>::iterator&,ofstream& assemblyFile,string& REGA,int& resCount);
    bool exp(vector<pair<string, int>>::iterator&,string& REGA,ofstream& assemblyFile,vector<string> &expression);
    bool term(vector<pair<string, int>>::iterator&,ofstream& assemblyFile,vector<string>& expression);
    bool factor(vector<pair<string, int>>::iterator&,vector<string>& expression);
    bool stmtList(vector<pair<string, int>>::iterator&,ofstream& assemblyFile,vector<string>&,string& REGA,int& reCount);
    bool stmt(vector<pair<string, int>>::iterator&,ofstream& assemblyFile,vector<string>&,string& REGA,int& reCount);
    bool prog(vector<pair<string, int>>::iterator& it,ofstream& assemblyFile,string& REGA);
    bool forProcedure(vector<pair<string, int>>::iterator&);
    bool index_exp(vector<pair<string, int>>::iterator&);



}


#endif //COMPILER_PARSER_H
