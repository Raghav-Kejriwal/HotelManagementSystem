#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <windows.h>
#include <cmath>

using namespace std;

typedef struct date
{
    int day;
    int month;
    int year;
}date;

void menu_box();
void clearScreen();
void add_room();
void makeReservation();
void displayRooms();
void displayReservations();
void check_in();
void check_out();
void room_details();
void hotel_amenities();
void p_bill();

class Booking {
    public:
        char name[50];
        long long int mobile;
        date *in_date;
        date *out_date;
        //int ct_days;


        int check_leap_year(int year)
        {
            if (year % 400 == 0)
                return 1;

            if (year % 100 == 0)
                return 0;

            if (year % 4 == 0)
                return 1;
            return 0;
        }


        void get_date(date *ptr)
        {
            int days[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            int days_in_leap_year[] = {-1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

            cout << "\tEnter year (YYYY): ";
            cin >> ptr->year;
            while (ptr->year < 1980) {
                cout << "\tPlease enter a valid year (YYYY > 1980): ";
                cin >> ptr->year;
            }

            cout << "\tEnter month (MM): ";
            cin >> ptr->month;
            while (ptr->month < 1 || ptr->month > 12) {
                cout << "\tPlease enter a valid month (1 <= MM <= 12): ";
                cin >> ptr->month;
                }

            if (check_leap_year(ptr->year) == 1)
            {
                cout << "\tEnter day (DD): ";
                cin >> ptr->day;
                while (ptr->day < 1 || ptr->day > days_in_leap_year[ptr->month])
                {
                    cout << "\tPlease enter a valid day (DD): ";
                    cin >> ptr->day;
                }
            }
            else
            {
                cout << "\tEnter day (DD): ";
                cin >> ptr->day;
                while (ptr->day < 1 || ptr->day > days[ptr->month])
                {
                    cout << "\tPlease enter a valid day (DD): ";
                    cin >> ptr->day;
                }
            }
        }


        int get_data_in()
        {
            cout << "WELCOME TO OUR HOTEL!" << endl;
            cout << endl ;
            cout << "Please Enter Details" << endl;
            cout << endl ;
            cout << "Please enter Name name: ";
            cin >> name;

            cout << "Please enter your mobile number: ";
            cin >> mobile;
            while (mobile < 1000000000 || mobile > 9999999999) {
                cout << "Please enter a valid mobile number: ";
                cin >> mobile;
            }

            in_date = (date*)malloc(sizeof(date));


            cout << "Please enter your check in date: " << endl;
            get_date(in_date);

            return 1;
        }

        void get_data_out()
        {
            out_date = (date*)malloc(sizeof(date));
            cout << "Please enter your check out date: " << endl;
            get_date(out_date);
        }


        void display_date()
        {
            cout << "Check in: " << in_date->day << "/" << in_date->month << "/" << in_date->year << endl;
            cout << "Check out: " << out_date->day << "/" << out_date->month << "/" << out_date->year << endl;
            cout << "Duration of stay: " << duration() << endl;
        }


        int countLeapYearDays(date *ptr)
        {
            int years = ptr->year;
            if (ptr->month <= 2)
                years--;
            return ((years / 4) - (years / 100) + (years / 400));
        }


        int duration()
        {
            int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

            long int n1 = in_date->year * 365 + in_date->day;
            long int n2 = out_date->year * 365 + out_date->day;

            for (int i=0; i < in_date->month - 1; i++)
                n1 += days[i];
            n1 += countLeapYearDays(in_date);

            for (int i=0; i < out_date->month - 1; i++)
                n2 += days[i];
            n2 += countLeapYearDays(out_date);

            return (n2 - n1);
        }

        //(ct_days)=(duration());

};

class Rooms {
public:
    int single_r,si_r;
    int double_r,d_r;
    int queen_r,q_r;
    int king_r,k_r;
    int suite_r,su_r;
    int villa_r,v_r;
    int r_flag=0;

    Rooms() {
        single_r = 15;si_r=0;
        double_r = 30;d_r=0;
        queen_r = 30;q_r=0;
        king_r = 20;k_r=0;
        suite_r = 10;su_r;
        villa_r = 5;v_r;
    }

    void select_a_room() {
        int choice;
        clearScreen();
        cout << "Please select a room of your choice" << endl;
        cout << "1. Single Room" << endl;
        cout << "2. Double Room" << endl;
        cout << "3. Queen Room" << endl;
        cout << "4. King Room" << endl;
        cout << "5. Suite" << endl;
        cout << "6. Villa" << endl;
        cin >> choice;
        if (choice == 1) {
            if (single_r == 0) {
                cout << "Sorry, no single rooms are available" << endl;
                select_a_room();
            }
            else {
                single_r--;
                si_r++;
                r_flag=1;
                cout << "Single Room selected" << endl;
            }
        }
        else if (choice == 2) {
            if (double_r == 0) {
                cout << "Sorry, no double rooms are available" << endl;
                select_a_room();
            }
            else {
                double_r--;
                d_r++;
                r_flag=1;
                cout << "Double Room selected" << endl;
            }
        }
        else if (choice == 3) {
            if (queen_r == 0) {
                cout << "Sorry, no queen rooms are available" << endl;
                select_a_room();
            }
            else {
                queen_r--;
                q_r++;
                r_flag=1;
                cout << "Queen Room selected" << endl;
            }
        }
        else if (choice == 4) {
            if (king_r == 0) {
                cout << "Sorry, no king rooms are available" << endl;
                select_a_room();
            }
            else {
                king_r--;
                k_r++;
                r_flag=1;
                cout << "King Room selected" << endl;
            }
        }
        else if (choice == 5) {
            if (suite_r == 0) {
                cout << "Sorry, no suites are available" << endl;
                select_a_room();
            }
            else {
                suite_r--;
                su_r++;
                r_flag=1;
                cout << "Suite selected" << endl;
            }
        }
        else if (choice == 6) {
            if (villa_r == 0) {
                cout << "Sorry, no villas are available" << endl;
                select_a_room();
            }
            else {
                villa_r--;
                v_r++;
                r_flag=1;
                cout << "Villa selected" << endl;
            }
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
            select_a_room();
        }
    }
};

class roomdetails : public Rooms{
public:
    void singleroom(){
        cout<<"1 Person per room"<<endl;
        cout<<"Size: 6 m2 (64 sq ft)"<<endl;
        cout<<"Bathroom with shower"<<endl;
        cout<<"Flat Screen Televisions"<<endl;
        cout<<"Hair Dryer"<<endl;
        cout<<"1000 Rs per Night"<<endl;
        cout<<"No. of rooms left "<<single_r<<endl;
        Sleep(9000);
    }
    void doubleroom(){
        cout<<"Accommodates: 2 persons"<<endl;
        cout<<"Central heating"<<endl;
        cout<<"Direct Dial Telephone"<<endl;
        cout<<"Flat Screen Televisions"<<endl;
        cout<<"Tea & Coffee"<<endl;
        cout<<"1500 Rs Per Night"<<endl;
        cout<<"No. of rooms left "<<double_r<<endl;
        Sleep(9000);
    }
    void queenroom(){
        cout<<"Pillow-top mattress"<<endl;
        cout<<"Luxury linens"<<endl;
        cout<<"Black-out drapes/curtains"<<endl;
        cout<<"Full bath, complimentary toiletries, and plush towel"<<endl;
        cout<<"50” HDTV with cable channels, work desk with a lamp"<<endl;
        cout<<"2000 Rs Per Night"<<endl;
        cout<<"No. of rooms left "<<queen_r<<endl;
        Sleep(9000);
    }
    void kingroom(){
        cout<<"Bottled Mineral Water"<<endl;
        cout<<"Free Mini Bar"<<endl;
        cout<<"Writing Desk & Chair"<<endl;
        cout<<"Extra 1-person bed available on demand"<<endl;
        cout<<"24x7 restaurant service available on phone"<<endl;
        cout<<"2500 Rs Per Night"<<endl;
        cout<<"No. of rooms left "<<king_r<<endl;
        Sleep(9000);
    }
    void suite(){
        cout<<"4-person capacity"<<endl;
        cout<<"2 rooms and 1 living room"<<endl;
        cout<<"Personalized food available on demand"<<endl;
        cout<<"Beach View"<<endl;
        cout<<"Fully equipped Bar"<<endl;
        cout<<"3500 Rs Per Night"<<endl;
        cout<<"No. of rooms left "<<suite_r<<endl;
        Sleep(9000);
    }
    void villa(){
        cout<<"Private Chef"<<endl;
        cout<<"Free Chocolates and Savories"<<endl;
        cout<<"Fully equipped bathtub"<<endl;
        cout<<"8-person capacity"<<endl;
        cout<<"4 rooms and 1 living room"<<endl;
        cout<<"5000 Rs Per Night"<<endl;
        cout<<"No. of rooms left "<<villa_r<<endl;
        Sleep(9000);
    }
};

class amenities
{
    public:
    int choose;
    int total;
      int br=0;
      int lu=0;
      int di=0;
      int pick=0;
      int drop=0;
      int gym=0;
      int spa=0;
      int swim=0;
      int ls=0;
      int cr=0;
      int tg=0;
      int gp=0;
    void menu(){

        cout<<"These are the services provided by our hotel"<<endl;
        cout<<"1.Breakfast (Price:Rs 500)"<<endl;
        cout<<"2.Lunch (Price:Rs 750)"<<endl;
        cout<<"3.Dinner (Price:Rs 1000)"<<endl;
        cout<<"4.Pickup from airport (Price:Rs 600)"<<endl;
        cout<<"5.Drop at airport (Price:Rs 600)"<<endl;
        cout<<"6.Gym (Price:Rs 450)"<<endl;
        cout<<"7.Spa (Price:Rs 900)"<<endl;
        cout<<"8.Swimming pool (Price:Rs 450)"<<endl;
        cout<<"9.Laundary services (Price:Rs 250)"<<endl;
        cout<<"10.Car rental (Price:Rs 550)"<<endl;
        cout<<"11.Tour guide (Price:Rs 1500)"<<endl;
        cout<<"12.Gaming parlor (Price:Rs 450)"<<endl;
    }
    int total_bill(){

        do{
            clearScreen();
          menu();
          cout<<"Which of the above mentioned services would you like to choose(press 13 for exit)"<<endl;
          cin>>choose;
          switch(choose)
          {
            case 1:
                br+=1;
                break;
            case 2:
                lu+=1;
                break;
            case 3:
                di+=1;
                break;
            case 4:
                pick+=1;
                break;
            case 5:
                drop+=1;
                break;
            case 6:
                gym+=1;
                break;
            case 7:
                spa+=1;
                break;
            case 8:
                swim+=1;
                break;
            case 9:
                ls+=1;
                break;
            case 10:
                cr+=1;
                break;
            case 11:
                tg+=1;
                break;
            case 12:
                gp+=1;
                break;
            case 13:
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
          }
        }while(choose!=13);
      total=(lu*750)+(br*500)+(di*1000)+(pick*600)+(drop*600)+(swim*450)+(spa*900)+(ls*250)+(tg*1500)+(gp*450)+(cr*550)+(gym*450);
      return total;

    }
};

class bill:public amenities,public roomdetails,public Booking
{
public:
    void print_bill()
    {
        int gt=0;
      //  if(r_flag==1)
       // {
        cout << "+--------------------------------+" << endl;
        cout << "|              BILL              |" << endl;
        cout << "+--------------------------------+" << endl;

       // if(ct_days>0)
       // {
        if(si_r!=0)
        {
            cout << "| Single Room              : " <<(si_r*1000*duration()) << "    |" << endl;
            cout << "+--------------------------------+" << endl;
        }

        if(d_r!=0)
        {
            cout << "| Double Room              : " <<(d_r*1500*duration()) << "    |" << endl;
            cout << "+--------------------------------+" << endl;
        }

       if(q_r!=0)
        {
            cout << "| Queen Room           : " <<(q_r*2000*duration()) << "    |" << endl;
            cout << "+--------------------------------+" << endl;
        }

        if(k_r!=0)
        {
            cout << "| King Room              : " <<(k_r*2500*duration()) << "    |" << endl;
            cout << "+--------------------------------+" << endl;
        }

       if(su_r!=0)
        {
            cout << "| Suite              : " <<(su_r*3500*duration()) << "    |" << endl;
            cout << "+--------------------------------+" << endl;
        }

       if(v_r!=0)
        {
            cout << "| Villa                  : " <<(v_r*5000*duration()) << "    |" << endl;
            cout << "+--------------------------------+" << endl;
        }
      //  }

        if(br!=0)
        {
            cout << "| Breakfast             : " <<(br*500) << "    |" << endl;
            cout << "+--------------------------------+" << endl;
        }
        if(lu!=0)
        {
            cout << "| Lunch                 : " <<(lu*750) << "    |" << endl;
            cout << "+--------------------------------+" << endl;
        }
        if(di!=0)
        {
            cout << "| Dinner                : " <<(di*1000) << "   |" << endl;
            cout << "+--------------------------------+" << endl;
        }
        if(spa!=0)
        {
            cout << "| Spa                   : " <<(spa*900) << "    |" << endl;
            cout << "+--------------------------------+" << endl;
        }
        if(ls!=0)
        {
            cout << "| Laundry Service       : " <<(ls*250) << "    |" << endl;
            cout << "+--------------------------------+" << endl;
        }
        if(tg!=0)
        {
            cout << "| Tour Guide            : " <<(tg*1500) << "   |" << endl;
            cout << "+--------------------------------+" << endl;
        }
        if(gp!=0)
        {
            cout << "| Gaming Parlour        : " <<(gp*450) << "    |" << endl;
            cout << "+--------------------------------+" << endl;
        }
        if(gym!=0)
        {
            cout << "| Gym                   : " <<(gym*450) << "    |" << endl;
            cout << "+--------------------------------+" << endl;
        }
        if(swim!=0)
        {
            cout << "| Swimming Pool         : " <<(swim*450) << "    |" << endl;
            cout << "+--------------------------------+" << endl;
        }
        if(cr!=0)
        {
            cout << "| Car Rent              : " <<(cr*550) << "    |" << endl;
            cout << "+--------------------------------+" << endl;
        }
        if(pick!=0)
        {
            cout << "| Airport Pickup        : " <<(pick*600) << "    |" << endl;
            cout << "+--------------------------------+" << endl;
        }
        if(drop!=0)
        {
            cout << "| Airport Drop          : " <<(drop*600) << "    |" << endl;
            cout << "+--------------------------------+" << endl;
        }

        gt=(total)+((si_r*1000)+(d_r*1500)+(q_r*2000)+(k_r*2500)+(su_r*3500)+(v_r*5000))*duration();
        float gst=(28.0/1000)*gt;
        float (total_gst)=gt+gst;

        if(gt>=0)
        {
            cout << "| GST                 : " <<(gst) << "    |" << endl;
            cout << "+--------------------------------+" << endl;
            cout << "| Total              : " <<(total_gst) << "    |" << endl;
            cout << "+--------------------------------+" << endl;
        }


        Sleep(5000);
      //  }
        //else{
        //    printf("No Items")
       // }
    }
};
//amenities a;
//Booking guest;
//roomdetails hotel;
bill guest;
int main()
{

    int choice;
    while(true)
    {
        menu_box();
        cout << "Enter your choice : " ;
        cin>> choice;

        clearScreen();
        switch (choice)
        {
            case 1:
                check_in();
                break;
            case 2:
                check_out();
                break;
            case 3:
                room_details();
                break;
            case 4:
                hotel_amenities();
                break;
            case 5:
                p_bill();
                break;
            case 6:
                cout << "Exiting program" ;
                for(int i=0;i<15;i++)
                {
                    clearScreen();
                    cout << "Exiting program" ;
                    Sleep(100);
                    cout << "..." ;
                    Sleep(100);
                    clearScreen();
                    cout << "Exiting program" ;
                }
                cout << endl;
                clearScreen();
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }



    return 0;
}


void menu_box()
{
    time_t currentTime = time(nullptr);
    char* dateString = ctime(&currentTime);
    cout << dateString;
    cout << endl ;

    cout << "+---------------------------------------------+" << endl;
    cout << "|                    WELCOME                  |" << endl;
    cout << "|                THE CONTINENTAL              |" << endl;
    cout << "+-----------------------+---------------------+" << endl;
    cout << "|    1. Check In        |     2. Check Out    |" << endl;
    cout << "+-----------------------+---------------------+" << endl;
    cout << "+-----------------------+---------------------+" << endl;
    cout << "|    3. Room Details    |     4. Amenities    |" << endl;
    cout << "+-----------------------+---------------------+" << endl;
    cout << "+-----------------------+---------------------+" << endl;
    cout << "|    5. Bill            |     6. Exit         |" << endl;
    cout << "+-----------------------+---------------------+" << endl;

    cout << endl ;

}

void clearScreen() {
    #ifdef _WIN32
        system ("cls");
    #else
        system("clear");
    #endif
}

void check_in()
{
    if (guest.get_data_in()) {
        guest.select_a_room();
        Sleep(9000);
        clearScreen();
    }

}
void check_out()
{
        guest.get_data_out();
        int duration = guest.duration();
        cout << "The total duration of the stay is: " << duration << " days" << endl;
        Sleep(5000);
        clearScreen();
}
void room_details()
{
    int choice1=0;
    while(choice1!=9){
    clearScreen();
    cout << "Please select a room of your choice" << endl;
    cout << "1. Single Room" << endl;
    cout << "2. Double Room" << endl;
    cout << "3. Queen Room" << endl;
    cout << "4. King Room" << endl;
    cout << "5. Suite" << endl;
    cout << "6. Villa" << endl;
    cout << "Press 9 to exit this menu" << endl;

    cin >> choice1;
    clearScreen();
    switch (choice1)
    {
    case 1:
        guest.singleroom();
        break;
    case 2:
        guest.doubleroom();
        break;
    case 3:
        guest.queenroom();
        break;
    case 4:
        guest.kingroom();
        break;
    case 5:
        guest.suite();
        break;
    case 6:
        guest.villa();
        break;
    case 9:
        break;
    default:
        cout<<"Enter a valid choice"<<endl;
        break;
    }
    }
}
void hotel_amenities()
{
    int d;
    d=guest.total_bill();
    clearScreen();
    cout<<"Bill: " << d<<endl;
    Sleep(4000);
    clearScreen();
}

void p_bill()
{
    guest.print_bill();
    clearScreen();
}
