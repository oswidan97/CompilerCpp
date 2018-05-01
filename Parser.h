//
// Created by omar_swidan on 29/04/18.
//

#ifndef COMPILER_PARSER_H
#define COMPILER_PARSER_H

#include <iostream>
#include <vector>
using namespace std;
namespace Parser{

    bool read(vector<pair<string, int>>::iterator);
    bool write(vector<pair<string, int>>::iterator);
    bool idList(vector<pair<string, int>>::iterator);
    bool assign(vector<pair<string, int>>::iterator);
    bool exp(vector<pair<string, int>>::iterator);
    bool term(vector<pair<string, int>>::iterator);
    bool factor(vector<pair<string, int>>::iterator);
    bool stmtList(vector<pair<string, int>>::iterator);
    bool stmt(vector<pair<string, int>>::iterator);
    bool forProcedure(vector<pair<string, int>>::iterator);
    bool prog(vector<pair<string, int>>::iterator);
    bool index_exp(vector<pair<string, int>>::iterator);





}


#endif //COMPILER_PARSER_H
