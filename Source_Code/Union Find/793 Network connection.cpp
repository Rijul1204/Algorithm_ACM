#include<stdio.h>

int pre[1000000];

void set(int n){
	for(int i=0;i<=n;i++){
		pre[i]=i;
	}
}

int find(int x){
	if(pre[x]==x) return x;
	else return pre[x]=find(pre[x]);
}
void Union(int a,int b){
	if(a!=b) pre[a]=b;
}

int main(){

	int i,j,k,l,n,m,count1,count2,t=1,test,flag=0;
	char s[10000],dum,ch,s1[10];

	//freopen("in.txt","r",stdin);


	scanf("%d",&test);

	while(test--){
		scanf("%d%c",&n,&dum);
		set(n);
		count1=count2=0;

		while(gets(s)){
			if(!s[0]) break;
			sscanf(s,"%s %d %d",s1,&k,&l);
			if(s1[0]=='c') Union(find(k),find(l));
			else{
				if(find(k)==find(l)) count1++;
				else count2++;
			}
		}	
		if(flag) printf("\n") ;
		flag=1;
		printf("%d,%d\n",count1,count2);
	}

	return 0;

}
