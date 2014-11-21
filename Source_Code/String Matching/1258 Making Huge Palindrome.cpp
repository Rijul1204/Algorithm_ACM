#include<stdio.h>
#include<string.h>

#define maxm 3001000

char s[maxm],p[maxm],sinv[maxm];
int pre[maxm];

void prefix();
int kmp();

int main(){

	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%s",s);
		k=strlen(s);

		for(i=k-1,j=0;i>=0;i--,j++) p[j]=s[i];
		p[j]='\0';
		j=kmp();
		
		printf("Case %d: %d\n",t++,k+(k-j));

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
			return m;
			k=pre[k];
		}
	}
	
	
	return k;
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