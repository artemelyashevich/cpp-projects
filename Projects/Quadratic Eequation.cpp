#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Quadratic_equation {
private:
	int a, b, c;
	float x1, x2, xv, yv;
	float d;

	int checkD() {
		cout << "D = " << this->d << endl;
		return (this->d < 0) ? false : true;
	}

	void findx() {
		this->x1 = (-this->b + pow(this->d, 0.5)) / 2;
		this->x2 = (-this->b - pow(this->d, 0.5)) / 2;
		cout << "x1 = " << this->x1 << "\nx2 = " << this->x2 << endl;
	}

	void findD() {
		this->d = pow(this->b, 2) - 4 * this->a * this->c;
	}

	void find_extremum_x() {
		this->xv = (-this->b) / (2 * this->a);
		if (this->a > 0) {
			cout << "Функция убывает до: " << this->xv << " Возрастает от: " << this->xv << endl;
		}
		else{
			cout << "Функция возрастает до: " << this->xv << " Убывает от: " << this->xv << endl;
		};
	}

	void find_extremum_y() {
		this->yv = this->a * pow(this->xv, 2) + this->b * this->xv + this->c;
		if (this->a > 0) {
			cout << "Минимальное значение функции: " << this->yv << endl;
		}
		else {
			cout << "Максимальное значение функции: " << this->yv << endl;
		}
	}

public:
	Quadratic_equation(int a, int b, int c) {
		this->a = a;
		this->b = b;
		this->c = c;	
	}
	
	void showx() {
		this->findD();
		if (this->checkD()) {
			this->findx();
			this->find_extremum_x();
			this->find_extremum_y();
		}
		else {
			cout << "D < 0" << endl;
		}
	}
};


int main() {
	setlocale(LC_ALL, "ru");
	Quadratic_equation first(1, 50, 10);
	first.showx();
}