#include<stdio.h>
#define Max 20

int stack[Max], top=-1;

int isEmpty()
{
return top==-1;
}

int isFull()
{
return top == Max - 1;
}

void push(int x)
{
if (isFull())
{
printf("Stack is overflow, no push operation possible. \n");
}
else
{
top=top+1;
stack[top]=x;
printf("element %d is pushed in the stack and its index is %d. \n", x, top); 
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
printf("element %d is poped from the stack, and the value of top index is %d. \n", stack[top], top-1); 
top=top-1;
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
printf("Top most element of stack is %d, and the index is %d. \n", stack[top], top); 
}
}

void main()
{
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
printf("value of top is %d.",top);
}