#include<stdio.h>
#include<math.h>

int main(){

	int i,j,k,n,leaf,test,d,node;

	scanf("%d",&test);
	
	while(test--){

		scanf("%d %d",&d,&n);

		leaf=pow(2,d)-pow(2,d-1);
		while(n>leaf){
			d--;
			n-=leaf;
			leaf=pow(2,d)-pow(2,d-1);
		}
		
		node=1;
		d--;
		while(d--){
			node*=2;
			if(n%2==0){
				node++;
				n/=2;
			}
			else {n/=2;n++;}
			if(n==0) n=1;
		}

		printf("%d\n",node);
	}
	scanf("%d",&n);

	return 0;
}
		


