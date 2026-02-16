#pragma once
#include <ClassB.h>
class ClassB;
class ClassA
{
	int m_n;		   // фактическое число частей
	ClassB *m_pB[100]; // массив указателей на части
public:
	ClassA();
	~ClassA();
	const int getN() const;			  // вернуть число частей
	const ClassB **getB(int &) const; // вернуть части
	bool add(const int);			  // добавить часть
	bool del(const int);			  // удалить часть
	int find(const int) const;		  // вернуть индекс части
	const int getX(const int) const;  // вернуть значение объекта
};
