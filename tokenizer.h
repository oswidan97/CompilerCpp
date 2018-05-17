//
// Created by omar_swidan on 24/04/18.
//

#ifndef COMPILER_TOKENIZER_H
#define COMPILER_TOKENIZER_H

using namespace std;

class tokenizer {
private:


    std::string str;

public :
        tokenizer();
        void tokenize(string,std::vector<std::pair<string,int>> &);

};


#endif //COMPILER_TOKENIZER_H
