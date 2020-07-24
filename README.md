# Movie_Rental_Store
Automate the local movie rental store 's inventory tracking system. 

Description:
A local movie rental store wishes to automate their inventory tracking system. Currently there are three types of movies/videos (in DVD media) to be tracked:
-	Comedy (denoted as ‘F’ for funny)
-	Drama (denoted as ‘D’)
-	Classics (denoted as ‘C’)
Borrows and returns of items by customers are also to be tracked. Four types of actions are desired in the system:
-	Borrow (denoted as ‘B’): (stock – 1) for each item borrowed  
-	Return (denoted as ‘R’): (stock + 1) for each item returned
-	Inventory (denoted as ‘I’): outputs the inventory of all the items in the store
-	History (denoted as ‘H’): outputs all the transactions of a customer 

I will design and implement a program that will initialize the contents of the inventory from a file (data4movies.txt), the customer list from another file (data4customers.txt), and then process an arbitrary sequence of commands from a third file (data4commands.txt).

Details:
In data4movies.txt, the information about each movie is listed as follows: 
-	For comedy movies: F, Stock, Director, Title, Year it released 
-	For drama movies: D, Stock, Director, Title, Year it released
-	For classics movies: C, Stock, Director, Title, Major actor Release date

data4customers.txt contains customer information, one line per customer. Customers have a 4-digit ID number that uniquely identifies them, followed by last name, first name, all separated by a space.

data4commands.txt is used to test the code. The first field is action type (B, R, I, or H). Then the rest of fields are as follows:
-	Action types I: no more fields
-	Action type H: one more field customer ID. Fields are separated by a space
-	Action types B and R: customer ID followed by type of media (currently only ‘D’ for DVD) then movie type and movie data (with values of the two sorting attributes, using comma or space to separate them as in the movie data file). Fields are separated by a space. 

