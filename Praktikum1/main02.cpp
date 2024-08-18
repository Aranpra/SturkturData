#include <iostream>

using namespace std;

int main()
{
	int a, b, temp;
		temp:
	cout<<"Nilai variable A dan B sebelum ditukar: \nA= ";
	cin>>a;
	cout<<"B= ";
	cin>>b;
	
	temp=a;
	a=b;
	b=temp;
	
	cout<<"\nNilai variable A dan B stelah ditukar:\nA= "<<a<<"\nB= "<<b<<endl;
	return 0;
}
