#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

#define maxm 2050

// Fast....... reader.............

const int BUFFSIZE = 10240;
char BUFF[BUFFSIZE + 1], *ppp = BUFF;
int RR, CHAR, SIGN, BYTES = 0;
#define GETCHAR(c) { \
        if(ppp-BUFF==BYTES && (BYTES==0 || BYTES==BUFFSIZE)) { BYTES = fread(BUFF,1,BUFFSIZE,stdin); ppp=BUFF; } \
        if(ppp-BUFF==BYTES && (BYTES>0 && BYTES<BUFFSIZE)) { BUFF[0] = 0; ppp=BUFF; } \
        c = *ppp++; \
}

#define DIGIT(c) (((c) >= '0') && ((c) <= '9'))
#define MINUS(c) ((c)== '-')
#define GETNUMBER(n) { \
        n = 0; SIGN = 1; do { GETCHAR(CHAR); } while(!(DIGIT(CHAR) || MINUS(CHAR))); \
        if(MINUS(CHAR)) { SIGN = -1; GETCHAR(CHAR); } \
        while(DIGIT(CHAR)) { n = 10*n + CHAR-'0'; GETCHAR(CHAR); } if(SIGN == -1) { n = -n; } \
}
//////////////*******************************/////////////

double dp[maxm][maxm][3],val[maxm][maxm],a[maxm],res[maxm][maxm],val1[maxm];
bool v[maxm][maxm][3];
int n,p,tot;

void init();
double cal(int n,int p,int fl);

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    init();

    GETNUMBER(test);
    //scanf("%d",&test);

	while(test--){

	    GETNUMBER(tot);
		//scanf("%d",&tot);

        double ans=0;

		int lim=tot/2;
		if(tot%2) lim++;

		for(i=1,k=tot;i<=lim;i++,k--){
			val1[i]=res[i][tot]+res[k][tot];
			//printf(" for %d res is %.5lf\n",i,val1[i]);
		}

		if(tot%2) k=lim-1;
		else k=lim;

		for(i=lim+1;i<=tot;i++,k--){
			val1[i]=val1[k];

			//printf(" for %d res is %.5lf\n",i,val1[i]);
		}


        for(i=1;i<=tot;i++){
            GETNUMBER(k);
			a[i]=k;
		//	scanf("%lf",&a[i]);
            ans+=(a[i]*val1[i]);
        }
        printf("%.3lf\n",ans);


	}


    return 0;
}
void init(){

    int i,j,k,p,n;
    tot=2000;

    for(j=1;j<=2000;j++){
		p=j;
		double res=0;
		for(i=1;i<=2000;i++){
			if(i%2==0) continue;
		    double ans=0;
			n=i;
			if(i>1) val[j][i]+=val[j][i-2]+cal(n,p,0)*.5;
			else val[j][i]+=cal(n,p,0)*.5;

		}
	}

	for(i=1;i<=2000;i++){
	    for(j=1;j<=2000;j++){
			if(j==1){
	            res[i][j]=val[i][j];
				continue;
	        }
			if(j%2==0){
				res[i][j]=val[i][j-1];
			}
	        else{
	            res[i][j]=val[i][j-2];
	            res[i][j]+=(cal(j-1,i,0)*.5);
	        }
        }
	}

}


double cal(int n,int p,int fl){

    if(p<0||p>tot) return 0;
    if(n==1&&p==1&&!fl) return 1;
    if(n==1&&p==tot&&fl) return 1;
    if(n<=1) return 0;

    if(v[n][p][fl]) return dp[n][p][fl];
    v[n][p][fl]=1;

    if(!fl) dp[n][p][fl]=cal(n-1,p,fl)+cal(n-1,p-1,fl);
    else    dp[n][p][fl]=cal(n-1,p,fl)+cal(n-1,p+1,fl);

    return dp[n][p][fl]*=.5;
}
