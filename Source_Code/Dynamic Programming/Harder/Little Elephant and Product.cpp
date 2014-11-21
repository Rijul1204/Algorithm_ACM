#include<stdio.h>
#include<string.h>

#define maxm 25
#define ii long long int

ii num,L,R;
ii a[maxm],b[maxm],tmp[maxm],lind,rind;
int dp[maxm][5][5][maxm][maxm];
bool v[maxm][5][5][maxm][maxm];

//nf= no of four
//ns= no of seven
int cal(int ind,int fl1,int fl2,int nf,int ns);
int maxi(int a,int b){
	if(a>b) return a;
	return b;
}

int main(){

	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%lld %lld",&L,&R);

		for(i=0;i<=20;i++){
			a[i]=0; b[i]=0;
		}
		num=L;
		k=0;
		while(num){
			tmp[k++]=num%10;
			num/=10;
		}
		for(i=0,k=k-1;k>=0;k--,i++){
			a[k]=tmp[k];
		}

		lind=i-1;

		num=R;
		k=0;
		while(num){
			tmp[k++]=num%10;
			num/=10;
		}
		for(i=0,k=k-1;k>=0;k--,i++){
			b[k]=tmp[k];
		}
		rind=maxi(i-1,0);
		memset(v,0,sizeof(v));
		int ans=0;

		for(i=0;i<=9;i++){
		    if(i==4) k=1;
		    else k=0;
		    if(i==7) l=1;
		    else l=0;
			if(a[rind]>i) continue;
			if(b[rind]<i) break;
			if(a[rind]==i&&b[rind]==i){
				ans=maxi(ans,cal(rind-1,1,1,k,l));
			}
			else if(a[rind]==i){
				ans=maxi(ans,cal(rind-1,1,0,k,l));
			}
			else if(b[rind]==i){
				ans=maxi(ans,cal(rind-1,0,1,k,l));
			}
			else ans=maxi(ans,cal(rind-1,0,0,k,l));
		}


		printf("%d\n",ans);

	}

	return 0;
}


int cal(int ind,int fl1,int fl2,int nf,int ns){

	if(ind<0) return ns*nf;

	if(v[ind][fl1][fl2][nf][ns]) return dp[ind][fl1][fl2][nf][ns];
	v[ind][fl1][fl2][nf][ns]=1;

	int ret=0,i,j,k,l,v1,v2;


	if(fl1==0&&fl2==0){
	    ret=maxi(cal(ind-1,fl1,fl2,nf,ns+1),cal(ind-1,fl1,fl2,nf+1,ns));
	    return dp[ind][fl1][fl2][nf][ns]=ret;
	}

	for(i=0;i<=9;i++){
		if(fl1==1&&a[ind]>i) continue;
		if(fl2==1&&b[ind]<i) break;
		if(fl1==1&&a[ind]==i) k=1;
		else k=0;
		if(fl2==1&&b[ind]==i) l=1;
		else l=0;
		if(i==4) v1=nf+1; else v1=nf;
		if(i==7) v2=ns+1; else v2=ns;
		ret=maxi(ret,cal(ind-1,k,l,v1,v2));
	}

	return dp[ind][fl1][fl2][nf][ns]=ret;
}
