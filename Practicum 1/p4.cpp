#include <iostream> 
using namespace std; 

int main()
{
	int month; 
	cout << "Enter A month:" << endl; 
	cin >>month; 
    if(month < 1 or month > 12){
		cout << "Invalid" << endl; 
	}
	if(month == 12 || month <= 3 && month>0){
		cout << "It's winter" << endl; 
	}else if(month >= 4 && month <= 5){
		cout << "its spring." << endl; 
	} else if (month >= 9 && month <= 11){
		cout << "It's Autumn" << endl; 
	} else if (month >= 6 && month <= 8){
		cout << "It's summer" << endl; 
	}

	return 0;
}
