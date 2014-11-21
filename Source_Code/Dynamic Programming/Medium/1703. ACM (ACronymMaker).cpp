#pragma warning (disable: 4786)
#pragma comment (linker, "/STACK:0x800000")

#include<stdio.h>
#include<string.h>
#include<map>
#include<string>
#include<ctype.h>
using namespace std;

#define maxm 200
#define ii int

map<string,int>word;

ii dp[maxm][maxm][maxm][3];
bool v[maxm][maxm][maxm][3];
char s[maxm],temp[maxm];
int wordind[maxm],wordlen[maxm],tot,len1,len2,n;

char lower(char ch);
char upper(char ch);
ii cal(int ch,int word,int len,int fl);

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	while(scanf("%d",&n)==1){

		if(!n) break; 

		word.clear();
		for(i=1;i<=n;i++){
			scanf("%s",s);
			word[s]=1;
		}
		gets(s);

		int ans=0;
		while(gets(s)){
			if(strcmp(s,"LAST CASE")==0) break;
			for(i=0;s[i];i++){
				if(s[i]==' ') continue;
				s[i]=lower(s[i]);
			}
			tot=0;
			for(i=0;s[i];i++){
				while(!isalpha(s[i])&&s[i]) i++;
				if(!s[i]) break;
				l=0; k=i; //k=ind of word;
				while(isalpha(s[i])){
					temp[l++]=s[i++];
				}
				temp[l]='\0'; i--;
				if(word[temp]&&tot!=0) continue;
				wordind[tot]=k;
				wordlen[tot++]=i+1;
			}
			memset(v,0,sizeof(v));
			len1=wordlen[0]-wordind[0];
			ans=cal(0,1,0,0);
			
			for(i=wordind[0];i<wordlen[0];i++){
				printf("%c",upper(s[i]));
			}
			if(ans==0){
				printf(" is not a valid abbreviation\n");
			}
			else {
				printf(" can be formed in %d ways\n",ans);
				
			}
		}
	}

	return 0;
}

char lower(char ch){

	if(ch>='a'&&ch<='z') return ch;
	return ch-'A'+'a';
}
char upper(char ch){

	if(ch>='A'&&ch<='Z') return ch;
	return ch-'a'+'A';
}


int cal(int ch,int word,int len,int fl){

	if(ch==len1&&((word==tot-1&&fl==1)||word>=tot)) return 1;
	if(ch==len1||word>=tot) return 0;

	if(v[ch][word][len][fl]) return dp[ch][word][len][fl];
	v[ch][word][len][fl]=1;
	
	ii ret=0; int i,j,k,l;

	if(fl) ret+=cal(ch,word+1,0,0);
	
	l=wordlen[word]-wordind[word];
	
	for(i=len;i<l;i++){
		if(s[i+wordind[word]]==s[wordind[0]+ch]){
			ret+=cal(ch+1,word,i+1,1);
		}
	}

	return dp[ch][word][len][fl]=ret;
}