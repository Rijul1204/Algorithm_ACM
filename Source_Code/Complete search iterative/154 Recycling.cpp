#include<stdio.h>
#include<map>
using namespace std;

char s[1000];
int city[1000][10];

map<char,int>m1;
map<char,int>m2;

int main(){
	
	int i,j,k,l,count1,n=0,max,sum,mark;
	
	//freopen("in.txt","r",stdin);


	m1['r']=1;
	m1['o']=2;
	m1['g']=3;
	m1['b']=4;
	m1['y']=5;
	m2['P']=1;
	m2['G']=2;
	m2['A']=3;
	m2['S']=4;
	m2['N']=5;
	
	while(scanf("%s",s)){
		if(s[0]=='#') break;
		
		if(s[0]=='e'){
			max=0;
			mark=0;
			

			for(i=0;i<n;i++){
				sum=0;
				for(j=1;j<=5;j++){
					for(k=0;k<n;k++){
						if(city[i][j]==city[k][j]) sum++;
					}
				}
				if(sum>max){
					max=sum;
					mark=i;
				}
				
			}
			printf("%d\n",mark+1);
			n=0;
			
		}

		else{
			city[n][m1[s[0]]]=m2[s[2]];
			city[n][m1[s[4]]]=m2[s[6]];
			city[n][m1[s[8]]]=m2[s[10]];
			city[n][m1[s[12]]]=m2[s[14]];
			city[n][m1[s[16]]]=m2[s[18]];
			n++;
		}
		
	}
	
	return 0;
	
}

