#include<stdio.h>
#define M 100
#define R 15

int q[M], b[R]={0},prev[R];
int head=0,tail=0;

void enqueue(int l);
int dequeue( );
void BFS (int a[][R],int l,int node);
void path(int s,int p);
int main()
{
	int i,j;
	int a[R][R],edge,x,y,node;
	
	for(i=0;i<R;i++)
	{
		for(j=0;j<R;j++)
		{
			a[i][j]=0;
		}
	}
	printf("How many node and edge?\n");
	scanf("%d%d",&node,&edge);
	
	for(i=1;i<=edge;i++)
	{
		scanf("%d%d",&x,&y);
		a[x][y]=a[y][x]=1;
	
	}
	printf("Enter source and destination.\n");
	scanf("%d%d",&x,&y);
	
	for(i=0;i<M;i++)
	{
		q[i]=0;
	
	}
	
	BFS(a,x,node);
	//printf("\n\n");
	/*for(i=1;i<=node;i++)
	{
		printf("source: %d distance: %d node no: %d\n",x,i,b[i]);
	}*/
	
	path(x,y);
	printf("\n");

return 0;
}



void enqueue(int l)
{
		
	q[tail]=l;
	tail++;
}
int dequeue()
{
	int l;	
	l=q[head];	
	q[head]=0;
	head++;
return l;
}

void BFS(int a[][R],int l,int node)
{
	int v,r,c,f=0,i;
	enqueue(l);
	b[l]=0;
		while(q[head]!=0)
		{
			v=dequeue();
			//printf("r=%d ",v);
			for(r=v,c=1;c<=node;c++)
			{
				if(a[r][c]==1)
				{
					for(i=1;i<=node;i++)
					a[i][c]=2;
		
					
					//printf("c=%d",c);	
					a[c][r]=a[r][c]=2;
					b[c]=b[v]+1;
					prev[c]=v;
					enqueue(c);
					
				}
				
			}
	
		//printf("\n");
		}




}

void path(int s,int p)
{
	if(s==p)
	{
		printf("%d",s);
		return ;
	}
	else 
	{
		path(s,prev[p]);
		printf(" ->%d",p);
	}


}