#include<stdio.h>
#include<string.h>
#include<math.h>

#define maxm 100
#define ii long long int

int sl[maxm],su[maxm],sp[maxm],automata[maxm][3];
ii L,U,P;
int ml,mu,mp,dp[55][2][2][55],pre[55][2][2][55];

int cal(int ind,int fl1,int fl2,int len);
ii print(int ind,int fl1,int fl2,int len,ii num);
void gen(int a[],int tot);

int main(){

    int i,j,k,l,test,t=1;

  //  freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        for(i=0;i<=70;i++){
            sl[i]=su[i]=sp[i]=0;
        }
        ml=mu=mp=0;

        scanf("%lld %lld %lld",&L,&U,&P);

        while(P){
            sp[mp++]=P%2; P/=2;
        }
        mp--;
        gen(sp,mp);

        while(L){
            sl[ml++]=L%2; L/=2;
        }
        ml--;

        while(U){
            su[mu++]=U%2; U/=2;
        }
        mu--;

        memset(dp,-1,sizeof(dp));

        int flag=0,val;

        for(i=0;i<=1;i++){
            if(sl[mu]>i) continue;
            if(su[mu]<i) break;
            if(sl[mu]==i) k=1; else k=0;
            if(su[mu]==i) l=1; else l=0;
            if(cal(mu-1,k,l,automata[0][i])){
                flag=1;
                val=i;
                break;
            }
        }
        printf("Case %d: ",t++);
        if(!flag){
            printf("NONE\n"); continue;
        }
        printf("%lld\n",print(mu-1,k,l,automata[0][val],val));
    }

    return 0;
}

ii print(int ind,int fl1,int fl2,int len,ii num){

    if(ind<0) return num;
    int k,l; ii j=2;
    ii i=pre[ind][fl1][fl2][len];
    if(sl[ind]==i&&fl1) k=1; else k=0;
    if(su[ind]==i&&fl2) l=1; else l=0;
    num*=j; num+=i;
    return print(ind-1,k,l,automata[len][i],num);
}

int cal(int ind,int fl1,int fl2,int len){

    if(ind<0&&len>mp) return 1;
    if(ind<0) return 0;

    if(dp[ind][fl1][fl2][len]!=-1) return dp[ind][fl1][fl2][len];

    int i,j,k,l;

    for(i=0;i<=1;i++){
        if(sl[ind]>i&&fl1) continue;
        if(su[ind]<i&&fl2) break;
        if(sl[ind]==i&&fl1) k=1; else k=0;
        if(su[ind]==i&&fl2) l=1; else l=0;
        if(cal(ind-1,k,l,automata[len][i])){
              pre[ind][fl1][fl2][len]=i;
              return dp[ind][fl1][fl2][len]=1;
        }
    }

    return dp[ind][fl1][fl2][len]=0;
}

void gen(int a[],int tot){

    int i,j,k,l;
    int pre[maxm],num[maxm];

	j=1;
    for(i=tot;i>=0;i--){
        num[j++]=a[i];
    }
	tot++;

    //for(i=1;i<=tot;i++) printf("%d ",num[i]);

    pre[1]=0; automata[0][num[1]]=1; automata[0][!num[1]]=0;
    k=0; l=0;

    for(i=2;i<=tot;i++){
        automata[i-1][num[i]]=i;

		while(k>0&&num[i]!=num[k+1]) k=pre[k];
        if(num[i]==num[k+1]) pre[i]=k+1;
        else pre[i]=k;

		j=!(num[i]);
		while(l>0&&j!=num[l+1]) l=pre[l];
        if(j==num[l+1]) automata[i-1][j]=l+1;
        else automata[i-1][j]=l;

		l=k=pre[i];

    }
    automata[tot][0]=automata[tot][1]=tot;

	/*
	printf("\n");
	for(i=0;i<tot;i++){
		printf("%d- 0->%d  1->%d\n",i,automata[i][0],automata[i][1]);
	}
	*/

}
