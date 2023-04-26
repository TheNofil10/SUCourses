
%{ 
#include <stdio.h> 
%} 

%% 
^[-][0-9][E]+"."[0-9]+           printf("tNEGREAL");
[0-9][E]+"."+[0-9]+      printf("tPOSREAL");
^[-][0-9][E]+         printf("tNEGINT");
[0-9][E]+         printf("tPOSINT");
. ; 
%% 

int main() 
{ 
yylex(); 
} 
