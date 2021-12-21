//Parallel Merge Sort 

#include <iostream>
#include<cstring>
#include<stdlib.h>
#include<time.h>
#include "omp.h"
#include<sstream>
#include<fstream>
#define MAX 20
using namespace std;
int get_count(char *inpt  ){
	ifstream in1;
	in1.open(inpt);
	int num;
	string text;
	getline(in1,text);
	istringstream iss(text);
	iss>> num;
	return num;		
}
void read_file(char *inpt , int *buffer , int *n ){
	ifstream in1;
	in1.open(inpt);
	int num;
	string text;
	getline(in1,text);
	while(getline(in1,text)){
		istringstream iss(text);
		iss>> num;
		buffer[*n] = num;
	 	*n = *n + 1;
	}
	cout << "n = " << *n <<endl;
	in1.close();
}
void merge(int a[],int l,int m, int r )
{	
	int left = m-l+1;
	int right = r-m;
	
	int *t1 = new int[m-l+1];
	int *t2 = new int[right];
	for(int i = 0 ; i < left ; i++){
		t1[i] = a[l+i];
		
	}
	
	for(int i = 0 ; i < right ; i++){
		t2[i] = a[m+i+1];
	}
	
	
	int p1=0,p2 = 0;
	int c =l;
	//distribute elements
	
	while(p1 < left && p2 < right){
		if(t1[p1] > t2[p2]){
			a[c] = t1[p1];
			p1++;
		}else{
			a[c]= t2[p2];
			p2++;
		}
		c++;
	}
	while(p1 < left){a[c++] = t1[p1++];}
	
	while(p2 < right){a[c++] = t2[p2++];}
	
	
	
}

void mergeSort(int a[],int l,int r )
{
  
    if (l<r)
    {
        int m=(l+r)/2;
        
        #pragma omp single nowait    
        {
            #pragma omp task shared(a)
            {
                mergeSort(a,l,m);
            }
            #pragma omp task shared(a)
            {
                mergeSort(a,m+1,r);
            }
        }
        #pragma omp taskwait
        merge(a,l,m,r);
    }
}

void print (int a[],int n)
{
    for (int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}





int main(int argc , char *argv[]){
	if(argc < 2){
		cout << "enter filenbame" << endl;
		return 0;
	}
	
	char filename[20] ="";
	strcpy(&filename[0] , argv[1])	;
	


	clock_t t,t1;
    
    int counter= 2000;
    int n = 1500;
    int count = get_count(&filename[0]);
    cout << "count = " << count <<endl;
    int *arr = new int[count +2];
    int k = 0;
    read_file(&filename[0] , arr, &k);
    n = k;
    //for(int i = 0 ; i < n ; i++){arr[i] = counter--; } 
    
    cout<<"/nUnsorted Array: ";
    print(arr,n);
    t = clock();
   

   mergeSort(arr,0,n-1 );
	
   
    	
    t1 = clock()-t;
    double time_taken = (double)t1 ;// in seconds
    
     cout<<"/nSortedArray: ";
    print(arr,n);
    cout <<"\nMerge sort parallel took total " << time_taken << " ms" << endl;
    free(arr);
    return 0;


}
