  #include<stdio.h>
  #include<string.h>
  #include<stdlib.h>
  #include<stdbool.h>
  #define SIZE 12
  bool mazeFun(char [SIZE][SIZE]);
  int main(int argc, char* argv[])
  {
     FILE *fp=NULL;
     int i=0,j=0;
     char array[SIZE][SIZE];
    
     if(argc !=2)
       {
	  printf("File name missing");
	  return 0;
       }
     fp=fopen(argv[1],"r");
     if(fp==NULL)
       {
          printf("\n Error opening file. ");
	  return 0;
       }
     
             char c ;
           
	     while(fscanf(fp,"%c",&c)!=EOF)
	     {
		 if(c == '#' || c == '.')
			 array[i][j++] = c;
		 if(j==12)
		 {
			i++;
			j = 0;
		 }
	     }

     fclose(fp);

     for(i=0;i<SIZE;i++)
     {
	 for(j=0;j<SIZE;j++)
		printf("%c ",array[i][j]);
	 printf("\n");
     }
     
     if( mazeFun(array))
	{
            printf("\n\n This is  our path \n Path is denoted by * \n\n    ");
            printf("\n==========================\n");
            for(i=0;i<SIZE;i++)
               {
                  for(j=0;j<SIZE;j++)
                     printf("%c ",array[i][j]);
                     printf("\n");
               }
   
	}
     else
         return 0;

     // Path using only * symbol 

     printf("\n\n Path using only * \n ");
     for(i=0;i<SIZE;i++)
	{
	   for(j=0;j<SIZE;j++)
               {	      
	          if(array[i][j]=='*')
		     printf("%c",array[i][j]);
		  else
	             printf(" ");
	       }
           printf("\n ");
	     
	}
   	
  }  

  // Function for maze solving

  bool mazeFun(char array[SIZE][SIZE])
  {
     char hand;
     int i,j=0;
     int sourceX, sourceY=0, destiX,destiY=11 ,srcCount=0,destCount=0;
  
     // checking for number of entry and exit point in the maze.

     for(i=0;i<SIZE;i++)
	{
	   if(array[i][0]=='.')
	     {
	        sourceX=i;
		srcCount++;
	     }
	   if(array[i][11]=='.')
	     {
                destiX=i;
	        destCount++;
	     }
	}
     if(srcCount!=1)
     {
        if(srcCount<1)
	{
	   printf("\n There is no Entry point in the Maze.");
	}
	else
        {
           printf("\n More than one entry point in  the Maze.");
	}
	return false;
     }
     
     if(destCount!=1)
     { 
 	if(destCount<0) 
           {
               printf("\n There is no Exit point in the maze.");
           }
        else
          {
               printf("\n More than one exit point");
          }

	return false;
     }
   
      // starting direction right.

     hand='R';
     i = sourceX;
     j = sourceY;
     fflush(stdin);
       
  // Logic for maze solving 
     while((i>=0 && i<SIZE) && (j>=0&&j<SIZE))
     {      
        if(hand=='R')
           {    array[i][j]='*';
        	if(array[i+1][j]=='*' || array[i+1][j]=='.')
                  {   
		      i++;
		      hand='D';
		   
                  }
		else if(array[i][j+1]=='*' || array[i][j+1]=='.')
	          {
		      j++;
		      hand='R';
		     
		  }
		else if(array[i-1][j]=='*' || array[i-1][j]=='.')
                  {
		      i--;
		      hand='U' ;
		       
		  }
		else
		  {
		      j--;
		      hand='L';
		    
	     	  }
           }
          else  if(hand=='L')
           {    array[i][j]='*';
                if(array[i-1][j]=='*' || array[i-1][j]=='.')
                  {
                      i-- ;
                      hand='U' ;
		    
                  }
                else if(array[i][j-1]=='*' || array[i][j-1]=='.')
                  {
                      j--;
                      hand='L';
		
		  }

                else if(array[i+1][j]=='*' || array[i+1][j]=='.')
                  {
                      i++;
                      hand='D';
		       
		     
                  }
                else
                  {
                      j++;
                      hand='R' ;
		       

                  }
           }
          else if(hand=='U')
           {    array[i][j]='*';
                if(array[i][j+1]=='*' || array[i][j+1]=='.')
                  {
                      j++;
                      hand='R' ;
                       
		     
                  }
		else if(array[i-1][j]=='*' || array[i-1][j]=='.')
                  {
                      i--;
                      hand='U';
                     
                   }
                 
                else if(array[i][j-1]=='*' || array[i][j-1]=='.')
                  {
                      j--;
                      hand='L';
                       
                  }
                else
                  {
                      i++;
                      hand='D';
                       		     
                  }
          }
	else 
           { 
	        array[i][j]='*';
                if(array[i][j-1]=='*' || array[i][j-1]=='.')
                  {
                      j--;
                      hand='L' ;
		       

                  }
                else if(array[i+1][j]=='*' || array[i+1][j]=='.')
                  {
                      i++;
                      hand='D';
		          
                  }
		else if(array[i][j+1]=='*' || array[i][j+1]=='.')
                  {
                      j++;
		      hand='R';
              
		  }

                else
                  {
                      i--;
                      hand='U';
		       

                  }
            }
           // checking point is there way to out from maze.
         if(i==sourceX && j== sourceY)
	   {
               printf("\n There is no any way to out from maze.\n ");
	       return false;
           	        
 	   }
	 // checking for destination point
	 if(i==destiX && j==destiY)
	 {
	    array[i][j]='*';
	    return true;
	 }
          
     }
  }

