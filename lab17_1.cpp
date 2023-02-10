#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}

void showData(double *a,int N,int M){
    cout << fixed << setprecision(2);
    for(int i = 0; i < N*M; i++){
        cout << a[i];
        if((i+1)%M == 0) cout << endl;
        else cout << " ";
    }
}

void randData(double *a ,int N ,int M){
    for(int i = 0; i < N*M; i++){
        a[i] = (rand()%101)/100.00;
    }
}

void findRowSum(const double *a ,double *b ,int N ,int M)
{
    double sum=0 , count = 0  ;
    for(int i = 0; i < N*M; i++){
        sum += a[i];
        if((i+1)%M == 0)
        {
         b[int(count)] = sum ;
         sum = 0 ;
         count ++;
        }
}
}

void findColSum(const double *a ,double *b ,int N ,int M)
{
    double sum =0 ;
    int count = 0  ;
    for(int i = 0; i < N*M; i++){
        sum += a[count+ M*(i%N)];
        if((i+1)%N == 0)
        {
         b[count] = sum ;
         sum = 0 ;
         count ++;
        }
}
}
