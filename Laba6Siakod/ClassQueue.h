#pragma once
using namespace std;

class queue {

private:
	int* arr;
	unsigned N;
	unsigned head, tail;

public:
	//_N - размер очереди;
	queue(unsigned _N) {
		N = _N + 1;
		head = tail = 0;
		arr = new int[_N + 1];
		for (int i = 0; i < (_N + 1); i++) {
			arr[i] = 0;
		}
	}

	~queue() {
		delete[] arr;
	}

	int size() {
		return N - 1;
	}

	int length() {
		return (N + tail - head) % N;
	}

	int print() {
		for (int i = 0; i < N; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return 0;
	}

	//Возвращает индекс максимального элемента
	int searchMax() {
		int max = arr[head + 1];
		int maxIndex = head + 1;
		int n = length();
		for (int i = 0; i < n; i++) {
			if (arr[(head + 1 + i) % N] > max) {
				max = arr[(head + 1 + i) % N];
				maxIndex = (head + 1 + i) % N;
			}
		}
		return maxIndex;
	}

	int add(int elem) {

		if ((tail + 1) % N == head) {
			return -1;
		}
		else {
			tail = (tail + 1) % N;
			arr[tail] = elem;
			return 0;
		}
	}

	int del() {

		if (head != tail) {
			int p = searchMax();
			int left = (N + p - head - 1) % N;
			int right = (N + tail - p) % N;

			if (left <= right) {
				for (int i = 0; i < left; i++) {
					arr[(N + p - i) % N] = arr[(N + p - i - 1) % N];
				}
				head = (N + head + 1) % N;
				return 0;
			}
			else {
				for (int i = 0; i < right; i++) {
					arr[(N + p + i) % N] = arr[(N + p + i + 1) % N];
				}
				tail = (N + tail - 1) % N;
				return 0;
			}
		}
		else return -1;
	}

	friend ostream& operator << (ostream& os, queue &qe) {
		int n = qe.length();
		if (n != 0) {
			for (int i = 0; i < n; i++) {
				os << qe.arr[(qe.head + i + 1) % qe.N] << " ";
			}
			return os << "\n";
		}
		else return os << "Queue empty" << "\n";
	}

	queue(const queue& qe) {
		N = qe.N;
		tail = qe.tail;
		head = qe.head;
		arr = new int[N];
		for (int i = 0; i < N; i++) {
			arr[i] = qe.arr[i];
		}
	}

	queue& operator= (queue& qe) {
		
		if (&qe != this)
		{
			int p = qe.length();
			if (N - 1 >= p) {
				for (int i = 1; i <= p; i++) {
					arr[i] = qe.arr[(qe.head + i) % qe.N];
				}
				head = 0;
				tail = p;
			}
			else {
				for (int i = 1; i < N; i++) {
					arr[i] = qe.arr[(qe.head + i) % qe.N];
				}
				head = 0;
				tail = N - 1;
			}
		}
		return *this;
	}
};