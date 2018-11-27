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

#ifndef PAIR_H
#define PAIR_H

template <typename A, typename B>
class Pair {
	A m_key;
	B m_value;
public:
	Pair();
	Pair(const A& a, const B& b);
	const A& getKey() const;
	const B& getValue() const;
};



#endif // !PAIR_H

template<typename A, typename B>
inline Pair<A, B>::Pair() {
}

template<typename A, typename B>
inline Pair<A, B>::Pair(const A& a, const B& b) : m_key(a), m_value(b) {
}

template<typename A, typename B>
inline const A & Pair<A, B>::getKey() const {
	return m_key;
}

template<typename A, typename B>
inline const B & Pair<A, B>::getValue() const {
	return m_value;
}
