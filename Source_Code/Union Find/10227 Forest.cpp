#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<algorithm>

struct node{
	int no;
	char s[1000];
};

node nodes[1000];
int pre[1000];

int find(int x){
	if(pre[x]==x) return x;
	return pre[x]=find(pre[x]);
}

int main(){
	
	int i,j,k,l,test,cas=1,t,p,t1,p1,bl=0;
	char s[1000],temp[1000];
	//freopen("in.txt","r",stdin);

	scanf("%d",&test);
	

	while(test--){

		scanf("%d %d",&p,&t);
		gets(temp);
		for(i=1;i<=p;i++){
			nodes[i].no=i;
			pre[i]=i;
			for(j=0;j<=t;j++){
				nodes[i].s[j]='0';
			}
			nodes[i].s[j]='\0';
		}

		while(gets(s)){
			if(!s[0]) break;
			p1=t1=-1;
			for(i=0;s[i];i++){
				if(isdigit(s[i])){
					k=0;
					while(isdigit(s[i])){
						temp[k++]=s[i++];
					}
					temp[k]='\0';
					if(p1==-1) p1=atoi(temp);
					else t1=atoi(temp);
				}
			}
			nodes[p1].s[t1]='1';
		}
		
		for(i=1;i<=p;i++){
		//	puts(nodes[i].s);
			for(j=i+1;j<=p;j++){
				if(strcmp(nodes[i].s,nodes[j].s)==0){
					k=find(i); l=find(j);
					if(k!=l) pre[k]=l;
				}
			}
		}
		
		j=0;
		for(i=1;i<=p;i++){
			if(pre[i]==i) j++;
		}
        
		if(bl) printf("\n");
		bl=1;
		printf("%d\n",j);
		
		

	}


	return 0;
}

