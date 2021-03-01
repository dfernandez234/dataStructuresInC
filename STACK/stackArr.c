#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int size;
    int top;
    int *Arr;
}s;

typedef s* stackPtr;

void Create(stackPtr *stack, int size){
    (*stack)->top = -1;
    (*stack)->size = size;
    (*stack)->Arr = (int*)malloc((*stack)->size*sizeof(int));
}

void push(stackPtr stack, int val){
    if (stack->top == stack->size-1){
        printf("Stack overflow\n");
    }else{
        stack->top++;
        stack->Arr[stack->top] = val;
    }
}

int pop(stackPtr stack){
    int popped = -1;
    if(stack->top==-1){
        printf("Stack Underflow\n");
    }else{
        popped = stack->Arr[stack->top];
        stack->top--;
    }
    return popped;
}

void display(stackPtr stack){
    int pos = stack->top;
    while(pos!=-1){
        printf("%d\n",stack->Arr[pos--]);
    }
}

int main(int argc, char const *argv[])
{
    stackPtr stack1;
    Create(&stack1,10);

    push(stack1, 10);
    push(stack1, 20);
    push(stack1, 30);
    push(stack1, 40);
    push(stack1, 50);
    display(stack1);

    return 0;
}
