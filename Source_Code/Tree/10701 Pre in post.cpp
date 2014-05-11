#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;

struct node{
	int no;
	char ch;
	int left;
	int right;
};

node nodes[5000];
map<char,int>let;
void print(int n);

int main(){

	int i,j,k,l,test,n;
	char s1[5000],s2[5000];
	
	//freopen("in.txt","r",stdin);
	scanf("%d",&test);

	while(test--){
		let.clear();
		scanf("%d %s %s",&n,s1,s2);

		for(i=0;i<n;i++){
			nodes[i].no=i;
			nodes[i].left=nodes[i].right=-1;
			let[s2[i]]=i+1;
		}
		nodes[0].ch=s1[0];
	
		for(i=1;i<n;i++){
			nodes[i].ch=s1[i];
			if(let[s1[i]]<let[nodes[i-1].ch]){
				nodes[i-1].left=nodes[i].no;
			}
			else{
				k=-1;
				for(j=0;j<i;j++){
					if(k==-1){
						if(let[s1[j]]<let[s1[i]]) k=j;
						continue;
					}
					if(let[s1[j]]>let[s1[k]]&&let[s1[j]]<let[s1[i]]){
						k=j;
					}
				}
				nodes[k].right=nodes[i].no;
			}			
		}
		for(i=0;i<n;i++){
	//		printf("%d %c %d %d\n",nodes[i].no,nodes[i].ch,nodes[i].left,nodes[i].right);
		}
		print(0);
		printf("\n");


	}

	return 0;
}

void print(int n){
	if(n==-1) return;

	print(nodes[n].left);
	print(nodes[n].right);
	printf("%c",nodes[n].ch);
}