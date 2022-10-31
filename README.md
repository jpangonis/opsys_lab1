# opsys_lab1

Operating Systems: Programming Assignment 1

Requirements:

You are required to use C/C++ in Linux/Unix. You can consider installing VirtualBox in your non-Linux environment.
Programs must succeed in compilation and execution as required (80 points)
Readme, documentation and example are required (20 points).
Topic: Producer-Consumer Problem

The producer generates items and puts items onto the table. The consumer will pick up items. The table can only hold two items at the same time. When the table is complete, the producer will wait. When there are no items, the consumer will wait. We use semaphores to synchronize producer and consumer. Mutual exclusion should be considered. We use threads in the producer program and consumer program. Shared memory is used for the “table”.

