# shellProject
Unix Shell Duplicate

Makefile given to compile bash shell program executible "os"

Make 
Compiles program

Make Clean
Clears compile program

Void ls ()
Prints the name of the node and name of the nodes children and siblings. Notes if the node is a file or directory

Void mkdir (char dirname)
Checks to see if the file name is taken then creates a node in the current directory and appends it to the end of linked list.
The file flag is changed to 0

Void cd (char dirname)
Allows direct access to a node in the current directory
The “..” character string will push to the parent of the selected node

Void pwd ()
Displays the current nodes path
	Etc (yourname/root/nextdir/etc/)

Void addf (char filename)
Checks to see if the file name is taken then creates a node in the current directory and appends it to the end of linked list.
The file flag is changed to 1


Void mv (char fname1, char fname2)
checks to see if the current nodes name equals fname1 if they are equal fname1 is changed to fname2

Void rm (char filename)
Calls the search function and when the specified node is found the type of node has to be determined.

If it is a file the child pointer of the parent node is copied then is set to the sibling pointer of specified node and the specified node is freed via the copied pointer path.

Void input()/bye
A loop that simulates a directory program based on user inputted commands until the bye command is inputted

Void search(char name) recursion
Starts at the root then pushes through all children and siblings to find the specified filename
