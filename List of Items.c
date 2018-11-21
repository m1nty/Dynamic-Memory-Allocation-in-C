#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure defintion
typedef struct
{
    int id;
    char name[25];
    float price;
    int num;
}item;
//PROTOTYPE DEFINTIONS
item **create_items_list(int *noP);
void print_list(item **list, int number);
void remove_item(int idNo, item **list, int *noP);
finder(int idNo, item **list, int num);

int main()
{
    //by running folloing code we can see output neccessary to see if  code works
    int numofitems;//Stores the number of items we want to make
    item **thelist = create_items_list(&numofitems);//the list created is assgined the variable item ** the list.
    print_list(thelist, numofitems);//prints the list that we created
    deallocate_list(thelist,&numofitems);


}


item **create_items_list(int *noP)
{
    printf("Enter the number of items you wish to add");
    scanf("%d",noP);//stores the number entered because the address is passed in function
    item **list = malloc(sizeof(item*)*(*noP));//allocates memory for the list and its pointer elements
    for(int i=0 ; i<*noP ; i++)
    {
        list[i]= malloc(sizeof(item));//for each pointer element it allocates enough memory for the size of structure
        printf("enter the id name price and quanity for item %d\n",i+1);//this shows the entry seperated by spaces for the values and also counts item number
        scanf("%d",&list[i]->id);//all values stores in correspoinding structure member
        scanf("%s",&list[i]->name);
        scanf("%f",&list[i]->price);
        scanf("%d",&list[i]->num);


    }
    return list;//returns the list of pointers with members as structures with values

}

void print_list(item **list, int number)
{
    for(int z=0 ; z<number ; z++)//this function simply prints what we stored by accesing member of structures.
        printf("ID: %d; item name: %s; price: %.2f$; number of articles in this category: %d\n",list[z]->id, list[z]->name,list[z]->price,list[z]->num);

}
finder(int idNo, item **list, int num)//this finder functinon is useful and made to assist later in code
//it finds the element number in the array where an ID number exists. You give function ID list and size and it will tel you which element that is in list
{
    for (int i=0 ; i<num ; i++)
    {
        if (list[i]->id == idNo)
            return i;

    }
    return -1;//returns negative 1 if the ID you input is not found in list
}
void remove_item(int idNo, item **list, int *noP)
{

    int x =finder(idNo,list,*noP);
    if (x==-1)//as in function returns -1 if ID not found
        printf("ID Not Found\n");
    else
    {
        if(x==*noP-1)//this checks to see if the id wanted to be removed is the last element in list, if so simply deallcoate it without shifting anything.
        {
            printf("last item");
            free(list[x]);
            *noP--;//decrements the size as well

        }
        else//for all other entrys there must be shifting, so this is what this else loop does
        {
            for(int i=x ; i<*noP-1 ; i++)
            {
                list[i]->id = list[i+1]->id;//copys next members values to current
                list[i]->price= list[i+1]->price;
                list[i]->num = list[i+1]->num;
                for (int j = 0 ; j<25 ; j++)
                {
                    (list[i]->name)[j] = (list[i+1]->name)[j];//sting must be copied manually lettter by letter so for loop used.
                }

            }
            free(list[*noP -1]);//deallocates last list element
            *noP--;//decrements size
        }

    }
}

void deallocate_list(item** list, int *noP)
{
    for(int i = 0 ; i<*noP ; i++)//this function deallocates all memory
    {
        free(list[i]);

    }
    *noP = NULL;//also sets size to 0 since no more elements

}
