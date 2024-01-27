#include<iostream>
#include<stdlib.h>
using namespace std;

struct Matrix{
	int *A;
	int n;
};

    //in order to modify matrix we will take pointer
void Set(struct Matrix *m, int i, int j, int x){
	if(i>=j)
	m->A[m->n*(j-i)-(j-2)*(j-1)/2+i-j]=x;
}

int get(struct Matrix m, int i, int j){
	if(i>=j)
	return m.A[m.n*(j-i)-(j-2)*(j-1)/2+i-j];
	else
	return 0;
}

void Display(struct Matrix m){
	int i,j;
	for(i=1; i<=m.n; i++){
		for(j=1; j<=m.n; j++){
			if(i>=j)
			cout<<" "<<m.A[m.n*(j-i)-(j-2)*(j-1)/2+i-j];
			else
			cout<<" 0";
		}
		cout<<endl;
	}
}

int main()
{
	struct Matrix m;
	int i,j,x;
	
	cout<<"enter dimensions: ";
	cin>>m.n;
	
	m.A=(int *)malloc(m.n*(m.n-1)/2*sizeof(int));
	cout<<"enter all elements: ";
	for (i=1;i<=m.n; i++){
		for(j=1; j<=m.n; j++){
			cin>>x;
			Set(&m,i,j,x);
		}
	}
	
	cout<<endl<<endl;
	Display(m);
}

