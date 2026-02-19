#include <ClassA.h>

#include <iostream>
#include <memory>

namespace
{
    /// @brief Вставляет и часть и фиксирует сообщение об успехе операции
    /// @param[in] classObj указатель на объект класса для добавления
    /// @param[in] part часть для добавления
    void AddAndCheckPart(const std::shared_ptr<ClassA> &classObj, const int &part)
    {
        const bool isSuccess = classObj->add(part);
        std::cout << "Is success: " << (isSuccess ? "true" : "false") << "\nIndex: " << (isSuccess ? (classObj->find(part)) : -1) << std::endl;
    }
}

int main()
{
    const auto &classObjA = std::make_shared<ClassA>();

    const size_t classObjASize = 5;

    int idx = 0;
    for (size_t partValue = 0; classObjA->getN() < classObjASize; ++idx, ++partValue)
    {

        AddAndCheckPart(classObjA, partValue);
        const bool isEven = classObjA->getX(idx) % 2 == 0;
        std::cout << "Is inserted part(" << partValue << ") even? " << isEven << std::endl
                  << std::endl;
        if (partValue % 5 == 0)
        {
            classObjA->del(idx);
            std::cout << "Part(" << partValue << ") removed " << std::endl
                      << std::endl;
            --idx;
        }
    }

    const auto parts = classObjA->getB(idx);
    for (int i = 0; i < idx; ++i)
    {
        const int value = parts[i]->getX();

        std::cout << "\nPart index: " << i
                  << "\ngetX(): " << value
                  << "\nverify(" << value << "): "
                  << (parts[i]->verify(value) ? "true" : "false")
                  << std::endl;

        ClassB temp;
        temp = *parts[i]; // проверка operator=

        std::cout << "operator== : "
                  << ((*parts[i] == temp) ? "true" : "false")
                  << "\noperator!= : "
                  << ((*parts[i] != temp) ? "true" : "false")
                  << std::endl;
    }

    return 0;
}