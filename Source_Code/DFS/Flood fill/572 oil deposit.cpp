#include<stdio.h>

void flood(int i,int j);

int R,C;
char oil[105][105];

int main(){
	
	int i,j,k,l,count;
    char help[10];

	while(1){
		scanf("%d %d",&R,&C);
		if(R==0) break;
		count=0;
        gets(help); 
		for(i=0;i<R;i++){
			scanf("%s",oil[i]);
		}
		
		for(i=0;i<R;i++){
			for(j=0;j<C;j++){
				if(oil[i][j]=='@') {
					flood(i,j);
					count++;
				}
			}
		}
		printf("%d\n",count);

	}

	return  0;
}
		
void flood(int i,int j){

	if(i<0||i>=R||j<0||j>=C||oil[i][j]=='*') return ;

	oil[i][j]='*';

	flood(i-1,j-1);
	flood(i+1,j+1);
	flood(i,j+1);
	flood(i,j-1);
	flood(i+1,j);
	flood(i-1,j);
	flood(i-1,j+1);
	flood(i+1,j-1);

}

