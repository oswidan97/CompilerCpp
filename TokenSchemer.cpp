//
// Created by ziad on 4/27/18.
//
#include <iostream>

#include "TokenSchemer.h"
#include <map>
#include <regex>

using namespace std ;
TokenSchemer::TokenSchemer(){} ;
void TokenSchemer::TokenSchemers(std :: map<int,regex> & tokenschemer){
regex rgx("[aA-Zz]+\d*");
    tokenschemer.insert( std::pair <int,regex>(1,regex("PROGRAM")));
    tokenschemer.insert( std::pair <int,regex>(2,regex("VAR")));
    tokenschemer.insert( std::pair <int,regex>(3,regex("BEGIN")));
    tokenschemer.insert( std::pair <int,regex>(4,regex("END")));
    tokenschemer.insert( std::pair <int,regex>(5,regex("END.")));
    tokenschemer.insert( std::pair <int,regex>(6,regex("FOR")));
    tokenschemer.insert( std::pair <int,regex>(7,regex("READ")));
    tokenschemer.insert( std::pair <int,regex>(8,regex("WRITE")));
    tokenschemer.insert( std::pair <int,regex>(9,regex("TO")));
    tokenschemer.insert( std::pair <int,regex>(10,regex("DO")));
    tokenschemer.insert( std::pair <int,regex>(11,regex(";")));
    tokenschemer.insert( std::pair <int,regex>(12,regex("=")));
    tokenschemer.insert( std::pair <int,regex>(13,regex("\\+")));
    tokenschemer.insert( std::pair <int,regex>(15,regex("\\(")));
    tokenschemer.insert( std::pair <int,regex>(16,regex("\\)")));
    tokenschemer.insert( std::pair <int,regex>(17,rgx));
    tokenschemer.insert( std::pair <int,regex>(18,regex("\\*")));

}
