#include<stdio.h>
#include<iostream>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

struct tree{
	int num;
	string name;
};

tree trees[11000];

map<string,int>word;
map<string,int>::iterator it;

bool comp(tree a,tree b){
	return a.name<b.name;

}

int main(){

	int i,j,k,l,count1=0,test;
	char s[100000],help[5];
	bool blank=0;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);
	gets(help);
	gets(help);
	while(test--){
		count1=1;
		word.clear();
		while(gets(s)){
			if(!s[0]) break;
			if(!word[s]) word[s]=1;
			else word[s]++;
			count1++;
			//cout<<word[s]<<endl;
		}

		i=0;
		for(it=word.begin();it!=word.end();it++){
			 trees[i].name=(*it).first;
			 trees[i++].num=(*it).second;
			 //printf("%d ",trees[i-1].num);
		}

		sort(trees,trees+i,comp);
		double res;
		count1--;
		//res=(double)((double)count1/(double)100.0);
		if(blank) printf("\n");
		blank=1;

		for(j=0;j<i;j++){
			 
    		res=(double)(( ( (double)trees[j].num * (double) 100.0 )/(double)count1));
			res+=.0000000001;
			cout<<trees[j].name;
			printf(" %.4lf\n",res);

		}



	}



	return 0;
}
