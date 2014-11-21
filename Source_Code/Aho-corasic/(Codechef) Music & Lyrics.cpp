#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;

#define maxm 50100

////////////*********  Trie + Aho Corasick  ********/////////////////

//  maxn =required trie  node ....
#define maxn 2500010
//  maxc= query...
#define maxc 550
//  maxl = length of query  string...
#define maxl 5050
#define cn 64

struct trie{
    int edges[cn+3],ind;
};
trie Tri[maxn],root;
int tot,f[maxn],n,pos[maxc]; //  f=failure....
int c[maxn]; // c= count;

int getid(char ch){
    if(ch>='a' && ch<='z') return ch-'a';
    else if(ch>='A' && ch<='Z') return ch-'A'+26;
    else if(ch>='0' && ch<='9') return ch-'0'+52;
    if(ch=='-') return cn-1;
    return ch-'a';
}

void init(trie *a,int ind){
    a->ind=ind;
    memset(a->edges,-1,sizeof(a->edges));
}

void add(trie *a,char *s,int ind){

    int i,l,id;
    l=strlen(s);

    for(i=0;i<=l;i++){
        if(i==l){
            pos[ind]=a->ind;
            continue;
        }
        id=getid(s[i]);
        if(a->edges[id]==-1){
            a->edges[id]=tot;
            init(&Tri[a->edges[id]],tot++);
        }
        a=&Tri[a->edges[id]];
    }

}
void build(){

    int i,j,piv;
    trie *a=&Tri[0];

    for(i=0;i<=cn;i++){
        if(a->edges[i]==-1) a->edges[i]=0;
    }

    //  Failure  Function .........

    queue<int>q;
    for(i=0;i<=cn;i++){
        if(a->edges[i]){
            f[a->edges[i]]=0;
            q.push(a->edges[i]);
        }
    }
    while(!q.empty()){
        int state=q.front(); q.pop();

		a=&Tri[state];
        for(i=0;i<=cn;i++){
            if(a->edges[i]==-1) continue;
            int failure=f[state];
            while(Tri[failure].edges[i]==-1){
                failure=f[failure];
            }
            failure=Tri[failure].edges[i];
            piv=Tri[state].edges[i];
            f[piv]=failure;
            /*
            trie *a1=&Tri[failure];
            trie *a2=&Tri[piv];
            for (it=a1->v.begin(); it!=a1->v.end(); ++it){
                a2->v.insert(*it);
            }
            */
			q.push(piv);
        }

    }
}


//////////////////**************   END       *****************////////////////

char s[maxm];
char pat[5010];

void match(char *s);

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    scanf("%d",&n);

    //Init.......
    c[0]=0;
    root=Tri[0];
    init(&Tri[0],tot++);

    for(i=1;i<=n;i++){
        scanf("%s",pat);
        //printf("%s\n",pat);
        add(&Tri[0],pat,i);
    }

    build();

    int m;
    scanf("%d",&m);
    for(i=1;i<=m;i++){
        scanf("%s",s);
        match(s);
    }

    queue<int>q;
    vector<int>v;

    q.push( 0 );
    while( !q.empty()){
        int now = q.front();
        q.pop();
        v.push_back(now);
        for( i=0;i<=cn;i++ ){
            if( Tri[now].edges[i]!=-1 && Tri[now].edges[i]!=0 ) q.push(Tri[now].edges[i]);
        }
    }
    for( i=v.size()-1;i>=0;i-- ){
        c[f[v[i]]] += c[v[i]];
    }

    for(i=1;i<=n;i++){
         printf("%d\n",c[pos[i]]);
    }



    return 0;
}

int find_next(int curr,char ch){

    int id=getid(ch);
    //printf("curr =%d %c-%d\n",curr,ch,id);
    while(Tri[curr].edges[id]==-1) curr=f[curr];
    //printf("curr =%d %c-%d %d\n",curr,ch,id,Tri[curr].edges[id]);
    return Tri[curr].edges[id];
}

void match(char *s){

    int i,j,l;

    l=strlen(s);

    int curr=0;
    for(i=0;i<l;i++){
        curr=find_next(curr,s[i]);
        c[curr]++;
        /*
        trie *a=&Tri[curr];
        for (it=a->v.begin(); it!=a->v.end(); ++it){
            c[*it]++;
        }
        */
    }

}
