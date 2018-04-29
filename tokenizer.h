//
// Created by omar_swidan on 24/04/18.
//

#ifndef COMPILER_TOKENIZER_H
#define COMPILER_TOKENIZER_H


#include <iostream>

class tokenizer {
private:


    std::string str;

public :
        tokenizer();
        void tokenize(std::string,std::vector<std::pair<std::string,int>> &);

};


#endif //COMPILER_TOKENIZER_H
