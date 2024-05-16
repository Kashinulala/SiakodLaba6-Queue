//Реализовать класс - циклическая очередь с приоритетным выходом, tail указывает на последний добавленный элемент.
#include <iostream>
#include "ClassQueue.h"

int main(){
	using namespace std;
	queue a(15);
	queue b(4);
	queue c(3);
	queue d(7);

	for (int i = 10; i > 0; i--) {
		a.add(i%5+1);
	}

	for (int i = 0; i <10; i++) {
		b.add(i+1);
	}
	cout << "a: " << a << "->"<< a.length() << "\n";
	cout << "b: " << b << "->" << b.length() << "\n";


	for (int i = 10; i > 5; i--) {
		a.del();
	}

	for (int i = 0; i < 3; i++) {
		b.del();
	}

	cout << "a: " << a << "->" << a.length() << "\n";
	cout << "b: " << b <<   "->" << b.length() << "\n";


	for (int i = 10; i > 9; i--) {
		a.add(i);
	}

	for (int i = 0; i < 5; i++) {
		b.add(i + 1);
	}
	a.print();
	b.print();
	cout << "a: " << a << "->" << a.length() << "\n";
	cout << "b: " << b << "->" << b.length() << "\n";

	a = a;
	d = b = a;

	cout << "a: " << a << "\n";
	cout << "b: " << b << "\n";
	cout << "c: " << c << "\n";
	cout << "d: " << d << "\n";
	
	/*
	cout << a << "\n";
	a.del();
	cout << a << "\n";
	a.add(3);
	a.add(9);
	cout << a << "\n";
	a.del();
	cout << a << "\n";
	a.print();
	a.del();
	cout << a << "\n";
	a.print();
	a.del();
	cout << a << "\n";
	a.del();
	a.del();
	cout << a << "\n";
	a.add(1);
	a.add(2);
	cout << a << "\n";

	queue b(a);
	cout << "\n\n"<< b << "\n";

	a.add(9);
	b.add(3);

	cout << "\n\n" << a << "\n";
	cout << "\n\n" << b << "\n";

	a = b;
	cout << "\n\n" << a << "\n";
	*/



}