#include<stdio.h>
#include<string.h>
#include<math.h>

#define maxm 100000000

int p[(maxm/32)+10],tot,prime[(maxm/10)+1000];

int on(int n,int k){
    return (n|(1<<k));
}
bool chck(int n,int k){
    return (bool)(n&(1<<k));
}
void gen(int n);

int main(){

    int i,j,k,l,test,t=1;

    gen(maxm-5);
    //for(i=0;(i*100)<tot;i++){
    //    printf("%d\n",prime[i*100]);
    //}

    return 0;
}

void gen(int n){

    int i,j,k,l,sq;

    sq=sqrt(n);

    for(i=3;i<=sq;i+=2){
        if(chck(p[i>>5],i&31)) continue;
        for(j=(i*i);j<=n;j+=(i<<1)){
            p[j>>5]=on(p[j>>5],j&31);
        }
    }

    // takine prime into array>>>>>>>>>
    prime[tot++]=2;
    printf("%d\n",2);
    for(i=3;i<=n;i+=2){
        if(!chck(p[i>>5],i&31)){
			prime[tot++]=i;
			//if((tot-1)%100==0) printf("%d\n",i);
		}
    }
    printf("%d\n",tot);
}
