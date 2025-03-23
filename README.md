# Bilkent University CS 202 Assignments

Repository includes my solutions for the course Fundamental Structures of Computer Science I assignments. The course introduces the fundamentals of the computer programming with C++ programming. The memory leaks are tested with Valgrind for the assignments. The code in the assignments are tested by using an automated test suite that includes multiple test cases on a remote server provided by Bilkent University.

## Assignments

- `Project 1` : Binary Search Tree
    - `Aim` : To implement a pointer-based BST whose keys are integers. An array of keys and its size are provided to the constructor to create the BST and it is assumed that there are no identical keys in the array.
    - `Public Member Functions` : Insert key, delete key, find the height of BST, show the level of the key, display an inorder traversal of BST, display a postorder traversal of BST, find the maximum level at which the tree is a full binary tree, find the lowest common          ancestor of given keys A and B, find the path from root to a leaf node which has the maximum sum of the keys included in the path, find the level of the tree which has the maximum number of nodes to display the keys in that level from left to right.
    - `Content` : Object-oriented programming that implements all of the previously stated functions by using recursion. Linked list and queue objects are used as well. There is also an analysis file that measures the time taken and finds the height of the tree after             every 1000 insertions into the BST.
 
- `Project 2` : Drone Fleet Management System
    - `Aim` : To implement a simulation by using heaps that ensures that high-priority tasks are handled by drones capable of completing them, optimizing overall performanc, and reducing the average task completion time.
    - `Public Member Functions` : Simulation method that starts the following process: Cooldown Update which means to assume that the battery life amount would be enough to handle the package delivery after cool down and set battery life to 300, task assignment which     
    means the highest-priority task is assigned to the best available drone, feasibility check which means the simulation calculates if the drone can complete the task based on its effective speed and remaining battery, execution or cooldown which means if the drone 
    completes the task, its battery is updated and it is reinserted into the available pool; if not, it enters a cooldown state.
    - `Content` : Object-oriented programming that implements the described simulation process by using heaps. There are seperate classes for drones, packages and tasks. The methods to check whether the cooldown process should be entered and to start the cooldown process 
    are implemented in the task class.
