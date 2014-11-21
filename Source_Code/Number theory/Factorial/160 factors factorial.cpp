#include<stdio.h>
int ans[100];
int main()
{
	int a[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	int n,i,j;
	freopen("in.txt","r",stdin);
//	freopen("go.txt","w",stdout);
	while(scanf("%d",&n)==1&&n!=0){
		printf("%3d! =",n);
		for(i=2;i<=n;i++){
			int temp=i;
			for(j=0;j<25;j++){
				while(temp%a[j]==0){
					++ans[a[j]];
					temp/=a[j];
				}
			}
		}
		int up=0;

		for(i=0;i<25;i++){
			if(ans[a[i]]!=0){
				if(up==15)printf("\n      ");
				printf("%3d",ans[a[i]]);
				up++;
			}
		}
		for(i=0;i<25;i++)ans[a[i]]=0;
		printf("\n");
	}
	return 0;
}
