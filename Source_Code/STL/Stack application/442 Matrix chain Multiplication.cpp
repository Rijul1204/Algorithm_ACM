#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<map>
#include<stack>
using namespace std;

struct node{
	int cost;
	int row;
	int col;
};

node matrix;


int main(){
	
	int i,j,k,l,n,r,c;
	bool error,start;
	int row[30],col[30];
	char ch[10],str[1000],str1[1000],cc;
	
	map<char,int>m;
	stack<node>st;
	stack<char>stch;
	
//	freopen("in.txt","r",stdin);
	
	
	while(scanf("%d",&n)==1){
		
		
		for(i=1;i<=n;i++){
			scanf("%s %d %d",ch,&r,&c);
			m[ch[0]]=i;
			row[m[ch[0]]]=r;
			col[m[ch[0]]]=c;
		}
		
			
		while(scanf("%s",str)==1){
			if(strlen(str)==1){
				printf("0\n");
				continue;
			}
			
			error=false;
			node res,temp,temp1;
			start=false;
			
			j=0;
			
			for(i=0;str[i];i++){
				if(str[i]=='('){
					stch.push(str[i]);
				}
				if(isalpha(str[i])){
					stch.push(str[i]);
					temp.col=col[m[str[i]]];
					temp.row=row[m[str[i]]];
					temp.cost=0;
					st.push(temp);
				}
				else if(str[i]==')'){
					while(stch.top()!='('){
						stch.pop();
					}
					stch.pop();
					temp1=st.top();
					st.pop();
					temp=st.top();
					st.pop();
					if(temp.col!=temp1.row){
						error=true;
						//break;
					}
					res.row=temp.row;
					res.col=temp1.col;
					res.cost=temp.row*temp.col*temp1.col+temp1.cost+temp.cost;
					st.push(res);

				}		
				
			}

			if(error){
				printf("error\n");
				continue;
			}


			res=st.top();
			st.pop();

			printf("%d\n",res.cost);
			
			
			
		}
		
		
		
	}
	
	return 0;
	
}