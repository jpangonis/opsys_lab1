#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <iostream>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
        //create variables for the table holding the two items and for the shared memory
        int sharedMemory;
        //for my solution, I table[0] is going to hold the number of items in the table, table[1] will hold the first item in the table
        //table[2] will hold the second item in the table
        int *table;
        //open shared memory for table                                                                                                         
        sharedMemory = shm_open("table", O_CREAT | O_RDWR, 0666);    
        //size of shared memory is the size of the int                                                       
        ftruncate(sharedMemory,sizeof(int));
        //maps shared memory to address                                                                                 
        table = static_cast<int*>(mmap(0, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, sharedMemory, 0));
                       
         //open semaphores                                                                                                                   
        sem_t* full = sem_open("full", O_CREAT, 0666, 0);                                                                    
        sem_t* empty = sem_open("empty", O_CREAT, 0666, 3);
        sem_t* mutex = sem_open("mutex", O_CREAT, 0666, 1);

        //loop through the producer consumer problem 5 times                                                                               
        for (int i = 0; i < 5; ++i) {
                //semaphores lock until they are ready
                sem_wait(full);
                sleep(1);                                                                                                   
                sem_wait(mutex); 
                //while there is at least one item in the table                                                                                         
                if (table[0] > 0) {     
                        //consume the second index first
                        if (table[2] != 0){
                          int y = table[2];
                          table[2] = 0;
                          table[0]--;
                          std::cout << "Consumed an item." << y << std::endl << "Table contains: " << table[0] << " items\n";
                        }
                        //consume the first index second
                        else{
                          int y = table[1];
                          table[1] = 0;
                          table[0]--;
                          std::cout << "Consumed an item." << y << std::endl << "Table contains: " << table[0] << " items\n";
                        }                                                                                                    
                    
                                                                                                              
                } else {
                        std::cout << "Buffer is empty!\n";
                }
                //unlocks the semaphores
                sem_post(mutex);                                                                                            
                sem_post(empty);
        }

        //closes semaphores                                                                                                                   
        sem_close(full);
        sem_close(empty);
        sem_close(mutex);

        //unlinks semaphores                                                                                                                   
        sem_unlink("full");
        sem_unlink("empty");
        sem_unlink("mutex");

        //unmap memory address                                                                                                                   
        munmap(table, sizeof(int));
        //close shared memory
        close(sharedMemory);
        //unlink the table to the shared memory
        shm_unlink("table");
        return 0;
}