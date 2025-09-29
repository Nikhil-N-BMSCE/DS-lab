#include <stdio.h>
char infix[20],postfix[20],stack[20];
int top = -1,po=0,in=0;
void push(char);
char pop();
int pre(char);
int main(){
     for (int i = 0; i < 20; i++) {
        infix[i] = postfix[i] = stack[i] = '\0';
    }
    top = -1; po = 0; in = 0;
    printf("Enter a valid infix expression \n");
    scanf("%s",infix);
    while(infix[in] != '\0'){
        char c = infix[in];
        char t;
        switch(c){
            case '(' : push('(');
                        break;
            case  ')' : t = pop();
                        while(t != '('){
                            if(po < 20)postfix[po++] = t;
                            t = pop();
                        }
                        break;
            case  '+' :
            case  '-' :
            case  '*' :
            case  '/' :while(top != -1 && pre(stack[top]) >= pre(c)){
                        char ch = pop();
                        postfix[po++] = ch;
                      }
                      push(c);
                      break;
            default : postfix[po++] = c;
        }
        in++;
    }
    char temp = pop();
    while(temp != '\0'){
        postfix[po++] = temp;
        temp = pop();
    }
    for(int i = 0 ; i < po ; i++){
        printf("%c",postfix[i]);
    }
    return 0; 
}
void push(char c){
    if(top == 19){
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = c;
}
char pop(){
    if(top == -1){
        return '\0';
    }
    char ch = stack[top];
    top--;
    return ch;
}
int pre(char c){
    switch(c){
        case '/':
        case '*':return 3;
        case '+':
        case '-':return 2;
        case '(':return 1;
    }
    return 0;
}