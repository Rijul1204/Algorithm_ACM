#include<stdio.h>
#include<map>
using namespace std;

map<int,int>num;


int main(){

	int i,j,k,l,test,t=1,z,m;
	
//	freopen("in.txt","r",stdin);

	while(scanf("%d %d %d %d",&z,&i,&m,&l)==4){

		if(!z&&!i&&!m&&!l) break;
		num.clear(); 
		k=1;
		num[l]=k++;

		while(1){
			j=(z*l+i)%m;
			if(num[j]!=0) break;
			num[j]=k++;
			l=j;
		}
		printf("Case %d: %d\n",t++,k-num[j]);


	}

	return 0;
}