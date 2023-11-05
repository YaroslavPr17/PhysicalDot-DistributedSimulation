# PhysicalDot-DistributedSimulation

## Решение системы обыкновенных дифференциальных уравнений

### Постановка задачи
![void_link](https://github.com)

### Формат ввода
На вход программе дается файл с массами, начальными координатами и скоростями всех материальных точек.
Первая строка файла состоит из одного числа `n` — количества
точек.

### Формат вывода
Файл формата `csv`, каждая строка которого
имеет следующий вид:

![void_link](https://github.com)

### Уравнение, которое требуется решить

![void_link](https://github.com)

### Итерационные формулы для решения каждого уравнения

![void_link](https://github.com)

## Полученные решения
Было получено несколько решений [итеративное](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/blob/development/src/single_thread.c), [параллельное с пересозданием потоков](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/blob/development/src/multi_thread_repeated_threading.c), [параллельное без пересоздания потоков](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/blob/development/src/multi_thread.c), также была создана визуализация, проведены исследования скорости выполнения различных решений и измерены характеристики, такие как *ускорение* и *эффективность*.

## Визуализация

![void_link](https://github.com)

## Измерения времени

### Параллельное решение без пересоздания потоков

![void_link](https://github.com)

![void_link](https://github.com)

### Параллельное решение с пересозданием потоков

![void_link](https://github.com)

![void_link](https://github.com)

## Измерения ускорения

### Параллельное решение без пересоздания потоков

![void_link](https://github.com)

![void_link](https://github.com)

### Параллельное решение с пересозданием потоков

![void_link](https://github.com)

![void_link](https://github.com)

## Измерения эффективности

### Параллельное решение без пересоздания потоков

![void_link](https://github.com)

![void_link](https://github.com)

### Параллельное решение с пересозданием потоков

![void_link](https://github.com)

![void_link](https://github.com)


