# PhysicalDot-DistributedSimulation

## Solving a system of ordinary differential equations

### Setting the task

Given $N$ material points with masses $m_k$, whose positions at the initial moment of time are given by radius vectors $r_k$, and velocities by vectors $v_k$, $k = \overline{1, N}$. It is required to determine the trajectories of all particles at all time points from $0$ to $t_{end}$.

### Input format
The program is given a file with the masses, initial coordinates and velocities of all material points.
The first line of the file consists of a single number `n` — the number
of dots.

### Output format
A `csv` file, each line of which
has the following format:

![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/7f5248e1-6f38-4ecb-8320-42a4919fe53f)

### The equation that needs to be solved

![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/72181ed4-045e-43a9-881d-5048c1409b1c)

### Iterative formulas for solving each equation

![image](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/assets/77744037/153b2fc6-42f6-4c5b-bab3-e3be840296f2)

## Computer configuration
* **CPU**: Intel(R) Core(TM) i5-10400F CPU @ 2.90GHz 2.90 GHz. | Cores: 6 | Hyper Threading
* **RAM**: 32.0 GB
* **OS**: Ubuntu 22.04.3 LTS

## Received solutions
Several solutions have been obtained [iterative](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/blob/development/src/single_thread.c) , [parallel with threads reassignment](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/blob/development/src/multi_thread_repeated_threading.c) , [parallel without threads reassignment](https://github.com/YaroslavPr17/PhysicalDot-DistributedSimulation/blob/development/src/multi_thread.c) Visualization was also created, studies of the speed of execution of various solutions were conducted and numerical characteristics were measured, such as *acceleration* and *efficiency*.

## Visualization

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

## Conclusions on working with multithreading
* The minimum execution time is achieved with the largest number of program threads;
* Threads, the number of which is many times higher than the number of processor cores, make a minimal contribution to the acceleration of calculations;
* For a large number of threads, there is an obvious overhead in time;
* Hyper Threading technology allows you to increase computing performance by 33% (with 12 active system threads instead of 6);
* After a certain threshold, the efficiency remains unchanged as the amount of data increases.
