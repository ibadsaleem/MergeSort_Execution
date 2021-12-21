
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int get_rand(){
	return rand()/1000;
}




int main(){
	
	char filename[50];
	cout << "enter filename : ";
	cin >> filename;
	cout << endl;
	ofstream of(filename);
	int n;
	cout << "enter number of inputs : ";
	cin >> n;
	cout <<endl;
	srand(time(0));
	//int *arr = new int[n+2];
	of << n <<endl;
	for(int i = 1 ; i <= n ;i++){
		of << get_rand() << endl;	
	}
	of.close();
	return 0;
}
