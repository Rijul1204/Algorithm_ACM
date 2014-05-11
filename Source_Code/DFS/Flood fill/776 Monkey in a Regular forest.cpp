#include<stdio.h>
#include<ctype.h>
#include<string.h>

char grid[1000][1000];
int num[1000][1000],color[1000][1000],value[1000],row,col;

void flood(int i,int j,char ch,int val);

int main(){
	
	
	int i=1,j=1,k,l;
	char s[10000];
	
	//freopen("in.txt","r",stdin);
	
	while(gets(s)){
		
		if(s[0]=='%'){
			memset(num,0,sizeof(num));
			memset(color,0,sizeof(color));
			memset(value,0,sizeof(value));
			int count1=0; char ch;
			row=i; col=j;
			for(k=1;k<i;k++){
				for(l=1;l<j;l++){
					ch=grid[k][l];
					if(color[k][l]==0) count1++;
					flood(k,l,ch,count1);
				}				
			}
			int mark;
			for(i=1;i<row;i++){
				for(j=1;j<col;j++){
					if(num[i][j]<10)  mark=1; else if(num[i][j]<100) mark=2; else if(num[i][j]<1000) mark=3; else if(num[i][j]<10000) mark=4;else if(num[i][j]<100000) mark=5;else if(num[i][j]<1000000) mark=6;else if(num[i][j]<10000000) mark=7;else if(num[i][j]<100000000) mark=8;
					if(value[j]<mark) value[j]=mark;
				}
			}
			
			
			for(i=1;i<row;i++){
				for(j=1;j<col;j++){
					if(j>1) printf(" ");
					if(value[j]==1) printf("%d",num[i][j]);
					else if(value[j]==2) printf("%2d",num[i][j]);
					else if(value[j]==3) printf("%3d",num[i][j]);
					else if(value[j]==4) printf("%4d",num[i][j]);
					else if(value[j]==5) printf("%5d",num[i][j]);
					else if(value[j]==6) printf("%6d",num[i][j]);
					else if(value[j]==7) printf("%7d",num[i][j]);
					else if(value[j]==8) printf("%8d",num[i][j]);	
				}
				printf("\n");
			}
			printf("%%\n");
			
			i=1;
			continue;
		}
		
		else{
			j=1;
			for(k=0;s[k];k++){
				if(isalpha(s[k])){
					grid[i][j++]=s[k];
				}
			}
			
			i++;
			
		}
		
	}
	memset(num,0,sizeof(num));
	memset(color,0,sizeof(color));
	memset(value,0,sizeof(value));
	int count1=0; char ch;
	row=i; col=j;
	for(k=1;k<i;k++){
		for(l=1;l<j;l++){
			ch=grid[k][l];
			if(color[k][l]==0) count1++;
			flood(k,l,ch,count1);
		}				
	}
	int mark;
	for(i=1;i<row;i++){
		for(j=1;j<col;j++){
			if(num[i][j]<10)  mark=1; else if(num[i][j]<100) mark=2; else if(num[i][j]<1000) mark=3; else if(num[i][j]<10000) mark=4;else if(num[i][j]<100000) mark=5;else if(num[i][j]<1000000) mark=6;else if(num[i][j]<10000000) mark=7;else if(num[i][j]<100000000) mark=8;
			if(value[j]<mark) value[j]=mark;
		}
	}
	
	
	for(i=1;i<row;i++){
		for(j=1;j<col;j++){
			if(j>1) printf(" ");
			if(value[j]==1) printf("%d",num[i][j]);
			else if(value[j]==2) printf("%2d",num[i][j]);
			else if(value[j]==3) printf("%3d",num[i][j]);
			else if(value[j]==4) printf("%4d",num[i][j]);
			else if(value[j]==5) printf("%5d",num[i][j]);
			else if(value[j]==6) printf("%6d",num[i][j]);
			else if(value[j]==7) printf("%7d",num[i][j]);
			else if(value[j]==8) printf("%8d",num[i][j]);	
		}
		printf("\n");
	}
	printf("%%\n");
	
	return 0;
	
	
}

void flood(int i,int j,char ch,int val){
	
	if(i<=0||j<=0||i>=row||j>=col) return ;
	if(color[i][j]) return ;
	color[i][j]=1;
	
	num[i][j]=val;
	
	if(grid[i+1][j]==ch) flood(i+1,j,ch,val);
	if(grid[i-1][j]==ch) flood(i-1,j,ch,val);
	if(grid[i][j+1]==ch) flood(i,j+1,ch,val);
	if(grid[i][j-1]==ch) flood(i,j-1,ch,val);
	if(grid[i-1][j-1]==ch) flood(i-1,j-1,ch,val);
	if(grid[i+1][j-1]==ch) flood(i+1,j-1,ch,val);
	if(grid[i-1][j+1]==ch) flood(i-1,j+1,ch,val);
	if(grid[i+1][j+1]==ch) flood(i+1,j+1,ch,val);
	
	
}