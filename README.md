# Bilkent University CS 202 Assignments

Repository includes my solutions for the course Fundamental Structures of Computer Science II assignments. The course introduces the fundamentals of the computer programming with C++ programming. The memory leaks are tested with Valgrind for the assignments. The code in the assignments are tested by using an automated test suite that includes multiple test cases on a remote server provided by Bilkent University.

## Assignments

- `Project 1` : Binary Search Tree
    - `Aim` : To implement a pointer-based BST whose keys are integers. An array of keys and its size are provided to the constructor to create the BST and it is assumed that there are no identical keys in the array.
    - `Public Member Functions` : Insert key, delete key, find the height of BST, show the level of the key, display an inorder traversal of BST, display a postorder traversal of BST, find the maximum level at which the 
    tree is a full binary tree, find the lowest common ancestor of given keys A and B, find the path from root to a leaf node which has the maximum sum of the keys included in the path, find the level of the tree which has 
    the maximum number of nodes to display the keys in that level from left to right.
    - `Content` : Object-oriented programming that implements all of the previously stated functions by using recursion. Linked list and queue objects are used as well. There is also an analysis file that measures the time 
    taken and finds the height of the tree after every 1000 insertions into the BST.
 
- `Project 2` : Drone Fleet Management System
    - `Aim` : To implement a simulation by using heaps that ensures that high-priority tasks are handled by drones capable of completing them, optimizing overall performance, and reducing the average task completion time.
    - `Public Member Functions` : Simulation method that starts the following process: Cooldown Update which means to assume that the battery life amount would be enough to handle the package delivery after cool down and 
    set battery life to 300, task assignment which means the highest-priority task is assigned to the best available drone, feasibility check which means the simulation calculates if the drone can complete the task based 
    on its effective speed and remaining battery, execution or cooldown which means if the drone completes the task, its battery is updated and it is reinserted into the available pool; if not, it enters a cooldown state.
    - `Content` : Object-oriented programming that implements the described simulation process by using heaps. There are separate classes for drones, packages and tasks. The methods to check whether the cooldown process 
    should be entered and to start the cooldown process are implemented in the task class.

- `Project 3` : Hash Table
    - `Aim` : To implement two different hash tables. The first one handles collisions by quadratic probing and the second one handles them by separate chaining method.
    - `Public Member Functions` : Both of hash tables have the same functions which are to insert, delete, and search for items. Items in this case are String objects.
    - `Content` : Object-oriented programming that implements all of the previously stated functions by using the mentioned methods to handle the collisions. The hash table that handles the collisions by quadratic probing 
    stores the items in one-dimensional statically allocated array and the one that handles the collisions by separate chaining method stores the items in two-dimensional statically allocated array.

- `Project 4` : Cyber Attack Containment System
    - `Aim` : To implement a simulation by using breadth-first search and Dijkstra's shortest path algorithms in an undirected graph to understand whether a node can be protected and to isolate the infected regions of a
      network by limiting malware spread.
    - `Public Member Functions` : There are two public functions. First one simulates the spreading process according to which nodes in the graph are dispatchers and malwares. Second one removes the connections between
    dispatcher and malware nodes to prevent further contamination; also, it prints out the connected zones after removing the necessary connections.
    - `Content` : Object-oriented programming that implements all of the previously stated functions by using Dijkstra's shortest path algorithm and slightly altered breadth-first search algorithm. A Queue object that is 
    implemented by using linked list is used to implement the breadth-first search algorithm. There is also a method to read a given file with certain word-per-line constraints and create the graph with given nodes and edges.
