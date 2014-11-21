#include<stdio.h>
#include<string.h>
#include<math.h>


int gcd(int a,int b);

int main(){

	int i,j,l,test,num1,num2,g,t=1;
	char s1[100],s2[100],dum;

	scanf("%d%c",&test,&dum);

	while(test--){

		gets(s1);
		gets(s2);

		if(strcmp(s1,s2)==0) {
			printf("Pair #%d: All you need is love!\n",t++);
			continue;
		}
		
		num1=0;
		num2=0;
		l=strlen(s1);
		for(i=0;s1[i];i++,l--){
			if(s1[i]=='1') num1+=pow(2,l-1);
		}

		num2=0;
		l=strlen(s2);
		for(i=0;s2[i];i++,l--){
			if(s2[i]=='1') num2+=pow(2,l-1);
		}

		//printf("%d %d\n",num1,num2);

		g=gcd(num1,num2);

		if(g==1) printf("Pair #%d: Love is not all you need!\n",t++);
		else printf("Pair #%d: All you need is love!\n",t++);

		//printf("%d\n",g);

		

	}

	return 0;

}

int gcd(int a,int b){

	if(a%b==0) return b;

	return gcd(b,a%b);

}




