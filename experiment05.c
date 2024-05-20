// Write a program to convert infix expression to its corresponding postfix and prefix expressions and vice versa

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int Precedence(char op){
	switch(op){
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		default:
			return 0;
		
	}
}
char* convertInfixToPostfix(char *str){
	
	int i,x=0,top=-1;
	char operator[50];
	char *s =(char*)malloc(strlen(str)+1);
	for(i=0; str[i]!='\0'; i++){
		char ch=str[i];
		if((ch>=48 && ch<=57)||(ch>=65 && ch<=90)||(ch>=97 && ch<=122))
			s[x++]=str[i];
		else if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
			if(top==-1)
				operator[++top]=ch;
			else{
				while(top!=-1 && Precedence(ch)<=Precedence(operator[top]))
					s[x++]=operator[top--];
				operator[++top]=ch;
			}
		}
		else if(ch=='(')
			operator[++top]=ch;
		else if(ch==')'){
			while(operator[top]!='('){
				s[x++]=operator[top--];
			}
			top--;
		}
	}
	while(top!=-1){
		s[x++]=operator[top--];
	}
	s[x]='\0';
	return s;
}
char* convertInfixToPrefix(char *str){  
	
	int i,x=0,top=-1;
	char operator[50];
	char *s =(char*)malloc(strlen(str)+1);
	for(i=strlen(str)-1; i>=0; i--){
		char ch=str[i];
		if((ch>=48 && ch<=57)||(ch>=65 && ch<=90)||(ch>=97 && ch<=122))
			s[x++]=str[i];
		else if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
			if(top==-1)
				operator[++top]=ch;
			else{
				while(top!=-1 && Precedence(ch)<=Precedence(operator[top]))
					s[x++]=operator[top--];
				operator[++top]=ch;
			}
		}
		else if(ch==')')
			operator[++top]=ch;
		else if(ch=='('){
			while(operator[top]!=')'){
				s[x++]=operator[top--];
			}
			top--;
		}
	}
	while(top!=-1){
		s[x++]=operator[top--];
	}
	s[x]='\0';
	return strrev(s);
}
char* convertPostfixToInfix(char *exp){
	char stack[100][100];
	int top=-1, i;
	for(i=0; exp[i]!='\0'; i++){
		char ch=exp[i];
		if(isalnum(ch)){
			char temp[]={ch,'\0'};
			strcpy(stack[++top],temp);
		}
		else if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
			char *s1=stack[top--];
			char *s2=stack[top--];
			char s3[100]="";
			snprintf(s3,100,"(%s%c%s)",s2,ch,s1);
			strcpy(stack[++top],s3);
		}
	}
	char *s=(char*)malloc(strlen(stack[top])+1);
	strcpy(s,stack[top]);
	return s;
}
char* convertPrefixToInfix(char *exp){
	char stack[100][100];
	int top=-1, i;
	for(i=strlen(exp)-1; i>=0; i--){
		char ch=exp[i];
		if(isalnum(ch)){
			char temp[]={ch,'\0'};
			strcpy(stack[++top],temp);
		}
		else if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
			char *s1=stack[top--];
			char *s2=stack[top--];
			char s3[100]="";
			snprintf(s3,100,"(%s%c%s)",s1,ch,s2);
			strcpy(stack[++top],s3);
		}
	}
	char *s=(char*)malloc(strlen(stack[top])+1);
	strcpy(s,stack[top]);
	return s;
}
int main(){
	char str[100];
	printf("Enter Infix Expression : ");
	gets(str);
	printf("Postfix form of Infix expression %s is %s\n",str,convertInfixToPostfix(str));
	printf("Prefix form of Infix expression %s is %s\n",str,convertInfixToPrefix(str));
	
	printf("Enter Postfix Expression : ");
	gets(str);
	printf("Infix form of postfix expression %s is %s\n",str,convertPostfixToInfix(str));
	
	printf("Enter Prefix Expression : ");
	gets(str);
	printf("Infix form of prefix expression %s is %s\n",str,convertPrefixToInfix(str));
	return 0;
}
