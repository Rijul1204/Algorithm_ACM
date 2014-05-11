#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<map>
#include<string>
using namespace std;

typedef struct{
	string st;
}str;

str ss1[1100],ss2[1100];


map<string,int>mymap;
string a;

int dp[1100][1100],count1,count2;

int lcs();

int main(){

	int i,test=1;

	char s1[1150],s2[1150],temp[1150];
	//freopen("in.txt","r",stdin);

	while(gets(s1)){



		gets(s2);
		mymap.clear();

		if(!s2[0]||!s1[0]){ printf("%2d. Blank!\n",test++); continue; }
          	count1=0;
		for(i=0;s1[i];i++){
		
		
			a.erase(a.begin(),a.end());
			if(isalpha(s1[i])||isdigit(s1[i])){
				while(isalpha(s1[i])||isdigit(s1[i])){
					temp[0]=s1[i];
					temp[1]='\0';
					a.append(temp);
					i++;
				}
				ss1[count1++].st=a;
				i--;
			}
		//	cout<<a<<endl;
			
		}

			count2=0;

		for(i=0;s2[i];i++){
		     
		
			a.erase(a.begin(),a.end());
			if(isalpha(s2[i])||isdigit(s2[i])){
				while(isalpha(s2[i])||isdigit(s2[i])){
					temp[0]=s2[i];
					temp[1]='\0';
					a.append(temp);
					i++;
				}
				ss2[count2++].st=a;
				i--;			
			}
			
		}

		printf("%2d. Length of longest match: %d\n",test++,lcs());
			
	}

	return 0;

}

int lcs(){

	int i,j;

	for(i=1;i<=count1;i++) dp[i][0]=0;
	for(j=1;j<=count2;j++) dp[0][j]=0;

	for(i=1;i<=count1;i++){
		for(j=1;j<=count2;j++){
			if(ss1[i-1].st==ss2[j-1].st){
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else if(dp[i-1][j]>=dp[i][j-1]) dp[i][j]=dp[i-1][j];
			else dp[i][j]=dp[i][j-1];
		}

	}

	return dp[count1][count2];

}



		








