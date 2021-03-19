#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
char st[MAX];
int top=-1;
void push(char st[],char);
char pop(char st[]);
void infixtopostfix(char source[], char target[]);
int getpriority(char);

int main()
{
   clrscr();
   char infix[100], postfix[100];
   printf("Enter an infix expression\n");
   gets(infix);
   strcpy(postfix, "");
   infixtopostfix(infix,postfix);
   printf("Postfix Expression\n");
   puts(postfix);
   getch();
   return 0;
}

void push(char st[], char val)
{
   if(top==MAX-1)
   {
	printf("Stack Overflow\n");
   }
   else
   {
	top+=1;
	st[top]=val;
   }
}

char pop(char st[])
{
   char val=' ';
   if(top==-1)
   {
	printf("Stack Underflow\n");
   }
   else
   {
	val = st[top];
	top--;
   }
   return val;
}

int getpriority(char op)
{
   if(op=='+' || op=='-')
	return 0;
   else if(op=='*' || op=='/' || op=='%')
	return 1;
}

void infixtopostfix(char source[], char target[])
{
   int i=0,j=0;
   char temp;
   strcpy(target, "");
   while(source[i]!='\0')
   {
      if(source[i]=='(')
      {
	 push(st, source[i]);
	 i++;
      }
      else if(source[i]==')')
      {
	 while((top!=-1) && (st[top]!='('))
	 {
	    target[j]=pop(st);
	    j++;
	 }
	 if(top==-1)
	 {
	    printf("INVALID EXPRESSION\n");
	    break;
	 }
	 temp=pop(st);
	 i++;
      }
      else if(isdigit(source[i]) || isalpha(source[i]))
      {
	 target[j]=source[i];
	 j++;
	 i++;
      }
      else if(source[i]=='+' || source[i] == '-' || source[i] == '*' || source[i] == '/' || source[i] == '%')
      {
	 while((top!=-1) && (st[top]!='(') && (getpriority(source[i])) < getpriority(st[top]))
	 {
	    target[j]=pop(st);
	    j++;
	 }
	 push(st, source[i]);
	 i++;
      }
      else
      {
	 printf("Invalid Element in the infix expression\n");
	 break;
      }
   }
   while((top!=-1) && (st[top]=='('))
   {
      target[j]=pop(st);
      j++;
   }
   target[j]='\0';
}