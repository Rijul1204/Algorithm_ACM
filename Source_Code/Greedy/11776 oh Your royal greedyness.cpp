#include<stdio.h>
#include<algorithm>
using namespace std;

typedef struct{
	int t;
	int flag;
}tim;

tim times[3500];

bool comp(tim a,tim b);

int main(){

	int i,j,n,max,count,test=1;

	freopen("in.txt","r",stdin);

	while(scanf("%d",&n)==1){

		if(n==-1) break;

		for(i=0,j=0;i<n;i++){
			scanf("%d %d",&times[j].t,&times[j+1].t);
			times[j++].flag=0;
			times[j++].flag=1;
		}
		sort(times,times+j,comp);
		max=0;
        count=0;
		for(i=0;i<j;i++){
		//	printf("%d %d\n",times[i].t,times[i].flag);
			if(times[i].flag==0){
				count++;
				if(count>max) max=count;
			}
			if(times[i].flag==1) count--;
		}
		printf("Case %d: %d\n",test++,max);

	}


	return 0;

}

bool comp(tim a,tim b){

	if(a.t<b.t) return 1;
	else if(a.t==b.t){
		if(a.flag==0) return 1;
		else return 0;
	}
	else return 0;
}



