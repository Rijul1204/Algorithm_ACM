#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;

#define maxm 1000100

////////////*********  Trie + Aho Corasick  ********/////////////////

#define maxn 11200
#define maxc 160
#define maxl 80

struct trie{
    vector<int>v;
    int edges[30],ind;
};
trie Tri[maxn],root;
int mat[maxn][maxc],tot,f[maxn],n; //  f=failure....

int getid(char ch){
    return ch-'a';
}

void init(trie *a){
    a->v.clear();
    memset(a->edges,-1,sizeof(a->edges));
}

void add(trie *a,char *s,int ind){

    int i,l,id;
    l=strlen(s);

    for(i=0;i<=l;i++){
        if(i==l){
            a->v.push_back(ind);
            mat[a->ind][ind]=1;
            continue;
        }
        id=getid(s[i]);
        if(a->edges[id]==-1){
            a->edges[id]=tot++;
            init(&Tri[a->edges[id]]);
            Tri[a->edges[id]].ind=a->edges[id];
        }
        a=&Tri[a->edges[id]];
    }

}
void build(){

    int i,j,piv;
    trie *a=&Tri[0];

    for(i=0;i<=26;i++){
        if(a->edges[i]==-1) a->edges[i]=0;
    }

    //  Failure  Function .........

    queue<int>q;
    for(i=0;i<=26;i++){
        if(a->edges[i]){
            f[a->edges[i]]=0;
            q.push(a->edges[i]);
        }
    }
    while(!q.empty()){
        int state=q.front(); q.pop();

		a=&Tri[state];
        for(i=0;i<=26;i++){
            if(a->edges[i]==-1) continue;
            int failure=f[state];
            while(Tri[failure].edges[i]==-1){
                failure=f[failure];
            }
            failure=Tri[failure].edges[i];
            piv=Tri[state].edges[i];
            f[piv]=failure;
            for(j=0;j<=n;j++){
                if(mat[failure][j] && !mat[piv][j]){
                    mat[piv][j]=1;
                    Tri[piv].v.push_back(j);
                }
            }
			q.push(piv);
        }

    }
}


//////////////////**************   END       *****************////////////////

char s[maxm];
char pat[200][100];
int c[200],max1; // c= count;

void match(char *s);

int main(){

    int i,j,k,l,test,t=1;

    freopen("in.txt","r",stdin);

    while(scanf("%d",&n)==1){

        if(!n) break;

        //Init.......
        memset(mat,0,sizeof(mat));
        memset(c,0,sizeof(c));
        tot=1; max1=0;
        root=Tri[0];
        init(&Tri[0]);

        for(i=1;i<=n;i++){
            scanf("%s",pat[i]);
            add(&Tri[0],pat[i],i);
        }
        build();

        scanf("%s",s);
        match(s);

        printf("%d\n",max1);
        for(i=1;i<=n;i++){
            if(c[i]==max1){
                printf("%s\n",pat[i]);
            }
        }

    }

    return 0;
}

int find_next(int curr,char ch){

    int id=getid(ch);
    while(Tri[curr].edges[id]==-1) curr=f[curr];
    return Tri[curr].edges[id];
}

void match(char *s){

    int i,j,l;

    l=strlen(s);

    int curr=0;
    for(i=0;i<l;i++){
        curr=find_next(curr,s[i]);
        for(j=0;j<Tri[curr].v.size();j++){
            //printf("%d no matched at %d\n",Tri[curr].v[j],i);
            c[Tri[curr].v[j]]++;
            if(c[Tri[curr].v[j]]>max1){
                max1=c[Tri[curr].v[j]];
            }
        }
    }

}
