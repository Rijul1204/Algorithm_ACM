#include<stdio.h>
#include<string.h>

typedef struct{
	char irregular[50];
	char plural[50];
}word;

word words[100];

int main(){
	
	int i,j,l,n,flag,len;
	char temp[50],s[50],dum;
    
//	freopen("in.txt","r",stdin);
	
	while(scanf("%d %d",&len,&n)==2){
		scanf("%c",&dum);
		
		for(i=0;i<len;i++){
			scanf("%s %s%c",words[i].irregular,words[i].plural,&dum);
		}

		for(i=1;i<=n;i++){
			gets(s);
			flag=0;
			
			for(j=0;j<len;j++){
				if(strcmp(s,words[j].irregular)==0){
					flag=1;
					puts(words[j].plural);
					break;
				}
			}
			if(flag==1) continue;
			

			l=strlen(s);
			if(s[l-1]=='y'){
				if(s[l-2]!='a'&&s[l-2]!='e'&&s[l-2]!='i'&&s[l-2]!='o'&&s[l-2]!='u'){
					s[l-1]='i';
					strcat(s,"es");
					puts(s);
					flag=1;
				}
			}
			if(flag==1) continue;
			

			if(s[l-1]=='o'||s[l-1]=='s'||s[l-1]=='x'){ 
				strcat(s,"es");
				puts(s);
				flag=1;
				
			}
			if(s[l-1]=='h'){
				if(s[l-2]=='c'||s[l-2]=='s'){
					strcat(s,"es");
					puts(s);
					flag=1;
				}
			}
			
			if(flag==1) continue;
			
			strcat(s,"s");
			
			puts(s);
			
		}
		
	}
	
	return 0;
	
}

















