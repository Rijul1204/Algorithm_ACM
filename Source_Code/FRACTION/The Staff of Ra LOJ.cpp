//  FRACTION  >>>>>>>>>>

#include<stdio.h>
#include<string.h>

#define maxm 110

struct node{
	int num;
	int den;
	node(){}
	node(int a,int b){
		if(b<0){
			num=-a; den=b;
		}
		else {
			num=a; den=b;
		}
	};
	
};

node dp[maxm];
int n,a[maxm];

int gcd(int a,int b){
	if(b%a==0) return a;
	return gcd(b%a,a);
}
int lcm(int a,int b){
	return ((a*b)/gcd(a,b));
}

node mul(node a,node b){
	node ret;
	ret.den=a.den*b.den;
	ret.num=a.num*b.num;
	int g=gcd(ret.num,ret.den);
	ret.den/=g; ret.num/=g;
	return ret;	
}
node div(node a,node b){
	node ret;
	node temp;
	temp.den=b.num; temp.num=b.den;
	return ret=mul(a,temp);
}
node add(node a,node b){
	int i,j,k,l;
	node temp;
	temp.den=lcm(a.den,b.den);
	k=temp.den/a.den;
	temp.num=k*(a.num);
	k=temp.den/b.den;
	temp.num+=(k*(b.num));
	l=gcd(temp.den,temp.num);
	temp.den/=l; temp.num/=l;
	return temp;
}
node minus(node a,node b){
	b.den=b.den; b.num=-b.num;
	return add(a,b);
}

int A,B,S1,S2;

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d %d %d",&A,&B,&S1,&S2);

		node ans1=node(S2*B,A-S2);
		node ans2=node(S1*B,A-S1);
		
		node ans=minus(ans1,ans2);
		if(ans.num<0) ans.num*=-1;
		if(ans.den<0) ans.den*=-1;
		printf("Case %d: %d/%d\n",t++,ans.num,ans.den);
	
	}

	

	return 0;
}
