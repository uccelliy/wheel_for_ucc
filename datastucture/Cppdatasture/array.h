#pragma once
#include <iostream>
#include <stdexcept>

template<typename E>
class MyArrayList {
private:
	E* data;
	int size;
	int cap;
	static const int INIT_CAP;
public:
	MyArrayList() {}

	MyArrayList(int initCapacity) {}

	void add(int index, E e) {
		checkPositionIndex(index);
		if (size == cap) {
			resize(cap * 2);
		}

		for (int i = size - 1; i >= index; i--) {
			data[i + 1] = data[i];
		}

		data[index] = e;
		size++;
	}

	void addLast(E e) {
		if (size == cap) {
			resize(2 * cap);
		}
		data[size] = e;
		size++;
	}

	void addFirst(E e) { add(0, e); }

	E remove(int index) {
		checkElementIndex(index);
		if (size == cap / 4) {
			resize(cap / 2);
		}
		E deletedVal = data[index];
		for (int i = index; i < size - 1; i++) {
			data[i] = data[i + 1];
		}
		size--;
		return deletedVal;
	}

	E removeLast(int index) {
		checkElementIndex(index);

		if (size == cap / 4) {
			resize(cap / 2);
		}

		E deletedVal = data[index];
		size--;

		return deletedVal;
	}

	E removeFirst() { return remove(0); }

	E get(int index) {
		checkElementIndex(index);
		return data[index];
	}

	E set(int index, E element) {
		checkPositionIndex(index);
		E oldVal = data[index];
		data[index] = element;
		return oldVal;
	}

	int getSize() { return size; }

	bool isEmpty() { return size == 0; }

	void display()  {
		std::cout << "size = " << size << "cap = " << cap << std::endl;
		for (int i = 0; i < size; i++) {
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}

	bool isElementIndex(int index)  { return index >= 0 && index < size; }

	bool isPositionIndex(int index) { return  index >= 0 && index <= size; }

	void checkElementIndex(int index)  {
		if (!isElementIndex(index)) {
			throw std::out_of_range("Index out of bounds");
		}
	}

	void checkPositionIndex(int index)  {
		if (!isPositionIndex(index)) {
			throw std::out_of_range("Index out of bounds");
		}
	}

	void resize(int newCap) {
		E* temp = new E[newCap];

		for (int i = 0; i < size; i++) {
			temp[i] = data[i];
		}

		delete[] data;

		data = temp;
		cap = newCap;
	}


	~MyArrayList() { delete[] data; }

};