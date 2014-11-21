#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define maxm 20
#define ii long long int

ii dp[maxm][4][4][maxm];
int a[maxm];
ii n1,n2;
ii cal(int i,int fl1,int fl2,int j);

int main(){

	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%lld %lld",&n1,&n2);
		ii nn1,nn2;


		if(n1>n2) swap(n1,n2);
		nn1=n1; nn2=n2;

		memset(dp,-1,sizeof(dp));
		for(i=0;i<=18;i++){
			a[i]=0;
		}
		k=0;
		while(n2){
			a[k++]=n2%10;
			n2/=10;
		}

		ii ans=0;
		if(k<=1){
			ans=nn2+1;
		}

		else{
			for(i=1;i<a[k-1];i++){
				ans+=cal(k-2,0,0,1);
			}
			if(i>a[0]) l=2;
			else if(i==a[0]) l=1;
			else l=0;
			ans+=cal(k-2,1,l,1);

			for(i=k-2;i>=0;i--){
				if(i==0) ans+=(10*cal(i-1,0,0,1));
				else ans+=(9*cal(i-1,0,0,1));
			}
			if(k-2<0){
				//	ans+=cal(0,0,0,1);
			}
		}

		n1--;
		if(n1<0){
			printf("Case %d: %lld\n",t++,ans);
			continue;
		}

		memset(dp,-1,sizeof(dp));
		for(i=0;i<=18;i++){
			a[i]=0;
		}
		k=0;
		while(n1){
			a[k++]=n1%10;
			n1/=10;
		}

		ii ans1=0;
		if(k<=1){
			ans1=nn1;

		}
		else{
			for(i=1;i<a[k-1];i++){
				ans1+=cal(k-2,0,0,1);
			}
			if(i>a[0]) l=2;
			else if(i==a[0]) l=1;
			else l=0;
			//if(a[k-1]!=0)
			ans1+=cal(k-2,1,l,1);

			for(i=k-2;i>=0;i--){
				if(i==0) ans1+=10*cal(i-1,0,0,1);
				else ans1+=(9*cal(i-1,0,0,1));
			}
			if(k-2<0){
				//ans1+=cal(0,0,0,1);
			}

		}

		ans-=ans1;
		printf("Case %d: %lld\n",t++,ans);

	}

	return 0;
}

ii cal(int i,int fl1,int fl2,int j){

	if(i<j){
		if(fl1==0) return 1;
		if(fl1==1&&fl2!=2) return 1;
		return 0;
	}

	if(dp[i][fl1][fl2][j]!=-1) return dp[i][fl1][fl2][j];

	int k,l; ii ret=0;
	if(fl1==1){
		for(k=0;k<a[i];k++){
			ret+=cal(i-1,0,0,j+1);
		}
		if(k>a[j]) l=2;
		else if(k==a[j]) l=1;
		else l=0;
		if(l==1&&fl2==2) l=2;
		ret+=cal(i-1,1,l,j+1);
	}
	else{
		ret+=(10*cal(i-1,0,0,j+1));
	}
	return dp[i][fl1][fl2][j]=ret;
}
