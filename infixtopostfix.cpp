#include<iostream>
#include<cstring>
using namespace std;

class stack{
private:
int top;
char arr[100];
public:
stack()
{
top=-1;
}
void push(char c)
{
if(top<99)
{
arr[++top]=c;
}
else{
cout<<"Stack Overflow"<<endl;
}
}
char pop(){
if(top>=0)
{
return arr[top--];
}
else{
cout<<"Stack underflow"<<endl;
return'\0';
}
}
char peek(){
if(top>=0){
return arr[top];
}
else{
return '\0';
}
}
bool isEmpty()
{
return top==-1;
}
};
int precedence(char op){
if(op=='+'||op=='-'){
return 1;
}else if(op=='*'||op=='/'){
return 2;
}else if(op=='^'){
return 3;
}
return 0;
}
bool isOperator(char c){
return(c=='+'||c=='-'||c=='*'||c=='/'||c=='^');
}
void infixToPostfix(char infix[],char postfix[]){
stack s;
int j=0;
for(int i=0;i<strlen(infix);i++){
char c=infix[i];
if(isalnum(c)){
postfix[j++]=c;
}
else if(c=='('){
s.push(c);
}
else if(c==')'){
while(!s.isEmpty()&&s.peek()!='('){
postfix[j++]=s.pop();
}
s.pop();
}
else if(isOperator(c)){
while(!s.isEmpty()&&precedence(s.peek())>=precedence(c)){
postfix[j++]=s.pop();
}
s.push(c);
}
}
while(!s.isEmpty()){
postfix[j++]=s.pop();
}
postfix[j]='\0';
}
int main(){
char infix[100],postfix[100];
cout<<"Enter an Infix Expression:";
cin>>infix;
infixToPostfix(infix,postfix);
cout<<"Postfix Expression:"<<postfix<<endl;
return 0;
}
