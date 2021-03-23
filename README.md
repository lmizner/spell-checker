# spell-checker

CS50 Problem Set: https://cs50.harvard.edu/x/2021/psets/5/speller/

This problem set required the implementation of 5 functions (load, hash, size, check, and unload) in the dictionary.c file. 

Load:
The load function starts by opening a dictionary file and reading each string, or word, from the file one at a time. For each string a node is created with the 
appropriate amount of allocated memory. The string, or word, is then copied into the node data structure. From there, the hash function is applied to the word to 
obtain the hash value. The hash value is input into the hash table along with the appropriate pointer. With each cycle through the while loop, a counter adds 1 in 
order to track the total number of words in our dictionary. The loop will continue until it has reached the end of the dictionary file.  

Hash:
The hash function is used to take the word and convert it to obtain the appropriate hash value.

Size:
The size function returns the number of words in the dictionary after the dictionary has been fully loaded. The number of words is determined by a counter that has 
been implemented within the while loop of the load function. 

Check:
The check function will take as input each word from the text file specified by the user. The hash function will be applied to the word to obtain the corresponding 
hash value. The hash value will be used as an index within the hash table to access the correct linked list. Once the linked list has been reached, the program will 
begin to loop through the contents of the linked list, comparing the string value of the text file to the string value of the dictionary that is sorted within the 
hash table. The while loop will continue to cycle through the linked list until a matching string is found or the end of the list is reached. If the word is not in 
the dictionary, then the function will return false. 

Unload:
The unload function is used to unload the dictionary file from memory. With any program, it is important to free any allocated memory once it is done being used 
within the program. To implement this, there are nested loops where we cycle through the hash table on the outer loop and cycle through the linked list on the inner 
loop. Within the inner loop, a temporary pointer is set to the value of the current cursor pointer, then the cursor pointer is moved to the next value in the linked 
list, and the temporary value is freed from memory. This process is used to make sure we do not break the linked list in the process of freeing the memory. 
