#include<stdio.h>
#include<string.h>

#define maxm 100110

struct trie{
    int pre,word;
    int edges[11];
};
trie Tri[maxm],root;

int n,tot,flag;
char s[15];

int getid(char ch){
    return (ch-'0');
}

void init(trie *a){
    a->pre=0;
    a->word=0;
    memset(a->edges,-1,sizeof(a->edges));
}

void add(trie *a,char *str){

    int i,j,k,l,id;

    l=strlen(str);
    for(i=0;i<=l;i++){
        if(i==l){
            a->word=a->word+1;
            for(j=0;j<10;j++){
                if(a->edges[j]!=-1) flag=0;
            }
        }
        else{
            if(a->word>0){
                flag=0; break;
            }
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

        tot=1;
        root=Tri[0];
        init(&Tri[0]);

        flag=1;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%s",s);
            if(flag) add(&Tri[0],s);
            //printf("%s\n",s);
        }
        if(flag) printf("Case %d: YES\n",t++);
        else printf("Case %d: NO\n",t++);

    }

}
