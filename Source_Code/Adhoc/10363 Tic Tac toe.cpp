#include<stdio.h>

char grid[10][10];
int flag[12];

int main(){

	int i,j,k,l,test,winx,winy;
	
//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		k=0; l=0; j=0;
		winx=winy=0;
		for(i=0;i<=8;i++) flag[i]=0;
		for(i=0;i<3;i++){
			scanf("%s",grid[i]);
		}
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				if(grid[i][j]=='X') k++;
				else if(grid[i][j]=='O') l++;
			}
		}
		j=0;
		if(grid[0][0]==grid[0][1]&&grid[0][0]==grid[0][2]&&grid[0][0]=='X') winx=1;
		if(grid[0][0]==grid[0][1]&&grid[0][0]==grid[0][2]&&grid[0][0]=='O') winy=1;

		if(grid[1][0]==grid[1][1]&&grid[1][0]==grid[1][2]&&grid[1][0]=='X') winx=1;
		if(grid[1][0]==grid[1][1]&&grid[1][0]==grid[1][2]&&grid[1][0]=='O') winy=1;

		if(grid[2][0]==grid[2][1]&&grid[2][0]==grid[2][2]&&grid[2][0]=='X') winx=1;
		if(grid[2][0]==grid[2][1]&&grid[2][0]==grid[2][2]&&grid[2][0]=='O') winy=1;
		
		if(grid[0][0]==grid[1][0]&&grid[0][0]==grid[2][0]&&grid[0][0]=='X') winx=1;
		if(grid[0][0]==grid[1][0]&&grid[0][0]==grid[2][0]&&grid[0][0]=='O') winy=1;
		
		if(grid[0][1]==grid[1][1]&&grid[0][1]==grid[2][1]&&grid[0][1]=='X') winx=1;
		if(grid[0][1]==grid[1][1]&&grid[0][1]==grid[2][1]&&grid[0][1]=='O') winy=1;
		
		if(grid[0][2]==grid[1][2]&&grid[0][2]==grid[2][2]&&grid[0][2]=='X') winx=1;
		if(grid[0][2]==grid[1][2]&&grid[0][2]==grid[2][2]&&grid[0][2]=='O') winy=1;
		
		if(grid[0][0]==grid[1][1]&&grid[0][0]==grid[2][2]&&grid[0][0]=='X') winx=1;
		if(grid[0][0]==grid[1][1]&&grid[0][0]==grid[2][2]&&grid[0][0]=='O') winy=1;
		
		if(grid[0][2]==grid[1][1]&&grid[0][2]==grid[2][0]&&grid[0][2]=='X') winx=1;
		if(grid[0][2]==grid[1][1]&&grid[0][2]==grid[2][0]&&grid[0][2]=='O') winy=1;
		
		if(l>k||k>l+1){
			printf("no\n");
			continue;
		}
		if(winx&&winy){
			printf("no\n");
			continue;
		}
		if(winx){
			if(l>=k) printf("no\n");
			else printf("yes\n");
			continue;
		}
		if(winy){
			if(k>l) printf("no\n");
			else printf("yes\n");
			continue;
		}			

		printf("yes\n");
	
	}



	return 0;
}