#include<stdio.h>
#include<algorithm>
using namespace std;

typedef struct{
	int l[100];
	int no;
}box;

box boxes[300];
int n,d;


bool comp(box a,box b);

int main(){
	

	//freopen("in.txt","r",stdin);
	
	int i,j,k,temp[100],flag,length[100],pre[100],max,mark,soln[100];
	
	while(scanf("%d %d",&n,&d)==2){
		
		for(i=0;i<n;i++){
			length[i]=1;
			pre[i]=50;
			for(j=0;j<d;j++){
				scanf("%d",&temp[j]);
			}
			sort(temp,temp+d);
			for(j=0;j<d;j++){
				boxes[i].l[j]=temp[j];
				
			}
			boxes[i].no=i+1;
			
		}
		sort(boxes,boxes+n,comp);

		/*
		for(i=0;i<n;i++){
			printf("%d-> ",boxes[i].no);
			for(j=0;j<d;j++){
				printf("%d ",boxes[i].l[j]);				
			}
			printf("\n");			
		}
		*/
		
		
		
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				flag=1;
				for(k=0;k<d;k++){
					if(boxes[i].l[k]>=boxes[j].l[k]){
						flag=0;
						break;
					}
				}
				if(flag==1){
					if(length[i]+1>length[j]){
						length[j]=length[i]+1;
						pre[j]=i;
					}
				}
			}
		}
		
		max=length[0];
		mark=0;
		for(i=1;i<n;i++){
			if(length[i]>max){
				max=length[i];
				mark=i;
			}
		}
        printf("%d\n",max); 
		i=0;
		
		while(pre[mark]!=50){
			soln[i++]=boxes[mark].no;
			mark=pre[mark];
		}
		
		soln[i]=boxes[mark].no;
		
		for(;i>=0;i--){
			if(i==0) printf("%d\n",soln[i]);
			else printf("%d ",soln[i]);
		}		
		
		
	}
	
	return 0;
}




bool comp(box a,box b){
	
	for(int i=0;i<=d;i++){
		if(a.l[i]< b.l[i]) return 1;
		if(a.l[i]> b.l[i]) return 0;
	}
	return 1;
}

