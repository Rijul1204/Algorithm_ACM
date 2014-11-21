#include<stdio.h>
#include<string.h>
#include<vector>
#include<map>
#include<string>
using namespace std;

#define maxm 1105

struct edge{
	int u,v;
	char str[40];
};

edge edges[maxm];
//map<string,int>word;
vector<int>v[maxm];
int mark[maxm],n,in[maxm],out[maxm],len[maxm],st,tot,en,flagn[40],mat[40][40];
char s[maxm][40],ans[maxm][40];

void back(int x);

int main(){

	int i,j,k,l,t=1,test;

//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);
		memset(in,0,sizeof(in)); memset(out,0,sizeof(out));
		memset(flagn,0,sizeof(flagn)); memset(mat,0,sizeof(mat));

		tot=0;
		
		for(i=1;i<=n;i++){
			scanf("%s",s[i]);
			len[i]=strlen(s[i]);
			edges[i].u=s[i][0]-'a'; edges[i].v=s[i][len[i]-1]-'a';
			strcpy(edges[i].str,s[i]);
			k=s[i][0]-'a'; l=s[i][len[i]-1]-'a';
			st=k;
			flagn[k]=1; flagn[l]=1;
			mat[k][l]=1; mat[l][k]=1;
			out[k]++; in[l]++;
		}

		//floyd  for conection>>
		for(k=0;k<=26;k++){
			for(i=0;i<=26;i++){
				for(j=0;j<=26;j++){
					if(mat[i][k]&&mat[k][j]) mat[i][j]=1;				
				}
			}
		}

		
		int flag=0; 
		
		//connectivity check>>>>>>>>>>>
		for(i=0;i<=26;i++){
			if(!flagn[i]) continue;
			for(j=0;j<=26;j++){
				if(!flagn[j]||i==j) continue;
				if(!mat[i][j]){
				//	printf("%c %c\n",i+'a',j+'a');
					flag=1;
				}
			}
		}	

		k=0; l=0;	
		
		//degree check>>>>
		for(i=0;i<=26;i++){
			if(in[i]==out[i]) continue;
			j=in[i]-out[i];
			if(j>1||j<-1){
				flag=1; break;
			}
			if(j==-1){
				k++; st=i;
			}
			else if(j==1){
				en=i;	l++;
			}
		}

		if(k>1||l>1) flag=1;
		if(k!=l) flag=1;

		printf("Case %d: ",t++);
	
		if(flag){
			printf("No\n");
			continue;
		}

		printf("Yes\n");	
		memset(mark,0,sizeof(mark));
	

		tot=0;
		//path print>>>
		back(st);
		
		for(i=tot-1;i>=0;i--){
			printf("%s",ans[i]);
			if(i) printf(" ");
		}
		printf("\n");		
	}

	return 0;
}

void back(int x){
     
	int i,y;

	for(i=1;i<=n;i++){
		if(mark[i]) continue;

		if(edges[i].u==x){
		//	ret[++tot]=edges[i];
			mark[i]=1;			
			y=edges[i].v;
			back(y);
			strcpy(ans[tot++],s[i]);
			
		}	

	}

}
