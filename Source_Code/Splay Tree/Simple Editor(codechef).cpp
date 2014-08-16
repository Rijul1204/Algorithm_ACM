/*
Author : Rahsedul Hasan Rijul
Created on  : 2014-07-27
// SPOJ: ORDERSET (Moshiur Vai)
// using Treap s
*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

#define FOR(i,n) for(int i=0;i<(n);++i)
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define CLR(a,x) memset(a,(x),sizeof(a))

#define INF (1<<30)
#define maxm 300100

typedef int LL;
typedef pair<int,int> pii;

struct Node {
    int cnt;
    int priority;
    char ch;

    Node *left, *right;

    Node(){cnt = 0; priority = 0; left = right = NULL;}
    Node(char _ch){cnt = 1; ch= _ch; priority = rand(); left = right = NULL;}
    Node(int pr,char _ch){ ch=_ch,cnt = 1; priority = pr; left = right = NULL;}
};

char t[5],s[maxm];
int ith,len,LEN;


struct Treap {
    Node* root;

    Treap(){root = NULL; srand(time(NULL));}

    int TreeSize(Node* T)
    {
        return T==NULL?0:T->cnt;
    }

    void UpdateCnt(Node* &T)
    {
        if(T)
        {
            T->cnt = 1 + TreeSize(T->left) + TreeSize(T->right);
        }
    }

    void LeftRotate(Node* &T)
    {
        Node* temp = T->left;
        T->left = temp->right;
        temp->right = T;
        T = temp;

        UpdateCnt(T->right);
        UpdateCnt(T);
    }

    void RightRotate(Node* &T)
    {
        Node* temp = T->right;
        T->right = temp->left;
        temp->left = T;
        T = temp;

        UpdateCnt(T->left);
        UpdateCnt(T);
    }

    void Insert(Node* &T,char ch,Node* req)
    {
        if(T == NULL)
        {
            T = new Node(ch);
            return;
        }

		if(T->left==NULL){

            return;
		}

        Insert(T->left,ch,req);

        if(T->priority < T->left->priority)
            LeftRotate(T);

        UpdateCnt(T);
    }

    /*int Count(Node* T, int bound)
    {
        if(T == NULL)
            return 0;

        if(T->key < bound)
            return 1 + TreeSize(T->left) + Count(T->right, bound);

        return Count(T->left, bound);
    }

    int Count(int bound)
    {
        return Count(root,bound);
    }*/

	void insert_kth(Node* &T, int k,char ch)
    {

		if(T == NULL)
        {
            T = new Node(ch);
            return;
        }

		int sz = 1 + TreeSize(T->left);

		if(sz==k){

			Node* tmp=new Node(ch);
			tmp->right=T->right;
			UpdateCnt(tmp);

			T->right=tmp;
			UpdateCnt(T);

			if(T->priority < T->right->priority)
            RightRotate(T);
		}

		else if(sz < k){
			insert_kth(T->right, k-sz,ch);
			if(T->priority < T->right->priority)
            RightRotate(T);
		}

        else{
            insert_kth(T->left,k,ch);
			if(T->priority < T->left->priority)
            LeftRotate(T);
        }

        UpdateCnt(T);

    }


	Node* FindKth(Node* T, int k)
    {
        if(TreeSize(T) < k)
            return root;

        int sz = 1 + TreeSize(T->left);

        if(sz == k){
            return T;
		}


        if(sz < k)
            return FindKth(T->right, k-sz);

        return FindKth(T->left,k);
    }

	Node* FindKth(int k)
    {
        return FindKth(root, k);
    }

	void insert(int k,char ch){
		insert_kth(root,k,ch);
	}


	void print(Node* T, int k,int len)
    {
		if(T==NULL) return;
        if(LEN<=0) return ;

        int sz = 1 + TreeSize(T->left);

        if(sz == k){
            printf("%c",T->ch);
            LEN--;
            print(T->right,1,len-1);
		}
        else if(sz < k){
            print(T->right, k-sz,len);
        }
        else{
            print(T->left,k,len);
			if(LEN>0){
				printf("%c",T->ch);
				LEN--;
			}
            print(T->right,1,len-sz);
        }
    }

	void print(int k,int len){
		print(root,k,len);
	}
};
Treap oTreap;


int main()
{

	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

    int i,j,k,l,test;
    int Q,len;

    scanf("%d",&Q);

    while(Q--)
    {
        scanf("%s %d",t,&ith);

        if(t[0]=='+')
        {
            scanf("%s",s);
			l=strlen(s);
            for(i=l-1;i>=0;i--){
                oTreap.insert(ith,s[i]);
            }
        }

        else if(t[0]=='?')
        {
            scanf("%d",&len);
            LEN=len;
            oTreap.print(ith,len);

            puts("");
        }

    }

	scanf("%d",&i);

    return 0;
}
