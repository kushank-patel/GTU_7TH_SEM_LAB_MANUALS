%{
int vow_count=0;
int const_count =0;
%}

%%
[aeiouAEIOU] {vow_count++;}
[a-zA-Z] {const_count++;}
%%

main()
{
printf("Enter the string of vowels and consonents:");
yylex();
printf("The number of vowels are:  %d\n",vow);
printf("The number of consonants are:  %d\n",cons);
return 0;
}