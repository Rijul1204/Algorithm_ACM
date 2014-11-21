#include<stdio.h>
#include<string.h>

int x1,y1,x2,y2,x,y,m;

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);

        scanf("%d",&m);
        printf("Case %d:\n",t++);

        for(i=1;i<=m;i++){
            scanf("%d %d",&x,&y);
            if(x>=x1&&x<=x2&&y>=y1&&y<=y2) printf("Yes\n");
            else printf("No\n");
        }

    }

    return 0;
}
