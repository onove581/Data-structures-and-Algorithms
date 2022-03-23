#include<iostream>
using namespace std;

struct TNode{
	int data;
	TNode *left;
	TNode *right;
};

typedef TNode *Tree;

void Init(Tree &t){
	t = NULL;
}

TNode *creatNode(int x){
	TNode *t=  new TNode;
	if(t == NULL ) exit(1);
	t->data = x;
	t->left = NULL;
	t->right = NULL;
	return t;
}

int insert(Tree &t, Tree p ){
	if( t != NULL ){
		if( t->data == p->data ) return -1;
		else{
			if( p->data < t->data) return insert( t->left, p );
			else return insert( t->right, p );
		}		
	}
	t = new TNode;
	if( t == NULL ) return 0;
	t = p;
	return 1;
}

TNode *searchDQ(Tree t, int x ){ // tim kiem dung de quy
	if( t ){
		if( t->data == x ) return t;
		else{
			if( t->data > x ) return searchDQ( t->left, x );
			else if( t->data < x ) return searchDQ( t->right, x );
		}
	}
	return NULL;
}

void thayThe( Tree p, Tree t ){
	if( t->left != NULL ) thayThe( p, t->left );
	else{
		p->data = t->data;
		p = t;
		t = t->right;
	//	delete t;
	}
}

TNode *getS( TNode *p ){
	TNode *current = p->right;
	TNode *parent = NULL;
	TNode *s = NULL;
	while( current != NULL ){
		parent = s;
		s = current;
		current = current->left;
	}
	if( s!= p->right ){
		parent->left = s->right;
		s->right = p->right;
	}
	return s;
}


void NLR(Tree t){
	if( t != NULL ){
		printf("%d ",t->data);
		NLR(t->left);
		NLR(t->right);
	}
}

void LNR(Tree t ){
	if(t != NULL ){
		LNR(t->left);
		printf("%d ",t->data);
		LNR(t->right);
	}
}

void LRN(Tree t){
	if(t != NULL ){
		LRN(t->left);
		LNR(t->right);
		printf("%d ",t->data);
	}
}

void NRL( Tree t){
	if( t!= NULL ){
		printf("%d ",t->data);				
		NRL(t->right);
		NRL(t->left);
	}
}

void RNL( Tree t){
	if( t != NULL ){
		RNL( t->right );
		printf("%d ",t->data);
		RNL(t->left);
	}
}

void RLN( Tree t ){
	if(t!=NULL){		
		RLN(t->right);
		RLN(t->left);
		printf("%d ",t->data);
	}
}
void countLeafNode(Tree t, int &count ){
	if(t){
		countLeafNode(t->left, count);
		if(t->left == NULL && t->right == NULL ) count++;
		countLeafNode(t->right, count);
	}
}
void delTree(Tree &t, int x){
    if(t==NULL) return;
    if(t->data > x) delTree(t->left,x);
    if(t->data < x) delTree(t->right,x);
    if(t->data == x) { // khi tim ra phan tu do roi
        // xoa Node la hoac Node co 1 phan tu
        TNode *q = t;// xoa phan tu bang con tro
        if(t->left==NULL) { // neu ma ben traiphan tu do bang NULL
            t=t->right; // cho t tro toi t->pRight
        }
        else if(t->right==NULL){
            t=t->left;
        }
        delete q;
    }
}
void menu(){
	Tree t;
	Init(t);
	int n, x;
	int count = 0;
	while(1){
		printf("\nNhap gia tri x cho node, nhap 0 de thoat: ");scanf("%d",&x);
		
		if( x == 0 ) break;
		Tree p = creatNode(x);
		int k = insert( t, p );
		if( k == 0 ) printf("\nkhong du bo nho.");
		else if( k == -1 ) printf("\nTrung voi phan tu da co, nhap lai: ");
	}	
	printf("\nDuyet cay nhi phan NLR: \n"); NLR(t);
	printf("\nDuyet cay nhi phan LNR: \n"); LNR(t);
	printf("\nDuyet cay nhi phan LRN: \n"); LRN(t);
	printf("\nDuyet cay nhi phan NRL: \n"); NRL(t);
	printf("\nDuyet cay nhi phan RNL: \n"); RNL(t);
	printf("\nDuyet cay nhi phan RLN: \n"); RLN(t);
	printf("\nNhap gtr can tim: "); scanf("%d",&x);;
	TNode *p = searchDQ(t,x);
	if( p ) printf("Tim kiem thanh cong");
	else printf("\nKhong tim duoc so can tim.");
	countLeafNode(t,count);
	printf("\ncay nhi phan co %d nut la cay",count);
}

int main(){
	menu();
	return 0;
}
