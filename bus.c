#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct{
    int b;//bus number
    char R[30];//Bus route
    char T[30];//Bus time
    int N;//Number of seats
}bus;
typedef struct 
{
    char name[30];//Name of passanger
    int age;//age of passenger
    long int phno;//Phone number of passenger
}person;
person s[50];
//array of buses
bus buses[]={
    {1530,"Moodbidri to Mangalore","7.20 AM",30},{1531,"Moodbidri to Karkala","9.30 AM",30},{1532,"Moodbidri to bangalore ","4.20 AM",30}
};
//Passenger detailes and reducing the seat
void passenger(int n,int index){
    for(int i=0;i<n;i++)
    {
        printf("Enter passenger %d name:",i+1);
        scanf("%s",s[i].name);
        printf("Enter passenger %d age:",i+1);
        scanf("%d",&s[i].age);
        printf("Enter passenger %d phone number:",i+1);
        scanf("%ld",&s[i].phno);
        buses[index].N--;
    }

}
//book the bus
void book_seat(int n)
{
    int bus_number,i,Found=0;
    printf("Enter the bus number:");
    scanf("%d",&bus_number);
    for(i=0;i<3;i++)
    {
        if(buses[i].b==bus_number){
            Found=1;
            break;
        }
    }
    if(Found==0){
        printf("wrong bus");
        return ;
    }
    if (buses[i].N>0)
    {
        passenger(n,i);
        printf("Booking confirmed\n");
        printf("Bus no:%d\nBus route:%s\nTime:%s\n",buses[i].b,buses[i].R,buses[i].T);
        printf("Remaining seats:%d",buses[i].N);
    }
    else{
        printf("Seat not available");
    }
}
//Display the seat number
void seat(int n){
    int seat_numbers[30] = {0}; // Track assigned seat numbers
    srand(time(0)); // Seed random generator

    for (int i = 0; i < n; i++) {
        int num;
        do {
            num = (rand() % 30) + 1; // Seat number between 1 and 30
        } while (seat_numbers[num] == 1); // Ensure uniqueness

        seat_numbers[num] = 1; // Mark seat as taken
        printf("\nPassenger: %s\nAge: %d\nPhone: %ld\nSeat Number: %d\n",
            s[i].name, s[i].age, s[i].phno, num);
    
    }
}
//seat cancel
void cancel(int n){
    char name[30];
    for(int i=0;i<n;i++){
        printf("\nEnter the Name of the person which seat want to be cancelled:(enter N for skip)");
        scanf("%s",name);
        if(strcmp (name, s[i].name)==0)
        {
            buses[i].N++;
            printf("Remaining seats:%d",buses[i].N);
        }
        else{
            printf("Person not found");
        }

    }

}
//display bus details
void bus_detl(){
    printf("Bus details:\n");
    printf("Sino.\tBus number\tRoute\t\t\tTime\n");
    for(int i=0;i<3;i++)
    {
        printf("%d\t%d\t\t%s\t%s\n",i+1,buses[i].b,buses[i].R,buses[i].T);
    }
}
//bus_choice
void bus_choice(int choice,int n)
{
    if (choice==1)
    {
        int count=0;
        book_seat(n);
    }
    if (choice==2)
    {
        seat(n);
    }
    if (choice==3)
    {
        cancel(n);
    }
    if (choice<0 || choice>3)
    {
        printf("Invalid choice");
        exit(0);
    }
}
void main()
{
    int n,choice;
    bus_detl();
    printf("Enter the no of passengers");
    scanf("%d",&n);
    while(1){
    printf("\n\n RED BUS\n1.Bus Booking\n2.Seat Number\n3.Cancel\n");
    printf("Enter your choice");
    scanf("%d",&choice);
    bus_choice(choice,n);}
    
}
