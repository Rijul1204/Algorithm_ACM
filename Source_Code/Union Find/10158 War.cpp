#include<stdio.h>

#define maxm 40100

int twin(int x){
	if(x%2) return x+1;
	return x-1;
}

int pre[maxm],n;

int find(int x){
	if(pre[x]==x) return x;
	return pre[x]=find(pre[x]);
}

void Union(int a,int b){
	if(a!=b) pre[a]=b;
}

int main(){

	int i,j,k,l,c;
	
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);

	for(i=0;i<=2*n+60;i++) pre[i]=i;

	while(scanf("%d %d %d",&c,&k,&l)==3){

		if(!c&&!k&&!l) break;

		k++; l++;
		k*=2; l*=2;

		if(c==1){			
			if(find(twin(k))==find(l)||find(twin(l))==find(k)) printf("-1\n");
			else {
				Union(find(twin(k)),find(twin(l))); Union(find(l),find(k));
			}
		}
		else if(c==2){
			if(find(k)==find(l)||find(twin(l))==find(twin(k))) printf("-1\n");
			else {
				Union(find(twin(k)),find(l)); Union(find(twin(l)),find(k));
			}
		}
		else if(c==3){
			if(find(k)==find(l)||find(twin(l))==find(twin(k))) printf("1\n");
			else printf("0\n");
		}
		else if(c==4){
			if(find(twin(k))==find(l)||find(twin(l))==find(k)) printf("1\n");
			else printf("0\n");		
		}

	}


	return 0;
}