#include<stdio.h>
#include<string>
using namespace std;

char number[10000];
char output[10000];
string a;
int len;

int main(){

	int i,j,k,l,flag,t=1;
	bool space=false;

//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);

	while(scanf("%s",number)==1){
		
		space=false;
        
		i=0;
		while(number[i]=='0')i++;
		
		for(j=0;number[i];j++,i++){
			output[j]=number[i];
		}
		output[j]='\0';
		strcpy(number,output);
		

		flag=0;

		len=strlen(number);
		j=0;
		for(i=len-1;i>=0;i--){
			if(flag==0){
				output[j++]='a';
				output[j++]=number[i];
				if(i>0)output[j++]=number[--i];
				flag=1;
				continue;
			}
			if(flag==1){
				output[j++]='b';
				output[j++]=number[i];
				flag=3;
				continue;
			}
			if(flag==3){
				output[j++]='c';
				output[j++]=number[i];
				if(i>0)output[j++]=number[--i];
				flag=4;
				continue;
			}
			if(flag==4){
				output[j++]='d';
				output[j++]=number[i];
				if(i>0)output[j++]=number[--i];
				flag=5;
				continue;
			}
			if(flag==5){
				output[j++]='e';
				output[j++]=number[i];
				if(i>0)output[j++]=number[--i];
				flag=1;
				continue;
			}
			
		}
		
		output[j]='\0';

		for(i=0,j=j-1;j>=0;i++,j--){
			number[i]=output[j];
		}
		number[i]='\0';

	//	puts(number);
        
		printf("%4d. ",t++);
		if(!number[0]) printf("0\n");
		for(i=0;number[i];i++){
			if(isdigit(number[i])){
				if(space) printf(" ");
				space=false;
				printf("%c",number[i]);
			}
			else{
				if(number[i]=='a') printf("\n");
				else if(number[i]=='b')printf(" shata");
				else if(number[i]=='c') printf(" hajar");
				else if(number[i]=='d') printf(" lakh");
				else if(number[i]=='e') printf(" kuti");
				space=true;

				while(number[i+1]=='0'||isalpha(number[i+1])){
					i++;
					if(number[i]=='e') {
						space=true;
						printf(" kuti");
					}
					if(!number[i+1]){
						printf("\n");
						break;
					}
				}
			}
		}

				


	}
	
	return 0;
	
}




