#include<stdio.h>
#include<iostream>
#include<map>
#include<string>
using namespace std;

int number[100100],pre[100100];

void set(int n);
int find(int x);
int Union(int a,int b);

int  main(){

	int i,j,k,l,test,n,count;

	//freopen("in.txt","r",stdin);

	map<string,int>frnd;
	string a,b;


	scanf("%d",&test);

	while(test--){

		frnd.clear();
	
		count=1;

		scanf("%d",&n);

		set(2*n);

		for(i=0;i<n;i++){
			cin>>a>>b;

			if(frnd[a]==0) frnd[a]=count++;
			if(frnd[b]==0) frnd[b]=count++;
			printf("%d\n",Union(find(frnd[a]),find(frnd[b])));

		}

	}
			

	return 0;
}

void set(int n){

	for(int i=0;i<=n;i++){
		pre[i]=i;
		number[i]=1;
	}
}

int find(int x){
	if(pre[x]==x) return x;
	else pre[x]=find(pre[x]);

}

int Union(int a,int b){

	if(a!=b){
		pre[a]=b;
		number[a]=number[b]+=number[a];
	}

	return number[a];

}