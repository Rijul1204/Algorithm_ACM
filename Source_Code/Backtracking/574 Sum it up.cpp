#include<stdio.h>
#include<algorithm>
#include<map>
#include<string>
#include<stdlib.h>
#include<string.h>
using namespace std;

int total,n;
int in[10000],out[1000],fl,temp[100000];
map<string,int>num;

void back(int ind,int count1,int sum);

int main(){


	int i,j,k,l;

//	freopen("in.txt","r",stdin);

	while(scanf("%d %d",&total,&n)==2){
		if(!n) break;
		num.clear();

		for(i=1;i<=n;i++){
			temp[i]=-1;
			scanf("%d",&in[i]);
		}
		sort(in+1,in+n+1);
		reverse(in+1,in+n+1);
		
		fl=0;
		printf("Sums of %d:\n",total);
		back(1,0,0);
		if(!fl) printf("NONE\n");


	}


	return 0;
}

void back(int ind,int count1,int sum){

	int i;
	if(sum>total) return;
	if(sum==total){
		fl=1;
		char temp[100],s[10000];
		strcpy(s,"");

		for(i=0;i<count1;i++){
			sprintf(temp,"%d",out[i]);
			strcat(s,temp);
			strcat(s,"+");
		}
		if(num[s]) return;
		num[s]=1;
	
		
		printf("%d",out[0]);
		for(i=1;i<count1;i++){
			printf("+%d",out[i]);
		}
		printf("\n");
		return;
	}

	for(i=ind;i<=n;i++){
		out[count1]=in[i];
		back(i+1,count1+1,sum+in[i]);
	}

}