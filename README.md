## Sorting Algorithmstime comparison
Project done by Teodorescu George-Tiberiu, group 132

## Sorting algorithms used
-STL Sort  
-Radix Sort (Base 10)  
-Radix Sort (Base 2^8)  
-Radix Sort (Base 2^16)  
-Merge Sort  
-Shell Sort (using the original sequence proposed by Shell)  
-Shell sort (using a custom sequence)  
-Quick sort (using median of three)  
-Heap sort  

## Time measurments
Time was measured using the chrono library.

## Implementation
The program takes an "input.txt" file with the following format:  
  
(first_value) (last_value) (step) (max_value)  
  
It then iterates from first_value to last_value with the step given in the input file and generates a vector with the size of the current value and the max_value given in the file.  
Each sorting is tested on a copy of the generated vector, checked for correctitude and then the time is printed in the "output.csv" file.  
  
## Results:
![image](https://github.com/TgeorgeT/SortingsComparison/blob/main/Number%20of%20Values_10%5E3-10%5E5%2C%20Max%20Value_%2010%5E8%2C%20Step_%2010%5E3.png)  

We can see that the fastest sorting algorithm is the radix sort in base 2^16. This is a trend that will remain throughout the majorityof the tests.  
Note that the only algorithms that should be impacted by a larger max value are the radix sorts.

![image](https://github.com/TgeorgeT/SortingsComparison/blob/main/Number%20of%20Values_%2010%5E4-2_10%5E6%2C%20Max%20Value_%2010%5E6%2C%20Step_%2010%5E4.png)

We can see that the radix sort in base 2^16 was overtaken by the radix sort in base 2^8. This may be due to the fact that the max_value is lower.  
Merge sort performs worse than quick sort, which is comparable to a radix sort in base 10 for this case.
It's also worth noticing that heap sort performs similar to the standard shell sort, but significantly worse than the shell sort using the modified gap sequence.

![image](https://github.com/TgeorgeT/Sorting-Algorithms-Comparison/blob/main/Number%20of%20Values_%2010%5E4-2_10%5E6%2C%20Max%20Value_%2010%5E16%2C%20Step_10%5E4.png)  
When the max value was increased radix sort in base 2^16 performed better than radix sort in base 2^8
![image](https://github.com/TgeorgeT/SortingsComparison/blob/main/Number%20of%20Values_%2010%5E7-2.5_10%5E7%2C%20Max%20Value_%2010%5E16%2C%20Step_10%5E6.png)  
Heap sort still performs similar to shell sort, even though its complexity is better than shell sort.  

![image](https://github.com/TgeorgeT/Sorting-Algorithms-Comparison/blob/main/Number%20of%20values_%2010%5E8%2C%20Max%20Value_10%5E16.png)
## Notes
The shell sort gap sequence use was: {  89766, 40803, 18315,8124,3611,1605,701, 301, 132, 57, 23, 10, 4, 1}

