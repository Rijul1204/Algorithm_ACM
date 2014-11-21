/*
Author  : Rashedul Hasan Rijul.
Problem : Loj 1255  ( Substring Frequency ).
Algo    : KMP .
*/

#include<stdio.h>
#include<string.h>

#define maxm 2001000

char s[maxm],p[maxm],sinv[maxm];
int pre[maxm];

void prefix();
int kmp();

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%s",s);
		scanf("%s",p);
		j=kmp();
		printf("Case %d: %d\n",t++,kmp());

	}

	return 0;
}

int kmp(){

	int i,j,k,l,ret=0;
	int n,m;
	n=strlen(s); m=strlen(p);
	prefix();
	k=0;

	for(i=1;i<=n;i++){
		while(k>0 && s[i-1]!=p[k]) k=pre[k];
		if(s[i-1]==p[k]) k++;
		if(k==m){
			ret++;
			k=pre[k];
		}
	}

	return ret;
}

void prefix(){

	int i,j,k,l;

	l=strlen(p);
	pre[1]=0;
	k=0;

	for(i=2;i<=l;i++){
		while(k>0 && p[k]!=p[i-1]) k=pre[k];
		if(p[k]==p[i-1]) k++;
		pre[i]=k;
	}

}
