#include<stdio.h>
#include<vector>
#include<iostream>
#include<map>
#include<string>
using namespace std;

#define inf 1232321

int in[1000],out[1000],mat[1000][1000];
map<string,int>word;
map<int,string>word1;

void set(int n);

int main(){


	int i,j,k,l,n,e,mark,min,t=1;
	char s[1000],s1[1000],s2[1000];

	//freopen("in.txt","r",stdin);

	while(scanf("%d",&n)==1){

		word.clear();word1.clear();
		for(i=1;i<=n;i++){
			scanf("%s",s);
			word[s]=i;word1[i]=s;
		}
		set(n);

		scanf("%d",&e);
		
		for(i=1;i<=e;i++){

			scanf("%s %s",s1,s2);
			mat[word[s1]][word[s2]]=1;
			out[word[s1]]++;
			in[word[s2]]++;

		}
		printf("Case #%d: Dilbert should drink beverages in this order:",t++);
	
		for(i=1;i<=n;i++){
			min=inf;			
			for(j=1;j<=n;j++){
				if(in[j]<min){
					min=in[j];
					mark=j;
				}
			}
			cout<<" "<<word1[mark];
			for(k=1;k<=n;k++){
				in[k]=0;
				mat[mark][k]=0;
				mat[k][mark]=1;
			}
			for(k=1;k<=n;k++){
				for(l=1;l<=n;l++){
					if(mat[k][l]==1) in[l]++;
				}
			}
		}
		printf(".\n\n");



	}


	return 0;
}

void set(int n){

	for(int i=0;i<=n;i++){
		in[i]=0;out[i]=0;
		for(int j=0;j<=n;j++){
			mat[i][j]=0;
		}
	}
}



