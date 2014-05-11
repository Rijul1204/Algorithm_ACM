#include<stdio.h>
#include<string.h>
#include<math.h>

#define ii unsigned long long int

ii n;
ii f_sum (ii a , ii b);

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%lld",&n);
        double nd=n,sqd;
        sqd=sqrt(nd);
        int sq=sqd;
        ii ans=0,prev=n,now,v,v1;

        for(i=2;i<=sq;i++){
            now=n/i;
			ans+=((now-1)*i);
            v=f_sum(now+1,prev);
			ans+=(v*(i-2));
            prev=now;
        }
		if(prev>sq){
			now=n/i;
			v=f_sum(now+1,prev);
            //ans+=((now-1)*i);
            ans+=(v*(i-2));
		}


        printf("Case %d: %lld\n",t++,ans);

    }

    return 0;
}

ii f_sum (ii a , ii b)
{
    ii n = (b-a)+1;
	ii ret=(b+a)*n; ret/=2;
    return ret;
}
