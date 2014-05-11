#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<stack>
#include<string.h>
using namespace std;



struct node{
	int move;
	char grid[100];
};

int dist[100000];
map<string,int>state;
queue<node>q;
int count1=1;

char s[1000];

void bfs(node s);

int main(){

	int i,j,k,l,ret,ans,flag,e,n,test;
	char temp[1000];

	state.clear();
	node temp1;
	strcpy(temp1.grid,"1111121111220112222122222");
	temp1.move=0;
	bfs(temp1);
//	printf("%d\n",count1);
//	freopen("in.txt","r",stdin);

	scanf("%d",&test);
	gets(temp);

	while(test--){

		strcpy(s,"");
		
		k=0;
		for(i=0;i<5;i++){
			gets(temp);		
			for(j=0;temp[j];j++){
				if(temp[j]==' ') s[k++]='0';
				else if(temp[j]=='0') s[k++]='2';
				else if(temp[j]=='1') s[k++]='1';
			}
		}
		s[k]='\0';
	//	printf("%s\n%d\n",s,state[s]);
			
		
		if(!state[s]){
			printf("Unsolvable in less than 11 move(s).\n");
		}
		else{
			printf("Solvable in %d move(s).\n",dist[state[s]]);
		}
	}

	return 0;

}

void bfs(node s){

	int i,j,k,l;
	node temp,temp1;
	char st[100],stt[100];
	state[s.grid]=count1++;
	dist[state[s.grid]]=0;
	q.push(s);

	while(!q.empty()){

		temp=q.front(); q.pop();
		strcpy(st,temp.grid);
	//	if(state[temp.grid]<10) printf("%s %d\n",temp.grid,state[temp.grid]);

		for(i=0;st[i];i++){
			if(st[i]=='0') break;
		}
		
		strcpy(stt,st);
		//upper--left........
		j=i-11;
		if(j>=0&&i%5>0){
			stt[i]=stt[j];
			stt[j]='0';
			
			if(state[stt]==0&&temp.move<10){
				temp1.move=temp.move+1;
	    		strcpy(temp1.grid,stt);
				state[stt]=count1++;
				dist[state[stt]]=temp1.move;
				q.push(temp1);
			}
		//	puts(stt);
		//	printf("%d\n",state[stt]);
		}
		
		strcpy(stt,st);
		//upper--right........
		j=i-9;
		if(j>=0&&i%5<4){
			stt[i]=stt[j];
			stt[j]='0';
			if(state[stt]==0&&temp.move<10){
				temp1.move=temp.move+1;
	    		strcpy(temp1.grid,stt);
				state[stt]=count1++;
				dist[state[stt]]=temp1.move;
				q.push(temp1);
			}
		}

		strcpy(stt,st);
		//left--upper........
		j=i-7;
		if(j>=0&&i%5>1){
			stt[i]=stt[j];
			stt[j]='0';
			if(state[stt]==0&&temp.move<10){
				temp1.move=temp.move+1;
	    		strcpy(temp1.grid,stt);
				state[stt]=count1++;
				dist[state[stt]]=temp1.move;
				q.push(temp1);
			}
		}

		strcpy(stt,st);
		//right--upper........
		j=i-3;
		if(j>=0&&i%5<3){
			stt[i]=stt[j];
			stt[j]='0';
			if(state[stt]==0&&temp.move<10){
				temp1.move=temp.move+1;
	    		strcpy(temp1.grid,stt);
				state[stt]=count1++;
				dist[state[stt]]=temp1.move;
				q.push(temp1);
			}
		}

		strcpy(stt,st);
		//left--lower........
		j=i+3;
		if(j<25&&i%5>1){
			stt[i]=stt[j];
			stt[j]='0';
			if(state[stt]==0&&temp.move<10){
				temp1.move=temp.move+1;
	    		strcpy(temp1.grid,stt);
				state[stt]=count1++;
				dist[state[stt]]=temp1.move;
				q.push(temp1);
			}
		}

		strcpy(stt,st);
		//right--lower........
		j=i+7;
		if(j<25&&i%5<3){
			stt[i]=stt[j];
			stt[j]='0';
			if(state[stt]==0&&temp.move<10){
				temp1.move=temp.move+1;
	    		strcpy(temp1.grid,stt);
				state[stt]=count1++;
				dist[state[stt]]=temp1.move;
				q.push(temp1);
			}
		}

		strcpy(stt,st);
		//lower--left........
		j=i+9;
		if(j<25&&i%5>0){
			stt[i]=stt[j];
			stt[j]='0';
			if(state[stt]==0&&temp.move<10){
				temp1.move=temp.move+1;
	    		strcpy(temp1.grid,stt);
				state[stt]=count1++;
				dist[state[stt]]=temp1.move;
				q.push(temp1);
			}
		}

		strcpy(stt,st);
		//lower--right........
		j=i+11;
		if(j<25&&i%5<4){
			stt[i]=stt[j];
			stt[j]='0';
			if(state[stt]==0&&temp.move<10){
				temp1.move=temp.move+1;
	    		strcpy(temp1.grid,stt);
				state[stt]=count1++;
				dist[state[stt]]=temp1.move;
				q.push(temp1);
			}
		}




	}


}