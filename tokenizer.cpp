//
// Created by omar_swidan on 24/04/18.
//

#include <regex>
#include <iostream>
#include "tokenizer.h"
#include "TokenSchemer.h"

using std::regex;
using std::sregex_iterator;
using std::iostream;
using std::cout;
using std::endl;
using namespace std;
tokenizer::tokenizer() {}

void tokenizer::tokenize(string str, vector<pair<string,int>> &vec) {

    int flag = 0;

    regex rgx("(\\w+\\.*)\\s*(:=)*(DIV|[-*+,();]{0,1})(;{0,1})");//The regex used to match the code based on the pascal grammar
    sregex_iterator position(str.cbegin(), str.cend(), rgx);//iterator on the vector of tokens
    sregex_iterator end;

    TokenSchemer tokenSchemer;

    map<int ,regex> scheme = tokenSchemer.getTokenScheme();//get map pf available keywords and non terminals


    while (position != end) {
        for (int i = 1; i < position->size(); ++i){

            if (position->str((unsigned long) i) != "") {

                for (int j = 0; j < scheme.size(); j++){ //loop on valid tokens to match to identify the type of the captured token
                    if (regex_match(position->str((unsigned long) i), scheme[j])) {
                         flag = 1;
                        vec.push_back(make_pair(position->str((unsigned long) i),j));
                        break;
                    }
                }

                if (flag == 0)  cout << "error " << "token " << position->str((unsigned long) i)<<" not valid" << endl;


                flag = 0;
            }

        }
        position++;


    }

}




