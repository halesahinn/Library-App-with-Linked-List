///////////////////////////////////////////////////////////////////////////////////***************************************************************************************************
//
///////////////////////                                               HALE ÞAHÝN                                                                            *************************                              ****************
//////////////////////                                                            150116841                                                                 *************************                             ****************
//////////////////////                                                                       HOMEWORK 3                                                     *************************
//
//////////////////////////////////////////////////////////////////////////////////*****************************************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>




struct myList{
	int id;
	char bookName[50];
	char authorName[50];
	struct myList * next;
};

typedef struct myList myLL;
// add new value to last of LL
// Assumption: There is a head node. (head node is not null)
void printList(myLL * head) {
    myLL * currentNode = head;

    while (currentNode != NULL) {
        printf("%d %s %s\n", currentNode->id, currentNode->bookName, currentNode->authorName);
        currentNode = currentNode->next;
    }
}
void addToLL(myLL *head,int id1, char bookName1[50], char authorName1[50]){
	myLL * currentNode = head;

	while(currentNode -> next != NULL)
		currentNode = currentNode -> next;

	// here, currentNode holds last node's address

	myLL * newlyAdded = malloc(sizeof(myLL));
	newlyAdded -> id = id1;
	strcpy(bookName1, newlyAdded -> bookName);
	strcpy(authorName1, newlyAdded -> authorName);
	newlyAdded -> next = NULL;
	currentNode -> next = newlyAdded;
}

// remove last node of LL
// Assumption: LinkedList has at least 3 nodes!
void removeLast(myLL *head){
	myLL * currentNode = head;

	while(currentNode -> next -> next != NULL)
		currentNode = currentNode -> next;

	free(currentNode -> next);
	currentNode -> next = NULL;
}

// add new node as first node to LL
void addToFirst(myLL * head, int id2, char bookName2[50], char authorName2[50]){

	myLL * newNode = malloc(sizeof(myLL));
	newNode -> id = id2;
	strcpy(bookName2, newNode -> bookName);
	strcpy(authorName2, newNode -> authorName);
	newNode -> next = head;
	head = newNode;
}


// Assumption1: position < length of LL
// Assumption2: LL has at least 1 node
void addToIndex(int position, myLL * head, int id3, char bookName3[50], char authorName3[50]){

	myLL * newNode = malloc(sizeof(myLL));
    newNode -> id = id3;
	strcpy(bookName3, newNode -> bookName);
	strcpy(authorName3, newNode -> authorName);
	myLL * currentNode = head;
	int counter = 0;
	for(; counter < position; counter++)
		currentNode = currentNode -> next;

	newNode -> next = currentNode -> next;
	currentNode -> next = newNode;
}


void updateNodeId(myLL * head, int position, int id4){
	myLL * currentNode = head;
	int counter = 0;
	for(; counter < position; counter++)
		currentNode = currentNode -> next;
	// currentNode is where i want
	currentNode -> id = id4;
}
void updateNodeBook(myLL * head, int position, char bookName4[50]){
	myLL * currentNode = head;
	int counter = 0;
	for(; counter < position; counter++)
		currentNode = currentNode -> next;
	// currentNode is where i want
	strcpy(bookName4, currentNode -> bookName);
}
void updateNodeAuthor(myLL * head, int position, char authorName4[50]){
    printf("****");
	myLL * currentNode = head;
	int counter = 0;
	for(; counter < position; counter++)
		currentNode = currentNode -> next;
	// currentNode is where i want
	strcpy(authorName4, currentNode -> authorName);
}



void removeByIndex(myLL * head, int index){
	myLL * currentNode = head;
	int counter = 0;
	for(;counter <= index - 1 ; counter++){
		currentNode = currentNode -> next;
	}


	myLL * willDeleted = currentNode -> next;
	currentNode -> next = willDeleted -> next;
	free(willDeleted);
}


int length(char s[1000]){
   char c;
    for(c = 0; s[c] != '\0'; ++c);         //find the length of a string to specify place of name,surname,address
    return c;
}
int length2(long int m){
   int result = 0;
    while( m != 0 ) {                    //length of a number to specify place of it
       m /= 10;
       result++;
    }
    return result;

}






////////////////////////////////////////////////////   MAIN    **********************************************************************************************************




int main(){



	printf("LIBRARY PROGRAM\n1 - List all books\n2 - Update a book\n3 - Create a new book\n4 - Delete a book\n5 - Sort all books according to id");
	printf("\n6 - Sort all books according to book name\n7 - Sort all books according to author name\n8 - Exit\nEnter your choice :");

        int a, i, k, m, j, b;
		char s[100];
		FILE * file;                                    //declaring and some initializing
		int datacntr = 0;
        typedef struct myList myLL;
		myLL * myLinkedList = malloc(sizeof(myLL));
		myLinkedList -> id = 1;
		strcpy("asdfg", myLinkedList -> bookName);
		strcpy("asgfggg", myLinkedList -> authorName);
        char x[1000];
        char y[1000];
        char z[1000];
        char t[1000];
        FILE * temp;



         file = fopen("records.txt","r");
		    		if(file==NULL){
		              file =  fopen("records.txt","w");                        //if there is no file, create new, and prompt the user that it is created now
		              fprintf(file, "Id Book Name   Author Name\n");
                      fprintf(file, "== ==========  ===========");
                      printf("\nCouldn't find the file, created a new one, and it is empty now.\n");
                      fclose(file);
                      main();
	                }
         fclose(file);
		if(scanf("%d", &a) == 1){                    //error check for getting choice from user


	      if((a<9)&&(a>0)){            //if it is on the list continue,otherwise prompt the user

		    switch(a)
		    {

		    	case 1 :
		    	          printf("Id Book Name   Author Name\n");
                          printf("== ==========  ===========\n");
                          printList(myLinkedList);
		    	break;




////////////////////////////////////////////////////////////////////******************************************************************************************************************
////////////////////////////////////////////////////////////////////*****************************************************************************************************************



		    	case 2 :

		    		printf("Please enter the record number of the person you want to update : ");

		    		if(scanf("%d",&k)==1){               //error check


                    fclose(file);

		    		printf("1 - Update book name\n2 - Update author name\nEnter your choice :");
		    		if(scanf("%d",&m)==1){



		    		if(m==1){
		    			printf("Enter the new book name : ");
		    			if(scanf("%s", z)==1){
                        updateNodeBook(myLinkedList, k, z);
                      }else{
                    printf("Please write an integer value.");
                    return EXIT_FAILURE;
		    		}


					}else if(m==2){
						printf("Enter the new author name : ");
						if(scanf("%s", z)==1){

				        updateNodeAuthor(myLinkedList, k, z);
                         }else{
                    printf("Please write an integer value.");
                    return EXIT_FAILURE;
		    		}


					}else{
						printf("Please check your choice!");
					}
					}else{
                    printf("Please write an integer value.");
                    return EXIT_FAILURE;
		    		}
		    		}else{
                    printf("Please write an integer value.");
                    return EXIT_FAILURE;
		    		}

		    	break;







//////////////////////////////////////////////////////////*************************************************************************************************************************
/////////////////////////////////////////////////////////*************************************************************************************************************************




		    	case 3 :



                    printf("Enter the record number to create a new record : ");
		    	    if(scanf("%d", &k)==1){


		    	    printf("Enter the book name : ");
		    	    if(scanf("%s", &z)==1){
                                                                 //ask the info that required the next record
		    	    printf("Enter the author name : ");
		    	    if(scanf("%s", &t)==1){


                    myLL * newNode = malloc(sizeof(myLL));

                    addToLL(newNode, k, z, t);



                    }else{
                    	printf("Please enter string with no space.");
                    	return EXIT_FAILURE;
					}
					}else{
                    	printf("Please enter string with no space.");
                    	return EXIT_FAILURE;
					}

                    }else{
                    	printf("Please write an integer value.");
                    	return EXIT_FAILURE;
					}


		        break;


////////////////////////////////////////////////////////////////////////////*****************************************************************************************************
///////////////////////////////////////////////////////////////////////////*******************************************************************************************************




		    	case 4 :
                    printf("Enter the record number to delete : ");
                    if(scanf("%d", &k)==1){                //error check




					}else{
						printf("Please write an integer value.");
						return EXIT_FAILURE;
					}


                 printf("Deleted.\n");


		    	break;
		    	case 5 :
		    	break;
		    	case 6 :
		    	break;
		    	case 7 :
		    	break;
		    	case 8 :
		    		printf("Bye..");
		    		exit(0);
		    	break;

			}





      }else{
      	printf("Please choose an option in between 1-5.\n");
	  }


     }else{
     	printf("Please write an integer value!");
     	return EXIT_FAILURE;
	 }


fclose(file);

//call the menu again
main();


return 0;

}

