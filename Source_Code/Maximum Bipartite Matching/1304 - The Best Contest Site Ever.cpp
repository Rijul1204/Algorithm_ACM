#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

#define maxm 110
#define maxe (maxm*maxm)

vector<int>v[maxm*maxm];
char s[maxm][maxm];
int r,c,c1[maxm],mapr[maxe],mapc[maxe];
int left[maxe],right[maxe],col[maxe];

int match(int n);
bool dfs(int s);

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%d %d",&r,&c);

        memset(mapr,0,sizeof(mapr));
        memset(mapc,0,sizeof(mapc));
        for(i=0;i<=r*c;i++) v[i].clear();

        for(i=1;i<=r;i++){
            scanf("%s",s[i]+1);
        }
        for(i=1;i<=c;i++) c1[i]=i;

        int currr=1,currc=c+1;
        for(i=1;i<=r;i++,currr++){
            for(j=1;j<=c;j++){
                if(s[i][j]=='R') continue;
                if(s[i][j]=='W'){
                    currr++; c1[j]=currc++;
                }
                if(s[i][j]=='.'){
                    mapr[currr]=i; mapc[c1[j]]=j;
                    v[currr].push_back(c1[j]);
                }
            }
        }

        printf("Case %d: %d\n",t++,match(currr));

        for(i=1;i<=r;i++) printf("%s\n",s[i]+1);



    }

    return 0;
}



int match(int n){

	memset(left,-1,sizeof(left));
	memset(right,-1,sizeof(right));

	int i,j,k,l,done;

	do{

		done=1;
		memset(col,0,sizeof(col));
		for(i=1;i<=n;i++){
			if(right[i]==-1&&dfs(i)) done=0;
		}

	}while(!done);

	k=0;

	for(i=1;i<=n;i++){
		if(right[i]!=-1){
		    s[mapr[i]][mapc[right[i]]]='T';
		    k++;
		}
	}

	return k;

}

bool dfs(int s){

	if(col[s]) return 0;

	col[s]=1;
	int i,j,k,l;

	for(i=0;i<v[s].size();i++){
		k=v[s][i];

		if(left[k]==-1){
			left[k]=s;
			right[s]=k;
			return 1;
		}
	}

	for(i=0;i<v[s].size();i++){
		k=v[s][i];

		if(dfs(left[k])){
			left[k]=s;
			right[s]=k;
			return 1;
		}
	}

	return 0;
}
