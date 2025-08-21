#include<stdio.h>
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
printf("element %d is pushed in the stack and its index is %d. \n", x, s1.top); 
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
printf("element %d is poped from the stack, and the value of top index is %d. \n", s1.S[s1.top], s1.top-1); 
s1.top=s1.top-1;
}
}

void print_top()
{
if(isEmpty())
{
printf("Stack is Empty, no element for print. \n");
}
else
{
printf("Top most element of stack is %d, and the index is %d. \n", s1.S[s1.top], s1.top); 
}
}

void main()
{
s1.top = -1;
push(1);
push(3);
push(5);
pop();
push(2);
push(4);
pop();
pop();
pop();
pop();
pop();
printf("value of top is %d.",s1.top);
}