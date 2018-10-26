/***************************************************************
Title: README.txt
Author: Edward Lam
Date Created: 04/04/2017
Class: Spring 2017, CSCI 235-03, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Assignment #2
***************************************************************/

Make File Instructions:
make all - builds all the .o as well as the project itself.
make run - runs the project.
make clean - removes all the .o files as well as the project.

Part Complete and Parts Incomplete:
The entire project is fully complete as far as I know.

Description of known bugs:
-When exiting the program there is a segmentation fault, but only if you choose to load a file first
before attempting to exit. Exiting regularly without a load or save is fine.
-Sometimes the program will crash randomly, however the crashes were not reproducable.

Project 2 - To-Do List
The project is a templated linked list that will store nodes which contain tasks inside. All of the tasks
are inherited from a base class 'generic' which only has a due date and a description, which all the other
tasks have as well so inheritance was the obvious choice. 2 of the generic functions were names virtual
(boht of the print tasks) because of their different implementations in the child classes. A very large 
portion of this project relied on strings and the ability to parse or combine and to change into integers.
The project can be thought of in layers since the most basic class was the date class, which was used 
inside the generic class, which was then inherited into homework, event, and shopping. These were then
inserted into templated nodes which were called inside the linkedList class. Becuase of the layers in the 
linkedList class, calling print functions and dealing with the nodes was very straightfoward. 
-insertSorted()
In my opinion, adding and removing from the list was the most difficult part of the assignment. Having to sort 
the items by dates did not make it any easier, sorting by dates made comparing an even longer task; first you would 
compre the years, then if they were equal you would compare the months, and if those were also equal, then you
would compare the days. Because I chose to compare and insert before the node if the date was indeed smaller, I
did not have to worry about equivalent dates, the program would simply go onto the next node and compare; 
if it was smaller than the next node then it would be inserted before it and placing it right behind the 
equivalnet node.
