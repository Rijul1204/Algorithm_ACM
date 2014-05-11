#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<set>
#include<stack>
using namespace std;

#define maxm 550
#define pii pair<int,int>

// low= low value of node, d=discovery time of node , tim= visiting time ....(current);
// state= for  bicoloring  ....
int col[maxm],low[maxm],d[maxm],tim,tot=0;
bool flag[maxm];
stack< pii >st;
vector<int>v[maxm];
set<int>sets[maxm];
void dfs(int s,int pre);

int n,m,b,can[maxm],req[maxm],val[maxm],cost[maxm][maxm];

int bs();

int lefts[maxm],rights[maxm];
int dfs1(int s,int lim);
int f(int piv);



int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%d %d %d",&n,&m,&b);

        //initialization.......
        for(i=0;i<=n;i++){
            v[i].clear();
        }
        for(i=0;i<=tot;i++){
            sets[i].clear();
        }
        while(!st.empty()) st.pop();
        memset(col,0,sizeof(col));
		memset(flag,0,sizeof(flag));
        memset(low,0,sizeof(low));
        memset(d,0,sizeof(d));
        tim=0; tot=0;
        ////******/////

        for(i=1;i<=n;i++){
            scanf("%d",&can[i]);
        }
        for(i=1;i<=b;i++){
            scanf("%d",&req[i]);
        }

        for(i=1;i<=m;i++){
            scanf("%d %d",&k,&l);
            v[k].push_back(l);
            v[l].push_back(k);
        }
        for(i=1;i<=n;i++){
            if(!col[i]) dfs(i,i);
        }

		for(i=1;i<=n;i++){
			if(!flag[i]){
				sets[tot].insert(i);
				tot++;
			}
		}

        printf("Buzz Mission %d: %d",t++,tot);
 		if(tot>b){
			printf(" No\n"); continue;
		}

		set<int>::iterator it;
		for(i=0;i<tot;i++){
		    int ans=0;
		    //puts("");
		    for(it=sets[i].begin();it!=sets[i].end();it++){
		        k=(*it);
		        ans+=can[k];
		    }
		    val[i]=ans;
		    for(j=1;j<=b;j++){
		        int diff=val[i]-req[j];
		        if(diff<0) diff*=-1;
		        cost[i][j]=diff;
		    }
		}

		printf(" %d\n",bs());

    }

    return 0;
}

int bs(){

	int lo=0,hi=552051000;

	while(lo<hi){

		int mid=lo+hi; mid/=2;

		if(!f(mid)){
		    lo=mid+1;
		}
		else{
		    if(hi==mid){
		        if(f(mid-1)) return mid-1;
		        return mid;
		    }
		    hi=mid;
		}
	}

	return hi;

}

int f(int piv){

    int i,j;
    memset(rights,-1,sizeof(rights));
    memset(lefts,-1,sizeof(lefts));

    bool done=false;

    do{
        done=true;
        memset(col,0,sizeof(col));
        for(i=0;i<tot;i++){
            if(rights[i]==-1 && dfs1(i,piv)) done=0;
        }
    }while(!done);

    for(i=0;i<tot;i++){
        if(rights[i]==-1) return 0;
    }

	return 1;

}

int dfs1(int s,int lim){

    if(col[s]) return 0;
    col[s]=1;

    for(int i=1;i<=b;i++){
        if(cost[s][i]>lim) continue;
        if(lefts[i]==-1){
            lefts[i]=s;
            rights[s]=i;
            return 1;
        }
        else if(dfs1(lefts[i],lim)){
            lefts[i]=s;
            rights[s]=i;
            return 1;
        }
    }

    return 0;

}


void dfs(int s,int pre){


    col[s]=1;
    low[s]=d[s]=tim++;

    int i,j,k;

    for(i=0;i<v[s].size();i++){
        k=v[s][i];

        if(k==pre) continue;
        if(col[k]==1 ){
            if(d[k]<low[s]) low[s]=d[k];
            if(d[k]<d[s]){
                st.push(pii(s,k));
            }
            continue;
        }
        if(!col[k]){
            st.push(pii(s,k));
            dfs(k,s);
            if(low[s]>low[k]) low[s]=low[k];
			if(d[s]<=low[k]){
			    //printf("new\n");
			    int fl=0;
			    vector<int>now;
			    while(!st.empty()){
                    int a=st.top().first;
                    int b=st.top().second;
                    st.pop();
                    now.push_back(a);
                    now.push_back(b);
                    //sets[tot].insert(b);
					fl++;
                    //printf("%d->%d\n",a,b);
                    if(a==s && b==k) break;
                    if(a==k && b==s) break;
                }
                if(fl>1){
                    for(j=0;j<now.size();j++){
                        flag[now[j]]=1;
                        sets[tot].insert(now[j]);
                    }
                    tot++;
                }

			}
        }
    }
}
