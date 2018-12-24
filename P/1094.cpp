/*Description

Digital clock use 4 digits to express time, each digit is described by 3*3 characters (including¡±|¡±,¡±_¡±and¡± ¡°).now given the current time, please tell us how can it be expressed by the digital clock.

Input

There are several test cases.
Each case contains 4 integers in a line, separated by space.
Proceed to the end of file.

Output

For each test case, output the time expressed by the digital clock such as Sample Output.

Sample Input
1 2 5 6
2 3 4 2
Sample Output
    _  _  _ 
  | _||_ |_ 
  ||_  _||_|
 _  _     _ 
 _| _||_| _|
|_  _|  ||_ 
HINT



The digits showed by the digital clock are as follows:

   _  _     _  _  _  _  _  _ 

 | _| _||_||_ |_   ||_||_|| |

 ||_  _|  | _||_|  ||_| _||_|

*/
#include<iostream>
using namespace std;

int main(){
	int a[4];
	while(cin >> a[0] >> a[1] >> a[2] >> a[3]){
		for(int i =0; i < 4; i++){
			switch(a[i]){
				case 0:{
					cout << " _ ";
					break;
				}
				case 1:{
					cout << "   "; 
					break;
				}
				case 2:{
					cout << " _ ";
					break;
				}
				case 3:{
					cout << " _ ";
					break;
				}
				case 4:{
					cout << "   ";
					break;
				}
				case 5:{
					cout << " _ ";
					break;
				}
				case 6:{ 
					cout << " _ ";
					break;
				} 
				case 7:{
					cout << " _ ";
					break;
				}
				case 8:{
					cout << " _ ";
					break;
				}
				case 9:{
					cout << " _ ";
					break;
				}
			}
		}
		cout << endl;
		for(int i =0; i < 4; i++){
			switch(a[i]){
				case 0:{
					cout << "| |";
					break;
				}
				case 1:{
					cout << "  |"; 
					break;
				}
				case 2:{
					cout << " _|";
					break;
				}
				case 3:{
					cout << " _|";
					break;
				}
				case 4:{
					cout << "|_|";
					break;
				}
				case 5:{
					cout << "|_ ";
					break;
				}
				case 6:{
					cout << "|_ ";
					break;
				} 
				case 7:{
					cout << "  |";
					break;
				}
				case 8:{
					cout << "|_|";
					break;
				}
				case 9:{
					cout << "|_|";
					break;
				}
			}
		}	
		cout << endl;
		for(int i =0; i < 4; i++){
				switch(a[i]){
				case 0:{
					cout << "|_|";
					break;
				}
				case 1:{
					cout << "  |"; 
					break;
				}
				case 2:{
					cout << "|_ ";
					break;
				}
				case 3:{
					cout << " _|";
					break;
				}
				case 4:{
					cout << "  |";
					break;
				}
				case 5:{
					cout << " _|";
					break;
				}
				case 6:{
					cout << "|_|";
					break;
				} 
				case 7:{
					cout << "  |";
					break;
				}
				case 8:{
					cout << "|_|";
					break;
				}
				case 9:{
					cout << " _|";
					break;
				}
			}
			}cout << endl;	
		}
		
}
