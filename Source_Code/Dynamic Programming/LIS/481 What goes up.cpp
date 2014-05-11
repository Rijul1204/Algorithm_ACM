#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define maxm 1000010

int a[maxm],p[maxm],L[maxm],n,len,pos,d[maxm];

bool com(int i,int value){
	if(value>=a[i]) return 1;
	return 0;
}
void print(int n){
	if(p[n]) print(p[n]);
	printf("%d\n",a[n]);
}

int main(){

	int i,j,k,l;

//	freopen("in.txt","r",stdin);
	i=1;
	while(scanf("%d",&a[i++])==1){
	}
	n=i-1;
	a[0]=-2147483648;
	L[0]=0;
	l=1;
	int f;

	for(i=1;i<n;i++){
		pos=lower_bound(L,L+l,a[i],com)-L;
		f=(pos==l);
		d[i]=pos;
		if(f||a[L[pos]]>a[i]){
			p[i]=L[pos-1];
			L[pos]=i;
			if(f) l++;
		}
	}

	l--;

	/*
	for(i=1;i<n;i++){
		printf("%d %2d ",a[i],d[i]);
	}
	*/

	printf("%d\n",l);
	printf("-\n");
	print(L[l]);


	return 0;
}
