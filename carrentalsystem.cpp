#include <iostream> //Header file to read input and print output to the screen
#include <iomanip>  //Header file providing parametric manipulators
#include <fstream>  //Header file for file operations
#include <conio.h>  //Header file common in c language used in this program for _getch() function
#include <unistd.h> //Header file that provides access to the POSIX operating system used this program for sleep() function
#include <string.h> //Header file for string operations
#include <vector>   //Header function for vector operations
#include <string>   //Header function for string operations
using namespace std;
//Brought you by Lalith Kumaran

//Customer Class
class Customer
{
public:
    //Variables in Customer Class
    char name[50];
    char password[10];

    void create_account(); //To create new user account
    void modify_user();    //To modify name or password in user account
};

void Customer::create_account()
{

    cout << "\n\n\n\t\t\t\t\t Enter Your Name : ";
    cin >> name;
    //Variables in create_account() function
    char pass1[10], pass2[10];
    bool valid;
    do
    {
        cout << "\n\n\n\t\t\t\t\t Create Your Password Max(10 characters) : ";
        cin >> pass1;
        cout << "\n\n\n\t\t\t\t\t ReEnter Your Password : ";
        cin >> pass2;
        valid = false;
        int res = strcmp(pass1, pass2); //For Checking whether password is valid or not

        if (res == 0)
        {
            valid = false;
        }
        else
        {
            valid = true;
        }

        if (valid)
        {

            system("cls");
            cout << "\n\n\n\t\tYour Password is Wrong" << endl;
            cout << "\n\n\n\t\tTry Again" << endl;
        }

    } while (valid);

    if (!valid)
    {
        for (int i = 0; i < sizeof(pass2) / sizeof(pass2[0]); i++)
        {
            password[i] = pass2[i];
        }

        cout << "\n\n\n\t\tYour Account is Created" << endl;
        sleep(1);
    }
}
void Customer::modify_user()
{
    cout << "\n\n\n\t\t\t\t\tRe-Enter User Name to Confirm";
    cout << "\n\n\n\t\t\t\t\tEnter User Name : ";
    cin >> name;
    cout << "\n\n\n\t\t\t\t\tEnter User Password : ";
    cin >> password;
}
//Class Journey inherited from class Customer
class Journey : public Customer
{
public:
    //Variables in Journey class
    int days = 0, rentalfee = 0;
    string billnumber = " #Cnb81353l";
    string customername;
    string carmodel;
    string carnumber;
    int choose_car();            //Function to select Car
    int duration();              //Function to enter duration
    string choose_destination(); // Function to enter destination
    void calculate();            //Function to calculate rent;
    void show_Rent();            //Function to Show rent for car
    string spacegiver(int i);    //Function to give space used in show rent function
    string addon(int i);         //Function to give '/' symbol used in show rent function
};
int Journey::choose_car()
{

    cout << "\n\n\n\t\t\t\tPlease Enter Your Name : ";
    cin >> customername;
    cout << endl;
    do
    {
        cout << "\t\t\t\tPlease Select a Car" << endl; //giving user a choice to select among three different models
        cout << "\t\t\t\tEnter 'A' for Tesla 20011." << endl;
        cout << "\t\t\t\tEnter 'B' for Hyundai 2015." << endl;
        cout << "\t\t\t\tEnter 'C' for Ford 2017." << endl;
        cout << endl;
        cout << "\t\t\t\tChoose a Car from the above options: ";
        cin >> carmodel;
        cout << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        if (carmodel == "A" || carmodel == "a")
        {
            system("cls");
            cout << "You have choosed Tesla model 2011" << endl;
            ifstream inA("A.txt"); //displaying details of model A
            char str[200];
            while (inA)
            {
                inA.getline(str, 200);
                if (inA)
                    cout << str << endl;
            }

            sleep(2);
        }
        if (carmodel == "B" || carmodel == "b")
        {
            system("cls");
            cout << "You have choosed Hyundai model 2015" << endl;
            ifstream inB("B.txt"); //displaying details of model B
            char str[200];
            while (inB)
            {
                inB.getline(str, 200);
                if (inB)
                    cout << str << endl;
            }
            sleep(2);
        }
        if (carmodel == "C" || carmodel == "c")
        {
            system("cls");
            cout << "You have Choosed Ford model 2017" << endl;
            ifstream inC("C.txt"); //displaying details of model C
            char str[200];
            while (inC)
            {
                inC.getline(str, 200);
                if (inC)
                    cout << str << endl;
            }
            sleep(2);
        }
        if (carmodel != "A" && carmodel != "B" && carmodel != "C" && carmodel != "a" && carmodel != "b" && carmodel != "c")

            cout << "Invalid Car Model. Please try again!" << endl;
        cout << endl;
        cout << endl;

    } while (carmodel != "A" && carmodel != "B" && carmodel != "C" && carmodel != "a" && carmodel != "b" && carmodel != "c");
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "\n\n\n\t\t\t\t\t Please Provide following information: " << endl;
    cout << "\n\n\n\t\t\t\t\t Please Enter license No. : ";
    cin >> carnumber;

    cout << "\n\n\n\t\t\t\t\t Number of days you wish to rent the car : ";
    cin >> days;
    while (days >= 50)
    {
        cout << "\n\n\n\t\t\t\t\tPlease enter days below or equal to 50 : ";
        cin >> days;
    }
}
string Journey::choose_destination()
{
    string i;
    cout << "\n\n\n\t\t\t\t\t Enter Your destination : ";
    cin >> i;
    return i;
}
int Journey::duration()
{
    int i;
    cout << "\n\n\n\t\t\t\t\t Enter how many days you need vehicle";
    cin >> i;
    return i;
}
void Journey::calculate()
{
    sleep(1);
    system("cls");
    cout << "\n\n\n"
         << endl;
    cout << "Calculating rent. Please wait......." << endl;
    sleep(2);
    if (carmodel == "A" || carmodel == "a")
        rentalfee = days * 56;
    if (carmodel == "B" || carmodel == "b")
        rentalfee = days * 60;
    if (carmodel == "C" || carmodel == "C")
        rentalfee = days * 75;
}
void Journey::show_Rent()
{   
    vector<string> g1;
    vector<int> g2;
    g1.push_back(customername);
    g1.push_back(carmodel);
    g1.push_back(billnumber);
    g2.push_back(days);
    g1.push_back(carnumber);
    g2.push_back(rentalfee);
    int u = g1[0].size();
    for (int i = 1; i < g1.size(); i++)
    {
        if (g1[i].size() > u)
        {
            u = g1[i].size();
        }
    }
    for (int i = 0; i < g2.size(); i++)
    {
        if (to_string(g2[i]).size() > u)
        {
            u = to_string(g2[i]).size();
        }
    }
    Journey j;
    
    cout << "\n\t\t                   Car Rental - Customer Invoice                  " << endl;
    cout << "\t\t        " << j.addon(u + 36) << endl;
    cout << "\t\t	| Bill No. :"
         << "---------------------|" << j.spacegiver(u - billnumber.size()) << billnumber
         << " |" << endl;
    cout << "\t\t	| Customer Name:"
         << "-----------------|" << j.spacegiver(u - customername.size()) << customername << " |" << endl;
    cout << "\t\t	| Car Model :"
         << "--------------------|" << j.spacegiver(u - carmodel.size()) << carmodel << " |" << endl;
    cout << "\t\t	| License No. :"
         << "------------------|" << j.spacegiver(u - (carnumber).size()) << carnumber << " |" << endl;
    cout << "\t\t	| Number of days :"
         << "---------------|" << j.spacegiver(u - to_string(days).size()) << days << " |" << endl;
    cout << "\t\t	| Your Rental Amount is :"
         << "--------|" << j.spacegiver(u - to_string(rentalfee).size()) << rentalfee << " |" << endl;
    cout << "\t\t	| Caution Money :"
         << "----------------|" << j.spacegiver(u - 1) << "0"
         << " |" << endl;
    cout << "\t\t	| Advanced :"
         << "---------------------|" << j.spacegiver(u - 1) << "0"
         << " |" << endl;
    cout << "\t\t	 ________________________________________________________" << endl;
    cout << "\n";
    cout << "\t\t	| Total Rental Amount is :"
         << "-------|" << j.spacegiver(u - to_string(rentalfee).size()) << rentalfee << " |" << endl;
    cout << "\t\t	 ________________________________________________________" << endl;
    cout << "\t\t	 # This is a computer generated invoce and it does not" << endl;
    cout << "\t\t	 require an authorised signture #" << endl;
    cout << " " << endl;
    cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
    cout << "\t\t	You are advised to pay up the amount before due date." << endl;
    cout << "\t\t	Otherwise penelty fee will be applied" << endl;
    cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
    int f;
    system("PAUSE");

    system("CLS");

    ifstream inf("thanks.txt"); //displaying thank you ASCII image text on output screen

    char str[300];

    while (inf)
    {
        inf.getline(str, 300);
        if (inf)
            cout << str << endl;
    }
    inf.close();
}
string Journey::spacegiver(int count)
{
    string h;
    for (int i = 0; i < count; i++)
    {
        h += " ";
    }
    //cout << h << 5 << endl;
    return h;
}
string Journey::addon(int n)
{
    string h;
    for (int i = 0; i < n; i++)
    {
        h += "/";
    }
    //cout << h << endl;
    return h;
}
class Admin
{ //Admin Class
public:
    int car_count();     //Function to find car count
    void delete_user();  //Function to delete user account
    void modify_user();  //Function to modify user account
    void display_user(); //Function to display all user accounts
};
int Admin::car_count()
{
    return 3;
}
void Admin::display_user()
{
    Customer ac;
    ifstream infile;
    infile.open("carentalsystem.dat", ios::binary); //Binary to store customer information
    if (!infile)
    {
        cout << "File Cannot Be Opened" << endl;
        return;
    }
    cout << "\n\n\n\t\t\t\t\tUsername"
         << "\t"
         << "Password" << endl;
    cout << endl;
    while (infile.read(reinterpret_cast<char *>(&ac), sizeof(Customer)))
    {

        cout << "\n\n\n\t\t\t\t\t" << ac.name << "\t" << ac.password << endl;
    }
    infile.close();
    cout << "\n\n"
         << endl;
    cout << endl;
    cout << "Press Enter to Continue  ---------";
}
void Admin::modify_user()
{
    bool found = false;
    string name;
    cout << "\n\n\n\t\t\t\t\tEnter the Name : ";
    cin >> name;
    cout << "\n\n";
    system("cls");
    cout << "\n\n\nPlease Wait------";
    sleep(2);

    Customer ac;
    fstream file;
    file.open("carentalsystem.dat", ios::binary | ios::in | ios::out);
    if (!file)
    {
        cout << "File could not be open!! press any key...";
        return;
    }
    while (!file.eof() && found == false)
    {
        file.read(reinterpret_cast<char *>(&ac), sizeof(Customer));
        if (ac.name == name)
        {
            ac.modify_user();
            int pos = (-1) * static_cast<int>(sizeof(Customer));
            file.seekp(pos, ios::cur);
            file.write(reinterpret_cast<char *>(&ac), sizeof(Customer));
            cout << "\n\n\tRECORD UPDATED";
            found = true;
        }
    }
    file.close();
    if (found == false)
    {
        cout << "\n\n\tRecord Not Found";
    }
}
void Admin::delete_user()
{
    Customer ac;
    ifstream infile;
    ofstream outfile;
    char date[10];
    string p;
    cout << "\n\n\n\t\t\t\t\t Enter user name : ";
    cin >> p;
    cout << "\n\n\n\t\t\t\t\t Enter user password : ";
    cin >> date;

    infile.open("carentalsystem.dat", ios::binary);
    if (!infile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    outfile.open("temp.dat", ios::binary);
    infile.seekg(0, ios::beg);
    while (infile.read(reinterpret_cast<char *>(&ac), sizeof(Customer)))
    {

        if (ac.name != p)
        {
            outfile.write(reinterpret_cast<char *>(&ac), sizeof(Customer));
        }
    }
    infile.close();
    outfile.close();
    remove("carentalsystem.dat");
    rename("temp.dat", "carentalsystem.dat");
    cout << "\n\n\tRECORD DELETED" << endl;
}
void create_user();                            //Function to create user account
bool check_user(string name, string password); //Function to check existing account
void admin();                                  //Function to display admin functions
void intro();                                  //Function to display Welcome text message;
void select_car();                             //Function to select car
void login()
{
    ifstream inl("welcome.txt"); //displaying thank you ASCII image text on output screen
    char str[300];
    while (inl)
    {
        inl.getline(str, 300);
        if (inl)
            cout << str << endl;
    }
    inl.close();
    cout << "\n\n\n"
         << endl;
    cout << "\n\n\n"
         << endl;
    cout << "\n\n\nPlease Wait---------------------" << endl;
}

int main()
{
    char choice1, choice2;
    bool run = true; //variable for looping inner do while loop
    string name;
    char password[10];
    login();
    sleep(2); //Stop running code for 2 seconds
    do
    {
        string pass;

        system("cls");
        //Printing menus to the user in the output Screen
        cout << "\n\n\n\t\t\t\t\t 01. USER";
        cout << "\n\n\n\t\t\t\t\t 02. ADMIN";
        cout << "\n\n\n\t\t\t\t\t 03. Quit";
        cout << "\n\n\n\t\t\t\t\t Please enter number based on your choice : ";
        cin >> choice1;
        system("cls");
        switch (choice1)
        {
        case '1':

            do
            {
                //Printing user menus in the output screen
                system("cls"); //Function to clear screen
                cout << "\n\n\n\t\t\t\t\t 01. Existing User";
                cout << "\n\n\n\t\t\t\t\t 02. New User";
                cout << "\n\n\n\t\t\t\t\t 03. Back";
                cout << "\n\n\n\t\t\t\t\t Please enter number based on your choice : ";
                cin >> choice2;
                system("cls");
                switch (choice2)
                {
                case '1':
                    bool pass;
                    cout << "\n\n\n\t\t\t\t\tEnter Your Name :";
                    cin >> name;
                    cout << "\n\n\n\t\t\t\t\tEnter Your Password :";
                    cin >> password;
                    system("cls");
                    pass = check_user(name, password);
                    if (pass)
                    {
                        select_car();
                    }
                    break;
                case '2':
                    create_user();
                    break;
                case '3':
                    run = false; //Breaking from the inner do while loop
                    break;
                default:
                    cout << "Please enter number from the given options ";
                    break;
                }
            } while (run);
            break;
        case '2':
            char ch;
            //Display login system for Admin
            cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t       CAR RENTAL SYSTEM \n\n";
            cout << "\t\t\t\t\t------------------------------";
            cout << "\n\t\t\t\t\t\t     LOGIN \n";
            cout << "\t\t\t\t\t------------------------------\n\n";
            cout << "\t\t\t\t\tEnter Password: ";
            ch = _getch(); //Function to get only ASCII enter by the user
            while (ch != 13)
            {
                pass.push_back(ch);
                cout << "*";
                ch = _getch();
            }
            if (pass == "admin")
            {
                cout << "\n\n\n\t\t\t\t\tAccess Granted! \n";
                system("PAUSE"); //Function to display press any key to continue
                admin();         //Calling admin Function

                system("CLS");
            }
            else
            {
                cout << "\n\n\t\t\t\t\t\t\tAccess Aborted...\n\t\t\t\t\t\t\tPlease Try Again\n\n";
                system("PAUSE");
                system("CLS");
            }
            break;
        case '3':
            break;
        default:
            cout << "Please enter number from the given options ";
            break;
        }

    } while (choice1 != '3');
    ifstream inf("thanks.txt");

    char str[300];

    while (inf)
    {
        inf.getline(str, 300);
        if (inf)
            cout << str << endl;
    }
    inf.close();
}

void create_user()
{
    Customer account;
    ofstream Outfile;
    Outfile.open("carentalsystem.dat", ios::binary | ios::app);
    account.create_account();
    Outfile.write(reinterpret_cast<char *>(&account), sizeof(Customer));
    Outfile.close();
}
bool check_user(string name, string password)
{
    Customer ac;
    bool flag = false;
    ifstream infile;
    infile.open("carentalsystem.dat", ios::binary);
    if (!infile)
    {
        cout << "\n\n\n\t\t\t\t\tFile cannot be opened" << endl;
        return false;
    }
    while (infile.read(reinterpret_cast<char *>(&ac), sizeof(Customer)))
    {
        if ((ac.name == name))
        {
            if (ac.password == password)
            {
                cout << "\n\n\n\t\t\t\t\tUser is Available" << endl;
                cout << "\n\n\nPlease Wait--------" << endl;
                sleep(2);
                system("cls");
                flag = true;
            }
        }
    }
    infile.close();
    if (flag == false)
    {

        cout << "\n\n\n\t\t\t\t\tAccount is not exist" << endl;
        sleep(2);
    }
    else
    {
        cout << "\n\n\n\t\t\t\t\tWelcome!!!!!!! " << endl;
        sleep(2);
        return true;
    }
}
void select_car()
{
    Journey j;
    j.choose_car();
    j.choose_destination();
    j.calculate();
    j.show_Rent();
    exit(0);
}
void admin()
{
    Admin lk;
    char ch;
    do
    { //Printing Admin menus in the output screen
        system("cls");
        cout << endl;
        cout << endl;
        cout << "\n\n\n\t\t\t\t\t01.Car Count" << endl;
        cout << "\n\n\n\t\t\t\t\t02.Display User" << endl;
        cout << "\n\n\n\t\t\t\t\t03.Modify User" << endl;
        cout << "\n\n\n\t\t\t\t\t04.Delete User" << endl;
        cout << "\n\n\n\t\t\t\t\t05.Back" << endl;
        cout << "\n\n\n\t\t\t\t\tPlease select number based on your choice : ";
        cin >> ch;
        system("cls");
        switch (ch)
        {
        case '1':
            cout << "\n\n\n\t\t\t\t\tTotal number of cars available " << lk.car_count();
            break;
        case '2':
            lk.display_user();
            break;
        case '3':
            lk.modify_user();
            break;
        case '4':
            lk.delete_user();
            break;
        case '5':
            return;

        default:
            break;
        }

        cin.ignore();
        cin.get();

    } while (ch != '5');
}
