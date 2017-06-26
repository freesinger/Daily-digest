#pragma once

typedef int  Status, SElemType; 
typedef struct{  
    SElemType *base;  
    SElemType *top;  
    int      stacksize;  
}SqStack;

Status InitStack(SqStack *S);
Status StackEmpty(SqStack S);
Status Push(SqStack *S, SElemType e);
Status Pop(SqStack *S, SElemType *e);
Status ListTraverse(SqStack S, Status (*visit)(SElemType));
Status output(SElemType e);