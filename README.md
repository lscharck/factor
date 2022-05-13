# factor
Repository for the *factor* project
## General implementation ##
Factor uses multiple threads with linked list to gather factors. These are then sorted into a binary tree for printing. Factor may be compiled by using cmake and make in the build directory. Executing "factorc" with the number to be factored as the command line argument will return the factors of that number in a list. Additionally, the cpu time and wall time will be printed out pertaining to just the factoring portion of code.


### TODO ###
Task that would make the code easier to maintain
#### Create an ADT for the linked list and the binary tree data structures ####

The ADT functional requirements (shall statments):
1. There shall be two ADTs, one for the ll and the other for the bst
2. There are two ideas to implement these ADTs
3. Firstly, the nodes and data structure are seprate
	1. Tenativly there should be a ll class, a bst class, and a data
	   strucuter class, each instance or object of these classes should be
	   a node or link in the data structer or the data strucuter itself
	2. There is a set (object) that represents the data strucuter itself.
	   There are two calls to "new", one for a data structer object and
	   multiple calls for a node object. There is a call to "add" which adds
	   the node object to the data strucuter object
	3. Operations must defined for the set such that one can add nodes,
	   remove nodes, retrive nodes, cycle through all nodes (print all nodes)
	4. The finner details remain to be layout such as how is a node
	   represented? How is a data strucuter object represented? How are the
	   ll, bst, and data strucuter objects seperated from one another? How
	   are node objects added to the data strucuter set? How are operations
	   such as cycle implemented?
3. Secondly, the data strucuter is internal to the nodes themselfs
	1. This idea allows for the nodes to be created and automatically added
	   the respective data strucuter
	2. The data strucuters are located inside the TU or dot c file that
	   implements the node. Thus, the ll class has a file for the class
	   specific operations that house a local data structuer for the ll. The
	   same is true for the bst data strucuter
	3. Operations must defined for the set such that one can add nodes,
	   remove nodes, retrive nodes, cycle through all nodes (print all nodes)
	4. The finner details remain to be layout such as how is a node
	   represented? How are the ll and bst objects seperated from one 
	   another? How are node objects added to the data strucuter set? 
	   How are operations such as cycle implemented?
4. Note that a set is not neccessarily a data structer as it too is an object
that can represent anything. A set is just an object that holds, contains
referencs to, or points to objects that are members of that set. In some cases
a set has no refernce to its objects as the objects themselfs contain references
to the set that contains them. However, it may be convient to represent the data
structer as a set as it contains objects like a set does. But this is not strict
as the definiton of a set is more abstract. The choice to make the data
strucuter a set has not been decided yet
