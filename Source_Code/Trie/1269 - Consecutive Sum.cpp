#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define maxm 800000
#define ii int

struct trie{
    int edges[4];
};

trie root,Tri[maxm];

void init(trie *a){
    memset(a->edges,-1,sizeof(a->edges));
}

ii num,ar[35],tot;
int n;
void gen(ii n);

void add(trie *a,int h){

    if(h<0) return ;

    int id;

    id=ar[h];

    if(a->edges[id]==-1){
        a->edges[id]=tot++;
        init(&Tri[a->edges[id]]);
    }
    add(&Tri[a->edges[id]],h-1);
}

ii findmax(trie *a,int h){

    if(h<0) return 0;

    int id1=ar[h],id;
    ii v;

    if(id1==0){
        id=1;
        if(a->edges[id]!=-1){
            v=findmax(&Tri[a->edges[id]],h-1);
            v+=(pow(2,h));
            return v;
        }
        else{
            return findmax(&Tri[a->edges[0]],h-1);
        }
    }
    else{
        id=0;
        if(a->edges[id]!=-1){
            v=findmax(&Tri[a->edges[id]],h-1);
            v+=(pow(2,h));
            return v;
        }
        else{
            return findmax(&Tri[a->edges[1]],h-1);
        }
    }
}
ii findmin(trie *a,int h){

    if(h<0) return 0;

    int id=ar[h],ret1,v;

	if(a->edges[id]!=-1){
		return findmin(&Tri[a->edges[id]],h-1);

	}
	else{
		v=findmin(&Tri[a->edges[!id]],h-1);
		v+=(pow(2,h));
		return v;
	}

}



int main(){

	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);

		init(&Tri[0]);
		root=Tri[0];
		tot=1;

		num=0; gen(num); add(&root,32);

		ii ans1,ans2;
		for(i=1;i<=n;i++){
			scanf("%d",&j);
			num^=j;
			gen(num);
			if(i==1){
				ans1=num; ans2=num;
			}
			else{
				k=findmax(&root,32);
				if(k>ans1){
					ans1=k;
				}
				k=findmin(&root,32);
				if(k<ans2){
					ans2=k;
				}
			}
			add(&root,32);
		}

		printf("Case %d: %d %d\n",t++,ans1,ans2);

	}

	return 0;
}

void gen(ii n){

    int i,k=0;

    for(i=0;i<=32;i++){
        ar[i]=0;
    }

    while(n){
        ar[k++]=n%2; n/=2;
    }

}
