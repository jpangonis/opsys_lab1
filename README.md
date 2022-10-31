# Operating Systems Lab 1: Producer and Consumer problem

Operating Systems: Programming Assignment 1

Requirements:

You are required to use C/C++ in Linux/Unix. You can consider installing VirtualBox in your non-Linux environment.
Programs must succeed in compilation and execution as required (80 points)
Readme, documentation and example are required (20 points).
Topic: Producer-Consumer Problem

The producer generates items and puts items onto the table. The consumer will pick up items. The table can only hold two items at the same time. When the table is complete, the producer will wait. When there are no items, the consumer will wait. We use semaphores to synchronize producer and consumer. Mutual exclusion should be considered. We use threads in the producer program and consumer program. Shared memory is used for the “table”.

Implementation:

Written in C++, there are two files pro.cpp and con.cpp. The pro.cpp file produces an item and adds it into the table and the con.cpp consumes an item and deletes it from the table. The two files are working synchronously using a shared memory and sempahores. There can be at most two items in the table at a time. For the implementation, table[0] records how many items are in the table. Table[1] and table[2] are the spots open for items in the table. Random numbers generated are added into the table and then consumed from the table. Comments in the code further explain how the code works. 

Compiling:
$ g++ producer.cpp -pthread -lrt -o producer

$ g++ consumer.cpp -pthread -lrt -o consumer

$ ./producer & ./consumer &

Output:

![Screenshot (52)](https://user-images.githubusercontent.com/117044135/199100295-d600f83d-869e-43da-8cae-e840933c6265.png)
