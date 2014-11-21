#include<stdio.h>
#include<string.h>

char s[10000][10000];

int main(){

	int i,j,k,l,n,i1,i2,i3,flag,t=1;
	i=0;

//	freopen("in.txt","r",stdin);

	while(gets(s[i])){
		if(strcmp(s[i],"9")==0){
			n=i;
			for(i=0;i<=n;i++){
				for(j=i+1;j<=n;j++){
					k=strlen(s[i]);
					l=strlen(s[j]);
					flag=0;
					if(k<l){						
						for(i1=0;i1<k;i1++){
							if(s[i][i1]!=s[j][i1]){
							   flag=1;
							   break;
							}
						}

					}
					else {
						for(i1=0;i1<l;i1++){
							if(s[i][i1]!=s[j][i1]){
							   flag=1;
							   break;
							}
						}

					}
					if(!flag) break;
				}
				if(!flag) break;
			}
			if(flag) printf("Set %d is immediately decodable\n",t++);
			else printf("Set %d is not immediately decodable\n",t++);
			i=0;
			continue;
		}
		i++;
	}





	return 0;
}