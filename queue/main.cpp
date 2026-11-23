#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include "tqueue.h"

using namespace std;


int main() {
	Queue<int> q(3);
	
	try { Queue<int> bad(0); } catch (const std::invalid_argument&) { cout << "queue can't be 0 size\n"; }

	q.push(1);
	cout << "added 1\n";
	q.push(2);
	cout << "added 2\n";
	q.push(3);
	cout << "added 3\n";
	if (q.IsFull() && q.size() == 3) cout << "after 3 pushes: full, size 3\n";
	cout << q.get() << " - first num\n";
	q.pop();
	if(q.get() == 2 && q.size() == 2, "pop() removes the oldest, next is 2");

	q.push(4);       // пишется в начало буфера (индекс 0), очередь: 2 3 4
	cout << "added 4\n" << "new order: ";
	Queue<int> check(q);   
	while (!check.IsEmpty()) { 
		cout << to_string(check.get()) + ' ';
		check.pop(); 
	}
	cout << "\nwrap-around keeps FIFO order (2 3 4)\n";

}
