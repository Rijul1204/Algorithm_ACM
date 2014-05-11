#include<stdio.h>
#include<string.h>

#define maxm 1050000

struct trie{
    int pre;
    int edges[4];
};

trie Tri[maxm],root;

int n,tot,ans;
char s[maxm];

void init(trie *a){
    a->pre=0;  memset(a->edges,-1,sizeof(a->edges));
}
int getid(char ch){
    if(ch=='A') return 0;    if(ch=='C') return 1;   if(ch=='G') return 2;   if(ch=='T') return 3;
}
void add(trie *a,char *str){

    int i,j,k,l,id,ret=0;
    l=strlen(str);

    for(i=0;i<=l;i++){

        if(i==l){
            a->pre=a->pre+1;
            if((a->pre)*i>ans) ans=(a->pre)*i;
        }
        else{
            a->pre=a->pre+1;
            if((a->pre)*i>ans) ans=(a->pre)*i;
            id=getid(str[i]);
            if(a->edges[id]==-1){
                a->edges[id]=tot++;
                init(&Tri[a->edges[id]]);
            }
            a=&Tri[a->edges[id]];
        }

    }
}

int main(){

	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

	    scanf("%d",&n);
        tot=1;
	    root=Tri[0];
	    init(&root);

	    ans=0;

	    for(i=1;i<=n;i++){
	        scanf("%s",s);
	        add(&root,s);
	    }

	    printf("Case %d: %d\n",t++,ans);
	}

	return 0;
}
