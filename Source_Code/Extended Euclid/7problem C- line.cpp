#include<stdio.h>
#include<string.h>

#define ii __int64

struct node{
	ii x,y,g;
	node(){};
	node(ii xx,ii yy,ii gg){ x=xx; y=yy; g=gg;};
};


node euclid(ii a,ii b);

int main(){

	int i,j,k,l,test,t=1,n;

	ii a,b,c;
	
	scanf("%I64d %I64d %I64d",&a,&b,&c);
	
	node ans=euclid(a,b);
	
	ii d=a*ans.x+b*ans.y;
	c*=-1;

	if(c%d!=0) printf("-1\n");
	else printf("%I64d %I64d\n",ans.x*(c/d),ans.y*(c/d));


	return 0;
}

node euclid(ii a,ii b){

	if(!b) return node(1,0,a);
	node r=euclid(b,a%b);
	return node(r.y,r.x-(a/b)*r.y,r.g);
}
