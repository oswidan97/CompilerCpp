#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include "tokenizer.h"
#include "TokenSchemer.h"
#include <regex>;
using namespace std;



int main() {
    map<int,regex> tokenScheme;

    vector<string> lines;
    vector<string> tokens;

    ifstream input("/home/ziad/Desktop/CompilerCpp-master(1)/CompilerCpp-master/code");

    if (!input.is_open())cout<<"not open";
    string s;
    while(!input.eof()){
        getline(input,s);
        lines.insert(lines.end(),s);

    }
    int flag=0;

    input.close();
    tokenizer tok;
    TokenSchemer tokenSchemer;
    for (int i = 0; i < lines.size(); ++i)
        tok.tokenize(lines[i],tokens);
    for (int i = 0; i < tokens.size(); ++i)
        cout<< tokens[i]<<endl;

    tokenSchemer.TokenSchemers(tokenScheme);
    cout << "--------------------------------------------" << endl ;

    auto it = tokenScheme.begin();
for(int i =0; i<tokens.size();++i){
    { for (int j =0 ; j < tokenScheme.size(); j++)
       if(regex_match(tokens[i],tokenScheme[j])) {
            flag = 1;
          auto   it= tokenScheme.find(j);
             cout << tokens[i] << " --- > " <<it -> first << endl;
             break;
             }
    }
if(flag==0)
{ //cout << "error ";
    //break;
}
flag=0;
}


    return 0;
}