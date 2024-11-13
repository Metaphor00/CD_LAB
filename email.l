%{
    #include"y.tab.h"
    #include<stdio.h>
%}
%%
[0-9]*  {return DIGIT;}
[a-zA-Z]*   {return LETTER;}
.com      {return ADDRESS;}
@           {return AT;}
[\t\n]  ;
.   ;
%%