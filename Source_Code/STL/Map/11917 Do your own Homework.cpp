#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(){

	int i,j,k,l,n,d,test,t=1;
	string s;

	map<string,int>m,e;

	scanf("%d",&test);
	
	while(test--){

		m.clear();
		e.clear();

		scanf("%d",&n);

		for(i=1;i<=n;i++){
			cin>>s>>d;
			m[s]=d;
			e[s]=1;
		}
		cin>>d>>s;
		printf("Case %d:",t++);
		if(m[s]<=d&&e[s]!=0) printf(" Yesss\n");
		else if(m[s]<=d+5&&e[s]!=0) printf(" Late\n");
		else printf(" Do your own homework!\n");



		
	}

	return 0;
}

