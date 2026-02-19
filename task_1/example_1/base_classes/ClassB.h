#pragma once
class ClassB
{
	int m_x; // член-данное части

public:
	ClassB();
	~ClassB();
	// методы установки и получения значения m_х
	void setX(const int);
	const int getX() const;
	bool verify(const int) const;	   // проверить объект
	ClassB &operator=(const ClassB &); // перегрузка оператора =
	// перегрузка операторов == и !=
	bool operator==(const ClassB &) const;
	bool operator!=(const ClassB &) const;
};
