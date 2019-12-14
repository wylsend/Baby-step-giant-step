#include <iostream>
#include <cmath>
using namespace std;

int ipow(int a, int i)
{
    int r = 1;
    for (int l = 0; l < i; l++)
    {
        r *= a;
    }
    return r;
}

int modexp(int x, int y, int N)
{
  if (y == 0) return 1;
  int z = modexp(x, y / 2, N);
  if (y % 2 == 0)
    return (z*z) % N;
  else
    return (x*z*z) % N;
}

int gen1(int *A,int m, int b,int a,int p){
	for(int i=0;i<m;i++){
	A[i]=((modexp(a,i,p))*b)%p;
	cout<<A[i]<<" ";
	}
}
int gen2(int *B,int k,int b,int a,int m,int p){
	for(int i=1;i<=k;i++){
		B[i-1]= (modexp(a,i*m,p));
		cout<<B[i-1]<<" ";
	}
	
}

void sravn(int *A,int *B,int k, int m, int p){
	for(int i=0;i<k;i++){
		for(int j=0;j<m;j++){
			if (A[i]==B[j]){
				int x;
				j++;
				cout<<"Ёлементы "<<i+1<<" и "<<j<<" совпадают"<<endl;
				x = (j*m - i)%p ;
				cout<<"x= "<<x<<endl;
			//	exit(0);
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
	int a,b,p,k,m;
	cout<<"a= ";cin>>a;
    cout<<"b= ";cin>>b;
    cout<<"p= ";cin>>p; 
    ///////////////////
    int P=sqrt(p);
	m=P+1;
	cout<<"m= "<<m<<endl;
	k=P+1;
	cout<<"k= "<<k<<endl;
	//////////////////////
    int *A = new int[m];
	int *B = new int[k];
	cout<<"р€д первый "<<endl;
    gen1(A,m,b,a,p);
    cout<<endl<<"р€д второй " << endl;
    gen2(B,k,b,a,m,p);
    cout<<" "<<endl;
    cout<<"”равнение вида: "<<endl;
    cout<<a<<"^x = "<<b<<"(mod "<<p<<")"<<endl;
    sravn(A,B,k,m, p);
}
