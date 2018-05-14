//
// Created by omar_swidan on 13/05/18.
//

#include <stack>
#include <iostream>
#include "expEvaluator.h"
#include "codeGenerator.h"

using namespace std;

int ::expEvaluator::prec(string s) {
    if (s == "^")
        return 3;
    else if (s == "*" || s == "/")
        return 2;
    else if (s == "+" || s == "-")
        return 1;
    else
        return -1;
}

bool ::expEvaluator::isOperator(string s) {

    return (bool) (s == "+" || s == "*" ||s=="-"||s=="DIV" ? 1 : 0);
}

vector<string>& ::expEvaluator::infixToPostfix(vector<string> infix,string& REGA,ofstream& assemblyfile) {

    std::stack<string> st;
    st.push("N");
    int l = (int) infix.size();
    vector<string>* postFix=new vector<string>;
    string s;

    for (int i = 0; i < l; i++) {
        // If the scanned character is an operand, add it to output string.
        if (!isOperator(infix[i]))
            postFix->push_back(infix[i]);

            // If the scanned character is an ‘(‘, push it to the stack.
        else if (infix[i] == "(")

            st.push("(");

            // If the scanned character is an ‘)’, pop and to output string from the stack
            // until an ‘(‘ is encountered.
        else if (infix[i] == ")") {
            while (st.top() != "N" && st.top() != "(") {
                s = st.top();
                st.pop();
                postFix->push_back(s);
            }
            if (st.top() == "(") {
                s = st.top();
                st.pop();
            }
        }

            //If an operator is scanned
        else {

            while (st.top() != "N" && prec(infix[i]) <= prec(st.top())) {
                s = st.top();
                st.pop();
                postFix->push_back(s);
            }
            st.push(infix[i]);
        }

    }
    //Pop all the remaining elements from the stack
    while (st.top() != "N") {
        s = st.top();
        st.pop();
        postFix->push_back(s);
    }


    return * postFix;
}



void expEvaluator::EvaluatePostfix(vector<string> expression,int& Tcount ,string &REGA, ofstream &assemblyfile) {

    vector<string>& postFixExp=expEvaluator::infixToPostfix(expression,REGA,assemblyfile);
    // Declaring a Stack from Standard template library in C++.
    stack<string> S;
    int TLocalCount=0;
    string operand1,operand2;
    for (int i = 0; i < postFixExp.size(); i++) {

        // Scanning each character from left.

        // If character is operator, pop two elements from stack, perform operation and push the result back.
        if (expEvaluator::isOperator(postFixExp[i])) {
            // Pop two operands.
            operand2= S.top();
            S.pop();
            operand1 = S.top();
            S.pop();
            // Perform operation
            codeGenerator::assembleExp(operand1, operand2,postFixExp[i],REGA,assemblyfile,TLocalCount);
            //Push back result of operation on stack.
            S.push("T"+std::to_string(TLocalCount-1));
        }
        else if(!expEvaluator::isOperator(postFixExp[i])){

            // Push operand on stack.
            S.push(postFixExp[i]);
        }
    }
    Tcount=TLocalCount;
    // If expression is in correct format, Stack will finally have one element. This will be the output.
     delete &postFixExp;
}

