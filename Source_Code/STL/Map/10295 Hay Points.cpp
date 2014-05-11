#include<stdio.h>
#include<map>
#include<string>
#include<string.h>
using namespace std;

map<string,int>word;
char s[100000];


int main(){

	int i,j,k,l,n,m;

	//freopen("in.txt","r",stdin);

	scanf("%d %d",&n,&m);
    
	word.clear();

	for(i=1;i<=n;i++){
		scanf("%s %d",s,&k);
		word[s]=k;
	}
	l=0;
	int sum=0;

	while(scanf("%s",s)==1){
		if(strcmp(s,".")==0){
			l++;
		    printf("%d\n",sum);
			if(l==m) break;
			sum=0;
		}
		sum+=word[s];
	}

	


	return 0;
}