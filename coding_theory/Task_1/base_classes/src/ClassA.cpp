#include <ClassA.h>

ClassA::ClassA() : m_n(0) {}
ClassA ::~ClassA()
{
	for (int j(0); j < m_n; j++)
		delete m_pB[j];
}
// вернуть количество частей
const int ClassA ::getN() const { return m_n; }
// вернуть части const
const ClassB **ClassA ::getB(int &n) const
{
	n = m_n;
	return const_cast<const ClassB **>(m_pB);
}
// добавить часть
// метод получает все необходимые параметры для создания части
bool ClassA ::add(const int x)
{
	if (find(x) >= 0)
		return false;
	m_pB[m_n] = new ClassB;
	m_pB[m_n]->setX(x);
	m_n++;
	return true;
}
// удалить часть
bool ClassA ::del(int key)
{
	int JDel = find(key);
	// поиск индекса части
	if (JDel < 0)
		return false;
	// часть не найдена
	delete m_pB[JDel];
	// разрушение части
	while (JDel < m_n - 1)
	{
		// сжатие массива
		m_pB[JDel] = m_pB[JDel + 1];
		JDel++;
	}
	m_n--;
	return true;
}
// вернуть индекс части
int ClassA ::find(const int key) const
{
	for (int j(0); j < m_n; j++)
		if (m_pB[j]->verify(key))
			return j;
	return -1;
}
// вернуть значение объекта с индексом
//  вызывается метод класса частей m_pB[j]->getX();
const int ClassA::getX(const int j) const
{
	return m_pB[j]->getX();
}