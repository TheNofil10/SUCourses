%{

#include <stdio.h>

void yyerror(const char * s ){}
%}





%left '+' '-'
%left '/' '*'
%left tDOTPROD
%left tTRANSPOSE
%left tOR
%left tAND
%token tINTTYPE
%token tINTVECTORTYPE
%token tINTMATRIXTYPE
%token tREALTYPE
%token tREALVECTORTYPE
%token tREALMATRIXTYPE
%token tTRANSPOSE
%token tIDENT
%token tDOTPROD
%token tIF
%token tENDIF
%token tREALNUM
%token tINTNUM
%token tAND
%token tOR
%token tGT
%token tLT
%token tGTE
%token tLTE
%token tNE
%token tEQ

%start prog

%%
prog: stmtlst;

stmtlst: stmt |
       stmt stmtlst;

stmt:	decl |	 
	asgn |
	if;

decl: type vars '=' expr ';' ;

vars: tIDENT |
      vars ',' tIDENT
;
type: tINTTYPE |
      tINTVECTORTYPE |
      tINTMATRIXTYPE |
      tREALVECTORTYPE |
      tREALMATRIXTYPE |
      tREALTYPE ;

asgn: tIDENT '=' expr  ';' ;
	
if: tIF '(' bool ')' stmtlst tENDIF; 

expr: value|
      vectorLIT|
      matrixLIT|
      expr '*' expr|
      expr '+' expr|
      expr '-' expr|
      expr '/' expr|
      expr tDOTPROD expr|
      transpose;

transpose: tTRANSPOSE '(' expr ')' ;
vectorLIT: '[' row ']';
matrixLIT: '['rows ']';
row: value|
     value ',' row;
rows: row ';' row|
      row ';' rows;

value: tINTNUM|
       tREALNUM|
       tIDENT;   
bool: comp|
      bool tOR bool|
      bool tAND bool;
comp: tIDENT relation tIDENT;
relation: tGT| tLT| tGTE| tLTE| tNE| tEQ;

%%

int main (void)
{
if(yyparse())
{printf("ERROR\n");}
else
{printf("OK\n");}
}
