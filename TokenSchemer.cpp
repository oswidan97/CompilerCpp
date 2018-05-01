//
// Created by ziad on 4/27/18.
//
#include <iostream>

#include "TokenSchemer.h"
#include <map>
#include <regex>

using namespace std ;


void TokenSchemer::scheme(){
regex rgx("[aA-Zz]+\\d*");
regex rgx1("//d+");
    TokenSchemer::tokenScheme.insert( std::pair <int,regex>(1,regex("PROGRAM")));
    TokenSchemer::tokenScheme.insert( std::pair <int,regex>(2,regex("VAR")));
    TokenSchemer::tokenScheme.insert( std::pair <int,regex>(3,regex("BEGIN")));
    TokenSchemer::tokenScheme.insert( std::pair <int,regex>(4,regex("END")));
    TokenSchemer::tokenScheme.insert( std::pair <int,regex>(5,regex("END.")));
    TokenSchemer::tokenScheme.insert( std::pair <int,regex>(6,regex("FOR")));
    TokenSchemer::tokenScheme.insert( std::pair <int,regex>(7,regex("READ")));
    TokenSchemer::tokenScheme.insert( std::pair <int,regex>(8,regex("WRITE")));
    TokenSchemer::tokenScheme.insert( std::pair <int,regex>(9,regex("TO")));
    TokenSchemer::tokenScheme.insert( std::pair <int,regex>(10,regex("DO")));
    TokenSchemer::tokenScheme.insert( std::pair <int,regex>(11,regex(";")));
    TokenSchemer::tokenScheme.insert( std::pair <int,regex>(12,regex(":=")));
    TokenSchemer::tokenScheme.insert( std::pair <int,regex>(13,regex("\\+")));
    TokenSchemer::tokenScheme.insert( std::pair <int,regex>(14,regex("-")));
    TokenSchemer::tokenScheme.insert( std::pair <int,regex>(14,regex("\\-")));
    TokenSchemer::tokenScheme.insert( std::pair <int,regex>(15,regex("\\(")));
    TokenSchemer::tokenScheme.insert( std::pair <int,regex>(16,regex("\\)")));
    TokenSchemer::tokenScheme.insert( std::pair <int,regex>(17,rgx));
    TokenSchemer::tokenScheme.insert( std::pair <int,regex>(18,regex("\\*")));
    TokenSchemer::tokenScheme.insert( std::pair <int,regex>(19,regex(",")));
    TokenSchemer::tokenScheme.insert( std::pair <int,regex>(20,rgx1));


}

const map<int, regex> &TokenSchemer::getTokenScheme() const {
    return tokenScheme;
}
