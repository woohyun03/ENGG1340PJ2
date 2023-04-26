# ENGG1340_GROUP97_YUTGAME


Code explaination
  for map display
    The printmap function takes a two-dimensional string array k as its parameter and prints out each element of the array to the console. The main function initializes a two-dimensional string array map with 77 rows and 77 columns, and an index array index with 29 rows and 2 columns. The printmap function is then called with map as its parameter, causing the map to be printed out to the console.
    
    
    
  for map.cpp
  
  Map() : Constructor for creating a map object. It initializes the mapPlayerLocation array to false and sets the player's starting location to the bottom left of the map.
  Map(Station mapPlayerLocation[7][7]) : Constructor that takes a Station array as input and creates a map object with that array.
  
  removeMal(int row, int col) : Method for removing a 3x3 piece from the map at the specified row and column position.
  
  addMal(int row, int col, string** mal) : Method for adding a 3x3 piece to the map at the specified row and column position.
  
  moveMal(int previRow, int previCol, int row, int col, string** mal) : Method for moving a 3x3 piece from its previous position to a new position on the map.
  
  UpdatePlayerLocation(int previRow, int previCol, int row, int col) : Method for updating the player's location on the map.
printMap() : Method for printing the current state of the map.
