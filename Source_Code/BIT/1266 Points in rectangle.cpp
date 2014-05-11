//2-D bit

#include<stdio.h>
#include<string.h>

#define maxm 1010
#define max_v 1005

int tree[maxm][maxm];
bool fl[maxm][maxm];

void updatey(int x,int y,int val){
	while(y<=max_v){
		tree[x][y]+=val;
		y+=(y & -y);
	}
}
void updatex(int x,int y,int val){
	while(x<=max_v){
		updatey(x,y,val);
		x+=(x & -x);
	}
}
int ready(int x,int y){
	int ret=0;
	while(y>0){
		ret+=tree[x][y];
		y-=(y & -y);
	}
	return ret;
}
int readx(int x,int y){
	int ret=0;
	while(x>0){
		ret+=ready(x,y);
		x-=(x & -x);
	}
	return ret;
}

int main(){

	int i,j,k,l,k1,l1,test,t=1,q,ans;

	//freopen("in.txt","r",stdin);
	
	scanf("%d",&test);

	while(test--){
		
		memset(tree,0,sizeof(tree));
		memset(fl,0,sizeof(fl));
		scanf("%d",&q);
		printf("Case %d:\n",t++);
		for(i=1;i<=q;i++){
			scanf("%d",&j);
			if(j==0){
				scanf("%d %d",&k,&l);
				k++; l++;
				if(fl[k][l]) continue;
				fl[k][l]=1;
				updatex(k,l,1);
			}
			else{
				scanf("%d %d %d %d",&k,&l,&k1,&l1);
				k++; l++; k1++; l1++;
				ans=readx(k1,l1);
				ans-=readx(k1,l);
				ans-=readx(k,l1);
				ans+=readx(k,l);
				for(j=k;j<=k1;j++){
					if(fl[j][l]) ans++;
				}
				for(j=l;j<=l1;j++){
					if(fl[k][j]) ans++;
				}
				if(fl[k][l]) ans--;
				//ans-=readx(k,l-1);
				//ans+=readx(k-1,l-1);
				printf("%d\n",ans);
			}
		}

	}

	return 0;
}