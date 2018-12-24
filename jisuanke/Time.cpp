#include<iostream>
using namespace std;

int main(){
	int a[4];
	while(cin >> a[0] >> a[1] >> a[2] >> a[3]){
		for(int i = 0; i < 4 ;i++){
			switch(a[i]){
				case 0:{
					cout<<" _ "; 
					break;
				}
				case 1:{
					cout<<"   " ;
					break;
				}
				case 2:{
					cout<<" _ ";
					break;
				}
				case 3:{
					cout<<" _ ";
					break;
				}
				case 4:{
					cout<<"   ";
					break;
				}
				case 5:{
					cout<<" _ ";
					break;
				}
				case 6:{
					cout<<" _ ";
					break;
				}
				case 7:{
					cout<<" _ ";
					break;
				}
				case 8:{
					cout<<" _ ";
					break;
				}
				case 9:{
					cout<<" _ ";
					break;
				}
			 }
		}
		cout << endl;
		for(int i = 0; i < 4 ;i++){
			switch(a[i]){
				case 0:{
					cout<<"| |"; 
					break;
				}
				case 1:{
					cout<<"  |";
					break;
				}
				case 2:{
					cout<<" _|";
					break;
				}
				case 3:{
					cout<<" _|";
					break;
				}
				case 4:{
					cout<<"|_|";
					break;
				}
				case 5:{
					cout<<"|_ ";
					break;
				}
				case 6:{
					cout<<"|_ ";
					break;
				}
				case 7:{
					cout<<"  |";
					break;
				}
				case 8:{
					cout<<"|_|";
					break;
				}
				case 9:{
					cout<<"|_|";
					break;
				}
			}
		}
		cout << endl; 
		for(int i = 0; i < 4 ;i++){
			switch(a[i]){
				case 0:{
					cout<<"|_|"; 
					break;
				}
				case 1:{
					cout<<"  |";
					break;
				}
				case 2:{
					cout<<"|_ ";
					break;
				}
				case 3:{
					cout<<" _|";
					break;
				}
				case 4:{
					cout<<"  |";
					break;
				}
				case 5:{
					cout<<" _|";
					break;
				}
				case 6:{
					cout<<"|_|";
					break;
				}
				case 7:{
					cout<<"  |";
					break;
				}
				case 8:{
					cout<<"|_|";
					break;
				}
				case 9:{
					cout<<" _|";
					break;
				}
			}
		}cout<<endl;
	}
	return 0;
}
