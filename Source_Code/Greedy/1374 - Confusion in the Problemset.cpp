#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define maxm 10100

int a[maxm];
bool fl[maxm];

int main(){

	int i,j,k,l,test,t=1,n;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);
		k=n-1; l=0;
		int flag=1;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);

		memset(fl,0,sizeof(fl));
		
		for(i=1;i<=n;i++){
			k=a[i];
			if(k+1<=n&&fl[1+k]==0){
				fl[k+1]=1; continue;
			}
			if(n-k<=0){
				flag=0; break;
			}
			if(fl[n-k]==0){
				fl[n-k]=1; continue;
			}
			flag=0; break;

		}

		if(flag){
			printf("Case %d: yes\n",t++);
		}
		else{
			printf("Case %d: no\n",t++);
		}

	}

	return 0;
}