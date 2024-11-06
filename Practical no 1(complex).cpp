#include <iostream>
using namespace std;
class Complex
{
	int x;
	int y;
	public:
	Complex()
	{
		x=y=0;
	}
	Complex operator+(Complex);
	Complex operator*(Complex);
	friend istream & operator >> (istream &input, Complex & c)
	{
		cout<<"Enter real part of the number : ";
		input>>c.x;
		cout<<"Enter imaginary part of the number : ";
		input>>c.y;
	}
	friend ostream & operator << (ostream &output, Complex &c)
	{
		cout<<c.x<<"+"<<c.y<<"i"<<endl;
	}
};
Complex Complex :: operator+(Complex c)
{
	Complex temp;
	temp.x=x+c.x;
	temp.y=y+c.y;
	return temp;
}
Complex Complex :: operator*(Complex c)
{
	Complex temp;
	temp.x=(x*c.x)-(y*c.y);
	temp.y=(x*c.y)+(y*c.x);
	return temp;
}
int main()
{
	Complex c1,c2,c3,c4;
	int ch;
	do
	{
		cout<<"------------Menu------------------"<<endl;
		cout<<"1. Default Constructor "<<endl;
		cout<<"2. Add Complex number "<<endl;
		cout<<"3. Addition of Complex numbers "<<endl;
		cout<<"4. Multiplicatin of two numbers "<<endl;
		cout<<"5. Display the numbers "<<endl;
		cout<<"6. Exit"<<endl;	
		cout<<"Enter Your choice : "<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<c1;
				break;
			case 2:
				cout<<"Enter first number : "<<endl;
				cin>>c1;
				cout<<"Enter Second number : "<<endl;
				cin>>c2;
			    break;
			case 3:
			    c3=c1+c2;
				cout<<"Addition : " <<c3;
			    break;
			case 4:
				c4=c1*c2;
				cout<<"Multiplication : "<<c4;
				break;
			case 5:
				cout<<"1st complex number :";
				cout<<c1;
				cout<<"2nd complex number :";
				cout<<c2;  
			case 6:
			     exit(0);	
		}
	}
	while(ch!=6);
	return 0;
}
