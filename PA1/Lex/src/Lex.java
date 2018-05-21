//Jason Chen

import java.io.*;
import java.util.Scanner;

public class Lex {
	
   public static void main(String[] args) throws IOException {
      int count = 0;
      int line = 0;
      
      Scanner in = new Scanner (new File(args[0]));
      PrintWriter out = new PrintWriter (new FileWriter(args[1]));
      
      // Count the number of lines
      while (in.hasNextLine()) {
    	  line++;
    	  in.nextLine();
      }
      
      in.close();
      
      in = new Scanner (new File(args[0])); //Read in the each line as Strings
      List list = new List(); //Create new list to store indexes
      String[] array = new String[line]; //
      
      while (in.hasNext()) {
    	  array[count] = in.nextLine();
    	  count++;
      }
      
      //Insert a number to the list that is smaller or equal to all indexes
      list.prepend(0);
	  
      //Insertion Sort 
      for(int i = 1; i < array.length; i++) {
     	 int j = 0;
      
          list.moveBack();
          while(j < i && array[i].compareTo(array[list.get()]) <= 0) {
             j++;
             list.movePrev();
          }
          
          if (list.index() != -1) {
			  list.insertAfter(i);
		  } else {
			  list.prepend(i);
		  }
	  }

      
	  list.moveFront();
	  
	  while (list.index() >= 0) {
		  out.println(array[list.get()]);
		  list.moveNext();
	  }
	  
	  in.close();
	  out.close();
   }
}