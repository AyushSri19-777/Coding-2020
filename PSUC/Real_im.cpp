#include <iostream>
using namespace std;
struct Complex
{
    int real;
    int imaginary;
};
int main()
{
    Complex n1,n2;
    cout<<"Enter the real part of 1st number: ";
    cin>>n1.real;
    cout<<"Enter the imaginary part of 1st number: ";
    cin>>n1.imaginary;
    cout<<"Enter the real part of 2nd number: ";
    cin>>n2.real;
    cout<<"Enter the imaginary part of 2nd number: ";
    cin>>n2.imaginary;
    cout<<"The sum = "<<(n1.real+n2.real)<<"+"<<(n1.imaginary+n2.imaginary)<<"i";
}
