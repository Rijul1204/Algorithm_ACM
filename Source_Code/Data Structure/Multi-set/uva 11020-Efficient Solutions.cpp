/*
Author      : Rashedul Hasan Rijul ( Silent_coder ).
Created on  : 2014-08-17
*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;

#define maxm 2010
#define inf (1<<29)
#define ii int

#define pi  acos(-1.0)
#define eps 1e-9
#define iseq(a,b) (fabs(a-b)<eps)

#define pii pair<int,int>
#define mp  make_pair
#define uu first
#define vv second

ii on(ii n,ii k){ return (n|(1<<k)); }
ii off(ii n,ii k){ return (n-(n&(1<<k))); }
bool chck(ii n,ii k){ return (n&(1<<k)); }

ii mini(ii a,ii b){ if(a<b) return a;  return b;  }
ii maxi(ii a,ii b){ if(a>b) return a;  return b;  }

int n,m;
multiset<pii>set1;
multiset<pii>:: iterator it;

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    scanf("%d",&test);

    while(test--){

        scanf("%d",&n);

        set1.clear();

        printf("Case #%d:\n",t++);

        int li,ci;
        for(i=1;i<=n;i++){
            scanf("%d %d",&li,&ci);
            pii now=mp(li,ci);

            if(set1.find(now)!=set1.end()){
                set1.insert(now);
                printf("%d\n",set1.size());
                continue;
            }

            //printf("\n%d %d\n",li,ci);

            while(set1.size()){
                it=set1.upper_bound(now);
                //printf("it= %d-%d\n ",(*it).uu,(*it).vv);
                if(it==set1.end()){
                    break;
                }
                else if((*it).vv>=ci){
                    set1.erase(it);
                }
                else break;
            }


			it=set1.upper_bound(now);

			if(it==set1.begin()){
				set1.insert(now);
			}
			else{
				it--;
				if((*it).vv>ci){
					set1.insert(now);
				}
			}

            for(it=set1.begin();it!=set1.end();it++){
            //    printf("%d-%d  ",(*it).uu,(*it).vv);
            }
            //puts("");
            printf("%d\n",set1.size());
            continue;
        }

        if(test) puts("");
    }

    return 0;
}

