#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define maxm 100100
//#define ii __int64
#define ii long long int

struct node{
	int a,b;
};
node nodes1[maxm],nodes2[maxm];
int n,m;
int bs(int ind);
int bs1(int n);
int bss(int ind);
int bs2(int n);
bool comp(node a,node b){
	return a.a<b.a;
}

int main(){

	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&n,&m);

		for(i=0;i<n;i++){
			scanf("%d %d",&nodes1[i].a,&nodes1[i].b);
		}
		for(i=0;i<m;i++){
			scanf("%d %d",&nodes2[i].a,&nodes2[i].b);
		}
		sort(nodes1,nodes1+n,comp);
		sort(nodes2,nodes2+m,comp);

		ii ans=0;
		for(i=0;i<n;i++){
			ans+=bs(i);
			ans+=bss(i);
		}

		printf("Case %d: %lld\n",t++,ans);

	}


	return 0;
}
//immidiete choto> >>
int bss(int ind){

	int i,j,k,l,lo,hi,mid,pivot,tot;
	pivot=nodes1[ind].b;
	tot=bs2(nodes1[ind].a);
	if(nodes2[tot].b>pivot||tot==-1) return 0;
	lo=tot; hi=m-1;
	while(lo<hi){
		mid=lo+hi; mid/=2;
		if(nodes2[mid].b==pivot) return mid-tot+1;
		if(nodes2[mid].b>pivot){
			hi=mid-1;
		}
		else{
			if(lo==mid){
				if(nodes2[mid+1].b<=pivot) return mid+2-tot;
				else return mid-tot+1;
			}
			lo=mid;
		}
	}

	return lo-tot+1;

}
//immidiet boro...
int bs(int ind){

	int i,j,k,l,lo,hi,mid,pivot,tot;
	pivot=nodes1[ind].b;
	tot=bs1(nodes1[ind].a);
	if(nodes2[tot].b<pivot||tot==-1) return 0;
	lo=0; hi=tot;
	while(lo<hi){
		mid=lo+hi; mid/=2;
		if(nodes2[mid].b==pivot) return tot-mid+1;
		if(nodes2[mid].b<pivot){
			lo=mid+1;
		}
		else{
			if(hi==mid){
			if(nodes2[mid-1].b>=pivot) return tot-mid+2;
			else return tot-mid+1;
			}
			hi=mid;
		}
	}

	return tot-hi+1;

}
//immidiete boro>>.
int bs2(int num){

	int lo,hi,mid;

	lo=0; hi=m-1;
	if(nodes2[hi].a<num) return -1;

	while(lo<hi){

		mid=lo+hi; mid/=2;

		if(nodes2[mid].a<num){

			lo=mid+1;
		}
		else{
			if(hi==mid){
				if(nodes2[mid-1].a>num) return mid-1;
				else return mid;
			}
			hi=mid;
		}
	}

	return hi;
}
//immidiete choto>>>>>
int bs1(int num){

	int lo,hi,mid;

	lo=0; hi=m-1;
	if(nodes2[lo].a>num) return -1;

	while(lo<hi){

		mid=lo+hi; mid/=2;

		if(nodes2[mid].a>num){

			hi=mid-1;
		}
		else{
			if(lo==mid){
				if(nodes2[mid+1].a<num) return mid+1;
				else return mid;
			}
			lo=mid;
		}
	}

	return lo;
}
