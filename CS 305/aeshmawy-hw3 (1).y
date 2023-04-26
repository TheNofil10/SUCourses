%{
#include <stdio.h>
#include <stdlib.h>
void yyerror (const char *s) 
{
	printf ("%s\n", s); 
}
int linenumber = 1;

%}

%locations

%code requires{ //you can define this in the C part of the code above but it kept giving me an error that the struct
//isnt defined so i tried this and it worked.
typedef struct dimensions{//define the struct to contain the two int values rows and columns
	int rows;
	int columns;
}dimensions;
}

%union {//union just to define the struct as a type
dimensions x;
}

//make it so that all the token are able to use the struct you defined by writing <x> at the beginning
%token <x> tINTTYPE tINTVECTORTYPE tINTMATRIXTYPE tREALTYPE tREALVECTORTYPE tREALMATRIXTYPE tTRANSPOSE tIDENT tDOTPROD tIF tENDIF tREALNUM tINTNUM tAND tOR tGT tLT tGTE tLTE tNE tEQ tNEW

//define some of the things to have type x. only the important one cause otherwise it crashed for me.
//so we only neeed these to have teh struct
%type <x> row rows matrixLit expr transpose value vectorLit

%left '='
%left tOR
%left tAND
%left tEQ tNE
%left tLTE tGTE tLT tGT
%left '+' '-'
%left '*' '/'
%left tDOTPROD
%left '(' ')'
%left tTRANSPOSE

%start prog

%%


prog: 		stmtlst
;

stmtlst:	stmtlst stmt 
		| stmt
;

stmt:       decl 
            | asgn 
            | if 
	    | increment    
;

decl:		type vars '=' expr ';'
;

asgn:		tIDENT '=' expr ';'
;

if:		tIF '(' bool ')' stmtlst tENDIF
;


type:		tINTTYPE
		| tINTVECTORTYPE
            	| tINTMATRIXTYPE
            	| tREALTYPE
            	| tREALVECTORTYPE    
           	| tREALMATRIXTYPE
;
vars:		vars ',' tIDENT
		| tIDENT
;
//check cs305 discussion board if you have any questions about syntax of the expressions
expr:		value      {$$.rows = 0; $$.columns = 0;//not a matrix or a vector.if it just a number make it 
    //have dimesnions 0x0
    } 
		| vectorLit {$$.rows = $1.rows; $$.columns = $1.columns;//rows is always one for vector lit
									//and columns is calculate in row 
									//then moved to vector lit 
									//so we can access it here
}
  		| matrixLit {$$.rows = $1.rows; $$.columns = $1.columns;
//same logic as last comment. but row isnt always 1 now
	}
            	| expr	'*' expr
		{
 		//for the multiplication operation the left should have teh same number of columns as
		//the right has rows NOTE that $2 is * symbol
			if($1.columns == 0 && $1.rows == 0) //checking if one is a scalar
			{
			  $$.rows = $3.rows;
			  $$.columns = $3.columns;
			}
			else if($3.columns == 0 && $3.rows == 0 )//checking if the otehr is a scalar
			{
			 $$.rows = $1.rows;
			 $$.columns = $1.columns;
			}
			//if both arent scalar. then both are matrices/vectors
			else if($1.columns != $3.rows) //checking if its two conflicting matrices
			{
			  printf("Error 2: %d dimension mismatch\n",linenumber);
			  exit(1);
			}
			else//if its two matrices
			{	
			$$.rows = $1.rows;
			$$.columns = $3.columns;
			}

		}
            	| expr	'/' expr 
		{//has the same condition as multiplication with 
		 //the added condition of the righthand side matrix being square
			if($1.columns == 0 && $1.rows == 0 &&  $3.columns == $3.rows) //checking if one is a scalar
			{
			  $$.rows = $3.rows;
			  $$.columns = $3.columns;
			}
			else if($3.columns == 0 && $3.rows == 0 )//checking if the otehr is a scalar
			{
			 $$.rows = $1.rows;
			 $$.columns = $1.columns;
			}
			else if($1.columns != $3.rows || $3.columns != $3.rows)//second condition checks if its square
			{
			  printf("Error 2: %d dimension mismatch\n",linenumber);
			  exit(1);
			}
			else
			{
			 $$.rows = $1.rows;
			 $$.columns = $1.columns;
			}
			
		
			
		}
            	| expr	'+' expr 
		{//both matrices have to have the same dimensions
			if($1.columns != $3.columns || $1.rows != $3.rows)
			{
			  printf("Error 2: %d dimension mismatch\n",linenumber);
			  exit(1);
			}
			$$.rows = $1.rows;
			$$.columns = $1.columns;
		}
            	| expr	'-' expr 
		{//both matrices have to have the same dimensions
			if($1.columns != $3.columns || $1.rows != $3.rows)
			{
			  printf("Error 2: %d dimension mismatch\n",linenumber);
			  exit(1);
			}
			$$.rows = $1.rows;
			$$.columns = $1.columns;
		}
            	| expr tDOTPROD expr 
		{//should only work for vector dot product vector of vectors of the same size
		// as per the discussion forum
			if($1.rows != 1 || $3.rows != 1 || $1.columns != $3.columns) 
			{
			  printf("Error 2: %d dimension mismatch\n",linenumber);
			  exit(1);
			}
		}
		| transpose {//no need for checks
}
;    

transpose: 	tTRANSPOSE '(' expr ')'
;

vectorLit:	'[' row ']' {//vector always has only one row and the same number of columns as row
				$$.columns = $2.columns;
				$$.rows = 1;
}
;

row:		 value {        //i switched it around a bit cause i was experimenting so be careful.
   				//the syntax given should be right if you wanna use it
				//for teh first value you see increment once
				$$.columns = $$.columns + 1;	
 		       }
		|value ','  row {  //this is the recursive part and were basically just finding the number of columns
				  $$.columns = $3.columns + 1;  
				 			
				}
;

matrixLit: 	'[' rows ']' {    $$.rows = $2.rows;//the matrix should have the same number of columns and rows
	 					   // as the rows expression
                                  $$.columns = $2.columns;
				}
;

rows:		row ';' row  {
				if($1.columns == $3.columns)//this is the first part(non-recursive)
			      {                             //check if both left row and right row have the same num 
							    // of columns
				$$.columns = $3.columns;//make the rows number of columns the same as the row number of column. (doesnt matter if you use $3 or $1 here)
				$$.rows = $$.rows + 2;//+2 since you only enter here with two rows
						     // and the intial value is 0 so increment twice
			      }
				else//if not print error message
				{printf("Error 1: %d inconsistent matrix size\n",linenumber);
				exit(1);}		
    			     }
		| rows ';' row { if($1.columns == $3.columns)//recursive part. just check if the number of row of
								// current row is the same as all the other rows
			       {
				$$.columns = $3.columns;//note this? i think this line is unnecessary but not sure
				$$.rows = $$.rows + 1;//increment number of rows each time to ccount them
			        }
				else//if number of columns is different print error
				{printf("Error 1: %d inconsistent matrix size\n",linenumber);
				exit(1);}
}

;


value:		tINTNUM 
		| tREALNUM
;

bool: 		comp
		| bool tAND bool
		| bool tOR bool
;

comp:		tIDENT relation tIDENT
;


relation:	tGT
		| tLT
		| tGTE
            	| tLTE
		| tEQ
		| tNE
;

increment:    tNEW {linenumber++;}
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
