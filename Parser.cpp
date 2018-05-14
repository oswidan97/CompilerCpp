//
// Created by omar_swidan on 29/04/18.
//

#include "Parser.h"
#include "codeGenerator.h"
#include <iterator>
#include <vector>

using namespace std;
bool ::Parser::read(vector<pair<string, int>>::iterator& it,ofstream& assemblyFile,
                    vector<string>& idNames) {
    bool found = 0;
    if (it->second == 7) {
        it++;
        if (it->second == 15) {
            it++;
            if (idList(it,idNames)) {
                if (it->second == 16) {
                    codeGenerator::readGen(idNames,assemblyFile);
                    found = 1;
                    it++;

                }
            }
        }
    }
    return found;
}


bool ::Parser::write(vector<pair<string, int>>::iterator& it,ofstream& assemblyFile,
vector<string>& idNames) {

    bool found = 0;
    if (it->second == 8) {
        it++;
        if (it->second == 15) {
            it++;
            if (idList(it,idNames)) {
                if (it->second == 16) {

                    codeGenerator::writeGen(idNames,assemblyFile);

                    found = 1;
                    it++;
                  //  idwriteNames.push_back(it->first);
                }
            }
        }
    }
    return found;

}


bool Parser::assign(vector<pair<string, int>>::iterator& it,ofstream& assemblyFile,string& REGA,int& resCount) {
    bool found = 0;
    vector<string> expression;
    int Tcount=0;
    if (it->second == 21) {
        vector<pair<string, int>>::iterator tempIt=it;
        it++;
        if (it->second == 12) {
            it++;
            if (exp(it,REGA,assemblyFile,expression)) {
                codeGenerator::assgGen(it,assemblyFile,expression,Tcount,REGA);
                if (Tcount>resCount)
                    resCount++;
                assemblyFile<<"STA "<<tempIt->first<<endl;
                REGA=tempIt->first;
                found = 1;
            }
        }
    }

    return found;
}

bool ::Parser::exp(vector<pair<string, int>>::iterator& it,string& REGA,ofstream& assemblyFile,vector<string>& expression) {
    bool found = 0;
    if (term(it,assemblyFile,expression)) {
        found = 1;
        while ((it->second == 13||it->second==14 ) && found ) {
            expression.push_back(it->first);
            it++;
            if (!term(it,assemblyFile,expression))
                found = 0;

        }
    }


    return found;
}

bool ::Parser::factor(vector<pair<string, int>>::iterator& it,vector<string>& expression) {
    bool found = 0;
    if (it->second == 21 ) {
        found = 1;
        expression.push_back(it->first);
        it++;
    } else if (it->second == 15) {
        expression.push_back(it->first);
        it++;
        if (exp) {
            if (it->second == 16) {
                found = 1;
                expression.push_back(it->first);
                it++;
            }
        }
    }
    return found;

}
bool ::Parser::term(vector<pair<string, int>>::iterator & it,ofstream& assemblyFile, vector<string>& expression) {
    bool found=0;
    if(factor(it,expression)){
        found=1;

        while((it->second==18 || it->second==17)&& found){ //* || DIV || found
            cout<<it->second<<endl;
            expression.push_back(it->first);
            it++;
            if(!factor(it,expression))
                found=0;
        }

    }

    return found;
}

bool ::Parser::idList(vector<pair<string, int>>::iterator& it,vector<string>& idName) {

    bool found = 0;
    if (it->second == 21) {
        found = 1;
        idName.push_back(it->first);
        it++;
        while (it->second == 19 && found) {
            it++;
            if (it->second == 21){
                idName.push_back(it->first);
                it++;

            }
            else found = 0;

        }

    }
    return found;
}

bool ::Parser::stmtList(vector<pair<string, int>>::iterator& it,ofstream& assemblyFile,vector<string>& idNames,string& REGA,int& reCount) {
    bool found = 0;
    if(stmt(it,assemblyFile,idNames,REGA,reCount)) {
        cout<<"stmt"<<endl;
        found = 1;

        while (it->second == 11 && found) {
            it++;
            if (!stmt(it,assemblyFile,idNames,REGA,reCount))
                found=0;


        }
        if (it->second==5)
            found=1;
    }

    return found;
}

bool ::Parser::stmt(vector<pair<string, int>>::iterator& it,ofstream& assemblyFile,vector<string>& idNames,string& REGA,int& reCount) {
    bool found=0;
    if (assign(it,assemblyFile,REGA,reCount)||read(it,assemblyFile,idNames)||write(it,assemblyFile,idNames)||forProcedure(it))
        found=1;

    return found;

}

bool ::Parser::forProcedure(vector<pair<string, int>>::iterator&) {
    return false;
}

bool ::Parser::prog(vector<pair<string, int>>::iterator& it,ofstream& assemblyFile,string& REGA) {
    bool found=0;
    vector<string> idNames;
    int reCount=0;
    if(it->second==1){
        it++;
        cout<<"prog"<<endl;
        if (it->second==21){
            it++;
            cout<<"id"<<endl;
            if (it->second==2){
                it++;
                cout<<"var"<<endl;
                if (idList(it,idNames)){
                    codeGenerator::ProgNameGen(idNames,assemblyFile);
                    cout<<"idlist"<<endl;
                    if (it->second==3) {
                        cout<<"begin"<<endl;
                        it++;
                        if (stmtList(it,assemblyFile,idNames,REGA,reCount)) {
                            cout << "stmtlist" << endl;
                            for (int i = 0; i < reCount; ++i)
                                assemblyFile<<"T"<<i<<" RESW "<<"1"<<endl;

                            if (it->second == 5) {
                                codeGenerator::EndGEN(idNames,assemblyFile);
                                cout << "end" << endl;
                                found = 1;
                                it++;
                            }

                        }
                    }
                }
            }
        }
    }

    return found;
}

bool ::Parser::index_exp(vector<pair<string, int>>::iterator&) {
    return false;
}









