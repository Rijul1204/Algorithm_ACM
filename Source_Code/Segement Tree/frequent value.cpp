#include<stdio.h>
//#include<conio.h>

#define maxm 100000

struct node{
       int pre;
       int max;
       int maxv;
       int suff;
       int prev; int suffv;
};

node  m[4*maxm+1000];
int a[maxm+100];
int maxi(int a,int b){
    if(a>b) return a;
    return b;
}

void init(int node,int b,int e);
node query(int node,int b,int e,int i,int j);

int main(){
    
    int i,j,k,l,n,q;
    //freopen("in.txt","r",stdin);   
    
    while(scanf("%d",&n)==1){
         if(!n) break;
         scanf("%d",&q);
         for(i=0;i<n;i++) scanf("%d",&a[i]);                            
         init(1,0,n-1);
    //   printf("%d\n",m[1].max);            
         for(i=1;i<=q;i++){
             scanf("%d %d",&k,&l);
             k--; l--;
             printf("%d\n",query(1,0,n-1,k,l).max);
         }
                             
    }   
    
   // getch();
    return 0;
}

node query(int nod,int b,int e,int i,int j){
     
     node ret;
     if(b==e){
        return m[nod];
     }
     if(b==i&&e==j){
          return m[nod];     
     }
     
     int left,right,mid;
     left=nod<<1; right=left+1; mid=b+e; mid/=2;
     
     if(j<=mid) return query(left,b,mid,i,j);
     if(i>mid) return query(right,mid+1,e,i,j);
     
     node t1,t2;
     
     t1=query(left,b,mid,i,mid);
     t2=query(right,mid+1,e,mid+1,j);
     
     ret.max=maxi(t1.max,t2.max);
     ret.prev=t1.prev; ret.suffv=t2.suffv;
     if(t1.suffv==t2.prev){
         ret.max=maxi(ret.max,t1.suff+t2.pre);
         if(t1.pre==(mid-b+1)){
            ret.pre=t1.pre+t2.pre;                    
         }
         else ret.pre=t1.pre;
         if(t2.suff==(e-mid)){
             ret.suff=t2.suff+t1.suff;                     
         }
         else ret.suff=t2.suff;                               
     }
     else {
          ret.pre=t1.pre;
          ret.suff=t2.suff;
     }
          
     return ret;
}

void init(int node,int b,int e){
     
     if(b==e){
         m[node].max=1; m[node].prev=m[node].suffv=m[node].maxv=a[b]; m[node].pre=1; m[node].suff=1;
         return ; 
     }
     
     int left,right,mid;
     left=node<<1; right=left+1;
      mid=b+e; mid/=2;
     
     init(left,b,mid); init(right,mid+1,e);
     
     m[node].max=maxi(m[left].max,m[right].max);
     m[node].prev=m[left].prev; m[node].suffv=m[right].suffv;
     if(m[left].suffv==m[right].prev){
         m[node].max=maxi(m[node].max,m[left].suff+m[right].pre);
         if(m[left].pre==(mid-b+1)){
             m[node].pre=m[left].pre+m[right].pre;                    
         }
         else m[node].pre=m[left].pre;
         if(m[right].suff==(e-mid)){
             m[node].suff=m[right].suff+m[left].suff;                     
         }
         else m[node].suff=m[right].suff;                               
     }
     else {
          m[node].pre=m[left].pre;
          m[node].suff=m[right].suff;
     }    
         
     
}
