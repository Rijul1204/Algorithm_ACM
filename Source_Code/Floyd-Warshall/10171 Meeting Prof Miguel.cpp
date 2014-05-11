#include<stdio.h>

#define maxm 110
#define inf 1<<26

int maty[maxm][maxm],mato[maxm][maxm],shah,mig,flag[maxm];
int mini(int a,int b){
	if(a<b) return a;
	return b;
}

int main(){

	int i,j,k,l,c,m;
	char s1[10],s2[10],s3[10],s4[10],s5[10];
	

    //freopen("in.txt","r",stdin);

	while(scanf("%d",&m)==1){
		
		if(!m) break;

		for(i=0;i<=35;i++){
			for(j=0;j<=35;j++){
				maty[i][j]=mato[i][j]=inf;
			}
			flag[i]=0;
			maty[i][i]=mato[i][i]=0;			
		}

		for(i=1;i<=m;i++){
			scanf("%s %s %s %s %d",s1,s2,s3,s4,&c);
			k=s3[0]-'A';
			l=s4[0]-'A';
			flag[k]=flag[l]=1;
			if(s1[0]=='Y'){
				if(s2[0]=='U'){
					maty[k][l]=mini(maty[k][l],c);
				}
				else{
					maty[l][k]=mini(maty[l][k],c);
					maty[k][l]=mini(maty[k][l],c);
				}
			}
			else {
				if(s2[0]=='U'){
					mato[k][l]=mini(mato[k][l],c);
				}
				else{
					mato[l][k]=mini(mato[l][k],c);
					mato[k][l]=mini(mato[k][l],c);
				}
			}
		}
		scanf("%s %s",s1,s2);
		shah=s1[0]-'A';
		mig=s2[0]-'A';
		if(flag[shah]==0||flag[mig]==0){
			printf("You will never meet.\n");
			continue;
		}
		
		for(k=0;k<28;k++){
			if(flag[k]==0) continue;
			for(i=0;i<28;i++){
				if(flag[i]==0) continue;
				for(j=0;j<28;j++){
					if(flag[j]==0) continue;
					mato[i][j]=mini(mato[i][j],mato[i][k]+mato[k][j]);
					maty[i][j]=mini(maty[i][j],maty[i][k]+maty[k][j]);
					
				}
			}
		}

		int ans=inf;
		int mark[30];
		int count1=0;

		for(i=0;i<27;i++){
			if(flag[i]==0) continue;
			if(maty[shah][i]==inf||mato[mig][i]==inf){
				//printf(" %3d",-1);
				continue;
			}
			else if(maty[shah][i]+mato[mig][i]<ans){
				ans=maty[shah][i]+mato[mig][i];
				mark[0]=i;
				count1=1;
			}
			else if(maty[shah][i]+mato[mig][i]==ans){
				mark[count1++]=i;
			}
		}
	//	printf("\n");

		
		if(ans==inf) printf("You will never meet.\n");
		else{
			printf("%d",ans);
			for(i=0;i<count1;i++){
				printf(" %c",mark[i]+'A');
			}
			printf("\n");
		}

		
	}


	return 0;
}