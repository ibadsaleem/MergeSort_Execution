#include<iostream>
#include<time.h>
#include<sstream>
#include<fstream>
#include<cstring>
using namespace std;

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
}
void merge(int *arr , int i,int mid , int j  , int n){
	int *L = new int[n];
	int *R= new int[n];
	int *f = new int[n];
	int p1 = 0;
	int p2  = 0;
	int lsize = mid-i+1;
	int rsize = j-mid;
	for(int k = 0 ; k < lsize ; k++){
		L[k] = arr[k+i];

		
	}

	for(int k = 0 ; k < rsize ; k++){
		R[k] = arr[k+mid+1];

	}

	int c = i;
	
	while(p1 < lsize && p2 < rsize){
		if(L[p1] > R[p2]){
			arr[c] = L[p1];
			p1++;
		}else{
			arr[c]= R[p2];
			p2++;
		}
		c++;
	}
	while(p1 < lsize  ){
		arr[c++] = L[p1++];
	}
	
	while(p2 < rsize  ){
		arr[c++] = R[p2++];
	}
	
}


void mergesort(int *arr , int i ,  int j , int n){
	if(i < j){
		
		int mid = (i+j)/2;
	
		mergesort(arr , i,mid,n);
		mergesort(arr, mid+1 , j , n);
		
		merge(arr , i , mid,j , n);
		
		
	}
	
	
	
}

void sort(int *arr,  int n){
	mergesort(arr , 0 , n-1 , n);
}





int main(int argc , char*argv[]){
	if(argc < 2){
		cout << "enter filenbame" << endl;
		return 0;
	}
	
	char filename[20] ="";
	strcpy(&filename[0] , argv[1])	;
	
	int n = 1500;
	int counter = 2000;
	int *arr = new int[n];
	int k =0;
    	read_file(&filename[0] , &arr[0], &k);
    	n =k;
	//for(int i =  0 ; i < n ; i++){	arr[i] = counter--;}
	cout << "before sorting : " << endl; 
	for(int i = 0 ; i  < n ; i++){
		cout << arr[i] << " ";
	}
	clock_t t;
	t = clock();
	sort(arr,n);
	
	t=  clock()-t;
	cout <<endl << endl <<"after sorting : " << endl; 
	for(int i = 0 ; i  < n ; i++){
		cout << arr[i] << " ";
	}
	double time_taken = ((double)t); // in seconds
	cout <<"\nMerge sort serial took total " << time_taken << " ms" << endl;
		
	
	return 0;
}
