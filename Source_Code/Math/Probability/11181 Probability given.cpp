#include<stdio.h>
#include<algorithm>
using namespace std;


int main(){

	int i,j,n,r,flag[1000],t=1;
	double p[1000],tot,prob,player[1000];
	char s[10000];

	//freopen("in.txt","r",stdin);

	while(scanf("%d %d",&n,&r)==2){

		if(!n&&!r) break;

		for(i=0;i<n-r;i++) s[i]='0';
		for(i=n-r;i<n;i++) s[i]='1';
		s[n]='\0';

		for(i=0;i<n;i++){
			player[i]=0;
			scanf("%lf",&p[i]);
		}

		tot=0.0;

		do{
			for(i=0;i<=n;i++) flag[i]=0;
			//puts(s);
			prob=1;
			for(i=0;s[i];i++){
				if(s[i]=='1'){
					prob*=p[i];
					flag[i]=1;
				}
				if(s[i]=='0'){
					prob*=1.0-p[i];
				}
			}
			for(i=0;i<n;i++){
				if(flag[i]) player[i]+=prob;
			}
			tot+=prob;

		}while(next_permutation(s,s+n));

		printf("Case %d:\n",t++);

		for(i=0;i<n;i++){
			printf("%.6lf\n",player[i]/tot);

		}

	}

	return 0;

}

