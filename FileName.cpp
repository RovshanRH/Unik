#include <iostream>
#include <cmath>
using namespace std;

class Figure {
public:
	virtual double square() {
		return 0.;
	}
};

class Triangle : public Figure {
private:
	double a, b, c;
public:
	Triangle(double a, double b, double c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}
	double square() {
		double p = (a + b + c) / 2;
		return sqrt(p * (p - a) * (p - b) * (p - c));
		
	}
};

class Rectangle : public Figure {
private:
	double a, b;
public:
	Rectangle(double a, double b) {
		this->a = a;
		this->b = b;
	}
	double square() {
		return a * b;
		
	}
};

class Trapezoid : public Figure {
private:
	double a, b, h;
public:
	Trapezoid(double a, double b, double h) {
		this->a = a;
		this->b = b;
		this->h = h;
	}
	double square() {
		return (((a + b) / 2) * h);
	}
};

int main() {
	Figure* figure;
	Triangle triangle{3,4,5};
	Rectangle rectangle{ 2, 2 };
	Trapezoid trapezoid{ 2, 3, 4 };
	figure = &triangle;
	cout << figure->square();
	figure = &rectangle;
	cout << figure->square();
	figure = &trapezoid;
	cout << figure->square();
}