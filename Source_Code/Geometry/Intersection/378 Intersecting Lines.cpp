#include<stdio.h>
#include<string.h>
#include<math.h>

#define maxm 10
#define eps 1e-7

struct node{
	double x,y;
	bool is;
};
struct eq{
	double a,b,c;
};

node intersect(node a,node b,node c,node d);
bool line(node a,node b,node c,node d);
eq gen(node a,node b);
bool chck(eq a,node b);

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);
	
	printf("INTERSECTING LINES OUTPUT\n");
	scanf("%d",&test);
	

	while(test--){

		int i1,i2,k1,k2,l1,l2,j1,j2;

		scanf("%d %d %d %d %d %d %d %d",&i1,&i2,&k1,&k2,&l1,&l2,&j1,&j2);
		node a,b,c,d,ans;
		a.x=i1; a.y=i2; b.x=k1; b.y=k2; c.x=l1; c.y=l2;
		d.x=j1; d.y=j2;
		if(line(a,b,c,d)){
			printf("LINE\n");
			continue;
		}
		ans=intersect(a,b,c,d);
		if(ans.is){
			printf("POINT %.2lf %.2lf\n",ans.x,ans.y);
		}
		else printf("NONE\n");


	}
	printf("END OF OUTPUT\n");

	return 0;
}

eq gen(node a,node b){

	eq ret;
	ret.a=b.y-a.y; ret.b=a.x-b.x;
	ret.c=a.x*ret.a+ret.b*a.y;
	return ret;
	
}
node intersect(node a,node b,node c,node d){
	
	eq ret1,ret2; node ret;
	ret1=gen(a,b); ret2=gen(c,d);
	double A1,B1,A2,B2,C1,C2; A1=ret1.a; A2=ret2.a; B1=ret1.b; B2=ret2.b;
	C1=ret1.c; C2=ret2.c;

	double det=A1*B2-A2*B1;
	double com=det-0; 
	if(com<0) com*=-1;
	if(com<eps){
		ret.is=0;
		return ret;
	}
	ret.is=1;
	ret.x=C1*B2-C2*B1; ret.x/=det;
	ret.y=A1*C2-A2*C1; ret.y/=det;
	return ret;
}
bool line(node a,node b,node c,node d){
	
	eq ret1,ret2;

	ret1=gen(a,b);
	if(chck(ret1,c)&&chck(ret1,d)) return 1;
	return 0;

	double i,j,k;  i=ret2.a-ret1.a; j=ret2.b-ret1.b; k=ret2.c-ret2.c;
	if(i<0) i*=-1; if(j<0) j*=-1; if(k<0) k*=-1;
	
	if(i<eps&&j<eps&&k<eps) return 1;
	return 0;

}

bool chck(eq a,node b){

	double ans,ans1,ans2;
	
	ans1=a.a*b.x+a.b*b.y;
	ans2=a.c;
	ans=ans1-ans2;
	if(ans<0) ans*=-1;
	if(ans<eps) return 1;
	return 0;

}