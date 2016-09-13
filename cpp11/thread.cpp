#include <iostream>
#include <thread>
using namespace std;

volatile int order = 0;

void task(char name) {
	for (int i = 0; i < 10; i++) {
		while (order % 3 != name - 'A');
		cout << name <<endl;
		order ++;
	}
}

int main() {
	thread t1(task,'A');
	thread t2(task,'B');
	thread t3(task,'C');
	t1.join();
	t2.join();
	t3.join();

	return 0;
}

/*
note :
you have to add -pthread to compile this C++ file
*/
