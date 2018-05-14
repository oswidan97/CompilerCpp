//
// Created by omar_swidan on 13/05/18.
//

#include <vector>
#include <string>
#include <iostream>
#ifndef COMPILER_EXPEVALUATOR_H
#define COMPILER_EXPEVALUATOR_H

#endif //COMPILER_EXPEVALUATOR_H


using std::vector;
using std::string;
using std::ofstream;
namespace expEvaluator{

    vector<string>& infixToPostfix(vector<string> infix,string& REGA,ofstream& assemblyfile);
    void EvaluatePostfix(vector<string> expression,int& Tcount,string& REGA,ofstream& assemblyfile);

    bool isOperator(string s);



    int prec(string s);


}