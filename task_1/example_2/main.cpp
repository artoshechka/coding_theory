#include "ClassA.h"
#include "ClassB.h"

#include <iostream>
#include <memory>

namespace
{
    /// @brief Пытается добавить связь между ClassA и ClassB и выводит результат
    /// @param[in] a объект класса ClassA
    /// @param[in] b объект класса ClassB
    void AddAndCheckRelation(ClassA &a, ClassB &b)
    {
        a.addB(b);
        std::cout << "Relation added: " << (a.hasB(b) ? "true" : "false")
                  << ", B has A? " << (b.hasA() ? "true" : "false") << std::endl;
    }

    /// @brief Пытается удалить связь между ClassA и ClassB и выводит результат
    /// @param[in] a объект класса ClassA
    /// @param[in] b объект класса ClassB
    void RemoveAndCheckRelation(ClassA &a, ClassB &b)
    {
        a.removeВ(b);
        std::cout << "Relation removed: " << (!a.hasB(b) ? "true" : "false")
                  << ", B has A? " << (!b.hasA() ? "true" : "false") << std::endl;
    }
} // namespace

int main()
{
    ClassA a1, a2;
    ClassB b1, b2, b3, b4, b5;

    {
        AddAndCheckRelation(a1, b1);
        AddAndCheckRelation(a1, b2);
        AddAndCheckRelation(a1, b3);
        AddAndCheckRelation(a1, b4);
        std::cout << std::endl;
    }

    {
        AddAndCheckRelation(a1, b5); // не должно добавиться, max 4
        std::cout << std::endl;
    }

    {
        std::cout << "a1 multiplicity: " << a1.getMultiplicity() << std::endl;
        std::cout << std::endl;
    }

    {
        RemoveAndCheckRelation(a1, b2);
        std::cout << std::endl;
    }

    {
        AddAndCheckRelation(a1, b5); // теперь добавится
        std::cout << std::endl;
    }

    {
        const ClassB **relations = a1.getB();
        for (int i = 0; i < a1.getMultiplicity(); ++i)
        {
            std::cout << "Relation " << i
                      << ": B has A? " << (relations[i]->hasA() ? "true" : "false")
                      << std::endl;
        }
        std::cout << std::endl;
    }

    {
        a1.removeB();
        std::cout << "a1 has any B? " << (a1.hasB() ? "true" : "false") << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
