# PhysicalDot-DistributedSimulation

## Решение системы обыкновенных дифференциальных уравнений

### Постановка задачи

![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/8f16396a-77d3-4602-8cfc-b2fb44860484)

### Формат ввода
На вход программе дается файл с массами, начальными координатами и скоростями всех материальных точек.
Первая строка файла состоит из одного числа `n` — количества
точек.

### Формат вывода
Файл формата `csv`, каждая строка которого
имеет следующий вид:

![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/7f5248e1-6f38-4ecb-8320-42a4919fe53f)

### Уравнение, которое требуется решить

![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/72181ed4-045e-43a9-881d-5048c1409b1c)

### Итерационные формулы для решения каждого уравнения

![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/153b2fc6-42f6-4c5b-bab3-e3be840296f2)

## Полученные решения
Было получено несколько решений [итеративное](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/blob/development/src/single_thread.c), [параллельное с пересозданием потоков](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/blob/development/src/multi_thread_repeated_threading.c), [параллельное без пересоздания потоков](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/blob/development/src/multi_thread.c), также была создана визуализация, проведены исследования скорости выполнения различных решений и измерены характеристики, такие как *ускорение* и *эффективность*.

## Визуализация

https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/f3a72597-3e3a-4746-8e49-bc21bbb6d704

## Измерения времени

### Параллельное решение без пересоздания потоков

![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/7a7f1749-0c52-4b7d-8ccd-137254dfbbf8)

![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/122f34f2-a0e3-4656-a655-9913e6388173)

### Параллельное решение с пересозданием потоков
![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/3a073b6e-ee60-4b9c-ac73-9bc89b31d82b)

![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/ff457fd9-d779-48a3-b9f8-1f7c463a7a2e)

## Измерения ускорения

### Параллельное решение без пересоздания потоков

![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/71726a9b-c8f0-4d72-a19f-acda1ca319cb)

![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/f29ad1de-a081-4eff-8568-b1be1e9b758c)

### Параллельное решение с пересозданием потоков

![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/a44bf85f-0065-4e08-b0de-da548f86e799)

![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/c40e69a2-73e6-4d6c-95e0-40f96c6bfa03)

## Измерения эффективности

### Параллельное решение без пересоздания потоков

![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/b2cde11d-9d7a-4dab-90b6-cccb4c416baa)

![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/030a0aec-fd99-4be0-8f86-a4d36e61eb2c)

### Параллельное решение с пересозданием потоков

![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/39784df7-478a-4be7-8f3a-209bdef21a7c)

![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/9e3dd7ff-fa95-49ae-8baf-047b25f5727d)



