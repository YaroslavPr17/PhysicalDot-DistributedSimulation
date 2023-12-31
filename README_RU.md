# PhysicalDot-DistributedSimulation

## Решение системы обыкновенных дифференциальных уравнений

### Постановка задачи

Дано $N$ материальных точек с массами $m_k$, положения которых в начальный момент времени заданы радиус-векторами $r_k$, а скорости — векторами $v_k$, $k = \overline{1, N}$. Требуется определить траектории всех частиц во все моменты времени от $0$ до $t_{end}$.

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

## Конфигурация вычислительной машины
* **CPU**: Intel(R) Core(TM) i5-10400F CPU @ 2.90GHz   2.90 GHz. | Cores: 6 | Hyper Threading
* **RAM**: 32,0 ГБ
* **OS**: Ubuntu 22.04.3 LTS

## Полученные решения
Было получено несколько решений [итеративное](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/blob/development/src/single_thread.c), [параллельное с пересозданием потоков](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/blob/development/src/multi_thread_repeated_threading.c), [параллельное без пересоздания потоков](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/blob/development/src/multi_thread.c), также была создана визуализация, проведены исследования скорости выполнения различных решений и измерены характеристики, такие как *ускорение* и *эффективность*.

## Визуализация

https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/f3a72597-3e3a-4746-8e49-bc21bbb6d704

## Metrics investigation

### *Computation time*
![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77925460/f4233be0-a2a7-434b-96d2-7238cbe6cd69)

![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77925460/933df1e0-9afb-4579-808a-640adf5561e6)

### *Speed Up*
![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77925460/51a281eb-6231-43a0-b2c0-fdee49efd2cd)

![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77925460/b2afa6eb-148d-4a46-8225-8e32b454c13b)

### *Efficiency*
![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77925460/92cf44e8-0042-4b07-94d3-1ff6bad08631)

![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77925460/18019ea5-2783-4143-9252-28015b56cf45)

## Выводы по работе с многопоточностью
* Минимальное время работы программы достигается при наибольшем количестве программных потоков;
* Потоки, число которых многократно превышает количество ядер процессора вносят минимальный вклад в ускорение вычислений;
* Для большого количества потоков наблюдается очевидный "overhead" по времени;
* Технология Hyper Threading позволяет увеличить производительность вычислений на 33% (при 12 активных системных потоках вместо 6);
* После некоторого порога эффективность остаётся неизменной с ростом количества данных.
