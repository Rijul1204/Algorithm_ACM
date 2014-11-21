#include<stdio.h>
#include<map>
#include<queue>
using namespace std;

#define inf 9999999


map<char,int>first;
int matrix[50][50],pre[50],dis[50],color[50];

void bfs(int s,int n);
void set();
void setm();
void print(int n);


int main(){

	int i,j,test,n,q,node,soln[100],c;
    bool flag=false;
	char dum,temp1[100],temp2[100];

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		setm();

		scanf("%d %d%c",&n,&q,&dum);

		for(i=1;i<=n;i++){
			scanf("%s %s%c",temp1,temp2,&dum);
    		matrix[temp1[0]-'A'][temp2[0]-'A']=matrix[temp2[0]-'A'][temp1[0]-'A']=1;
		}
        
		if(flag) printf("\n");
		flag=true;
		for(j=1;j<=q;j++){
			c=0;
			set();
			scanf("%s %s%c",temp1,temp2,&dum);
			bfs(temp1[0]-'A',temp2[0]-'A');
			node=temp2[0]-'A';
			print(temp2[0]-'A');
			printf("\n");
		}

	}

	return 0;

}

void bfs(int s,int n){

	queue<int>myqueue;
    int temp;

	myqueue.push(s);

	dis[s]=0;
	pre[s]=-1;

	while(!myqueue.empty()){
		temp=myqueue.front();
		myqueue.pop();
		color[temp]=2;
		if(color[n]==2) break;

		for(int i=0;i<26;i++){
			if(matrix[temp][i]==1){
				if(color[i]==0){
					color[i]=1;
					dis[i]=dis[temp]+1;
					pre[i]=temp;
					myqueue.push(i);
				}
			}
		}
	}

}

void set(){

	for(int i=0;i<=26;i++){
		dis[i]=inf;
		color[i]=0;
		pre[i]=-1;
	}
}

void setm(){

	for(int i=0;i<=26;i++){
		for(int j=0;j<=26;j++){
			matrix[i][j]=0;
		}
	}
}

void print(int n){
    
	if(n>=0){
	if(pre[n]==-1){
		printf("%c",n+'A');
		return ;
	}
    print(pre[n]);
	printf("%c",n+'A');

	}

}







		


		

