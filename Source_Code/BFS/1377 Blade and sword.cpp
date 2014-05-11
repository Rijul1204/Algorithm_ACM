#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;

#define maxm 210
#define inf 1<<26

struct node{
	int i,j,d;	
};
int d1[maxm*maxm],d2[maxm*maxm];
int map[maxm][maxm];
char s[maxm][maxm];
vector<int>v;
int d[maxm][maxm],r,c,col[maxm][maxm],ans,c1,ans1,ans2;
queue<node>q;
int mini(int a,int b){
	if(a<b) return a;
	return b;
}
void bfs1(node s1);
void bfs2(node s2);

int main(){
	
	int i,j,k,l,test,t=1;
	
//	freopen("in.txt","r",stdin);
	
	scanf("%d",&test);
	
	while(test--){
		
		scanf("%d %d",&r,&c);
		v.clear();
		
		for(i=1;i<=r;i++){
			scanf("%s",s[i]+1);
		}
		
		node temp,temp1;
		c1=0;
		for(i=1;i<=r;i++){
			for(j=1;j<=c;j++){
				if(s[i][j]=='P'){
					temp.i=i; temp.j=j; temp.d=0;
				}
				if(s[i][j]=='D'){
					temp1.i=i; temp1.j=j; temp1.d=0;
				}
				if(s[i][j]=='*'){
					map[i][j]=c1++;
				}				
			}
		}

		bfs1(temp);
		if(ans!=inf){
			printf("Case %d: %d\n",t++,ans);
			continue;
		}
		bfs2(temp1);		
		if(c1>1) ans=mini(ans,ans1+ans2);
		if(ans==inf){
			printf("Case %d: impossible\n",t++);
		}
		else printf("Case %d: %d\n",t++,ans);
		
	}
	
	return 0;
}

void bfs2(node s1){
	
	int i,j,k,l,i1,c2=0;
	node temp,temp1;
	memset(col,0,sizeof(col));
	while(!q.empty()) q.pop();
	col[s1.i][s1.j]=1;
	
	q.push(s1);
	
	ans2=inf;
	
	while(!q.empty()){
		
		temp=q.front(); q.pop();
		if(temp.d>=ans1+ans2 && c1>1) break;		
		i=temp.i; j=temp.j;
		
		if(i<1||j<1||i>r||j>c) continue;
		if(s[i][j]=='#') continue;
		if(s[i][j]=='*'&&ans1!=inf){
			if(v.size()==1){
				if(map[i][j]==v[0]) ans2=mini(ans2,temp.d+2);
				else  ans2=mini(ans2,temp.d+1);
			}
			else{
				ans2=mini(ans2,temp.d+1);
			}
			continue;
		}
		if(s[i][j]=='P'){
			ans=temp.d;
			break;
		}
		//left>>>>>>>
		k=i; l=j-1;
		if(!col[k][l]){
			temp1.d=temp.d+1; temp1.i=k; temp1.j=l; col[k][l]=1; 
			q.push(temp1);
		}
		
		//right>>>
		k=i; l=j+1;
		if(!col[k][l]){
			temp1.d=temp.d+1; temp1.i=k; temp1.j=l; col[k][l]=1; 
			q.push(temp1);
		}
		
		//up
		k=i-1; l=j;
		if(!col[k][l]){
			temp1.d=temp.d+1; temp1.i=k; temp1.j=l; col[k][l]=1; 
			q.push(temp1);
		}
		
		//down
		
		k=i+1; l=j;
		if(!col[k][l]){
			temp1.d=temp.d+1; temp1.i=k; temp1.j=l; col[k][l]=1; 
			q.push(temp1);
		}			
		
	}	
	
}
void bfs1(node s1){
	
	int i,j,k,l,i1,c2=0;	
	node temp,temp1;
	memset(col,0,sizeof(col));
	while(!q.empty()) q.pop();
	col[s1.i][s1.j]=1;
	q.push(s1);
	ans1=inf; ans=inf;
	
	while(!q.empty()){
		
		temp=q.front(); q.pop();
	
		if(temp.d>ans1) break;
		
		i=temp.i; j=temp.j;
		if(i<1||j<1||i>r||j>c) continue;
		if(s[i][j]=='#') continue;
		
		if(s[i][j]=='*'){
			ans1=mini(ans1,temp.d);
			d1[map[i][j]]=ans1;
			v.push_back(map[i][j]);			
			continue;
		}
		if(s[i][j]=='D'){
			ans=temp.d; 
			break;
		}
		//left>>>>>>>
		k=i; l=j-1;
		if(!col[k][l]){
			temp1.d=temp.d+1; temp1.i=k; temp1.j=l; col[k][l]=1; 
			q.push(temp1);
		}
		
		//right>>>
		k=i; l=j+1;
		if(!col[k][l]){
			temp1.d=temp.d+1; temp1.i=k; temp1.j=l; col[k][l]=1; 
			q.push(temp1);
		}
		
		//up
		k=i-1; l=j;
		if(!col[k][l]){
			temp1.d=temp.d+1; temp1.i=k; temp1.j=l; col[k][l]=1; 
			q.push(temp1);
		}		
		//down
		
		k=i+1; l=j;
		if(!col[k][l]){
			temp1.d=temp.d+1; temp1.i=k; temp1.j=l; col[k][l]=1; 
			q.push(temp1);
		}			
		
	}	
	
}

/* critical input >>>

  3
5 6
######
##.#*#
#.P#D#
##..*#
######
5 10
##########
#...#....#
#...#....#
#.*P#D.*.#
##########
11 10
##########
#*#.....D#
###.###.##
#...#.#..#
#.....##.#
#####*####
#........#
#........#
#........#
#P.......#
##########
  */
