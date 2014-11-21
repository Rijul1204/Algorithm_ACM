#include<stdio.h>

char s[1000][1000];
int count,w,h;

void flood(int i,int j);

int main(){

	int  i,j;

	//freopen("in.txt","r",stdin);

	while(scanf("%d %d",&w,&h)==2){

		if(!w&&!h) break;

		count=0;

		for(i=0;i<h;i++){
			scanf("%s",s[i]);
		}


		for(i=0;i<=h;i++){
			for(j=0;j<=w;j++){
				if(s[i][j]=='@'){
					flood(i,j);
				}
			}
		}

		printf("%d\n",count);

	}

	return 0;

}

void flood(int i,int j){

	if(s[i][j]=='#') return;

	count++;

	s[i][j]='#';

	if(i+1<h) flood(i+1,j);
	if(j+1<w) flood(i,j+1);
	if(i-1>=0) flood(i-1,j);
	if(j-1>=0) flood(i,j-1);
}




