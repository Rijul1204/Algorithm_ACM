#include<stdio.h>
#include<string.h>

#define maxm 110
#define mod 1000000007
#define ii long long int

struct node{
	int len;
	int val;
	node(){}
	node(int a,int b){len=a; val=b;}
};

char s1[maxm],s2[maxm],s3[305];
int pre1[30][maxm],pre2[30][maxm],pre3[30][310],l1,l2,l3;
node dp[maxm][maxm][305];
int pre[maxm][maxm][305];
bool v[maxm][maxm][305];

void init();
node cal(int i,int j,int k);
void print(int i,int j,int k);

int main(){
	
	int i,j,k,l,test,t=1;
	
//	freopen("in.txt","r",stdin);
	
	scanf("%d",&test);
	
	while(test--){
		
		scanf("%s",s1); 	scanf("%s",s2);		scanf("%s",s3);
		l1=strlen(s1);      l2=strlen(s2);      l3=strlen(s3);
		init();
		memset(v,0,sizeof(v));
		node ans=cal(0,0,0);
		if(ans.val==-1){
			printf("Case %d: 0\nNOT FOUND\n",t++); continue;
		}
		printf("Case %d: %d\n",t++,ans.val);
		print(0,0,0);
		printf("\n");
	}
	
	return 0;
}

void print(int i,int j,int k){
	
	if(i>=l1&&j>=l2) return ;
	if(k>=l3) return ;
	
	int i1;
	
	i1=pre[i][j][k];
	
	if(pre1[i1][i]==i&&pre2[i1][j]==j&&i<l1&&j<l2){
		printf("%c",s1[i]);
		print(i+1,j+1,pre3[i1][k]+1); return ;
	}
	else if(pre1[i1][i]==i&&i<l1){
		printf("%c",s1[i]);
		print(i+1,j,pre3[i1][k]+1); return ;
		
	}
	else if(pre2[i1][j]==j&&j<l2){
		printf("%c",s2[j]);
		print(i,j+1,pre3[i1][k]+1);return ;
		
	}
	
}

void init(){
	
	int i1,i,j,k,l;
	
	for(i1=0;i1<26;i1++){
		pre1[i1][l1]=l1; pre2[i1][l2]=l2; pre3[i1][l3]=l3;
	}
	
	for(i1=0;i1<26;i1++){
		for(i=l1-1;i>=0;i--){
			if(s1[i]==i1+'a') pre1[i1][i]=i;
			else pre1[i1][i]=pre1[i1][i+1];
		}
		for(i=l2-1;i>=0;i--){
			if(s2[i]==i1+'a') pre2[i1][i]=i;
			else pre2[i1][i]=pre2[i1][i+1];
		}
		for(i=l3-1;i>=0;i--){
			if(s3[i]==i1+'a') pre3[i1][i]=i;
			else pre3[i1][i]=pre3[i1][i+1];
		}
	}
}

node cal(int i,int j,int k){
	
	if(i>=l1&&j>=l2) return node(0,1);
	if(k>=l3) return node(500,-1);
	
	if(v[i][j][k]) return dp[i][j][k];
	v[i][j][k]=1;
	
	ii val=0;
	node ret=node(500,-1),ret1;
	int i1,j1,l,len=500;
	
	i1=s1[i]-'a'; 
	if(i>=l1) i1=1000;
	j1=s2[j]-'a';
	if(j>=l2) j1=1000;
	
	if(i1>j1){
		l=i1; i1=j1; j1=l;
	}
	if(i1==1000) return dp[i][j][k]=node(500,-1);
	//for(i1=0;i1<26;i1++){

	if(pre1[i1][i]==i&&pre2[i1][j]==j&&i<l1&&j<l2){
		if(pre3[i1][k]<l3){
			ret1=cal(i+1,j+1,pre3[i1][k]+1);
			ret1.len++;
			if(ret1.val!=-1){
				if(ret1.len<ret.len){
					ret=ret1;
					pre[i][j][k]=i1;
				}
				else if(ret1.len==ret.len){
					val=ret1.val+ret.val; val%=mod;
					ret.val=val;
				}
				return dp[i][j][k]=ret;
			}
		}
		else return dp[i][j][k]=node(500,-1);
	}
	else if(pre1[i1][i]==i&&i<l1){
		if(pre3[i1][k]<l3){
			ret1=cal(i+1,j,pre3[i1][k]+1);
			ret1.len++;
			if(ret1.val!=-1){
				if(ret1.len<ret.len){
					ret=ret1;
					pre[i][j][k]=i1;
				}
				else if(ret1.len==ret.len){
					val=ret1.val+ret.val; val%=mod;
					ret.val=val;
				}
			}
		}
		else return dp[i][j][k]=node(500,-1);
		
	}
	else if(pre2[i1][j]==j&&j<l2){
		if(pre3[i1][k]<l3){
			ret1=cal(i,j+1,pre3[i1][k]+1);
			ret1.len++;
			if(ret1.val!=-1){
				if(ret1.len<ret.len){
					ret=ret1;
					pre[i][j][k]=i1;
				}
				else if(ret1.len==ret.len){
					val=ret1.val+ret.val; val%=mod;
					ret.val=val;
				}
			}
		}
		else return dp[i][j][k]=node(500,-1);
	}
	
	//	}
    i1=j1;
	if(i1==1000) return dp[i][j][k]=ret;
	
	if(pre1[i1][i]==i&&pre2[i1][j]==j&&i<l1&&j<l2){
		if(pre3[i1][k]<l3){
			ret1=cal(i+1,j+1,pre3[i1][k]+1);
			ret1.len++;
			if(ret1.val!=-1){
				if(ret1.len<ret.len){
					ret=ret1;
					pre[i][j][k]=i1;
				}
				else if(ret1.len==ret.len){
					val=ret1.val+ret.val; val%=mod;
					ret.val=val;
				}
				return dp[i][j][k]=ret;
			}
		}
		else return dp[i][j][k]=node(500,-1);
	}
	else if(pre1[i1][i]==i&&i<l1){
		if(pre3[i1][k]<l3){
			ret1=cal(i+1,j,pre3[i1][k]+1);
			ret1.len++;
			if(ret1.val!=-1){				
				if(ret1.len<ret.len){
					ret=ret1;
					pre[i][j][k]=i1;
				}
				else if(ret1.len==ret.len){
					val=ret1.val+ret.val; val%=mod;
					ret.val=val;
				}
			}
		}
		else return dp[i][j][k]=node(500,-1);
		
	}
	else if(pre2[i1][j]==j&&j<l2){
		if(pre3[i1][k]<l3){
			ret1=cal(i,j+1,pre3[i1][k]+1);
			ret1.len++;
			if(ret1.val!=-1){
				if(ret1.len<ret.len){
					ret=ret1;
					pre[i][j][k]=i1;
				}
				else if(ret1.len==ret.len){
					val=ret1.val+ret.val; val%=mod;
					ret.val=val;
				}
			}
		}
		else return dp[i][j][k]=node(500,-1);
	}

	ret.val%=mod;
	
	return dp[i][j][k]=ret;
	
}

