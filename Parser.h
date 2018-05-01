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
    bool idList(vector<pair<string, int>>::iterator);
    bool assign(vector<pair<string, int>>::iterator);
    bool exp(vector<pair<string, int>>::iterator);
    bool term(vector<pair<string, int>>::iterator);
    bool factor(vector<pair<string, int>>::iterator);


}


#endif //COMPILER_PARSER_H
