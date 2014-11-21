#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define maxm 25
//#define ii __int64
#define ii long long int

int n,fl[30];
bool flag[30];
ii fact[maxm];
char s[50];

void print(ii num);
ii cal();
void gen(int n);

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);
	
	gen(20);
	scanf("%d",&test);

	while(test--){

		memset(flag,0,sizeof(flag));
		scanf("%s %d",&s,&n);
		sort(s,s+strlen(s));
		if(cal()<n){
			printf("Case %d: Impossible\n",t++);
			continue;
		}	
		printf("Case %d: ",t++);
		print(n-1);
		printf("\n");		
	}

	return 0;
}

void print(ii num){
	
	int i,j,l;
	ii k,prev;
	prev=0; k=0;
	for(i=0;s[i];i++){
		if(flag[i]) continue;
		if(i!=0&&s[i]==s[i-1]&&!flag[i-1]) continue;
		flag[i]=1;
		k+=cal();
		if(k>num){
			printf("%c",s[i]);
			print(num-prev);
			break;
		}
		else{
			prev=k;
			flag[i]=0;
		}
	}
}

ii cal(){

	int i,j,k,l;
	ii ret=0;
	memset(fl,0,sizeof(fl));

	k=0;
	for(i=0;s[i];i++){
		if(flag[i]==1) continue;
		fl[s[i]-'a']++;
		k++;
	}
	ret=fact[k];
	for(i=0;i<26;i++){
		ret/=fact[fl[i]];
	}
	return ret;
}


void gen(int n){

	int i;

	fact[0]=1;

	for(i=1;i<=n;i++){
		fact[i]=fact[i-1]*i;
	}
}