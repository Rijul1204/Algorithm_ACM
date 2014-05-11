#include<stdio.h>
#include<algorithm>
using namespace std;

#define inf 12345678

int d[10120];

bool comp(int a,int b){
	return a>b;

}


int main(){

	int i,j,k,l,n;
	int odd,even,sum;

	//freopen("in.txt","r",stdin);

	while(scanf("%d",&n)==1){
		if(!n) break;
		odd=0;
		even=0;
		sum=0;

		for(i=0;i<n;i++){
			scanf("%d",&d[i]);
				sum+=d[i];
		}
		if(sum%2){
			printf("Not possible\n");
			continue;
		}

		int flag=0;

		for(i=0;i<n;i++){
			sort(d,d+n,comp);
			k=d[0];
			if(d[0]==0) break;
			for(j=1;j<=k;j++){
				if(d[0]==0) break;
				if(d[j]==0){
					flag=1;
					break;
				}
				d[j]--;
				d[0]--;
			}
			if(d[0]!=0){
				flag=1;
				break;
			}
			if(flag) break;		
			
		}

	//	if(flag==0) for(i=0;i<n;i++){
	//		if(d[i]!=0) flag=1;
	//	}
		
		if(!flag) printf("Possible\n");
		else printf("Not possible\n");
	


	}

	return 0;
}