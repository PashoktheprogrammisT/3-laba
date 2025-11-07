# Название проекта
project(FigureManagement)

# Установка стандарта C++ (C++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Указание директории с заголовочными файлами
include_directories(include)

# Создание статической библиотеки из исходных файлов
add_library(figures_lib
    src/Figure.cpp
    src/Pentagon.cpp
    src/Hexagon.cpp
    src/Octagon.cpp
    src/Array.cpp
)

# Создание исполняемого файла из main.cpp
add_executable(figure_management src/main.cpp)

# Связывание исполняемого файла с библиотекой фигур
target_link_libraries(figure_management figures_lib)

# Опция для сборки тестов (по умолчанию включена)
option(BUILD_TESTS "Build tests" ON)

if(BUILD_TESTS)
    # Включение модуля для загрузки внешних зависимостей
    include(FetchContent)

    # Установка флага для использования совместного CRT в GTest
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    # Загрузка GoogleTest из репозитория
    FetchContent_Declare(
      googletest
      URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    )

    # Обновление политики CMake для поддержки новых функций
    set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)

    # Загружает и делает доступным GoogleTest
    FetchContent_MakeAvailable(googletest)

    # Включение режима тестирования
    enable_testing()

    # Создание тестового исполняемого файла из test.cpp
    add_executable(tests tests/test.cpp)

    # Связывание тестов с библиотекой фигур и GoogleTest
    target_link_libraries(tests PRIVATE figures_lib GTest::gtest GTest::gtest_main)

    # Включение GoogleTest для автоматического обнаружения тестов
    include(GoogleTest)

    # Автоматическое обнаружение и запуск тестов
    gtest_discover_tests(tests)
endif
