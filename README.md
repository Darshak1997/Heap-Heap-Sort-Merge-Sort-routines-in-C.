# Heap-Heap-Sort-Merge-Sort-routines-in-C.
compile and run
     the template using these commands:

      $ gcc -o test testHMRoutines.c HMRoutines.c support.c

      $ ./test 1000 1 1 1

     In that test command, the '1000' means test the sorting
     algorithm on an array of 1000 elements.  The '1 1 1' means to
     do one test with the input elements in ascending order, one
     test with the elements in descending order, and one test with
     the elements in shuffled order.

     You should see output similar to this:
$ ./test 25000000 3 3 3
25,000,000 items in array.
=== Heap Sort ===
--- Ascending test
 1/ 3: fill 0.070s, run 9.628s, 0 errors.
 2/ 3: fill 0.040s, run 9.604s, 0 errors.
 3/ 3: fill 0.041s, run 9.611s, 0 errors.
Average run time 9.614s
--- Descending test
 1/ 3: fill 0.058s, run 9.340s, 0 errors.
 2/ 3: fill 0.058s, run 9.330s, 0 errors.
 3/ 3: fill 0.058s, run 9.311s, 0 errors.
Average run time 9.327s
--- Shuffle test
 1/ 3: fill 1.106s, run 15.557s, 0 errors.
 2/ 3: fill 1.106s, run 15.545s, 0 errors.
 3/ 3: fill 1.109s, run 15.581s, 0 errors.
Average run time 15.561s
=== Merge Sort ===
--- Ascending test
 1/ 3: fill 0.040s, run 3.223s, 0 errors.
 2/ 3: fill 0.041s, run 3.145s, 0 errors.
 3/ 3: fill 0.040s, run 3.146s, 0 errors.
Average run time 3.171s
--- Descending test
 1/ 3: fill 0.058s, run 3.140s, 0 errors.
 2/ 3: fill 0.058s, run 3.144s, 0 errors.
 3/ 3: fill 0.058s, run 3.138s, 0 errors.
Average run time 3.141s
--- Shuffle test
 1/ 3: fill 1.106s, run 5.327s, 0 errors.
 2/ 3: fill 1.107s, run 5.401s, 0 errors.
 3/ 3: fill 1.106s, run 5.328s, 0 errors.
Average run time 5.352s
