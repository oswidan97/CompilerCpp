#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include "tokenizer.h"
#include "TokenSchemer.h"
#include "Parser.h"
#include "codeGenerator.h"

using namespace std;

int main() {

codeGenerator::assignGEN("hhh","a + csdfgsg + sfs");
    vector<string> lines;
    vector<pair<string,int>> tokens;
    tokenizer tok;
    ifstream input("../code");

    if (!input.is_open())cout << "not open";
    string s;
    while (!input.eof()) {
        getline(input, s);
        lines.insert(lines.end(), s);
    }

    input.close();

    for (int i = 0; i < lines.size(); ++i)
        tok.tokenize(lines[i], tokens);
   // for(pair<string,int> x:tokens)
     //   cout<<x.first<<" "<<x.second<<endl;
    vector<pair<string,int>>::iterator it=tokens.begin();
    ofstream assemblyFile("../assembly");
    string REGA;
    cout<<Parser::prog(it,assemblyFile,REGA)<<endl;


    return 0;
}