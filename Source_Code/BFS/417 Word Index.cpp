#include<stdio.h>
#include<map>
#include<string>
#include<iostream>
using namespace std;

char letter[]="abcdefghijklmnopqrstuvwxyz";

map<string,int>word;
int count1=1,flag[100];
char out[100];

void back(int n,int count,int mark);

int main(){

	int i,j,k,l;
	char s[1000];

	for(i=1;i<=5;i++){
		back(i,0,0);
	}

	while(scanf("%s",s)==1){
		cout<<word[s]<<endl;
	}


	return 0;
}

void back(int n,int count,int mark){
	
	if(count==n){
		out[count]='\0';
		word[out]=count1++;
		return ;
	}

	for(int i=mark;letter[i];i++){
		if(!flag[i]){
			flag[i]=1;
			out[count]=letter[i];
			back(n,count+1,i+1);
			flag[i]=0;
		}
	}

}