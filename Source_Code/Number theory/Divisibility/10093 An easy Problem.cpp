#include<stdio.h>
#include<string.h>
#include<ctype.h>
	
char in[10000],temp[10000];
	

int main(){

	char s[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	
	int base[200];
    int i,j,k,l,max;

	for(i=0;s[i];i++){
		base[s[i]]=i+1;
	}

	while(scanf("%s",in)==1){

		for(i=0;in[i];i++){
			if(isalpha(in[i])||isdigit(in[i])){
				break;
			}
		}
		for(j=0;in[i];j++) temp[j]=in[i++];
		temp[j]='\0';
		
		strcpy(in,temp);
		max=0;
		int sum=0;
		for(i=0;in[i];i++){
			sum+=(base[in[i]]-1);
			if(base[in[i]]>max) max=base[in[i]];
		}
		if(max==1) max=2;
		int flag=0;
		for(i=max;i<=62;i++){
			if(sum%(i-1)==0){
				flag=1;
				break;
			}
		}
		if(flag) printf("%d\n",i);
		else printf("such number is impossible!\n");
		

	}


	return 0;
}