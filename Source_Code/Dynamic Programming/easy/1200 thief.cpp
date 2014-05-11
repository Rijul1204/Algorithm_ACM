#include<stdio.h>
#include<string.h>
#include<conio.h>

#define maxm 1000

char s[maxm];

int main(){
    
    int i,j,k,l,test,t=1,mod,num;
    
    freopen("in.txt","r",stdin);
    
    scanf("%d",&test);
    
    while(test--){
          
          scanf("%s %d",s,&num);
          if(s[0]=='-') i=1;
          else i=0;
          mod=0;
          if(num<0) num*=-1;
          int n=0;
          
          for(;s[i];i++){
              n=mod*10+s[i]-'0';
              mod=n%num;
           //   printf("%d %d\n",n,mod);  
          }
                                 
          if(mod) printf("Case %d: not divisible\n",t++);             
          else printf("Case %d: divisible\n",t++);        
    }
    
    getch();
    return 0;
}
