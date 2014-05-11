#include<stdio.h>
#include<ctype.h>

struct node{

	int freq[230];
};

node nodes[2000];
char s[10000];
int lett[250];

int main(){

	int i,j,k,l;

	//freopen("in.txt","r",stdin);
	
	k=0;
	while(gets(s)){
		if(s[0]=='#') break;
		for(i=50;i<=130;i++) nodes[k].freq[i]=0;

		for(i=0;s[i];i++){
			nodes[k].freq[s[i]]++;
		}
		k++;

	}
	while(gets(s)){
		if(s[0]=='#') break;
		for(i=50;i<=130;i++) lett[i]=0;

		for(i=0;s[i];i++){
			if(isalpha(s[i])){
				lett[s[i]]++;
			}
		}
		l=0; int flag;
		for(i=0;i<k;i++){
			flag=1;
			for(j=97;j<=125;j++){
				if(lett[j]<nodes[i].freq[j]){
					flag=0;
					break;
				}
			}
			if(flag) l++;

		}

		printf("%d\n",l);

	}



	return 0;
}