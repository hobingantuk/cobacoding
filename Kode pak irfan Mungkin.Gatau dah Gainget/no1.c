 #include <stdio.h>
 #include <stdlib.h>
 
 /* self-referential structure */                      
 struct listNode {                                     
    int data;                /* define data as char */
    struct listNode *nextPtr; /* listNode pointer */   
 }; /* end structure listNode */                       
   
 typedef struct listNode ListNode;
   typedef ListNode *ListNodePtr;
   
   /* prototypes */
   void insert( ListNodePtr *sPtr, char value );
   void sort ( ListNodePtr *sPtr );
   int isEmpty( ListNodePtr sPtr );
   void printList( ListNodePtr currentPtr );
   void instructions( void );
   
	int main(){
		
    ListNodePtr startPtr = NULL; /* initialize startPtr */
    int choice;                  /* user's choice */ 
    char item;                   /* char entered by user */
	instructions(); 				/* display the menu */
	printf( "" );
	scanf( "%d", &choice );	
  
  	/* loop while user does not choose 3 */
  
   while ( choice != 3 ) { 
     switch ( choice ) { 
        case 1:
           printf( "Enter a character: " );
           scanf( " %c", &item );
           insert( &startPtr, item );
           printList( startPtr );
           break;
           
        case 2:
           printf( "Sorting the list..\n " );
                sort( &startPtr );
                printList( startPtr );
                break;
                
     default:
        printf( "Invalid choice.\n\n" );
        instructions();
        break;
  
  } /* end switch */
        printf( "");
      scanf( "%d", &choice );
   } /* end while */

   printf( "End of run.\n" );
   
   return 0; /* indicates successful termination */

} /* end main */

/* display program instructions to user */
void instructions( void ){ 
   printf( "Enter your choice:\n"
          " 1 to insert an element into the list.\n"
          " 2 to sort the list.\n" 
          " 3 to end.\n\n" );
} /* end function instructions */

/* Insert a new value into the list in sorted order */
void insert( ListNodePtr *sPtr, char value ){ 
  ListNodePtr newPtr; /* pointer to new node */
  ListNodePtr previousPtr; /* pointer to previous node in list */
  ListNodePtr currentPtr; /* pointer to current node in list */
  newPtr = (ListNodePtr) malloc( sizeof( ListNode ) );

    if ( newPtr != NULL ) { /* is space available */
        newPtr->data = value;
        newPtr->nextPtr = NULL;
        previousPtr = NULL;
        currentPtr = *sPtr;

        /* if list is empty */
        if( *sPtr == NULL ) {
            *sPtr = newPtr;
        } /* end if */
        else {
            /* loop to find the end of the list */
            while ( currentPtr != NULL ) {
                previousPtr = currentPtr; /* walk to ... */
                currentPtr = currentPtr->nextPtr; /* ... next node */
            } /* end while */

            /* insert newPtr at end of list */
            previousPtr->nextPtr = newPtr;
        } /* end else */

    } /* end if */
    else {
        printf( " %c not inserted. No memory available.\n", value );
    } /* end else */
} /* end function insert */
     /* Print the list */ 
  void printList( ListNodePtr currentPtr )
  { 
  
     /* if list is empty */
     if ( currentPtr == NULL ) {
        printf( "List is empty.\n\n" );
     } /* end if */
     else { 
        printf( "The list is:\n" );
  
        /* while not the end of the list */
        while ( currentPtr != NULL ) { 
           printf( "%c --> ", currentPtr->data );
           currentPtr = currentPtr->nextPtr;    
        } /* end while */
  
        printf( "NULL\n\n" );
     } /* end else */
  
  } /* end function printList */ 
  
void sort ( ListNodePtr *sPtr ){
	
	ListNodePtr srtPtr;
	int srtVal;
	ListNodePtr crrntPtr;
	
	srtPtr = *sPtr;
	
	while (srtPtr->nextPtr){
		srtVal = srtPtr->data;
		crrntPtr = srtPtr->nextPtr;
		
		while (crrntPtr != NULL){
			if(crrntPtr->data < srtVal){
			srtPtr->data = crrntPtr->data;
			crrntPtr->data = srtVal;
			srtVal = srtPtr->data;
			}
			crrntPtr=crrntPtr->nextPtr;
		}
		srtPtr =srtPtr->nextPtr;	
	}
}
  
  
