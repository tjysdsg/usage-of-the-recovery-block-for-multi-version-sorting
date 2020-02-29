ECE 590K 

Homework 4

Spring 2020

February 17, 2020

Learn the usage of the recovery block for multi-version sorting

1. Please implement two variants of sorting algorithm, such as bubble sort, selection sort, insertion sort, quicksort, heapsort, etc. 
2. Treat each sorting algorithm as a block for the purpose of recovery and implement the recovery 
3. Use a method of logging, such as “printf()”, to track down the calling history of different blocks. 
4. Check whether the second sorting variant block will be called. If the second block is not called at all, you can manually insert one or two faults in your code to check again the calling history. A program with manually inserted faults is known as a mutant. It is not hard to obtain a mutant. The easiest way is to perturb an arithmetic operator, such as replacing “+” by “*”, and “-” with “/”. You can try several mutants to see the differences. 

So, please hand in the codes you implement in a zip/rar/tar file along with a readme to demo how your codes work. 
