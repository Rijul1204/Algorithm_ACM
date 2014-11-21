#include<stdio.h>

int main(){

	int i,j,k,l,flag,day;

	//freopen("in.txt","r",stdin);

	double h,u,d,f,st,fat;

	while(1){
		scanf("%lf %lf %lf %lf",&h,&u,&d,&f);
		
		if(h<0) h*=-1;
		if(h<.000000001) break;

		st=0;
		day=1;
		fat=(f*u)/100.0;

		while(1){
					
			if(u>0) st+=u;
			if(st>h){
				flag=0;
				break;
			}
			st-=d;
			if(st<0){
				flag=1;
				break;
			}
			u-=fat;
			day++;

		}

		if(!flag) printf("success on day %d\n",day);
		else printf("failure on day %d\n",day);


	}


	return 0;

}