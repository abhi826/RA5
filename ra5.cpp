//
// Created by 17323 on 2/27/2021.
//
#include "lex.h"
using namespace std;

LexItem id_or_kw(const string& lexeme,int linenum){
    map<string,Token>::iterator iter=kwmap.find(lexeme);
    if(iter!=kwmap.end()){
        return LexItem(iter->second,lexeme,linenum);
    }
    return LexItem(IDENT,lexeme,linenum);
}

ostream& operator<<(ostream& out, const LexItem& tok){
    Token t=tok.GetToken();
    out<<tokenPrint[t];
    if(t==IDENT||t==ICONST||t==RCONST||t==SCONST||t==ERR){
        out<<" ("<<tok.GetLexeme()<<")";
    }
    out<<" Line #: "<<tok.GetLinenum()<<endl;
    return out;
}

