/*
    CH-231-A by Dr. Kinga Lipskoch
    Name: Sanjay Timilsena
    Mail: s.timilsena@jacobs-university.de
    Problem: h1_p1
*/

#include <cassert>
#include <iostream>

using namespace std;

//defininf complex class
class Complex {
	private:
		double re, im;
	public:
        //parametric constructor
		Complex(double re, double im) {
			this->re = re;
			this->im = im;
		}
        //overloading different operators
		Complex& operator=(const Complex o) {
			this->re = o.re;
			this->im = o.im;
			return *this;
		}
        bool operator==(const Complex o) {
			return this->re==o.re && this->im==o.im;
		}
		Complex operator+(const Complex o) {
			return Complex(this->re + o.re, this->im + o.im);
		}
		friend ostream& operator<<(ostream &o, Complex c) {
			o << c.re << "+" << c.im << "i" << endl;
			return o;
		}
};

//defining the array_search function
template<typename T>
int array_search(T* myarray, int num, T searchfor)
{
    for(int i=0;i<num;i++)
    {
        if(myarray[i]==searchfor)
            return i;
    }
    return -1;
}

int main(int argc, char** argv)
{
    //creating array of integers
	int intarr[] = {1, 2, 3, 4, 5, 6};
	int result = array_search(intarr, 6, 3);
    cout << result << endl;

    //creating array of double
	double darr[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
	cout << array_search(darr, 6, 4.4) << endl;
	
    //creating array of complex numbers
	Complex carr[] = {Complex(1, 2), Complex(3, 4), Complex(-3, -5)};
	cout << array_search(carr, 3, Complex(13,5)) << endl;

    return 0;
}