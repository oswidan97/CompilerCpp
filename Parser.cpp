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

bool ::Parser::write(vector<pair<string,int>>::iterator it) {

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

    bool found = 0;

    if (it->second == 17) {
        found = 1;
        it++;
        while (it->second == 19 && found) {
            it++;
            if (it->second == 17)
                it++;
            else found = false;


        }
    }
    return found;
}

bool Parser::assign(vector<pair<string, int>>::iterator it) {
    bool found=0;
    if (it->second==17){
        it++;
        if (it->second==12){
            it++;
            if (exp(it)){
                found=1;
            }
        }
    }

    return found;
}

bool ::Parser::exp(vector<pair<string, int>>::iterator it) {
    bool found=0;
    if (term(it)){
        found=1;
        while((it->second==13 || it->second==14)&& found==1){
            it++;
            if(!term(it)){
                found=0;
            }
        }
        return found;
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
        if(exp){
        if(it->second==16){
found=1;
it++;
        }
    }}
return found;

}




