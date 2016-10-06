#include "stdio.h"
#include "stdlib.h"
#include "conio.h"


struct List 
{
	char symb;
	List *next;
};

void Add(List **node,char c)
{
	List *B=new List;
		B->next=*node;
		B->symb=c;
		*node=B;
}


bool isCorrect (char* _string)
{
	List *A=0;
	for (int i=0; _string[i]!=0; i++)
	
		if ((_string[i]=='{') || (_string[i]=='[') || (_string[i]=='('))
		{
			Add(&A,_string[i]);
		}
		else
			{
					if (A==0)
					return false;
				if ((A->symb!='[') && (_string[i]==']'))
					return false;
				if ((A->symb!='{') && (_string[i]=='}'))
					return false;
				if ((A->symb!='(') && (_string[i]==')'))
					return false;
				A=A->next;
		   }		
	
	if (A==0)
		return true;
	else
		return false;
}
	
void Tests (char* _string)
{
	if (isCorrect(_string)==true)
		printf ("%s :right answer\n", _string);
	else
		printf ("%s :wrong answer\n", _string);
}


void main(void)
{
	char S_1[8]="({[]})";
	char S_2[7]="((({[)";
	char S_3[12]="(){}[]()()";
	char S_4[10]="(){}[]((";
	char S_5[6]="[(}]";
	char S_6[8]="{[(})]";
	char S_7[3]="(";
	char S_8[1]="";
	char S_9[3]="}";
	Tests (S_1);
	Tests (S_2);
	Tests (S_3);
	Tests (S_4);
	Tests (S_5);
	Tests (S_6);
	Tests (S_7);
	Tests (S_8);
	Tests (S_9);
	_getch();
}