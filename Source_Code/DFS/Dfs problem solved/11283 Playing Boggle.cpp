#include<stdio.h>
#include<string.h>

char grid[10][10],input[20];
bool flag[10][10];
int len,res;

int back(int n,int count);
void flood(int i,int j,int count);

int main(){

	int i,j,k,l,test,n,ret,sum,point,t=1;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		for(i=0;i<4;i++){
			scanf("%s",grid[i]);
		}

		scanf("%d",&n);
        sum=0;
		
		for(i=0;i<n;i++){
			scanf("%s",input);
            len=strlen(input);
			ret=back(0,0);
			//printf("%s->%d\n",input,ret);
			if(ret==1){
				if(len==3||len==4) point=1;
				else if(len==5) point=2;
				else if(len==6) point=3;
				else if(len==7) point=5;
				else if(len>=8) point=11;
				sum+=point;
			}			
		}
		printf("Score for Boggle game #%d: %d\n",t++,sum);
	}

	return 0;

}

int back(int n,int count){

	int i,j,k,l;
    res=0;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(grid[i][j]==input[0]){
				flag[i][j]=1;
				flood(i,j,1);
				flag[i][j]=0;
				if(res==1) return res;
			}
		}
	}

	return res;

}

void flood(int i,int j,int count){
	
	if(count==len) res=1;

	if(res==1) return;

	if(i>0){
		//row above.......
		if(flag[i-1][j]==0&&grid[i-1][j]==input[count]){
			flag[i-1][j]=1;
			flood(i-1,j,count+1);
			flag[i-1][j]=0;
		}
	}
	if(j>0){
		//coloum back.....
		if(flag[i][j-1]==0&&grid[i][j-1]==input[count]){
			flag[i][j-1]=1;
			flood(i,j-1,count+1);
			flag[i][j-1]=0;
		}
	}	
	if(i<3){
		//row  below.........
		if(flag[i+1][j]==0&&grid[i+1][j]==input[count]){
			flag[i+1][j]=1;
			flood(i+1,j,count+1);
			flag[i+1][j]=0;
		}
	}
	if(j<3){
		//column  front.........
		if(flag[i][j+1]==0&&grid[i][j+1]==input[count]){
			flag[i][j+1]=1;
			flood(i,j+1,count+1);
			flag[i][j+1]=0;
		}
	}
	if(i>0&&j>0){
		//diagonally .. upper-left corner.........
		if(flag[i-1][j-1]==0&&grid[i-1][j-1]==input[count]){
			flag[i-1][j-1]=1;
			flood(i-1,j-1,count+1);
			flag[i-1][j-1]=0;
		}
	}
	if(j<3&&i<3){
		//diagonally .. lower-right corner.........
		if(flag[i+1][j+1]==0&&grid[i+1][j+1]==input[count]){
			flag[i+1][j+1]=1;
			flood(i+1,j+1,count+1);
			flag[i+1][j+1]=0;
		}
	}
	if(i>0&&j<3){
		//diagonally .. upper-right corner.........
		if(flag[i-1][j+1]==0&&grid[i-1][j+1]==input[count]){
			flag[i-1][j+1]=1;
			flood(i-1,j+1,count+1);
			flag[i-1][j+1]=0;
		}
	}
	if(j>0&&i<3){
		//diagonally .. lower-left corner.........
		if(flag[i+1][j-1]==0&&grid[i+1][j-1]==input[count]){
			flag[i+1][j-1]=1;
			flood(i+1,j-1,count+1);
			flag[i+1][j-1]=0;
		}
	}
	

	




}



	