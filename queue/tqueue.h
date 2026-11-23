#pragma once
#include <cstddef>
#include <stdexcept>
#include <utility>

using namespace std;

template <class T>
class Queue {
	T* pMem = nullptr;
	size_t sz;      
	size_t head;    
	size_t count;   

	size_t tail() const { return (head + count) % sz; } 
public:
	Queue(size_t n = 1) : pMem(nullptr), sz(n), head(0), count(0) {
		if (n == 0) throw invalid_argument("Queue: capacity must be positive");
		pMem = new T[sz];
	}

	Queue(const Queue& q) : pMem(nullptr), sz(q.sz), head(0), count(q.count) {
		pMem = new T[sz];
		try {
			for (size_t i = 0; i < count; ++i) {
				pMem[i] = q.pMem[(q.head + i) % q.sz];
			}
		}
		catch (...) {
			delete[] pMem;
			throw;
		}
	}

	Queue(Queue&& q) noexcept : pMem(q.pMem), sz(q.sz), head(q.head), count(q.count) {
		q.pMem = nullptr;
		q.sz = 0;
		q.head = 0;
		q.count = 0;
	}

	~Queue() {
		delete[] pMem;
	}

	Queue& operator=(const Queue& q) {
		if (this != &q) {
			Queue tmp(q);
			swap(tmp);
		}
		return *this;
	}

	Queue& operator=(Queue&& q) noexcept {
		if (this != &q) {
			swap(q);
		}
		return *this;
	}

	void swap(Queue& q) noexcept {
		std::swap(pMem, q.pMem);
		std::swap(sz, q.sz);
		std::swap(head, q.head);
		std::swap(count, q.count);
	}

	bool IsEmpty() const {
		return count == 0;
	}

	bool IsFull() const {
		return count >= sz;
	}

	size_t size() const {
		return count;
	}

	size_t capacity() const {
		return sz;
	}

	void push(const T& el) {
		if (IsFull()) throw std::overflow_error("Queue: push to full queue");
		pMem[tail()] = el;
		++count;
	}

	T& get() {
		if (IsEmpty()) throw std::underflow_error("Queue: get from empty queue");
		return pMem[head];
	}

	const T& get() const {
		if (IsEmpty()) throw std::underflow_error("Queue: get from empty queue");
		return pMem[head];
	}

	void pop() {
		if (IsEmpty()) throw std::underflow_error("Queue: pop from empty queue");
		head = (head + 1) % sz;
		--count;
	}

	void clear() {
		head = 0;
		count = 0;
	}
};
