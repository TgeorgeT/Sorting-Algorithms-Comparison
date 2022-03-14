## Sortings time comparison
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




![image](https://github.com/TgeorgeT/SortingsComparison/blob/main/Number%20of%20Values_%2010%5E4-2_10%5E6%2C%20Max%20Value_%2010%5E6%2C%20Step_%2010%5E4.png)
