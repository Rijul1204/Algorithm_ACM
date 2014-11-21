#include<stdio.h>
#include<map>
#include<string.h>
#include<string>
#include<queue>
using namespace std;

#define inf 99999

typedef struct{
	char s[100];
}str;

str strs[300];
int matrix[300][300];
int dis[300],color[300];
char source[300],end[300];

int bfs(int start,int fin,int n);
void reset(int n);
void set(int n);

int main(){

	int i,j,k,len,test,count,temp,so,en;
	bool blank=false;
	char total[700],dum;

	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){
		count=0;

		while(1){
			scanf("%s%c",strs[count++].s,&dum);
			if(!strcmp(strs[count-1].s,"*")) break;
		}
		count--;
		reset(count);

		for(i=0;i<count;i++){
			len=strlen(strs[i].s);
			for(j=i+1;j<count;j++){
			  if(len!=strlen(strs[j].s)) continue;
				temp=0;
				for(k=0;k<len;k++){
					if(strs[i].s[k]!=strs[j].s[k]) temp++;
				}
				if(temp==1) matrix[i][j]=matrix[j][i]=1;
			}
		}
		
        if(blank) printf("\n");
		blank=true;
		        
		while(gets(total)){
			if(!total[0]) break;
			set(count);
			for(i=0;total[i]!=' ';i++){
				source[i]=total[i];
			}
			source[i]='\0';
            for(j=0,i=i+1;total[i];i++,j++){
				end[j]=total[i];
			}
			end[j]='\0';
			
			for(i=0;i<count;i++){
				if(strcmp(source,strs[i].s)==0) so=i;
				if(strcmp(end,strs[i].s)==0) en=i;
			}
			printf("%s %s %d\n",source,end,bfs(so,en,count));

		}


	}

	return 0;

}

int bfs(int start,int fin,int n){

	dis[start]=0;
	int temp;

	queue<int>myqueue;

	myqueue.push(start);

	while(!myqueue.empty()){

		temp=myqueue.front();
		myqueue.pop();
		color[temp]=2;

		for(int i=0;i<n;i++){
			if(matrix[i][temp]==1&&color[i]==0){
				dis[i]=dis[temp]+1;
				color[i]=1;
				myqueue.push(i);
			}
		}
	}

	return dis[fin];

}





void reset(int n){

	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			matrix[i][j]=inf;
		}
	}
}

void set(int n){

	for(int i=0;i<=n;i++){
		dis[i]=inf;
		color[i]=0;
	}
}
		

	

		


