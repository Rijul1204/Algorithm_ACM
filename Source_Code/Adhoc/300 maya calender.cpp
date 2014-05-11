#include<stdio.h>
#include<string>
#include<string.h>
#include<map>
using namespace std;

map<string,int>months;


int main(){

	int i,j,k,l,test;
	int day,year,dayans,yearans,total;
	char s[1000];
	char m[][40]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

//	freopen("in.txt","r",stdin);

	months["pop"]=1;
	months["no"]=2; months["zip"]=3;months["zotz"]=4;months["tzec"]=5;
	months["xul"]=6;months["yoxkin"]=7;months["mol"]=8;months["chen"]=9;
	months["yax"]=10;months["zac"]=11;months["ceh"]=12; months["mac"]=13;
	months["kankin"]=14;months["muan"]=15;months["pax"]=16;months["koyab"]=17;
	months["cumhu"]=18;
	months["uayet"]=19;
	scanf("%d",&test);
	printf("%d\n",test);

	while(test--){

		scanf("%d.%s%d",&day,s,&year);

		total=year*365;
		total+=(months[s]-1)*20;
		total+=day;
		//printf("total->%d  ",total);

		yearans=total/260;
		total=total%260;
		printf("%d ",total%13+1);
		int temp;
		temp=total%20;
		printf("%s ",m[temp]);
		printf("%d\n",yearans);


	}


	return 0;
}