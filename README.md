# PhysicalDot-DistributedSimulation

## Решение системы обыновенных дифференциальных уравнений

### Постановка задачи
![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/7711db46-2ef8-431e-9d38-ad1adbc65757)

### Формат ввода
На вход программе дается файл с массами, начальными координатами и скоростями всех материальных точек.
Первая строка файла состоит из одного числа n — количества
точек.

### Формат вывода.
Файл формата csv, каждая строка которого
имеет следующий вид

![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/d1b93fb2-2b00-448f-a67c-cf58889e1630)

### Уравнение которое требуется решить

![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/c16de5b9-e988-4198-9d4d-ca66b0135512)

### Итерационные формулы для решения каждого уравнения

![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/1e7dbdd6-3643-4749-9a6e-a6e9e984105a)

## Полученные
 решения
Было получено несколько решений [итеративное](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/blob/development/src/single_thread.c), [параллельное с пересозданием потоков](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/blob/development/src/multi_thread_repeated_threading.c), [параллеьлное без пересоздания потоков](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/blob/development/src/multi_thread.c),  также была создана визуализация и проведены исследования скорости выполнения различных решений
## Визуализация

https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/f19f1a3b-20e1-416e-88f0-202c3372bc44


