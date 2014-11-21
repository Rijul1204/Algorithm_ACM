#include<stdio.h>
#include<algorithm>
using namespace std;

typedef struct{
	int num;
	int count;
}letter;

letter letters[100];

void set();
bool compare(letter a,letter b);

int main(){

	int i,test,n;

	char s[1000],dum;

	scanf("%d%c",&test,&dum);

	while(test--){

		set();
		gets(s);

		for(i=0;s[i];i++){
			if((s[i]>=65)&&(s[i]<91)||(s[i]>=97)&&(s[i]<=122)){
				if(s[i]>=65&&s[i]<=90) n=s[i]+32;
				else n=s[i];
				letters[n-97].count++;
								
			}
		}

		sort(letters,letters+26,compare);
        	printf("%c",letters[0].num+97); 
		for(i=1;i<=26;i++){
			if(letters[i].count==letters[i-1].count){
				printf("%c",letters[i].num+97);
			}
			else break;
		}
		printf("\n");

		

	}

	return 0;
}

void set(){

	int i;

	for(i=0;i<=50;i++){

		letters[i].num=i;
		letters[i].count=0;
	}
}

bool compare(letter a,letter b){

	if(a.count==b.count){
		if(a.num<b.num )return 1;
		else return 0;
	}
	else if(a.count<b.count) return 0;
	else return 1;
}






