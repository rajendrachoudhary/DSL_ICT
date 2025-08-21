#include<stdio.h>
#include <string.h>
#include <ctype.h>

#define Max 20
struct stack 
{
int S[Max];
int top;
};

struct stack s1;

int isEmpty()
{
return s1.top==-1;
}

int isFull()
{
return s1.top == Max - 1;
}

void push(int x)
{
if (isFull())
{
printf("Stack is overflow, no push operation possible. \n");
}
else
{
s1.top=s1.top+1;
s1.S[s1.top]=x;
//printf("element %d is pushed in the stack and its index is %d. \n", x, s1.top); 
}
}

void pop()
{
if(isEmpty())
{
printf("Stack is Empty, no pop operation possible. \n");
}
else
{
//printf("element %d is poped from the stack, and the value of top index is %d. \n", s1.S[s1.top], s1.top-1); 
s1.top=s1.top-1;
}
}

char print_top()
{
if(isEmpty())
printf("Stack is Empty, no element for print. \n");
else
return  s1.S[s1.top]; 
}

int precedence(char op)
{
    switch (op) {
        case '+':
        case '-': 
	return 1;
        case '*':
        case '/': 
	return 2;
        case '^': 
	return 3;
        default:
	 return -1;
    }
}



void infixtopostfix(char infix[])
{
char postfix[Max],c;
int i,j=0;
for(i=0;i<strlen(infix);i++)
{
 c=infix[i];
 if(isalnum(c))
{
postfix[j]=c;
j=j+1;
}
else if (c=='(')
{
push(c);
}
else if (c==')')
{
while (!isEmpty() && print_top() != '(' ) 
{
            postfix[j++] = print_top();
	pop();
}
pop();
}
else
{
while(!isEmpty() && (precedence(c) < precedence(print_top()) || precedence(c) == precedence(print_top())&& c != '^'))
{
 postfix[j++] = print_top();
	pop();
}
push(c);
}
}
while(!isEmpty())
{
 postfix[j++] = print_top();
	pop();
}
  postfix[j] = '\0'; 
printf("%s \n",postfix);
}


void main()
{
s1.top = -1;
char infix[Max];
printf("Enter an infix expression:");
scanf("%s",infix);
infixtopostfix(infix);
}