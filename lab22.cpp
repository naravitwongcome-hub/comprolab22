#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;
const double PI = acos(-1.0);
class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double, double);
		
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		
		ComplexNumber operator+(double d) { return ComplexNumber(real + d, imag); }
		ComplexNumber operator-(double d) { return ComplexNumber(real - d, imag); }
		ComplexNumber operator*(double d) { return ComplexNumber(real * d, imag * d); }
		ComplexNumber operator/(double d) { return ComplexNumber(real / d, imag / d); }

		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0, double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real + c.real, imag + c.imag);
}

ComplexNumber operator+(double d, const ComplexNumber &c){
	return ComplexNumber(d + c.real, c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real - c.real, imag - c.imag);
}

ComplexNumber operator-(double d, const ComplexNumber &c){
	return ComplexNumber(d - c.real, -c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	return ComplexNumber(real*c.real - imag*c.imag, real*c.imag + imag*c.real);
}

ComplexNumber operator*(double d, const ComplexNumber &c){
	return ComplexNumber(d * c.real, d * c.imag);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
	double den = pow(c.real, 2) + pow(c.imag, 2);
	return ComplexNumber((real*c.real + imag*c.imag)/den, (imag*c.real - real*c.imag)/den);
}

ComplexNumber operator/(double d, const ComplexNumber &c){
	double den = pow(c.real, 2) + pow(c.imag, 2);
	return ComplexNumber((d * c.real)/den, (-d * c.imag)/den);
}

bool ComplexNumber::operator==(const ComplexNumber &c){
	return (real == c.real && imag == c.imag);
}

bool operator==(double d, const ComplexNumber &c){
	return (d == c.real && c.imag == 0);
}

double ComplexNumber::abs(){
	return sqrt(pow(real, 2) + pow(imag, 2));
}

double ComplexNumber::angle(){
	return atan2(imag, real) * 180 / M_PI;
}

ostream& operator<<(ostream &os, const ComplexNumber &c){
	if(c.real == 0 && c.imag == 0) return os << "0";
	if(c.real != 0) os << c.real;
	if(c.imag == 0) return os;
	if(c.imag > 0 && c.real != 0) os << "+";
	return os << c.imag << "i";
}

int main(){
	ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);	
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a+2.5 << "\n";
	cout << 2.5+a << "\n";
	cout << a-1.5 << "\n";
	cout << 1.5-a << "\n";
	cout << b+ComplexNumber(0,2.5) << "\n";
	cout << c-c << "\n";
	cout << "-----------------------------------\n";
	
	ComplexNumber d = (a+b)/c;
	ComplexNumber e = b/(a-c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c*2 << "\n";
	cout << 0.5*c << "\n";
	cout << 1/c << "\n";
	cout << "-----------------------------------\n";
	
	cout << ComplexNumber(1,1).abs() << "\n";
	cout << ComplexNumber(-1,1).abs() << "\n";
	cout << ComplexNumber(1.5,2.4).abs() << "\n";
	cout << ComplexNumber(3,4).abs() << "\n";
	cout << ComplexNumber(69,-9).abs() << "\n";		
	cout << "-----------------------------------\n";	
	
	cout << ComplexNumber(1,1).angle() << "\n";
	cout << ComplexNumber(-1,1).angle() << "\n";
	cout << ComplexNumber(-1,-1).angle() << "\n";
	cout << ComplexNumber(1,-1).angle() << "\n";
	cout << ComplexNumber(5,2).angle() << "\n";
	cout << "-----------------------------------\n";
	
	cout << (ComplexNumber(1,1) == ComplexNumber(1,2)) << "\n";
	cout << (ComplexNumber(1,1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
}





