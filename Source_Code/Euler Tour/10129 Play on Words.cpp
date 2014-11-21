#include<stdio.h>
#include<map>
#include<string>
#include<vector>
#include<string.h>
using namespace std;


int out[100],in[100],flag[100];
int mat[100][100];


int main(){

	int i,j,k,l,test,n;
	char s[2000];

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);
		for(i=1;i<=50;i++){
			flag[i]=0; in[i]=0; out[i]=0;
			for(j=1;j<=50;j++){
				mat[i][j]=0;
			}
		}
		
		for(i=1;i<=n;i++){
			scanf("%s",s);
			k=s[0]-'a'+1;
			l=s[strlen(s)-1]-'a'+1;
			flag[k]=flag[l]=1;
			out[l]++;
			in[k]++;			
			mat[k][l]=mat[l][k]=1;
		}
		
		for(k=1;k<=26;k++){
			for(i=1;i<=26;i++){
				for(j=1;j<=26;j++){
					if(mat[i][k]&&mat[k][j]) mat[i][j]=1;
				}
			}
		}
		
		int sou=0;
		int dest=0;
		int euler=1;

		for(i=1;i<=26;i++){
			if(flag[i]==0) continue;
			for(j=1;j<=26;j++){
				if(flag[j]==0) continue;
				if(mat[i][j]!=1){
					euler=0;
					break;
				}

			}

		}

		if(!euler){
			printf("The door cannot be opened.\n");
			continue;
		}

		int diffin=0;
		int diffout=0;

		for(i=1;i<=30;i++){
			if(flag[i]){
				if((in[i]-out[i])==1) diffin++;
				else if((out[i]-in[i])==1)diffout++;
				else if(in[i]!=out[i]) euler=0;
			}
		}
		
		if(diffin==1&&diffout!=1) euler=0;
		if(diffin!=1&&diffout==1) euler=0;
		if(diffin>1||diffout>1) euler=0;
		if(euler) printf("Ordering is possible.\n");
		else printf("The door cannot be opened.\n");


	}


	return 0;
}