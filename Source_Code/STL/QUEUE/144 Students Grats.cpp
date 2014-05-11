#include<stdio.h>
#include<map>
#include<queue>
using namespace std;

map<int,int>student;

int main(){

	int i,j,k,l,n,money,temp,extra;

	//freopen("in.txt","r",stdin);

	
	while(scanf("%d %d",&n,&k)&&n&&k){

		queue<int>q;
		student.clear();
		
		for(i=1;i<=n;i++){
			q.push(i);
		}
		money=1;
		extra=1;
		while(!q.empty()){
			temp=q.front();
			if(student[temp]+extra<=40){
				student[temp]+=extra;
				q.pop();
				if(student[temp]!=40) q.push(temp);
				else if(student[temp]==40) printf("%3d",temp);
			}
			else if(student[temp]+extra>40){
				extra=student[temp]+extra-40;
				q.pop();
				printf("%3d",temp);
				continue;
			}
			money++;
			if(money>k) money=1;
			extra=money;
		}
		printf("\n");

	}

	return 0;

}
		
			

		



		

	

