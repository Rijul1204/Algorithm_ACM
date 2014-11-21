#include<stdio.h>
#include<string.h>

#define maxm  1000100

char p[maxm];
int pre[maxm],n;

void prefix();
int gcd(int a,int b){
    if(a%b==0) return b;
    return gcd(b,a%b);
}

int main(){

    int i,j,k,l,test,t=1;

   // freopen("in.txt","r",stdin);

    while(scanf("%d",&n)==1){

        if(!n) break;

        scanf("%s",p);

        prefix();

        printf("Test case #%d\n",t++);
        for(i=0;p[i];i++){
            if(i==0) continue;
			if(pre[i+1]==0) continue;
			if((i+1)%2){
				k=(i+1)/2; k++;
			    if(pre[i+1]<k) continue;
			}
			else{
			    k=(i+1)/2;
			    if(pre[i+1]<k) continue;
			}

			if(pre[i+1]==i){
				printf("%d %d\n",i+1,i+1);
				continue;
			}
         	k=gcd(pre[i+1],i+1);
            if(k>1){
				if(pre[i+1]+k==(i+1)) printf("%d %d\n",i+1,(i+1)/k);
            }
        }
        printf("\n");
    }



    return 0;
}

void prefix(){

	int i,j,k,l;

	l=strlen(p);
	pre[1]=0;
	k=0;

	for(i=2;i<=l;i++){
		while(k>0 && p[k]!=p[i-1]) k=pre[k];
		if(p[k]==p[i-1]) k++;
		pre[i]=k;
	}

}
