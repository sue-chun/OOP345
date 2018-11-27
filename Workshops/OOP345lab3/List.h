// Name: Sue Ming Chun
// Seneca Student ID: 032343154
// Seneca email: smchun@myseneca.ca
// Date of completion: Sept 17 2018
//
// I confirm that the contents of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include <iomanip>
#include <string>

#ifndef LIST_H
#define LIST_H 

template <typename T, int N> 
class List {
	T m_array[N];
	T dummy;
	size_t m_size;

public: 
	List();
	size_t size() const;
	const T& operator[](int index) const;
	void operator +=(const T& add);
	~List();
};


template<typename T, int N>
List<T, N>::List() {
	m_size = 0;
}

template<typename T, int N>
size_t List<T, N>::size() const {
	return m_size;
}

template<typename T,  int N>
const T & List<T, N>::operator[](int index) const {
	return index < static_cast<int>(m_size) ? m_array[index] : dummy;
}

template<typename T, int N>
void List<T, N>::operator+=(const T & add) {
	if (m_size < N) { // had no elements in the beginning, added them all after 
		m_array[m_size] = add;
		m_size++;
	}
}

template<typename T, int N> // do I need this? 
List<T, N>::~List() {
}

#endif // !LIST_H
