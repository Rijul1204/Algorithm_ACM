#include<stdio.h>
#include<map>
#include<string>
using namespace std;

#define maxm 101000

map<string,int>word;
int pre[maxm];

int twin(int a){
	if(a%2) return a+1;
	return a-1;
}

int find(int x){
	if(pre[x]==x) return x;
	return pre[x]=find(pre[x]);
}

void Union(int a,int b){
	a=find(a); b=find(b);
	if(a!=b) pre[a]=b;
}

char s1[1000],s2[1000];

int main(){
	
	int i,j,k,l,test,t=1;
	int n1,n2,c;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){
		
		scanf("%d %d",&n1,&n2);
		word.clear();
		for(i=1;i<=100100;i++) pre[i]=i;

		c=1;
		
		for(i=1;i<=n1;i++){
			scanf("%s %s",s1,s2);
			if(word[s1]==0) word[s1]=c++;
			if(word[s2]==0) word[s2]=c++;

			k=word[s1]; l=word[s2];

			k=2*k; l=2*l;

			Union(k,l); Union(twin(k),twin(l));

			
		}

		int flag=0;

		for(i=1;i<=n2;i++){
			scanf("%s %s",s1,s2);
			if(word[s1]==0) word[s1]=c++;
			if(word[s2]==0) word[s2]=c++;

			if(flag) continue;

			k=word[s1]; l=word[s2];

			k=2*k; l=2*l;
			
			if(find(k)==find(l)||find(twin(k))==find(twin(l))){
				flag=1;
				continue;
			}
			
			Union(twin(k),l); Union(k,twin(l));

			
		}

		if(flag) printf("Case %d: NO\n",t++);
		else printf("Case %d: YES\n",t++);



	}

	return 0;
}