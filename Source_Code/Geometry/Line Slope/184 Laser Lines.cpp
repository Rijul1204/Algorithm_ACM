#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

#define maxm 500
#define maxn 250000
#define inf (1<<28)

int gcd(int a,int b){
	if(a==0 && b==0) return 1;
	if(a==0) return b;
	if(b==0) return a;
	return gcd(b,a%b);
}

struct point{
    int x,y,ind;
    bool operator == (const point &p) const{
		return (p.x==x && p.y==y);
	}
	bool operator < (const point &p) const{
		if(p.x==x) return y<p.y;
		return x<p.x;
	}

	bool operator > (const point &p) const{
		if(p.x==x) return y>p.y;
		return x>p.y;
	}
};

point p[maxm];

// y/x=m;
struct line{

	point p1,p2;
	int x,y;
	line(){}
	line(point p3,point p4){

		p1=p3; p2=p4;

		y=p2.y-p1.y; x=p2.x-p1.x;

		if(x==0&&y!=0) y=inf;
		else{
			if(x<0){
				y*=-1; x*=-1;
			}
			int k;

			if(y<0) k=-y;
			else k=y;

			int g=gcd(k,x);
			if(g!=0) { y/=g; x/=g; }

		}
	}
};

line lines[maxn];
bool flag[maxm][maxm];

bool comp(point p1,point p2){
	if(p1.x==p2.x) return p1.y<p2.y;
	return p1.x<p2.x;
}
bool comp1(line l1,line l2){
	if(l1.x==l2.x) return l1.y<l2.y;
	return l1.x<l2.x;
}
vector<point>v[maxn];

struct node{
	int c;
	point a[15];
};
node nodes[maxn];

bool comp2(node a,node b){
	if(a.a[0]==b.a[0]) return a.a[1]<b.a[1];
	return a.a[0]<b.a[0];
}

bool comp3(vector<point>v1,vector<point>v2){
	if(v1[0]==v2[0]) return v1[1]<v2[1];
	return v1[0]<v2[0];
}

int n;
bool chck();

int main(){

	int i,j,k,l;

	//freopen("in.txt","r",stdin);
	//freopen("out1.txt","r",stdin);

	while(1){

		k=1;

		scanf("%d %d",&p[0].x,&p[0].y);
		if(!p[0].x && !p[0].y) break;

		while(scanf("%d %d",&p[k].x,&p[k].y)==2){
			if(!p[k].x&&!p[k].y) break;
			k++;
		}

		n=k;
		sort(p,p+k,comp);

		for(i=0;i<k;i++){
			p[i].ind=i;
		}

		memset(flag,0,sizeof(flag));

		if(chck()){
			printf("The following lines were found:\n");
		}
		else{
			printf("No lines were found\n"); continue;
		}

		//memset(flag,0,sizeof(flag));

		for(i=0;i<n;i++){
			for(j=i+1,k=0;j<n;j++){
                if(flag[i][j]) continue;
				lines[k]=line(p[i],p[j]);
				k++;
			}

			if(k<2) continue;
			stable_sort(lines,lines+k,comp1);
			l=0;
			/*
			v[l].clear();
			v[l].push_back(p[i]);
			v[l].push_back(lines[0].p2);
			*/
			nodes[l].c=0;
			nodes[l].a[nodes[l].c++]=p[i];
			nodes[l].a[nodes[l].c++]=lines[0].p2;

			for(j=1;j<k;j++){
			    if(lines[j].x==lines[j-1].x && lines[j].y==lines[j-1].y){
					//v[l].push_back(lines[j].p2);
					nodes[l].a[nodes[l].c++]=lines[j].p2;
				}
				else{
				    if(nodes[l].c>2) l++;
					/*
					v[l].clear();
					v[l].push_back(p[i]);
					v[l].push_back(lines[j].p2);
					*/
					nodes[l].c=0;
                    nodes[l].a[nodes[l].c++]=p[i];
                    nodes[l].a[nodes[l].c++]=lines[j].p2;
				}
			}
			//sort(v,v+(l+1),comp3);
			sort(nodes,nodes+l+1,comp2);

			for(j=0;j<=l;j++){
				//if(v[j].size()<3) continue;
				if(nodes[j].c<3) continue;;
				for(k=0;k<nodes[j].c;k++){
					printf("(%4d,%4d)",nodes[j].a[k].x,nodes[j].a[k].y);
					for(int k1=k+1;k1<nodes[j].c;k1++){
						flag[nodes[j].a[k].ind][nodes[j].a[k1].ind]=1;
					}
				}
				printf("\n");
			}
		}

	}

    return 0;
}


bool chck(){

	int i,j,k,l;

	for(i=0;i<n;i++){
		for(j=i+1,k=0;j<n;j++){
			lines[k]=line(p[i],p[j]);
			k++;
		}
		if(k<2) continue;
		sort(lines,lines+k,comp1);
		l=0;
		for(j=1;j<k;j++){
			if(lines[j].x==lines[j-1].x && lines[j].y==lines[j-1].y){
				return 1;
			}
		}
	}

	return 0;

}
