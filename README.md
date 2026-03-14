CSV Median Calculator

Небольшая утилита на C++23, которая вычисляет скользящую медиану цены из набора CSV-файлов.

Программа:

Находит входные CSV-файлы в директории examples/input

Фильтрует файлы по маскам имени (level, trade)

Читает записи и объединяет их

Сортирует записи по receive_ts

Вычисляет медиану цены по мере поступления данных

Записывает результат в examples/output/median_result.csv

Структура проекта
csv_median_calculato_NAScA
│
├─ examples
│  ├─ input
│  │  ├─ ancient_level.csv
│  │  ├─ ancient_trade.csv
│  │  └─ plato_notes.csv
│  │
│  └─ output
│
├─ include
│
├─ src
│
├─ CMakeLists.txt
└─ README.md
Формат входных CSV

Файлы должны иметь формат:

receive_ts;exchange_ts;price;quantity;side

Пример строки:

1000;2000;42.25;10;buy

Используются только поля:

receive_ts
price

Остальные поля игнорируются.

Алгоритм медианы

Для вычисления медианы используется стандартная структура:

max heap — нижняя половина значений

min heap — верхняя половина значений

Это позволяет вычислять медиану за:

O(log n) на добавление
O(1) на получение медианы
Сборка проекта

Требования:

C++23

CMake ≥ 3.23

компилятор с поддержкой C++23

Сборка через CMake
cmake -S . -B out/build
cmake --build out/build
Запуск
./out/build/csv_median_calculator

или в Windows:

.\out\build\x64-debug\csv_median_calculator.exe
Результат

Файл создаётся в:

examples/output/median_result.csv

Формат результата:

receive_ts;price_median
1000;42.00000000
1500;42.25000000
2000;42.50000000

Медиана записывается только если её значение изменилось.

Особенности реализации

сортировка файлов по имени

стабильная сортировка записей (std::stable_sort)

защита от некорректных строк CSV

округление медианы до 8 знаков после запятой
