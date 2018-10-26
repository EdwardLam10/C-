/***************************************************************
Title: Project 1
Author: Edward Lam
Date Created: 2/14/2017
Class: Spring 2017, CSCI 235-03, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Project 1
Description: A Vector class made from dynamic arrays with a
Set class that implements the previously built Vector class.
***************************************************************/

*Parts Complete/Incomplete*

-Clear function - Incomplete
Most of the functions provided have been completed with the exception of the Clear function
in the Vector class. Initially I had written the clear function to delete the dynamic array
and create a new one with the defaut size and capacity. Although the the Deletion of the
original dynamic array went smoothly, the program would crash upon recreating a new dynamic
array. The current Clear function will only reset the size and capacity to their default
states which will bound the capacity to what its supposed to be while the actual capacity may
be higher.


*Known Bugs*

-Program would randomly crash after compiling without any errors, the problem seemed to go away
after I copied and pasted the Vector and Set source files to a new project.


*Report*

-Set Class and Vector Class
Having written the Vector class first I found that alot of the functions from the Set Class would
overlap with the Vector class, allowing for easy definitions. For example; the size() and the clear()
functions could be achieved by simply returning the size() function from the vector class. The only
problem that I encountered in the Set Class was when I tried to use the [] operator in the contains 
funtion. The solution was remedied by a new const function getInt.

-GetInt Function (Vector Class)
A const function that returns the value of the array at a given int 'a'. 

-Remove Function (Vector Class)
counter is used to cycle through the values of the array, counter2 is used to cycle through the 
values of the array after a matching int has been found.
"arr_[counter2] = arr_[counter2 + 1]" replaces the value with the one found after it.

-Push back Function (Vector Class)
A temporary dynamic array is used to hold the values of the vector while it  is being overwritten 
with a new capacity. The temporary array is deleted after its values are transfered over to the 
new array as to save memory.

-Vector Class Copy Constructor and Vector Class Copy Assignment operator
First copies the values of size and capacity, then uses a for loop to cycle through the values of
the original array'rhs' to copy over the values.

