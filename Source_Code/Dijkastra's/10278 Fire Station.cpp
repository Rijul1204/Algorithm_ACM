#include<stdio.h>
#include<queue>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

struct node{
	int n;
	int w;
};

bool operator<(const node &a,const node &b){
	return a.w>b.w;
}

vector<node>v[1000];
int dis[1000],fire[1000],f,flagf[1000],tempdis[1000],n;
priority_queue<node>q;
void dij();
int secdij(int s);

int main(){

	int i,j,k,l,test,m,c,l1,k1,num,bl=0;
	char s[1000];
	node temp;
	
//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){


		memset(flagf,0,sizeof(flagf));
		scanf("%d %d",&f,&n);
		for(i=0;i<=n;i++){
			dis[i]=1234567;
			v[i].clear();
		}
		
		for(i=0;i<f;i++){
			scanf("%d",&fire[i]);
			flagf[i]=1;
		}
		gets(s);
		while(gets(s)){
			if(!s[0]) break;
			num=1;
			//scanf("%d %d %d",&k,&l,&c);
			for(i=0;s[i];i++){
				if(isdigit(s[i])){
					char temps[1000];
					l=0;
					while(isdigit(s[i])){
						temps[l++]=s[i++];
					}
					temps[l]='\0';
					i--;
					if(num==1){
						l1=atoi(temps);
						num=2;
					}
					else if(num==2){
						k1=atoi(temps);
						num=3;
					}
					else if(num==3){
						c=atoi(temps);
						num=4;
					}
				}
			}					
					
			temp.n=l1; temp.w=c;
			v[k1].push_back(temp);
			temp.n=k1;
			v[l1].push_back(temp);
		}

		dij();
	
		int min=12345678;
		int mark=0;
		for(i=1;i<=n;i++){
		//	if(!flagf[i]){
				k=secdij(i);
				if(min>k){
					min=k;
					mark=i;
				}
		//	}

		}
		if(bl)printf("\n");
		bl=1;
		printf("%d\n",mark);

	}

	return 0;
}

int  secdij(int s){

	int i,j,k,l;
	node temp,temp1;

	for(i=0;i<=n;i++){
		tempdis[i]=dis[i];
	}

	temp.n=s;
	temp.w=0;
	tempdis[s]=0;

	q.push(temp);

	
	while(!q.empty()){

		temp=q.top(); q.pop();
		i=temp.n;
		k=temp.w;


		for(j=0;j<v[i].size();j++){
			l=v[i][j].n;
			temp1=v[i][j];
			if(tempdis[l]>temp1.w+tempdis[i]){
				tempdis[l]=temp1.w+tempdis[i];
				temp.w=tempdis[l];
				temp.n=l;
				q.push(temp);
			}
		}

	}
	
	int max=-1;
	for(i=1;i<=n;i++){
		if(tempdis[i]>max) max=tempdis[i];
	}

	return max;


}

void dij(){

	node temp,temp1;
	int i,j,k,l;
	for(i=0;i<f;i++){
		j=fire[i];
		dis[j]=0;
		temp.n=j; temp.w=0;
		q.push(temp);
	}

	while(!q.empty()){

		temp=q.top(); q.pop();
		i=temp.n;
		k=temp.w;


		for(j=0;j<v[i].size();j++){
			l=v[i][j].n;
			temp1=v[i][j];
			if(dis[l]>temp1.w+dis[i]){
				dis[l]=temp1.w+dis[i];
				temp.w=dis[l];
				temp.n=l;
				q.push(temp);
			}
		}

	}



}




