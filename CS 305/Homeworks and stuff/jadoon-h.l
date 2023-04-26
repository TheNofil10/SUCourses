%{ 
#include <stdio.h> 

int num=1;
%} 

%%
\n num++;
"int" printf("%d",num); printf(" "); printf("tINT\n");
"real" printf("%d",num); printf(" "); printf("tREAL\n");
"if" printf("%d",num); printf(" "); printf("tIF\n");
"endif" printf("%d",num); printf(" "); printf("tENDIF\n");
"vector" printf("%d",num); printf(" "); printf("tVECTOR\n");
"matrix" printf("%d",num); printf(" "); printf("tMATRIX\n");
"transpose" printf("%d",num); printf(" "); printf("tTRANSPOSE\n");
[a-zA-Z_]+[a-zA-Z0-9_]*  printf("%d",num); printf(" "); printf("tIDENT"); printf(" "); printf("(%s)\n",yytext);
"//".*\n {};
-[0-9]+"."[0-9]*E?-?[0-9]* printf("%d",num); printf(" "); printf("tNEGREAL"); printf(" "); printf("(%s)\n",yytext);
[0-9]+"."[0-9]*E?-?[0-9]* printf("%d",num); printf(" "); printf("tPOSREAL"); printf(" "); printf("(%s)\n",yytext);
-[0-9]+E?[0-9]+ printf("%d",num); printf(" "); printf("tNEGINT"); printf(" "); printf("(%s)\n",yytext);
[0-9]+E?[0-9]+ printf("%d",num); printf(" "); printf("tPOSINT"); printf(" "); printf("(%s)\n",yytext);
"," printf("%d",num); printf(" "); printf("tCOMMA\n");
".*" printf("%d",num); printf(" "); printf("tDOTPROD\n");
"(" printf("%d",num); printf(" "); printf("tLPAR\n");
")" printf("%d",num); printf(" "); printf("tRPAR\n");
"=" printf("%d",num); printf(" "); printf("tASSIGNM\n");
"+" printf("%d",num); printf(" "); printf("tPLUS\n");
"*" printf("%d",num); printf(" "); printf("tSTAR\n");
"==" printf("%d",num); printf(" "); printf("tEQUL\n");
"<" printf("%d",num); printf(" "); printf("tLT\n");
">" printf("%d",num); printf(" "); printf("tGT\n");
"[" printf("%d",num); printf(" "); printf("tLBRAC\n");
"]" printf("%d",num); printf(" "); printf("tRBRAC\n");
"&&" printf("%d",num); printf(" "); printf("tAND\n");
"/" printf("%d",num); printf(" "); printf("tDIV\n");
";" printf("%d",num); printf(" "); printf("tSEMI\n");
"!=" printf("%d",num); printf(" "); printf("tINEQ\n");
"<=" printf("%d",num); printf(" "); printf("tLE\n");
">=" printf("%d",num); printf(" "); printf("tGE\n");
"||" printf("%d",num); printf(" "); printf("tOR\n");
"-" printf("%d",num); printf(" "); printf("tMINUS\n");

. {}
%%


int main()
{

yylex();

}