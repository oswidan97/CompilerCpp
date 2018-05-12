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


bool Parser::assign(vector<pair<string, int>>::iterator& it,ofstream& assemblyFile,string& REGA) {
    bool found = 0;
    if (it->second == 17) {
        it++;
        if (it->second == 12) {
            it++;
            if (exp(it,REGA,assemblyFile)) {
                codeGenerator::assgGen(it,assemblyFile,REGA);
                found = 1;
            }
        }
    }

    return found;
}

bool ::Parser::exp(vector<pair<string, int>>::iterator& it,string& REGA,ofstream& assemblyFile) {
    bool found = 0;
    bool isSimpleTerm=0;
    vector<pair<string, int>>::iterator temp=it;
    if (term(it,REGA,assemblyFile,isSimpleTerm)) {
        found = 1;
        isSimpleTerm=0;
       if(it->second!=13) codeGenerator::expGenTermOnly(temp,REGA);
        while ((it->second == 13 ) && found ) {
            isSimpleTerm=0;
            it++;
            if (!term(temp=it,REGA,assemblyFile,isSimpleTerm))
                found = 0;
            if(found){
                if (isSimpleTerm)codeGenerator::expGenExpPlusTerm(temp,assemblyFile,REGA);
                else
            }
        }
    }


    return found;
}

bool ::Parser::factor(vector<pair<string, int>>::iterator& it) {
    bool found = 0;
    if (it->second == 17 ) {
        found = 1;
        it++;
    } else if (it->second == 15) {
        it++;
        if (exp) {
            if (it->second == 16) {
                found = 1;
                it++;
            }
        }
    }
    return found;

}
bool ::Parser::term(vector<pair<string, int>>::iterator & it,string& REGA,ofstream& assemblyFile, bool& isSimpleTerm) {
    bool found=0;
    if(factor(it)){
        found=1;
        if (it->second!=18) isSimpleTerm=1;
        while(it->second==18 && found){
            it++;
            if(!factor(it))
                found=0;
        }
    }

    return found;
}

bool ::Parser::idList(vector<pair<string, int>>::iterator& it,vector<string>& idName) {

    bool found = 0;
    if (it->second == 17) {
        found = 1;
        idName.push_back(it->first);
        it++;
        while (it->second == 19 && found) {
            it++;
            if (it->second == 17){
                idName.push_back(it->first);
               // cout<< idName.back();
                it++;

            }
            else found = 0;

        }

    }
    return found;
}

bool ::Parser::stmtList(vector<pair<string, int>>::iterator& it,ofstream& assemblyFile,vector<string>& idNames,string& REGA) {
    bool found = 0;
    if(stmt(it,assemblyFile,idNames,REGA)) {
        found = 1;

        while (it->second == 11 && found) {
            it++;
            if (!stmt(it,assemblyFile,idNames,REGA))
                found=0;


        }
        if (it->second==5)
            found=1;
    }

    return found;
}

bool ::Parser::stmt(vector<pair<string, int>>::iterator& it,ofstream& assemblyFile,vector<string>& idNames,string& REGA) {
    bool found=0;
    if (assign(it,assemblyFile,REGA)||read(it,assemblyFile,idNames)||write(it,assemblyFile,idNames)||forProcedure(it))
        found=1;

    return found;

}

bool ::Parser::forProcedure(vector<pair<string, int>>::iterator&) {
    return false;
}

bool ::Parser::prog(vector<pair<string, int>>::iterator& it,ofstream& assemblyFile,string& REGA) {
    bool found=0;
    vector<string> idNames;
    if(it->second==1){
        it++;
        cout<<"prog"<<endl;
        if (it->second==17){
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
                        if (stmtList(it,assemblyFile,idNames,REGA)) {
                            cout << "stmtlist" << endl;
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









