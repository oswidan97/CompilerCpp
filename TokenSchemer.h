//
// Created by ziad on 4/27/18.
//

#ifndef COMPILER_TOKENSCHEMER_H
#define COMPILER_TOKENSCHEMER_H
#include <map>
#include <string>
#include <string>
#include <regex>

using std::vector;
using std::string;
using std::pair;
using std::ofstream;
using std::regex;
using std::map;


class TokenSchemer {

public :
    TokenSchemer(){
        scheme();
    };

public:
    const map<int, regex> &getTokenScheme() const;

private:
    map<int,regex> tokenScheme;

    void scheme();

};





#endif //COMPILER_TOKENSCHEMER_H
