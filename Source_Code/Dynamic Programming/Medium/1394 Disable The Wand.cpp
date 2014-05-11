#include<stdio.h>
#include<string.h>
#include<math.h>

#define maxm 50
#define ii __int64
//#define ii long long int

struct node{
	ii n,sum;
	node(){}
	node(ii a,ii b){ n=a,sum=b; }
};
int s,e,m,ideal,a[maxm],kk,b[maxm];
node dp[34][3][34][5][10][34];
bool v[34][3][34][5][10][34];
node cal(int ind,int fl,int m,int th,int sev,int diff,int num);

int main(){

	int i,j,k,l,test,t=1;

	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){
		
		scanf("%d %d %d %d %d",&s,&e,&m,&ideal,&kk);
		if(m>32) m=33; if(kk>32) kk=33;
	
		for(i=31;i>=0;i--){
			a[i]=0; b[i]=0;
		}
		k=0;
		while(ideal){
			b[k++]=ideal%2;
			ideal/=2;
		}
		k=0;
		while(e){
			a[k++]=e%2;
			e/=2;
		}
		k--;
		memset(v,0,sizeof(v));
		node ans=cal(32,0,m,0,0,kk,0);
		
		if(!s){
			printf("Case %d: %I64d\n",t++,ans);
			continue;
		}
		s--;
		for(i=31;i>=0;i--){
			a[i]=0;
		}		
		k=0;
		while(s){
			a[k++]=s%2;
			s/=2;
		}
		k--;
		memset(v,0,sizeof(v));
		node ans2=cal(32,0,m,0,0,kk,0);
		ii ans1=ans.sum-ans2.sum;
		printf("Case %d: %I64d\n",t++,ans1);		

	}

	return 0;
}


node cal(int ind,int fl,int m,int th,int sev,int diff,int num){
	
	if(m<0||diff<0) return node(0,0);
	if(ind<0&&!th&&sev){
		return node(1,0);
	}
	if(ind<0) return node(0,0);

	if(v[ind][fl][m][th][sev][diff]) return dp[ind][fl][m][th][sev][diff];
	v[ind][fl][m][th][sev][diff]=1;
	
	node ret,ret1;
	ii r=0;
	int fl1,m1,th1,sev1,d=0,num1;
	if(!fl){
		if(a[ind]==0){
			if(b[ind]!=0) d=1; else d=0;
			//num1=num*2;
			th1=(th*2)%3;
			sev1=(sev*2)%7;			
			ret=cal(ind-1,0,m,th1,sev1,diff-d,num*2);
		}
		else{			
			if(b[ind]!=0) d=1; else d=0;
			num1=num*2;			
			th1=(th*2)%3;
			sev1=(sev*2)%7;
			ret=cal(ind-1,1,m,th1,sev1,diff-d,num*2);
			
			if(b[ind]!=1) d=1; else d=0;
			num1=num*2+1;			
			th1=((th*2)+1)%3;
		sev1=((sev*2)+1)%7;
			ret1=cal(ind-1,0,m-1,th1,sev1,diff-d,num1);
			ret.sum+=ret1.sum; ret.sum=ret.sum+ret1.n*pow(2,ind);
			ret.n+=ret1.n;
		}
	}
	else{

		if(b[ind]!=0) d=1; else d=0;
		num1=num*2;
		th1=(th*2)%3;
		sev1=(sev*2)%7;
		ret=(cal(ind-1,1,m,th1,sev1,diff-d,num*2));
			
		if(b[ind]!=1) d=1; else d=0;
		num1=num*2+1;
		th1=((th*2)+1)%3;
		sev1=((sev*2)+1)%7;
		ret1=cal(ind-1,1,m-1,th1,sev1,diff-d,num1);
		ret.sum+=ret1.sum; ret.sum=ret.sum+ret1.n*pow(2,ind);
		ret.n+=ret1.n;

	}
	
	return dp[ind][fl][m][th][sev][diff]=ret;

}