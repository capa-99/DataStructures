//An array stores items (C/C++, Java Primitive Arrays) or their references (Python, JS, Java Non-Primitive) at contiguous locations
//Advantages over other data structures:
//Random Access: i-th item can be accessed in O(1) Time as we have the base address and every item is of same size
//Cache Friendliness: Since items are sorted at contiguous locations, we get the advantage of locality of reference
//It is not useful in places where we have operations like insert in the middle, delete from middle and search in an unsorted data
//It is a fundamental and linear data structure usd to build other data structures like Stack, Queue, Deque, Graph, Hash Table, etc.