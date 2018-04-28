//
// Created by omar_swidan on 24/04/18.
//

#include <regex>
#include "tokenizer.h"
using namespace std;
tokenizer::tokenizer() {}

void tokenizer::tokenize(string str,vector<string>& vec) {


    regex rgx("(\\w+)\\s*([*+,()=;.]*)");
    sregex_iterator position(str.cbegin(),str.cend(),rgx);

    sregex_iterator end;
    while(position!=end){
        //cout<<"matched:"<<position->str(2)<<endl;
        for (int i = 1; i < position->size(); ++i)
            if (position->str((unsigned long) i) != "")
                vec.push_back(position->str((unsigned long) i));

    position++;
    }



}

