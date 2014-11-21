#include<stdio.h>
#include<queue>
using namespace std;

struct node{
	int row;
	int col;
	int color;
	int value;
}a[8][8],temp;

queue<node>q;

void reset(void);
void set(void);


int main(){

	int i,j,k,l;
	char s1[5],s2[5];
	while(scanf("%s %s",s1,s2)==2){
	    	
        reset();

		int sourcerow=s1[1]-'1';
		int sourcecol=s1[0]-'a';
		
		int destinationrow=s2[1]-'1';
		int destinationcol=s2[0]-'a';

		a[sourcerow][sourcecol].value=0;

		q.push(a[sourcerow][sourcecol]);

		while(!q.empty()){
			temp=q.front();
			q.pop();
			if(a[temp.row][temp.col].color!=2){
				a[temp.row][temp.col].color=2;
				set();
			}
		}
		printf("To get from %s to %s takes %d knight moves.\n",s1,s2
			,a[destinationrow][destinationcol].value);

	}

		return 0;

}

void reset(void){
	int i,j,k,l;

	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			a[i][j].row=i;
			a[i][j].col=j;
			a[i][j].color=0;
			a[i][j].value=99;
		}
	}
}

void set(void){

	int r,c;

	// row -2 / col+1  

	r=temp.row-2;
	c=temp.col+1;
	
	if(r>=0&&c<8&&a[r][c].color==0){
		a[r][c].color=1;
		a[r][c].value=a[temp.row][temp.col].value+1;
		q.push(a[r][c]);
	}

	/* row - 1 / col + 2 */
	r = temp.row - 1;
	c = temp.col + 2;

	if ( r> -1 && c < 8 && a [r] [c].color == 0 ) {
		a [r] [c].value = a [temp.row] [temp.col].value + 1;
		a [r] [c].color = 1;
		q.push (a [r] [c]);
	}

	/* row + 1 / col + 2 */
	r = temp.row + 1;
	c = temp.col + 2;

	if ( r < 8 && c < 8 && a [r] [c].color == 0 ) {
		a [r] [c].value = a [temp.row] [temp.col].value + 1;
		a [r] [c].color = 1;
		q.push (a [r] [c]);
	}

	/* row + 2 / col + 1 */
	r = temp.row + 2;
	c = temp.col + 1;

	if ( r < 8 && c < 8 && a [r] [c].color == 0 ) {
		a [r] [c].value = a [temp.row] [temp.col].value + 1;
		a [r] [c].color = 1;
		q.push (a [r] [c]);
	}

	/* row + 2 / col - 1 */
	r = temp.row + 2;
	c = temp.col - 1;

	if ( r < 8 && c > -1 && a [r] [c].color == 0 ) {
		a [r] [c].value = a [temp.row] [temp.col].value + 1;
		a [r] [c].color = 1;
		q.push (a [r] [c]);
	}

	/* row + 1 / col - 2 */
	r = temp.row + 1;
	c = temp.col - 2;

	if ( r < 8 && c > -1 && a [r] [c].color == 0 ) {
		a [r] [c].value = a [temp.row] [temp.col].value + 1;
		a [r] [c].color = 1;
		q.push (a [r] [c]);
	}

	/* row - 1 / col - 2 */
	r = temp.row - 1;
	c = temp.col - 2;

	if ( r > -1 && c > -1 && a [r] [c].color == 0 ) {
		a [r] [c].value = a [temp.row] [temp.col].value + 1;
		a [r] [c].color = 1;
		q.push (a [r] [c]);
	}

	/* row - 2 / col - 1 */
	r = temp.row - 2;
	c = temp.col - 1;

	if ( r > -1 && c > -1 && a [r] [c].color == 0 ) {
		a [r] [c].value = a [temp.row] [temp.col].value + 1;
		a [r] [c].color = 1;
		q.push (a [r] [c]);
	}

}



	





	


