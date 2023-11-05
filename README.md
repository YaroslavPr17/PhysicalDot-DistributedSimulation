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

## Полученные решения
Было получено несколько решений [итеративное](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/blob/development/src/single_thread.c), [параллельное с пересозданием потоков](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/blob/development/src/multi_thread_repeated_threading.c), [параллельное без пересоздания потоков](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/blob/development/src/multi_thread.c),  также была создана визуализация и проведены исследования скорости выполнения различных решений

## Визуализация

https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/f19f1a3b-20e1-416e-88f0-202c3372bc44

## Измерения времени

### Параллельное решение без пересоздания потоков

![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/38ef8180-e8b1-4399-8b55-cf006e5223b8)

![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/e7e37548-2825-4798-be9c-63b1ca556812)

### Параллельное решение с пересозданием потоков

![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/dfdf11a2-7ebc-4395-84f0-4609365da990)

![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/47cee8c6-43ed-4168-b031-a2f96655dd43)

## Измерения ускорения

### Параллельное решение без пересоздания потоков

![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/b7e98bd5-1c42-4561-b6d7-ea89f674729b)

![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/16144002-31b6-4e61-8dd6-00e0fb42727d)

### Параллельное решение с пересозданием потоков

![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/084b7f7b-c42b-4d29-a6f3-8efda91ac0cf)

![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/5d25b877-ffab-4fe5-a2c3-fd188599ed91)

## Измерения эффективности

### Параллельное решение без пересоздания потоков

![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/893f590a-98f7-4801-9821-c5f615bab891)

![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/3b063801-cc72-4508-b029-2bd5a600cdfa)

### Параллельное решение с пересозданием потоков

![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/c6ae48f3-215c-4901-8e90-7b39980d94cb)

![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/e41c61dc-25a6-4f66-be6b-a63d16cdc9ed)


