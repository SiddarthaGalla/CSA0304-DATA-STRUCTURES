#include <stdio.h>
#include <ctype.h>

char stack[20];
int top = -1;
void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
int prec(char c) {
    if(c=='*'||c=='/') return 2;
    if(c=='+'||c=='-') return 1;
    return 0;
}
void infixToPostfix(char* exp) {
    int i = 0;
    char ch;
    while((ch = exp[i++]) != '\0') {
        if(isalnum(ch)) printf("%c", ch);
        else if(ch == '(') push(ch);
        else if(ch == ')') {
            while(stack[top] != '(') printf("%c", pop());
            pop();
        }
        else {
            while(top != -1 && prec(stack[top]) >= prec(ch)) printf("%c", pop());
            push(ch);
        }
    }
    while(top != -1) printf("%c", pop());
}
int main() {
    char infix[100] ;
    printf("Enter infix: ");
    scanf("%s",infix);
    infixToPostfix(infix);
    return 0;
}

OUTPUT :
Enter infix: a-b
ab-
