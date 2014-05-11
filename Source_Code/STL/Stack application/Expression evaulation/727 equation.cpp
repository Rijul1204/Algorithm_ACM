#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stack>
#include<map>
using namespace std;

stack<char>post;
map<char,int>operate;
char infix[1100],postfix[1100];

void convert();

int main(){
	
	int i,j,test,count;
	bool flag=false;
	char temp[15],dum,help[10];
	
//	freopen("in.txt","r",stdin);
	
	scanf("%d%c",&test,&dum);
	gets(help);
	
	while(test--){
		
		count=0;postfix[0]='\0';
		
		while(gets(temp)){			
			if(!temp[0]) break;
			infix[count++]=temp[0];
		}
		
		infix[count]='\0';
		
		convert();
		if(flag) printf("\n");
		flag=true;
		
		puts(postfix);
	}
	
	return 0;
	
}

void convert(){
	
	operate['/']=4;
	operate['*']=4;
	operate['+']=3;
	operate['-']=3;
	operate['%']=4;
	
	post.push('(');
	strcat(infix,")");
	
	char temp;
	int count=0;
	
	while(!post.empty()){
		
		
		for(int i=0;infix[i];i++){
			
			if(isdigit(infix[i])){
				while(isdigit(infix[i])){
					postfix[count++]=infix[i];
					i++;
				}
			//	postfix[count++]=' ';
				i--;
			}
			else if(infix[i]=='(') post.push('(');
			else if(infix[i]==')'){
				
				temp=post.top();
				
				while(temp!='('){
					postfix[count++]=temp;
					post.pop();
					temp=post.top();
				}
				post.pop();
				
			}
			else if(infix[i]==' ') postfix[count++]=' ';
			else{
				temp=post.top();
				while(1){
					if(temp=='+'||temp=='-'||temp=='*'||temp=='/'){
						if(operate[temp]>=operate[infix[i]]){
							postfix[count++]=temp;
						}
						else break;
						post.pop();
						temp=post.top();
					}
					else break;				
					
				}
				post.push(infix[i]);
			}
			
		}
		
	}
	
	postfix[count]='\0';
	
}
















