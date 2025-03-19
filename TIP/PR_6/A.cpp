#define _USE_MATH_DEFINES
#include <iostream>
//#include <exception>
#include <cmath>
using namespace std;

class WrongTriangleSideException : public  exception {
public:
	const char* what() const noexcept override {
		return "Wrong triangle!";
	}
};

class Triangle : public WrongTriangleSideException {
public:
	double a, b, c;
	bool exst_tr() {
		if (a + b > c) {
			return true;
		}
		else if (b + c > a) {
			return true;
		}
		else if (a + c > b) {
			return true;
		}
		else {
			return false;
		}
	}

	Triangle(double a, double b, double c) {
		if (!this->exst_tr()) {
			this->a = 3;
			this->b = 4;
			this->c = 5;
		}
		else {
			this->a = a;
			this->b = b;
			this->c = c;
		}
		//if (a == 0 || b == 0 || c == 0) {
		//	throw WrongTriangleSideException();
		//}
		////throw WrongTriangleSideException();
	}
	Triangle() {
		throw WrongTriangleSideException();
	}

	void show() {
		std::cout << "A = " << a << ", B = " << b << ", C = " << c << std::endl;
	}
	double perimetr() {
		return a + b + c;
	}
	double square() {
		double p = (a + b + c) / 2;
		double s = std::sqrt(p * (p - a) * (p - b) * (p - c));
		return s;
	}
	double get_a() {
		return a;
	}
	double get_b() {
		return b;
	}
	double get_c() {
		return c;
	}
};
//#include "main4_1.cpp"
int main() {
	try {
		Triangle triangle(3,4,5);
		triangle.show();
	}
	catch (const Triangle::WrongTriangleSideException& ex) {
		cout << "error: " << ex.what();
	}
}