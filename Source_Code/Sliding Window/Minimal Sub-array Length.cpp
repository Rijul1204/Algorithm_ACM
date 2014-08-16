#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;

#define maxm 500100
#define ii int

#define pii pair<int,int>
#define mp make_pair
#define uu first
#define vv second

ii n,X;
int a[maxm];
deque<pii>dq;

int mini(int a,int b){
    if(a<b) return a;
    return b;
}

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    scanf("%d",&test);

    while(test--){

        scanf("%d %d",&n,&X);

        while(!dq.empty()) dq.pop_back();

        dq.push_front(mp(0,0));

        ii sum=0;
        int ans=n+1;
		pii val;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]>=X) ans=1;
            sum+=a[i];
            while(!dq.empty()){
                val=dq.front();
                if(sum-val.uu>=X){
                    ans=mini(ans,i-val.vv);
					dq.pop_front();
                }
				else break;

            }
            if(dq.empty()){
                dq.push_back(mp(sum,i));
                continue;
            }

            val=dq.front();
            if(sum<val.uu){
                while(!dq.empty()) dq.pop_back();
                dq.push_front(mp(sum,i));
				continue;
            }
            while(!dq.empty()){
                pii val=dq.back();
                if(sum<val.uu){
                    dq.pop_back();
                }
				else break;
            }

            //continue;

            while(!dq.empty()){
                pii val=dq.front();
                if(sum-val.uu<=0){
                    dq.pop_front();
                }
				else break;
            }
            while(!dq.empty()){
                pii val=dq.front();
                if(i-val.vv>=ans){
                    dq.pop_front();
                }
				else break;
            }

            dq.push_back(mp(sum,i));

        }

		if(ans>n) ans=-1;
        printf("%d\n",ans);

    }

    return 0;
}
