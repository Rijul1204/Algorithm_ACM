#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define maxm 110

int n;

//Gaussian  Elimination...............................................

#define eps (1e-9)
#define iseq(a,b) (fabs(a-b)<eps)

//  a1x1+a2x2+.....=b1 .....
double a[maxm][maxm],b[maxm],x[maxm];

void gauss(int r,int c){

    int i,j,k,l;
    double val;

    i=j=0;

    while(i<r&&j<c){

        for(k=i;k<r;k++){
            if(iseq(a[k][j],0.0)) continue;
            for(l=j;l<c;l++){
                swap(a[i][l],a[k][l]);
            }
            swap(b[i],b[k]);
            break;
        }
        if(k==r){
            j++; continue;
        }
        // Making jth col of every row  from (i+1)th to rth row  into  zero........
        for(k=i+1;k<r;k++){
            val=a[k][j]/a[i][j];
            for(l=j;l<c;l++){
                a[k][l]-=(a[i][l]*val);
            }
            b[k]-=(b[i]*val);

        }

        i++; j++;
    }

    ///  Additional  information.............

	/*
	rep(k,i,r)
	{
	rep(j,0,c)        if(!(fabs(a[k][j])<eps))   goto stop ;

	  if(!(fabs(b[k])<eps))               return -1 ;       // no solution

		stop : ;
		}

		  if(i>c)           return -1 ; // no solution
		  if(i==c)         return 0 ; // unique solution
		  if(i<c)           return 1 ; // multiple solution
	*/

    /// ................

	for(i=c-1;i>=0;i--){
	    x[i]=b[i];
	    for(k=i+1;k<c;k++){
	        x[i]-=(a[i][k]*x[k]);
	    }
	    if(!iseq(a[i][i],0.0)) x[i]/=a[i][i];
	}

}

///   Gaussian  Elimination   Finish.....................


int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%d",&n);

        memset(a,0.0,sizeof(a));

        for(i=0;i<n;i++){
            a[i][i]=1.0;

            if(i==n-1){  b[i]=0;  continue; }
            else b[i]=1;

            // prob= probabilty.........
            double prob=(double) 1.0/ (double) 6.0;
            prob*=(double) .5;

            for(j=1;j<=6;j++){
                k=i-j;
                if(k<0){ k=i; a[i][k]-=prob;}
                else a[i][k]+=(prob);
            }
            for(j=1;j<=6;j++){
                k=i+j;
                if(k>=n){ k=i; a[i][k]-=prob;}
                else a[i][k]+=(prob);
            }

            for(k=0;k<n;k++){
                if(i==k) continue;
                a[i][k]*=(-1.0);
            }

        }

        gauss(n,n);

        printf("Case %d: %.5lf\n",t++,x[0]);

    }

    return 0;
}
