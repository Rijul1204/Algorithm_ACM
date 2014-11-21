#include<stdio.h>
#include<string.h>
#include<math.h>

#define maxm 100

int a[15],m;
int dp[15][3][100][100];
int cal(int ind,int fl,int sum,int num);

int main(){

	int i,j,k,l,test,t=1;
	
//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){
		
		scanf("%d %d %d",&k,&l,&m);
		if(m>90){
			printf("Case %d: 0\n",t++);
			continue;
		}
		j=0;
		while(l){
			a[j++]=l%10;
			l/=10;
		}

		memset(dp,-1,sizeof(dp));
		int ans1=cal(j-1,1,0,0);
		ans1--;

		j=0;
		k--;
		while(k){
			a[j++]=k%10;
			k/=10;
		}
		memset(dp,-1,sizeof(dp));
		int ans2=cal(j-1,1,0,0);
		ans2--;
		int ans=ans1-ans2;		
		printf("Case %d: %d\n",t++,ans);


	}
	return 0;
}
int cal(int ind,int fl,int sum,int num){
	
	if(ind<0&&sum==0&&num%m==0) return 1;
	if(ind<0) return 0;

	if(dp[ind][fl][sum][num]!=-1) return dp[ind][fl][sum][num];

	int ret=0,i,j,k,l,l1;
	l=pow(10,ind);
	for(i=0;i<=9;i++){
		if(fl==1){
			k=l*i;
			if(num+k==0) l1=1; else l1=0;
			if(a[ind]<i) break;
			if(a[ind]>i){				
				ret+=cal(ind-1,0,(sum+i)%m,(num+k)%m);
			}
			else ret+=cal(ind-1,1,(sum+i)%m,(num+k)%m);
		}
		else{
			k=l*i;
			if(num+k==0) l1=1; else l1=0;
			ret+=cal(ind-1,fl,(sum+i)%m,(num+k)%m);
		}
	}
	return dp[ind][fl][sum][num]=ret;

}
