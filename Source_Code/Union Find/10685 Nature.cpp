#include<stdio.h>
#include<map>
#include<string>
using namespace std;

int pre[10000],count[10000];
map<string,int>word;

int find(int x){
	if(pre[x]==x) return x;
	return pre[x]=find(pre[x]);
}

int main(){

	int i,j,k,l,c,r;
	char s[1200],s1[1000];

	//freopen("in.txt","r",stdin);

	while(scanf("%d %d",&c,&r)==2){

		if(!c&&!r) break;
		word.clear();

		for(i=1;i<=c;i++){
			scanf("%s",s);
			word[s]=i;
			pre[i]=i;
			count[i]=1;
		}
		
		for(i=1;i<=r;i++){
			scanf("%s %s",s,s1);
			k=find(word[s]);
			l=find(word[s1]);
			if(k!=l){
				pre[k]=l;
				count[k]=count[l]+=count[k];
			}
		}
		int max=1;

		for(i=1;i<=c;i++){
			if(count[i]>max) max=count[i];

		}

		printf("%d\n",max);


	}
	


	return 0;
}