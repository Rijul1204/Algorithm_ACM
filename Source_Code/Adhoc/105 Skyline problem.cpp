#include<stdio.h>

int maxi(int a,int b){
	if(a>b) return a;
	return b;
}

int hei[10100],h,s,e;

int main(){

	int i,j,k,l;

//	freopen("in.txt","r",stdin);

	while(scanf("%d %d %d",&s,&h,&e)==3){

		for(i=s;i<e;i++){
			hei[i]=maxi(hei[i],h);
		}

	}
	int a,b,y;
	a=-1;
	y=0;
	int fl=0;

	for(i=0;i<=10010;i++){
		if(y!=hei[i]){
			if(fl) printf(" ");
		    fl=1;
			printf("%d %d",i,hei[i]);
			y=hei[i];
		}
	}

	printf("\n");


	return 0;
}