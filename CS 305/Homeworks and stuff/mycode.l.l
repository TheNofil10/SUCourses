[int] tINT
[real] tREAL
[if] tIF
[endif] tENDIF
[vector] tVECTOR
[matrix] tMATRIX
[transpose] tTRANSPOSE
%%
tINT printf("tIF");
tREAL printf("tREAL");
tIF printf("tIF");
tENDIF printf("tENDIF");
tVECTOR printf("tVECTOR");
tMATRIX printf("tMATRIX");
tTRANSPOSE printf("tTRANSPOSE");

%%

int main()
{
yylex();
}