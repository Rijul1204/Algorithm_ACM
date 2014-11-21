#include<stdio.h>
#include<string.h>

#define maxm 100010

char s[maxm];
int mem[maxm],mem1[maxm];

void cal(int i,int j,int fl);
int chck(int i,int j);
int chck1(int i,int j);

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%s",s);
		l=strlen(s);

		memset(mem,-1,sizeof(mem));
		memset(mem1,-1,sizeof(mem1));

		if((chck(0,l-1)==0)&&(chck1(0,l-1)==0)){
			printf("Case %d: 1",t++); 
			for(i=0;i<l-1;i++) printf("0");
			printf("1\n"); continue;
		}		

		cal(0,l-1,1);
		printf("Case %d: %s\n",t++,s);

	}

	return 0;
}


void cal(int i,int j,int fl){

	if(i>j) return ;
	if(fl==2){
		s[i]=s[j]='0';
		cal(i+1,j-1,2); 
		return ;
	}

	if(i==j){
		if(fl){
			s[i]=s[i]+1;
			return ;
		}
		return ;
	}

	if(s[i]>s[j]){
		s[j]=s[i];
		cal(i+1,j-1,0);
	}
	else if(s[j]>s[i]){
		if((chck(i+1,j-1)==1)||(chck1(i+1,j-1)==1)){
			s[j]=s[i];
			cal(i+1,j-1,1);
		}
		else{
			s[j]=s[i]=s[i]+1;
			cal(i+1,j-1,2);
		}
	}
	else{
		if(fl==0){
			cal(i+1,j-1,0);
			return ;
		}
		else if((chck(i+1,j-1)==1)||(chck1(i+1,j-1)==1)){			
			cal(i+1,j-1,1);
		}
		else{
			s[i]=s[j]=s[j]+1;
			cal(i+1,j-1,2);
		}
	}

}


int chck1(int i,int j){

	if(i>j) return 0;
	if(i==j&&s[i]=='9') return 0;
	if(i==j) return 1;

	if(mem1[i]!=-1) return mem1[i];
	
	if(s[i]<'9') return mem1[i]=1;
	if(chck1(i+1,j-1)==1){
		return mem1[j]=1;
	}
	return mem1[j]=0;

}

int chck(int i,int j){

	if(i>j) return 0;
	if(i==j&&s[i]=='9') return 0;
	if(i==j) return 1;

	if(mem[j]!=-1) return mem[j];
	
	if(s[i]>s[j]){
		return mem[j]=1;
	}
	if(s[i]==s[j]&&s[i]!='9') return mem[j]=1;

	if(chck(i+1,j-1)==1){
		return mem[j]=1;
	}
	return mem[j]=0;

}