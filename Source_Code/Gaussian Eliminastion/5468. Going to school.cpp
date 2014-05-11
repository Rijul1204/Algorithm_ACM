#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

#define maxm 200
#define eps (1e-9)
#define iseq(a,b) (fabs(a-b)<eps)

int n,st,en;

vector<int>v[maxm],w[maxm];

///Gaussian  Elimination...............................................

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

        scanf("%d %d %d",&n,&st,&en);

        //  initializing..................
        for(i=0;i<=n;i++){
            v[i].clear(); w[i].clear();
        }

        // 0 based  Indexing........
        st--; en--;
        for(i=1;i<n;i++){
            scanf("%d %d %d",&k,&l,&j);
            k--; l--;
            v[k].push_back(l); w[k].push_back(j);
            v[l].push_back(k); w[l].push_back(j);
        }

        //  Build  co-efficient  Matrix..................

        memset(a,0,sizeof(a));
        for(i=0;i<n;i++){

            a[i][i]=1;
            if(i==en){
                b[i]=0; continue;
            }

            b[i]=1;
            double tot=0,val;
            for(j=0;j<v[i].size();j++) tot+=w[i][j];
            for(j=0;j<v[i].size();j++){
                k=v[i][j]; val=(double) w[i][j]/(double) tot; val*=-1.;
                a[i][k]=val;
            }
        }

        //  Calling  Gaussian  Elimination......................
        gauss(n,n);
        printf("%.5lf\n",x[st]);
    }



    return 0;
}
