Edward Lam
Professor Stamos
CSCI 335
Project 2

Make File Instructions
make all : creates the files needed to run the program
make clean : deletes program and .o files
make run1bst: Runs querytree.cc with BST tree
make run1avl: Runs querytree.cc with AVL tree
make run2bst: Runs test_tree.cc with BST tree
make run2avl: Runs test_tree.cc with AVL tree

Project 2 was to use both an AVL tree and a BST tree to store data from a text file; rebase210.txt.
We were to create our own new containers for the data in rebase210.txt; SequenceMap. It had basic functions
such as an overloaded operater< that would return true if the object being compared to it was larger and
false if it was smaller. It also has a Merge function that would add onto the data vector in the case that 
there were duplicates in the data. query_tree should run smoothly without any problems, however test_tree 
has bugs. For parts 4 and 5 of part 2b, I decided to make functions that would return a pair of values, 
<bool, int>. Bool for wether or not the query or delete was successfull, and the int for counting how many recursive
calls were made. Although the functions worked properly in the private area of the classes, once they were returned
to the public function the values inside the pair changed. For example if there were only 13 recursive calls for a 
query, once returned the value would jump to ~35000.