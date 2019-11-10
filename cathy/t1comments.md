## Q1 to 7

* A - using linear search through commits is very slow 
* B - calculation error for how long it takes for commits, or mismatch with answer for part a answer 
* C - tombstones stop search on first "Empty" (E) spot. Must look at deleted 
* D - start at hash index for "lemon" 
* E - any function call in loop must do the number of ops in it * number of loop iterations (or depending on call, some function with respect to n.  Not just the call itself one time)
* F - Array data being already sorted is one way but the key is that the pivot picked is always smallest or biggest every time we partition. You can pick a pivot that isn't biggest and smallest even if partition is sorted.  
* G - This won't work.  Its about how to pick pivot. 
* H - describe a bit more details about how to binary search through commits... which way do you go if there is a bug in the middle? 
* I - better to just randomize the picking of pivot.  array being sorted.  Picking a random pivot is like having a random array and faster, no need to preprocess 
* J - there is nothing that actually says anything about what either function do, how its written etc. ... just that they do the same thing, how fast they operate on some amount of data, so your answer should only look at that.  resource usage with respect to data.  No specific algorithms.
* K - don't forget to talk about treating it as ring 
* L - there isn't anything here about speed.. just that testing passed or not passed.  Slow doesn't always mean bug, fast doesn't always mean correct.  this has nothing to do with error.
* M - this is just repeating the code in comments... explain why...why is back incremented with the wierd modulus, why do we need front and back... explanation not code.
* N - quick sort does not require median to be chosen in order to not be n^2.  Just can't always pick smallest/biggest every time.
* O - picking end for pivot isn't always bad... it depends on shape of the data set.  its bad if end value is biggest/smallest each time.  the key is not position of pivot but rather if the pivot can divide the dataset evenly.


## Q8

* A - Missing base case 
* B - O(n) algorithm -3
* C - logic error, no loop needed 
* D - return value is wrong, should return  if not found, index of where it is found if it is found
* E - checking wrong location
* F - return value offset error
* G - calling recursive twice on both halfs of array makes it linear.
* H - array[idx] is an integer, you really need & here if you want to use it as an array... its really not just a syntax thing, its a logical thing 
* I - search returns index with respect to the start of the array it is passed.  If you pass in array starting at middle, return index needs to be offsetted 
* J - if(a == b){} else if(a<b) else if (a > b) covers ALL possiblities.. any else that follows will never execute.  
* K - potential for crash based on order of checks.. if size is 0, and you check array[size] thats out of range
* L - misses the situation with 1 element in array 
* M - writing the entire algorithm iteratively in a different function and then making a call to that function does not make the function recursive.
* N - return value error 
* O - array[idx1 -idx2] does NOT give you an array between indexes idx1 and idx2.  It will give you one integer at index (idx1-idx2) and if that index is negative, it will crash your program 
* P - you need to use the return value from your search(return it, assign to local and return that etc.)
* Q - you are using array[idx] when what you want is idx 



## Q9A

* A - non sentinel versions require taking care of special cases (inserting beginning/end etc.) 
* B - if item is not found in current iteration of loop, it doesn't mean you should insert it at back... this happens only if NONE of the list items match, has to happen after you know this 
* C - iterator it; *it is an int (data_).  it.curr_ is a Node*.  *it->anything is wrong (int->...) it.next_/prev_/data_ is wrong.  it.curr_->next_/prev_/data_ is fine.
* D - Link errors
* E - Node not placed into correct position 
* F - Logical error, using ++ on an iterator that is changed in the for loop will cause iterator to skip nodes 
* G - doesn't work if curr is first node 
* H - situation of n not found not handled 
* I - infinite loop 
* J - inserted Nodes must be new'd 
* K - many typing errors 
* L - deleting the node you just newed will dealloate it, causing it to not exist.


## Q9B

* A - other is not empty an empty list at the end.  
* B - calling a destructor explictly on a non-dynamically allocated object is NOT a good idea.
* C - empty list does not mean to delete, it means other must look like an empty linked list.  non-sentinel lists must have nullptrs on front/back, sentinel list sentinels should point at each other.
* D - when current list or other starts off empty, code won't handle it 
* E - iterator it; *it is an int (data_).  it.curr_ is a Node*.  *it->anything is wrong (int->...) it.next_/prev_/data_ is wrong.  it.curr_->next_/prev_/data_ is fine.
* F - missing/incorrect links
