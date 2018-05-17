#include <iostream>
#include <vector>
#include <fstream>
#include "tokenizer.h"
#include "TokenSchemer.h"
#include "Parser.h"

using namespace std;

int main(int argc,char* argv[]) {

    vector<string> lines;
    vector<pair<string,int>> tokens;
    tokenizer tok;
    ifstream input;
    if(argc==1)
        input.open("../code");//open file with default file name if no arguments are supplied
    else {
        string fileName(argv[1]);
        input.open("../"+fileName);//open file with the name supplied in the arguments

    }

    if (!input.is_open())cout << "not open";
    string s;
    while (!input.eof()) {
        getline(input, s);//get the input from the file
        lines.insert(lines.end(), s);
    }

    input.close();

    for (int i = 0; i < lines.size(); ++i)
        tok.tokenize(lines[i], tokens);//call the lexical analyser to fill the vector of tokens

    vector<pair<string,int>>::iterator it=tokens.begin();
    ofstream assemblyFile("../assembly");
    string REGA="";
    if(Parser::prog(it,assemblyFile,REGA)==0) //call the parser to analyse the identified tokens
        cout<<"Parsing error"<<endl;


    return 0;
}