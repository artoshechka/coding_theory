# Создаем статическую библиотеку из классов
add_library(BaseClasses STATIC src/classA.cpp
                               src/classB.cpp)

target_include_directories(BaseClasses PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)