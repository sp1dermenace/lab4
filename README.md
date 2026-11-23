# Очередь на кольцевом буфере

Шаблонный класс `Queue<T>` фиксированной ёмкости и тесты на Google Test.

## Структура

```
CMakeLists.txt       корневой: подключает три проекта ниже
gtest/               общий Google Test 1.18.0 -> статическая библиотека `gtest`
  CMakeLists.txt
  include/, src/     исходники gtest (src/gtest-all.cc)
queue/               приложение `queue`: класс + локальный main
  CMakeLists.txt
  tqueue.h           класс Queue<T> (header-only)
  main.cpp           ручная проверка основных функций (без gtest)
tests/               исполняемый `run_tests`: gtest-тесты очереди
  CMakeLists.txt
  test_main.cpp      main для gtest
  test_queue.cpp     тесты
```

## Сборка (CMake >= 3.16, C++17)

```
cmake -S . -B build
cmake --build build --config Debug
build/queue/queue            # локальный main  (Windows: build\queue\Debug\queue.exe)
ctest --test-dir build -C Debug --output-on-failure   # gtest-тесты
```

В Visual Studio: *Файл → Открыть → CMake…* → `CMakeLists.txt`, запускать цели `queue` и `run_tests`.

## API `Queue<T>`

| Метод | Описание |
|---|---|
| `Queue(n)` | очередь ёмкости `n` (`n > 0`, иначе `std::invalid_argument`) |
| `push(x)` | добавить в конец; на полной очереди — `std::overflow_error` |
| `get()` | первый элемент; на пустой — `std::underflow_error` |
| `pop()` | убрать первый; на пустой — `std::underflow_error` |
| `IsEmpty()`, `IsFull()`, `size()`, `capacity()`, `clear()` | |
