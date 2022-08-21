               //DOUBLY LINKED LISTS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
  struct node *prev;
  int data;
  struct node *next;
};
struct node *head,*newnode,*temp;

void Create(){
   head=0;
   int choise=1;
   while(choise==1){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data-");
    scanf("%d",&newnode->data);
    newnode->prev=0;
    newnode->next=0;

    if(head==0){
        head=temp=newnode;
    }
    else{
       newnode->prev=temp;
       temp->next=newnode;
       temp=newnode;
    }

   printf("\nDo you want to continue?(0,1)-");
   scanf("%d",&choise);
   }
}
void Display(){
    printf("\n----------------->> LINKED LIST <<------------------------\t");
    temp=head;
    while(temp!=0){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}

void InsertBegin(){
     struct node *beginnode;
     beginnode=(struct node*)malloc(sizeof(struct node));
     printf("\nEnter the data to be inserted-");
     scanf("%d",&beginnode->data);
     beginnode->prev=0;
     beginnode->next=0;

     beginnode->next=head;
     head=beginnode;
}

void InsertEnd(){
     struct node *endnode;
     endnode=(struct node*)malloc(sizeof(struct node));
     printf("\nEnter the data to be inserted-");
     scanf("%d",&endnode->data);
     endnode->prev=0;
     endnode->next=0;

     temp=head;
     while(temp->next!=0){
        temp=temp->next;
     }
     endnode->prev=temp;
     temp->next=endnode;
}

void InsertGiven(){
    int i=1;
    int Pos;
    int count=1;

    struct node *givennode;
    givennode=(struct node*)malloc(sizeof(struct node));
    givennode->prev=0;
    givennode->next=0;

    //Count the existing elements
    temp=head;
    while(temp->next!=0){
        temp=temp->next;
        count++;

    }
     printf("\nEnter the position to  insert-");
     scanf("%d",&Pos);

     if(Pos>count){
        printf("\nLIST IS FULL.CAN'T INSERT");
     }
     else{
        temp=head;
        while(i<Pos-1){
            temp=temp->next;
            i++;
        }
        printf("\nEnter the value to be insert-");
        scanf("%d",&givennode->data);

        givennode->next=temp->next;
        temp->next->prev=givennode;

        givennode->prev=temp;
        temp->next=givennode;

     }
}

void DeleteBegin(){
    if(head==NULL){
        printf("\n------------------>> LIST IS EMPTY <<------------------------------");
    }
    else{
       temp=head;
       head=temp->next;
       temp->next->prev=0;

       free(temp);
    }
}

void DeleteEnd(){
    if(head==0){
        printf("\n------------------>> LIST IS EMPTY <<-------------------------------");
    }
    else{
      struct node *prevnode;
      temp=head;
      while(temp->next!=0){
        prevnode=temp;
        temp=temp->next;
      }
      prevnode->next=0;
      free(temp);
    }
}

void DeleteGiven(){
    if(head==0){
            printf("\n--------------->> LIST IS EMPTY <<------------------------------");
    }
    else{
        struct node *nextnode;
        int i=1;
        int Pos;

        printf("\nEnter the position to delete-");
        scanf("%d",&Pos);

        temp=head;
        while(i<Pos){
            nextnode=temp;
            temp=temp->next;
            i++;
        }
        temp->next->prev=nextnode;
        nextnode->next=temp->next;

        free(temp);
    }


}

void main(){
   printf("\n==========================================OPERATIONS OF DOUBLY LINKED LISTS=====================================\n\n");

   int option;
   bool condtion=true;

   while(condtion){
   printf("\n\n\t\t\t**************MAIN MENU*****************");
   printf("\n\t\t\t\t1.CREATE A LIST\n\t\t\t\t2.DISPLAY THE LIST\n\t\t\t\t3.INSERT AN ELEMENT\n\t\t\t\t4.DELETE AN ELEMENT\n\t\t\t\t5.EXIT");
   printf("\n\nEnter your option------->>");
   scanf("%d",&option);

   switch(option){
   case(1):
       Create();
       printf(" \n-------------------->> A DOUBLY LINKED LIST CREATED <<-----------------------");
       break;
   case(2):
       Display();
       break;
   case(3):
     printf("\n\t\t\tWHERE DO YOU WANT TO INSERT?");
     printf("\n\t\t\t\t1.Insert to the beginning\n\t\t\t\t2.Insert to the end\n\t\t\t\t3.Insert to a given location");
     int ch;
     printf("\nEnter your choice--------->>");
     scanf("%d",&ch);

     switch(ch){
      case(1):
         InsertBegin();
         printf("\n------------------>> SUCCESSFULLY INSERTED  <<--------------------");
         break;
      case(2):
        InsertEnd();
        printf("\n------------------>> SUCCESSFULLY INSERTED  <<--------------------");
        break;
      case(3):
        InsertGiven();
        printf("\n------------------>> SUCCESSFULLY INSERTED  <<--------------------");
        break;
      default:
        printf("\nInvalid input");
     }
      break;

   case(4):
     printf("\n\t\t\tHOW DO YOU WANT TO DELETE?");
     printf("\n\t\t\t\t1.Delete from the beginning\n\t\t\t\t2.Delete from the end\n\t\t\t\t3.Delete a node in given location");
     int c;
     printf("\nEnter your choice--------->>");
     scanf("%d",&c);

     switch(c){
      case(1):
         DeleteBegin();
         printf("\n------------------>> SUCCESSFULLY DELETED  <<--------------------");
         break;
      case(2):
        DeleteEnd();
        printf("\n------------------>> SUCCESSFULLY DELETED  <<--------------------");
        break;
      case(3):
        DeleteGiven();
        printf("\n------------------>> SUCCESSFULLY DELETED  <<--------------------");
        break;
      default:
        printf("\nInvalid input");
     }
      break;

    case(5):
        condtion=false;
        printf("\n\t\t\t=====================THANK YOU!!!  BYE=====================");
        break;
    default:
        printf("\n\t\t\t==========INVALID INPUT.TRY AGAIN===========================");

   }
  }
   return 0;
}

                      //CIRCULAR LINKED LISTS
 #include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
  int data;
  struct node *next;
};
struct node *head,*newnode,*temp;

void Create(){
   head=0;
   int choise=1;
   while(choise==1){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data-");
    scanf("%d",&newnode->data);
    newnode->next=0;

    if(head==0){
        head=temp=newnode;
    }
    else{
       temp->next=newnode;
       newnode->next=head;
       temp=newnode;
    }


   printf("\nDo you want to continue?(0,1)-");
   scanf("%d",&choise);
   }
}
void Display(){
    printf("\n----------------->> LINKED LIST <<------------------------\t");
    temp=head;
    printf("%d\t",temp->data);
    temp=temp->next;
    while(temp!=head){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}

void InsertBegin(){
     struct node *beginnode;
     beginnode=(struct node*)malloc(sizeof(struct node));
     printf("\nEnter the data to be inserted-");
     scanf("%d",&beginnode->data);
     beginnode->next=0;

     temp=head;
     while(temp->next!=head){
        temp=temp->next;
     }
     beginnode->next=head;
     head=beginnode;
     temp->next=beginnode;

}

void InsertEnd(){
     struct node *endnode;
     endnode=(struct node*)malloc(sizeof(struct node));
     printf("\nEnter the data to be inserted-");
     scanf("%d",&endnode->data);
     endnode->next=0;

     temp=head;
     while(temp->next!=head){
        temp=temp->next;
     }
     endnode->next=head;
     temp->next=endnode;
}

void InsertGiven(){
    int i=1;
    int Pos;
    int count=1;

    struct node *givennode;
    givennode=(struct node*)malloc(sizeof(struct node));
    givennode->next=0;

    //Count the existing elements
    temp=head;
    while(temp->next!=head){
        temp=temp->next;
        count++;

    }
     printf("\nEnter the position to  insert-");
     scanf("%d",&Pos);

     if(Pos>count){
        printf("\n--------------->> LIST IS FULL.CAN'T INSERT <<--------------------");
     }
     else{
        temp=head;
        while(i<Pos-1){
            temp=temp->next;
            i++;
        }
        printf("\nEnter the value to be insert-");
        scanf("%d",&givennode->data);

        givennode->next=temp->next;
        temp->next=givennode;

        printf("\n------------------>> SUCCESSFULLY INSERTED  <<--------------------");
     }
}

void DeleteBegin(){
    if(head==NULL){
        printf("\n------------------>> LIST IS EMPTY <<------------------------------");
    }
    else{
       struct node *begin;

       temp=head;
       while(temp->next!=head){
            temp=temp->next;
       }
       begin=head;
       head=begin->next;
       temp->next=head;

       free(begin);

       printf("\n------------------>> SUCCESSFULLY DELETED  <<--------------------");
    }
}

void DeleteEnd(){
    if(head==0){
        printf("\n------------------>> LIST IS EMPTY <<-------------------------------");
    }
    else{
      struct node *end;
      temp=head;
      while(temp->next!=head){
        end=temp;
        temp=temp->next;
      }
      end->next=head;
      free(temp);

      printf("\n------------------>> SUCCESSFULLY DELETED  <<--------------------");
    }
}

void DeleteGiven(){
    if(head==0){
            printf("\n--------------->> LIST IS EMPTY <<------------------------------");
    }
    else{
        struct node *nextnode;
        int i=1;
        int Pos;
        int count=1;

       //Count the existing elements
       temp=head;
       while(temp->next!=head){
         temp=temp->next;
         count++;

      }

        printf("\nEnter the position to delete-");
        scanf("%d",&Pos);

      if(Pos>count){
            printf("\n\t\t------------>> THERE IS NO SUCH POSITION <<-------------------");
        }
      else{
        temp=head;
        while(i<Pos){
            nextnode=temp;
            temp=temp->next;
            i++;
        }
        nextnode->next=temp->next;

        free(temp);

        printf("\n------------------>> SUCCESSFULLY DELETED  <<--------------------");
    }
  }



}

void main(){
   printf("\n==========================================OPERATIONS OF CIRCULAR LINKED LISTS=====================================\n\n");

   int option;
   bool condtion=true;

   while(condtion){
   printf("\n\n\t\t\t**************MAIN MENU*****************");
   printf("\n\t\t\t\t1.CREATE A LIST\n\t\t\t\t2.DISPLAY THE LIST\n\t\t\t\t3.INSERT AN ELEMENT\n\t\t\t\t4.DELETE AN ELEMENT\n\t\t\t\t5.EXIT");
   printf("\n\nEnter your option------->>");
   scanf("%d",&option);

   switch(option){
   case(1):
       Create();
       printf(" \n-------------------->> A CIRCULAR LINKED LIST CREATED <<-----------------------");
       break;
   case(2):
       Display();
       break;
   case(3):
     printf("\n\t\t\tWHERE DO YOU WANT TO INSERT?");
     printf("\n\t\t\t\t1.Insert to the beginning\n\t\t\t\t2.Insert to the end\n\t\t\t\t3.Insert to a given location");
     int ch;
     printf("\nEnter your choice--------->>");
     scanf("%d",&ch);

     switch(ch){
      case(1):
         InsertBegin();
         printf("\n------------------>> SUCCESSFULLY INSERTED  <<--------------------");
         break;
      case(2):
        InsertEnd();
        printf("\n------------------>> SUCCESSFULLY INSERTED  <<--------------------");
        break;
      case(3):
        InsertGiven();
        break;
      default:
        printf("\nInvalid input");
     }
      break;

    case(4):
     printf("\n\t\t\tHOW DO YOU WANT TO DELETE?");
     printf("\n\t\t\t\t1.Delete from the beginning\n\t\t\t\t2.Delete from the end\n\t\t\t\t3.Delete a node in given location");
     int c;
     printf("\nEnter your choice--------->>");
     scanf("%d",&c);

     switch(c){
      case(1):
         DeleteBegin();
         break;
      case(2):
        DeleteEnd();
        break;
      case(3):
        DeleteGiven();
        break;
      default:
        printf("\nInvalid input");
     }
      break;

    case(5):
        condtion=false;
        printf("\n\t\t\t=====================THANK YOU!!!  BYE=====================");
        break;
    default:
        printf("\n\t\t\t==========  INVALID INPUT TRY AGAIN   ===========================");

   }
  }

   return 0;
}

