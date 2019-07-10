#include<iostream>
#include<omp.h>
#include<time.h>
#include<cstdlib>
/* Title:-Implement Parallel Reduction using Min, Max, Sum and Average operations.*/
using namespace std;
class openmp{
	public:
	int max(int a,int b);
	int min(int a,int b);
	int avg(int a,int b);
};
int openmp :: max(int a,int b){
	if(a<b){
		return b;
	}
	else{
		return a;
	}
	
}
int openmp :: min(int a,int b){
	if(a>b){
		return b;
	}
	else{
		return a;
	}
}
int openmp :: avg(int a,int b){
	int sum=a+b;
	return (sum/2);

}
int main(){
	openmp op;
	int mx,mn,av;
	int num1,num2;
	cout<<"\nEnter two numbers:- ";
	cin>>num1>>num2;
	mx=op.max(num1,num2);
	mn=op.min(num1,num2);
	av=op.avg(num1,num2);
	clock_t start, finish;
	///double start_parallel = omp_get_wtime( );
	start=clock();
	cout<<"\n----------------------------------------------------------------";
	#pragma omp parallel 
	{
		cout<<"\nMAX number==> "<<mx;
		cout<<"\nMIN numbers==> "<<mn;
		cout<<"\nAVG of two numbers==> "<<av;
	}
	//double finish_parallel = omp_get_wtime( );
	finish=clock();
	//cout << "\ntotal time taken " << finish - start << " sec\n";
	double processing_time = (double(finish-start)/CLOCKS_PER_SEC);
	cout<<"\nTotal processing time==> "<<processing_time<<" sec\n";
	cout<<"\n----------------------------------------------------------------";
	//double start_parallel1 = omp_get_wtime( );
	start=clock();
	#pragma omp parallel 
	{
		cout<<"\nMAX number==> "<<mx;
	}
	#pragma omp parallel 
	{
		cout<<"\nmin number==> "<<mn;	
	}
	#pragma omp parallel 
	{
		cout<<"\nAVG of two number==> "<<av;
	}
	finish=clock();
	double processing_time1 = (double(finish-start)/CLOCKS_PER_SEC);
	cout<<"\nTotal processing time==> "<<processing_time1<<" sec\n";
	//double finish_parallel1 = omp_get_wtime( );
	//cout << "\ntotal time taken " << finish_parallel1 - start_parallel1 << " sec\n";
	cout<<"\n";
	return 0;
}


