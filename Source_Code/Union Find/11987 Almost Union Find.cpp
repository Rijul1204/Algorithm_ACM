#include<stdio.h>

#define maxm 401000

int pre[maxm],sum[maxm],count1[maxm],n,q;

int find(int x){
	if(pre[x]==x) return x;
	return pre[x]=find(pre[x]);
}


int main(){

	int i,j,k,l,ch,pk,pl,c;

	//freopen("in.txt","r",stdin);

	while(scanf("%d %d",&n,&q)==2){

		k=4*n+10;
	
		for(i=0;i<=k;i++){
			pre[i]=i;
		}		
		for(i=1;i<=n;i++){
    		count1[i]=1;
			sum[i]=i;
		}
		for(i=n+1;i<=k;i++){
			count1[i]=1; 
			sum[i]=i;
		}
		c=n+1;
		

		for(i=1;i<=q;i++){
			
			scanf("%d",&ch);

			if(ch==1){
				scanf("%d %d",&k,&l);
				pk=find(k);
				pl=find(l);
				if(pk==pl) continue;
				if(pk==k&&pl==l){
					count1[c]=2;
					sum[c]=k+l;
					pre[k]=pre[l]=c++;
					continue;
				}
				if(pl==l){
					count1[pk]++;
					sum[pk]+=l;
					pre[l]=pk;
					continue;
				}
				if(pk==k){
					count1[pl]++;
					sum[pl]+=k;
					pre[k]=pl;
					continue;
				}
				sum[c]=sum[pk]+sum[pl];
				count1[c]=count1[pk]+count1[pl];
				pre[pk]=pre[pl]=c++;
				continue;			
				
			}

			if(ch==2){
     			scanf("%d %d",&k,&l);
    			pk=find(k);
				pl=find(l);
				if(pk==pl) continue;
				if(pk==k&&pl==l){
					count1[c]=2;
					sum[c]=k+l;
					pre[k]=pre[l]=c++;
					continue;
				}				
				if(pl==l){
					count1[c]=2;
					sum[c]=k+l;
					sum[pk]-=k;
					count1[pk]--;
					pre[k]=pre[l]=c++;
					continue;
				}				
				if(pk==k){
					count1[k]=0;
					sum[k]=0;
					count1[pl]++;
					sum[pl]+=k;
					pre[k]=pl;
					continue;
				}
				sum[pk]-=k;
				count1[pk]--;
				pre[k]=pl;
				count1[pl]++;
				sum[pl]+=k;
				continue;
			}

			if(ch==3){
				scanf("%d",&k);
				pk=find(k);
				printf("%d %d\n",count1[pk],sum[pk]);
			
			}

			
		}



	}


	return 0;
}