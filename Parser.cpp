//
// Created by omar_swidan on 29/04/18.
//

#include "Parser.h"
#include <iterator>
#include <vector>

using namespace std;

bool ::Parser::read(vector<pair<string,int>>::iterator it) {

    bool found=0;
    if (it->second==7){
        it++;
        if(it->second==15){
            it++;
            if(idList(it)){
                it++;
                if(it->second==16){
                    found=1;
                    it++;
                }
            }
        }
    }
    return found;

}

bool ::Parser::idList(vector<pair<string, int>>::iterator it) {

bool found =0;

if(it->second==17){
    found=1;
    it++;
    while(it -> second == 19 && found== true){
it++;
if(it -> second ==17 )
    it++;
    else found= false;


    }
}
return found;
}

bool ::Parser::factor(vector<pair<string, int>>::iterator it) {
    bool found =0;
    if(it->second==17 || it->second ==  18){
found=1;
it++;
    } else if (it->second ==15){
        it++;
        if(it->second==16){
found=1;
it++;
        }
    }
return found;

}


