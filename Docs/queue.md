# Queue 
First In, First Out (FIFO)

## Circular Queue
Implemented: enqueue, dequeue, first, size, isempty. 

### Implementation
1. Initialize the queue, with size of the queue defined (maxSize), and head and tail pointers.
2. enqueue: Check if the number of elements is equal to maxSize - 1:
  - If Yes, then return Queue is full.
  - If No, then add the new data element to the location of tail pointer and increment the tail pointer.
3. dequeue: Check if the number of elements in the queue is zero:
  - If Yes, then return Queue is empty.
  - If No, then increment the head pointer.
4. Finding the size:
  - If, tail >= head, size = (tail - head) + 1
  - But if, head > tail, then size = maxSize - (head - tail) + 1
[src](#link1)


### Application / Real World Examples
* M/M/1 queue. One of the most important queueing models is known as an M/M/1 queue, which has been shown to accurately model many real-world situations. It is characterized by three properties: 
  - There is one server—a FIFO queue. 
  - Interarrival times to the queue obey an exponential distribution with rate λ per minute. 
  - Service times from a nonempty queue obey an exponential distribution with rate μ per minute. 
  [src](#link3)
* Load balancing. LoadBalance.java simulate the process of assigning n items to a set of m servers. For each item, it chooses a sample of s servers and assigns the item to the server that has the fewest current items. 
* Computer controlled Traffic Signal System uses circular queue.
* When a resource is shared among multiple consumers. CPU scheduling, Disk Scheduling and Memory management.
* When data is transferred asynchronously (data not necessarily received at same rate as sent) between two processes. Examples include IO Buffers, pipes, file IO, etc.
[src](#link1)[src](#link2)

## Problems / Exercises
* [src](#link3)
* Josephus Problem [src](#alg_java_gtg) page 246


## Sources
* [src1](#alg_java_gtg) page 238 
* [src2](#b-alg-c-segw) page 30
* <a name="link1" href="https://www.studytonight.com/data-structures/circular-queue">link1</a>
* <a name="link2" href="https://www.geeksforgeeks.org/applications-of-queue-data-structure/">link2</a>
* <a name="link3" href="https://introcs.cs.princeton.edu/java/43stack/">link3</a>
* https://www.cs.cmu.edu/~adamchik/15-121/lectures/Stacks%20and%20Queues/Stacks%20and%20Queues.html
* https://introcs.cs.princeton.edu/java/43stack/
