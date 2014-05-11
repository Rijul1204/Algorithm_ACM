#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

#define maxm 15

struct node{
    int i,j,move;
};

int dirx[]={1,1,2,2,-1,-1,-2,-2};
int diry[]={2,-2,1,-1,2,-2,1,-1};

char s[maxm][maxm];
int ans[maxm*maxm][maxm][maxm],tot=0,r,c,kth;
int col[maxm][maxm];
queue<node>q;
void bfs(node s,int ind);
void gen(int ind,int x,int y,int rem,node temp);

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%d %d",&r,&c);

        for(i=1;i<=r;i++){
            scanf("%s",s[i]+1);
        }

        memset(ans,-1,sizeof(ans));
        tot=0; node temp;
        for(i=1;i<=r;i++){
            for(j=1;j<=c;j++){
                if(s[i][j]!='.'){
                    temp.i=i; temp.j=j; kth=s[i][j]-'0'; temp.move=0;
                    bfs(temp,tot); tot++;
                }
            }
        }

        int i1,val,res=-1;
        for(i=1;i<=r;i++){
           for(j=1;j<=c;j++){
               val=0;
               for(i1=0;i1<tot;i1++){
				   if(ans[i1][i][j]==-1){
					   val=-1; break;
                   }
                   val+=ans[i1][i][j];
               }
               if(res==-1){
                   res=val;
               }
               else if(res>val&&val!=-1) res=val;
           }
        }

        printf("Case %d: %d\n",t++,res);



    }

    return 0;
}

void gen(int ind,int x,int y,int rem,node temp){

    if(rem<=0) return ;

    int i1,j1,i,j,k,l;
    node temp1;

    for(i1=0;i1<8;i1++){
        k=x+dirx[i1]; l=y+diry[i1];
        if(k<1||l<1||k>r||l>c) continue ;
        if(col[k][l]>=rem) continue;
        col[k][l]=rem;

		//temp1.i=k; temp1.j=l; temp1.move=temp.move+1; q.push(temp1);
		if(ans[ind][k][l]==-1){
			ans[ind][k][l]=temp.move+1;
			temp1.i=k; temp1.j=l; temp1.move=temp.move+1; q.push(temp1);
		}
        else if(ans[ind][k][l]>temp.move+1){
			printf("paise\n");

			temp1.i=k; temp1.j=l; temp1.move=temp.move+1; q.push(temp1);
			ans[ind][k][l]=temp.move+1;
		}
        gen(ind,k,l,rem-1,temp);
    }
}

void bfs(node s,int ind){

    int i,j,k,l,i1,k1;
    node temp,temp1;
    memset(col,0,sizeof(col));
    col[s.i][s.j]=kth; ans[ind][s.i][s.j]=0;
    q.push(s);

    while(!q.empty()){

        temp=q.front(); q.pop();

        i=temp.i; j=temp.j;

		gen(ind,i,j,kth,temp);

    }

}
