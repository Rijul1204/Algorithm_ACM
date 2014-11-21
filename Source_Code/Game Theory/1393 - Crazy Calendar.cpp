#include<stdio.h>
#include<string.h>

#define maxm 50010

int a[maxm],r,c;
int getid(int x,int y){
    return (x-1)*c+y;
}

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%d %d",&r,&c);

        for(i=1;i<=r*c;i++){
            scanf("%d",&a[i]);
        }
        int ans=0;

        int flag=0;
        for(i=r;i>=1;i--){
            if(flag) j=c;
            else j=c-1;

            for(;j>=1;j-=2){
                ans^=a[getid(i,j)];
            }
            flag=!flag;
        }

        if(!ans) printf("Case %d: lose\n",t++);
        else printf("Case %d: win\n",t++);

    }

    return 0;
}
