%{
#include <stdio.h>
#include "jadoon-ex1.h"
void yyerror (const char *s) 
{
	printf ("%s\n", s); 
}
%}

%left tASSIGNM
%left tPLUS tMINUS
%left tSTAR tDIV tMOD
%left tLPAR tRPAR
%token tINT 
%token tIDENT 
%token tSTRING 
%token tRETURN 
%token tPRINT 
%token tINTVAL 
%token tSTRINGVAL 
%token tLPAR 
%token tRPAR 
%token tCOMMA 
%token tASSIGNM 
%token tMINUS 
%token tPLUS 
%token tDIV 
%token tSTAR 
%token tSEMI 
%token tLBRAC 
%token tRBRAC
%token tMOD





%start prog

%%


prog: 		stmtlst
;
stmtlst:	stmtlst stmt 
			| stmt
;
stmt:      function 
	    |decl
            | asgn
            | print   
;
decl:		type vars tASSIGNM expr tSEMI
;
asgn:		tIDENT tASSIGNM expr tSEMI
;

type:		tINT
		|tSTRING
;
vars:		vars tCOMMA expr
			| expr
;
expr:		value
            | functioncall
            | expr tSTAR expr
            | expr tDIV expr
            | expr tPLUS expr
            | expr tMINUS expr
            | expr tMOD expr
	   
;    

value:		tIDENT
		| tINTVAL
		| tSTRINGVAL
;


functioncall: tIDENT tLPAR vars tRPAR
               
;

function: type tIDENT tLPAR formalpara tRPAR tLBRAC body tRBRAC

;

formalpara: type tIDENT
		|formalpara tCOMMA type tIDENT 
;
body:  body stmtlst return
       |stmtlst return 
;

return: tRETURN expr tSEMI
;

print:  tPRINT tLPAR expr tRPAR tSEMI	
 	
;



%%
int main ()
{
   if (yyparse()) {
   // parse error
       printf("ERROR\n");
       return 1;
   }
   else {
   // successful parsing
      printf("OK\n");
      return 0;
   }
   
}
