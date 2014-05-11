#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define maxm 2000

int a[maxm];

int gcd(int a,int b){
    if(a%b==0) return b;
    return gcd(b,a%b);
}

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    while(scanf("%d",&a[0])==1){
        if(a[0]==0) break; i=1;
        while(scanf("%d",&a[i])==1){ if(a[i]==0) break; i++; }
        int n=i;
        sort(a,a+n);
		k=a[1]-a[0]; if(k==0) k=a[0];
        int gc=k;
        for(i=2;i<n;i++){
			if(a[i]==a[0]) continue;		
           gc=gcd(gc,a[i]-a[0]);
        }
		printf("%d\n",gc);
    }

    return 0;
}
