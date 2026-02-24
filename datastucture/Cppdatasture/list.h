//Á´±í½Úµã
#pragma once
#include <iostream>

template<typename T>
class LinkList{

private:
	class ListNode {
		T data;
		ListNode* next;
		List(T t) : data(t), next(nullptr) {}
	};

	ListNode* head;	
	ListNode* tail;
	int size_;

public:
	LinkList() {
		head = new ListNode(T());
		tail = head;
		size_ = 0;
	}
	
	~LinkList() {
		ListNode* current = head;
		while (current != nullptr) {
			ListNode* next = current->next;
			delete current;
			current = next;
		}
	}
	
	void addFirst(T t) {
		ListNode* newnode = new ListNode(t);
		newnode->next = head;
		head = newnode;
		size_++;
	}

	void addLast(T t) {
		ListNode* newnode = new ListNode(t);
		tail->next = newnode;
		tail = newnode;
		size_++;
	}
	
	void add(int index, T t) {
		ListNode* newnode = new ListNode(t);
		ListNode* current = head;
		checkPositionIndex(index);
		for (int i = 1; i < index-1; i++){
			current = current->next;
		} 
		newnode->next = current->next;
		current->next = newnode;
		size_++;

	}
	
	T removefirst() {
		ListNode* toRemove = head;	
		if (head == nullptr) return T(); // or throw an exception
		head = head->next;
		T data = toRemove->data;
		delete toRemove;
		return data;
	}
	
	T removelast() {}
	
	T remove(int index) {}
	
	T getFirst() {}
	
	T getLast(){}
	
	T get() {}
	
	T set(int index, T t) {}
	
	int getsize() { return size_; }
	
	bool isEmpty() { return size_ == 0; }

private:
	bool isElementIndex(int index){}

	bool isPositionIndex(int index) {}

	void checkElementIndex(int index) {}

	void checkPositionIndex(int index) {}

	ListNode* getNode(int index) {}






};