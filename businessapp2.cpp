#include <iostream>
#include <windows.h>
using namespace std;
void gotoxy(int, int);
void loginop();
void header();
void patient(int);
void patientOp();
string patientInt();
string Hpatient();
bool userfind(string, string);
int addpatient(string, string);
string doctor(string);
string appointment(string, string);
string Hdoctor();
string Happointment();
string doctorinfo();
string doctorinfo2();
int adddoctor(string, string);
void docappointment();
void doctorOp();
bool docfind(string, string);
bool docchoice(int, string);
float billing();
string billCal();
string Hadmin();
string doctorInt();
void adminOp();
int updatestockdisplay(int);
int updatestock();
int stock();
int viewp();
int viewd();
bool adminfind(string, string);
bool validum(string);
bool validpk(string);

string stockH[100] = {"1.== Medical Supplies ==", "2.== Medications ==", "3.== Medical Equipment==", "4.== Laboratory Supplies ==", "5.== Administrative Supplies =="};
string stocks1[100] = {"Surgical Masks", "Gloves", "Syringes and Needles", "IV Bags and Tubes", "Bandages and Dressings", "Antiseptic Solutions", "Catheters"};
int q1[100] = {100, 140, 456, 23, 26, 44, 34};
string stocks2[100] = {"Antibiotics", "Pain Relievers", "Anesthetics ", "Intravenous Fluids", "Anticoagulants", "Antiseptic Creams", "Insulin", "Vitamins and Supplements", "vaccines", "Sedatives"};
int q2[100] = {89, 92, 78, 84, 91, 76, 95, 45, 56, 65};
string stocks3[100] = {"Surgical Instruments", "ECG Machines", "X-Ray Machines", "Ultrasound Devices", "Ventilators"
                                                                                                       "Defibrillators",
                       "Patient Monitoring Systems", "Wheelchairs", "Hospital Beds", "Crutches and Walkers"};
int q3[100] = {12, 34, 56, 78, 45, 67, 56, 65, 45, 87};
string stocks4[100] = {"Test Tubes and Vials", "Centrifuges", "Microscopes", "Diagnostic Kits", "Slides and Cover Slips", "Petri Dishes", "Culture Media", "Reagents and Chemicals"};
int q4[100] = {25, 30, 18, 45, 60, 75, 20, 56};
string stocks5[100] = {"Patient Files and Folders", "Paper for Printers", "ID Bands for Patients", "Barcode Scanners", "Labeling Machines", "Pens,Clipboards,and Notepads", "Computers and Monitors"};
int q5[100] = {199, 499, 349, 250, 120, 899, 430};
string user[100] = {"nashra123", "nadia123", "faizan123"};
string pass[100] = {"12345678", "12345678", "12345678"};
string doc[100] = {"nofal123", "nazish123"};
string passdoc[100] = {"12345678", "12345678"};
string time1[30] = {"10:00am", "11:00am", "12:00pm", "03:00pm", "04:00pm", "05:00pm", "06:00pm"};
string time2[30] = {"08:00am", "09:00am", "10:00pm", "11:00am", "12:00pm", "02:00pm", "03:00pm", "04:00pm", "05:00pm", "06:00pm", "08:00pm", "09:00pm", "10:00pm"};
string adm[20] = {"admin123", "admin456"};
string passad[20] = {"12345678", "12345678"};

main()
{
    int choice = 0;
    string usr, pkey;
continue_label:
    system("Color 01");
    system("cls");
    header();
    loginop();
    while (choice != 4)
    {
        cout << "Enter choice:";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter your username(should only contain lowercase alphabets,numbers and underscore):";
            cin >> usr;
            cout << "Enter your password(should only be 8 characters long):";
            cin >> pkey;
            if (userfind(usr, pkey))
            {
                int ch = 0;
                c_label1:
                patientInt();
                patientOp();
                cout << "Enter choice:";
                cin >> ch;
                if (ch == 1)
                {
                    string name, n, m, k;
                    cout << "Enter doctor's name:";
                    cin >> name;
                    if (name == "nofal" || name == "Nofal" || name == "nazish" || name == "Nazish")
                    {
                        n = Hdoctor();
                        cout << n;
                        m = doctor(name);
                        cout << m;
                        cout << "\nEnter any character to go back.";
                        cin >> k;
                        goto c_label1;
                    }
                    else
                    {
                        cout << "Invalid name.";
                        cout << "\nEnter any character to go back.";
                        cin >> k;
                        goto c_label1;
                    }
                }
                else if (ch == 2)
                {
                    string name, t, r, r2, k;
                    Happointment();
                    r = doctorinfo();
                    r2 = doctorinfo2();
                    cout << r << endl;
                    cout << r2 << endl;
                    cout << "Enter doctor's name from the list:";
                    cin >> name;
                    cout << "Enter requested appointment hour(eg. 04:00am):";
                    cin >> t;
                    r = appointment(name, t);
                    cout << r;
                    cout << "\nEnter any character to go back.";
                    cin >> k;
                    goto c_label1;
                }
                else if (ch == 3)
                {
                    string n, k;
                    n = billCal();
                    cout << n;
                    billing();
                    cout << "\nEnter any character to go back.";
                    cin >> k;
                    goto c_label1;
                }
                else if (ch == 4)
                {
                    goto continue_label;
                }
            }
            else
            {
                string k;
                cout << "Invalid username or password.Try again";
                cout << "\nEnter any character to go back.";
                cin >> k;
                goto continue_label;
            }
        }
        else if (choice == 2)
        {
            int ch = 0;
            cout << "Enter your username(should only contain lowercase alphabets,numbers and underscore):";
            cin >> usr;
            cout << "Enter your password(should only be 8 characters long):";
            cin >> pkey;
            if (docfind(usr, pkey))
            {
            c_label2:
                doctorInt();
                doctorOp();
                cout << "Enter choice:";
                cin >> ch;
                if (ch == 1)
                {
                    string r, k;
                    int ID;
                    r = Hpatient();
                    cout << r;
                    cout << "Enter patient's ID";
                    cin >> ID;
                    patient(ID);
                    cout << "Enter any character to go back.";
                    cin >> k;
                    goto c_label2;
                }
                else
                {
                    string k;
                    cout << "Invalid name.";
                    cout << "\nEnter any character to go back.";
                    cin >> k;
                    goto c_label2;
                }
            }
            else if (ch == 2)
            {
                string name, re, nt, k;
                docappointment();
                cout << "Enter your name:";
                cin >> name;
                cout << "Enter choice:";
                cin >> ch;
                docchoice(ch, name);
                cout << "Enter any character to go back.";
                cin >> k;
                goto c_label2;
            }
            else if (ch == 3)
            {
                goto continue_label;
            }
            else
            {
                string k;
                cout << "Invalid username or password.Try again";
                cout << "Enter any character to go back.";
                cin >> k;
                goto c_label2;
            }
        }
    else if (choice == 3)
    {
        string p, q, k;
        cout << "Enter your username(should only contain lowercase alphabets,numbers and underscore):";
        cin >> p;
        cout << "Enter your password(should only be 8 characters long):";
        cin >> q;
        if (adminfind(p, q))
        {
            int ch = 0;
            c_label3:
            Hadmin();
            adminOp();
            cout << "Enter choice:";
            cin >> ch;
            if (ch == 1)
            {
                string n, p;
                cout << "Enter the name of patient you want to add(should contain lowercase letters,numbers, and underscore only):";
                cin >> n;
                cout << "Assign a password for the patient(should only be 8 characters long):";
                cin >> p;
                if (validum(n) && validpk(p))
                {
                    int var = addpatient(n, p);
                    if (var == -1)
                    {
                        cout << "Couldn't add patient.Try again";
                        cout << "\nEnter any character to go back.";
                        cin >> k;
                        goto c_label3;
                    }
                    else
                    {
                        cout << "Patient added.";
                        cout << "\nEnter any character to go back.";
                        cin >> k;
                        goto c_label3;
                    }
                }
                else
                {
                    cout << "Invalid username or password.";
                    cout << "\nEnter any character to go back.";
                    cin >> k;
                    goto c_label3;
                }
            }
            else if (ch == 2)
            {
                string n, p;
                cout << "Enter the name of doctor you want to add(should contain lowercase letters,numbers, and underscore only):";
                cin >> n;
                cout << "Assign a password for the doctor(should only be 8 characters long):";
                cin >> p;
                if (validum(n) && validpk(p))
                {
                    int var = adddoctor(n, p);
                    if (var == -1)
                    {
                        cout << "Couldn't add doctor.Try again";
                        cout << "\nEnter any character to go back.";
                        cin >> k;
                        goto c_label3;
                    }
                    else
                    {
                        cout << "Doctor added.";
                        cout << "\nEnter any character to go back.";
                        cin >> k;
                        goto c_label3;
                    }
                }
                else
                {
                    cout << "Invalid username or password.";
                    cout << "Enter any character to go back.";
                    cin >> k;
                    goto c_label3;
                }
            }
            else if (ch == 3)
            {
                stock();
                cout << "Enter any character to go back.";
                cin >> k;
                goto c_label3;
            }
            else if (ch == 4)
            {
                updatestockdisplay(ch);
                updatestock();
                cout << "Enter any character to go back.";
                cin >> k;
                goto c_label3;
            }
            else if (ch == 5)
            {
                viewp();
                cout << "Enter any character to go back.";
                cin >> k;
                goto c_label3;
            }
            else if (ch == 6)
            {
                viewd();
                cout << "Enter any character to go back.";
                cin >> k;
                goto c_label3;
            }
            else if (ch == 7)
            {
                cout << "Enter any character to go back.";
                cin >> k;
                goto continue_label;
            }
        }
    }
    else if (choice == 4)
    {
        string k;
        cout << "Enter any character to go back.";
        cin >> k;
        goto continue_label;
    }
    else
    {
        cout << "Invalid choice.";
        string k;
        cout << "Enter any character to go back.";
        cin >> k;
        goto continue_label;
    }
}
}
void header()
{
    cout << "                    #    #  ####   ####  #####  ###  #####   ##    #" << endl;
    cout << "                    #    #  #  #  ##     #   #   #     #    #  #   #" << endl;
    cout << "                    ######  #  #    ##   #####   #     #   ######  #" << endl;
    cout << "                    #    #  #  #     ##  #       #     #   #    #  #" << endl;
    cout << "                    #    #  ####  ####   #      ###    #   #    #  #####" << endl;
    cout << "                                                                                       " << endl;
    cout << "##    ##     ##     ##    ##     ##      #####    #####   ##    ##   ####    ##    #   #######" << endl;
    cout << "# #  # #    #   #   # #   ##    #  #     #        #       # #  # #   #       # #   #      #" << endl;
    cout << "#  ##  #   #######  #  #  ##   ######    #  ##    #####   #  ##  #   ####    #  #  #      #" << endl;
    cout << "#      #   #     #  #   # ##   #    #    #   ##   #       #      #   #       #   # #      #" << endl;
    cout << "#      #   #     #  #     ##   #    #    #####    #####   #      #   ####    #     #      #" << endl;
    cout << "                                                                                               " << endl;
    cout << "                    ######  ##   ##   ######   #####   #####   ##    ##" << endl;
    cout << "                   ###       ## ##   ###         #     #       # #  # #" << endl;
    cout << "                     ###      ###      ###       #     #####   #  ##  # " << endl;
    cout << "                       ###     #         ###     #     #       #      #" << endl;
    cout << "                    #####      #      #####      #     #####   #      #" << endl;
}
string Hpatient()
{
    string m;
    system("cls");
    gotoxy(30, 2);
    m = "-----P A T I E N T S   I N F O R M A T I O N-----\n";
    return m;
}
void patient(int ID)
{
    if (ID == 123456)
    {
        gotoxy(35, 4);
        cout << "=======================================" << endl;
        gotoxy(35, 5);
        cout << "||  Patient name:Shahzeb.            ||" << endl;
        gotoxy(35, 6);
        cout << "||  Age:35.                          ||" << endl;
        gotoxy(35, 7);
        cout << "||  Address:146-A,canal view,lahore. ||" << endl;
        gotoxy(35, 8);
        cout << "||  Illness:Fever,Mild headache.     ||" << endl;
        gotoxy(35, 9);
        cout << "=======================================" << endl;
    }
    else if (ID == 789012)
    {
        gotoxy(35, 4);
        cout << "============================================" << endl;
        gotoxy(35, 5);
        cout << "|| Patient name:Shazia.                   ||" << endl;
        gotoxy(35, 6);
        cout << "|| Age:30.                                ||" << endl;
        gotoxy(35, 7);
        cout << "|| Address:181-C,lake view city,Islamabad.||" << endl;
        gotoxy(35, 8);
        cout << "|| Illness:Fever,Mild headache.           ||" << endl;
        gotoxy(35, 9);
        cout << "============================================" << endl;
    }
    else
    {
        cout << "Invalid patient ID.";
    }
}
string doctor(string name)
{
    string r;
    if (name == "Nofal" || name == "nofal")
    {
        r = "====================================\n||  Doctor's ID:4567.             ||\n||  Specialization:Cardiologist.  ||\n||  Age:40.                       ||\n||  Gender=Male.                  ||\n====================================\n";
    }
    else if (name == "Nazish" || name == "nazish")
    {
        r = "====================================\n||  Doctor's ID:8901.             ||\n||  Specialization:MBBS.          ||\n||  Age:38.                       ||\n||  Gender=Female.                ||\n====================================\n";
    }
    return r;
}
string doctorinfo()
{
    string m;
    m = "\n====================================\n||  Doctor's ID:4567.             ||\n||  Doctor's Name:Nofal           ||\n||  Specialization:Cardiologist.  ||\n||  Age:40.                       ||\n||  Gender=Male.                  ||\n====================================\n";
    return m;
}
string doctorinfo2()
{
    string n;
    n = "\n====================================\n||  Doctor's ID:8901.             ||\n||  Doctor's Name:Nazish          ||\n||  Specialization:MBBS.          ||\n||  Age:38.                       ||\n||  Gender=Female.                ||\n====================================\n";
    return n;
}
string doctorInt()
{
    string m;
    system("cls");
    gotoxy(30, 2);
    m = "-----D O C T O R ' S    I N T E R F A C E-----\n";
    return m;
}
string appointment(string name, string t)
{
    string m;
    if (name == "Nofal" || name == "nofal")
    {
        bool found = false;
        for (int i = 0; i < 30; i++)
        {
            if (time1[i] == t)
            {
                m = "Doctor is free during this hour.";
                found = true;
                break;
            }
        }
        if (!found)
        {
            m = "Doctor isn't free during this hour.";
        }
    }
    else if (name == "Nazish" || name == "nazish")
    {
        bool found = false;
        for (int i = 0; i < 30; i++)
        {
            if (time2[i] == t)
            {
                m = "Doctor is free during this hour.";
                found = true;
                break;
            }
        }
        if (!found)
        {
            m = "Doctor isn't free during this hour.";
        }
    }
    else
    {
        m = "Invalid name.";
    }
    return m;
}
float billing()
{
    int choice, t;
    float total;
    cout << "Enter the number of appointment hours:";
    cin >> t;
    cout << "Enter the kind of treatment from the following list." << endl;
    cout << "=================================" << endl;
    cout << "||  1.Blood test               ||" << endl;
    cout << "||  2.ECG                      ||" << endl;
    cout << "||  3.Routine checkup          ||" << endl;
    cout << "||  4.Diabetes                 ||" << endl;
    cout << "||  5.Kidney desease           ||" << endl;
    cout << "=================================" << endl;
    cout << "Enter choice:";
    cin >> choice;
    if (choice == 1)
    {
        total = t * 50;
        cout << "The charges for blood tests are:$" << total;
    }
    else if (choice == 2)
    {
        total = t * 50;
        cout << "The charges for ECG are:$" << total;
    }
    else if (choice == 3)
    {
        total = t * 30;
        cout << "The charges for routine checkup are:$" << total;
    }
    else if (choice == 4)
    {
        total = t * 60;
        cout << "The charges for the treatment of diabetes are:$" << total;
    }
    else if (choice == 5)
    {
        total = t * 80;
        cout << "The charges for the treatment of kidney disease are:" << total;
    }
    else
    {
        cout << "Ilvalid input";
    }
    return total;
}
void patientOp()
{
    int ch;
    gotoxy(35, 4);
    cout << "=======================================" << endl;
    gotoxy(35, 5);
    cout << "||  1.Search doctor's information.   ||" << endl;
    gotoxy(35, 6);
    cout << "||  2.Appointment schedule.          ||" << endl;
    gotoxy(35, 7);
    cout << "||  3.Calculate bill.                ||" << endl;
    gotoxy(35, 8);
    cout << "||  4.Exit                           ||" << endl;
    gotoxy(35, 9);
    cout << "=======================================" << endl;
}
string patientInt()
{
    string m;
    system("cls");
    gotoxy(30, 2);
    m = "-----P A T I E N T ' S     I N T E R F A C E-----\n";
    return m;
}
string Hdoctor()
{
    string r;
    system("cls");
    gotoxy(30, 2);
    r = "-----D O C T O R ' S    I N F O R M A T I O N-----\n";
    return r;
}
string Happointment()
{
    string m;
    system("cls");
    gotoxy(30, 2);
    m = "-----A P P O I N T M E N T    S C H E D U L I N G-----";
    return m;
}
string billCal()
{
    string r;
    system("cls");
    gotoxy(30, 2);
    r = "-----B I L L    C A L C U L A T I O N-----\n";
    return r;
}
string Hadmin()
{
    string m;
    system("cls");
    gotoxy(30, 2);
    m = "-----A D M I N    I N T E R F A C E-----\n";
    return m;
}
void doctorOp()
{
    gotoxy(35, 4);
    cout << "=======================================" << endl;
    gotoxy(35, 5);
    cout << "||  1.Search patient's information   ||" << endl;
    gotoxy(35, 6);
    cout << "||  2.Change appointment schedule.   ||" << endl;
    gotoxy(35, 7);
    cout << "||  3.Exit.                          ||" << endl;
    gotoxy(35, 8);
    cout << "=======================================" << endl;
}
void adminOp()
{
    gotoxy(35, 4);
    cout << "==============================" << endl;
    gotoxy(35, 5);
    cout << "||  1.Add patient.          ||" << endl;
    gotoxy(35, 6);
    cout << "||  2.Add doctor.           ||" << endl;
    gotoxy(35, 7);
    cout << "||  3.Check stock.          ||" << endl;
    gotoxy(35, 8);
    cout << "||  4.Update stock.         ||" << endl;
    gotoxy(35, 9);
    cout << "||  5.View Patients.        ||" << endl;
    gotoxy(35, 10);
    cout << "||  6.View Doctors.         ||" << endl;
    gotoxy(35, 11);
    cout << "||  7.Exit.                 ||" << endl;
    gotoxy(35, 12);
    cout << "==============================" << endl;
}
int stock()
{
    int i;
    for (i = 0; i < 5; i++)
    {
        cout << stockH[i] << endl;
        if (i == 0)
        {
            for (int i = 0; stocks1[i] != "\0"; i++)
            {
                cout << stocks1[i] << "\t\t\t\t\t" << q1[i] << endl;
            }
        }
        if (i == 1)
        {
            for (int i = 0; stocks2[i] != "\0"; i++)
            {
                cout << stocks2[i] << "\t\t\t\t\t" << q2[i] << endl;
            }
        }
        if (i == 2)
        {
            for (int i = 0; stocks3[i] != "\0"; i++)
            {
                cout << stocks3[i] << "\t\t\t\t\t" << q3[i] << endl;
            }
        }
        if (i == 3)
        {
            for (int i = 0; stocks4[i] != "\0"; i++)
            {
                cout << stocks4[i] << "\t\t\t\t\t" << q4[i] << endl;
            }
        }
        if (i == 4)
        {
            for (int i = 0; stocks5[i] != "\0"; i++)
            {
                cout << stocks5[i] << "\t\t\t\t\t" << q5[i] << endl;
            }
        }
    }
    return i;
}
int viewp()
{
    int i;
    for (i = 0; user[i] != "\0"; i++)
    {
        cout << user[i] << "\t\t\t\t\t" << pass[i] << endl;
    }
    return i;
}
int viewd()
{
    int i;
    for (i = 0; doc[i] != "\0"; i++)
    {
        cout << doc[i] << "\t\t\t\t\t" << passdoc[i] << endl;
    }
    return i;
}
void loginop()
{
    gotoxy(35, 17);
    cout << "==============================" << endl;
    gotoxy(35, 18);
    cout << "||  Your identity:          ||" << endl;
    gotoxy(35, 19);
    cout << "||  1.Patient.              ||" << endl;
    gotoxy(35, 20);
    cout << "||  2.Doctor.               ||" << endl;
    gotoxy(35, 21);
    cout << "||  3.Admin.                ||" << endl;
    gotoxy(35, 22);
    cout << "||  4.Exit.                 ||" << endl;
    gotoxy(35, 23);
    cout << "==============================" << endl;
}
void docappointment()
{
    system("cls");
    gotoxy(35, 4);
    cout << "===============================" << endl;
    gotoxy(35, 5);
    cout << "||   Enter your choice       ||" << endl;
    gotoxy(35, 6);
    cout << "||1.Change existing schedule.||" << endl;
    gotoxy(35, 7);
    cout << "||2.Add appointment time.    ||" << endl;
    gotoxy(35, 8);
    cout << "||3.Delete appointment time. ||" << endl;
    gotoxy(35, 9);
    cout << "||4.Exit                     ||" << endl;
    gotoxy(35, 10);
    cout << "===============================" << endl;
}
bool docchoice(int ch, string name)
{
    bool found = false;
    if (ch == 1)
    {
        string re, nt;
        cout << "Enter the time you want to replace:";
        cin >> re;
        cout << "Enter the time you want to replace it with:";
        cin >> nt;
        if (name == "nofal" || name == "Nofal")
        {
            for (int i = 0; i < 30; i++)
            {
                if (time1[i] == re)
                {
                    time1[i] = nt;
                    cout << "The time has been changed.";
                    found = true;
                }
            }
            if (!found)
            {
                cout << "Time not found";
            }
        }
        else if (name == "nazish" || name == "Nazish")
        {
            for (int i = 0; i < 30; i++)
            {
                if (time2[i] == re)
                {
                    time2[i] = nt;
                    cout << "The time has been changed.";
                    found = true;
                }
            }
            if (!found)
            {
                cout << "Time not found";
            }
        }
        else
        {
            cout << "Invalid name.";
        }
    }
    else if (ch == 2)
    {
        string n;
        cout << "Enter the time you want to add:";
        cin >> n;
        if (name == "nofal" || name == "Nofal")
        {
            for (int i = 0; i < 30; i++)
            {
                if (time1[i] == "\0")
                {
                    time1[i] = n;
                    cout << "Time added.";
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Time not found";
            }
        }
        else if (name == "nazish" || name == "Nazish")
        {

            for (int i = 0; i < 30; i++)
            {
                if (time2[i] == "\0")
                {
                    time2[i] = n;
                    cout << "Time added.";
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Time not found";
            }
        }
        else
        {
            cout << "Invalid name.";
        }
    }
    else if (ch == 3)
    {
        string d;
        cout << "Enter the time you want to delete:";
        cin >> d;
        bool found = false;
        if (name == "nofal" || name == "Nofal")
        {
            for (int i = 0; i < 30; i++)
            {
                if (time1[i] == d)
                {
                    time1[i] = " ";
                    cout << "Time deleted.";
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Time not found";
            }
        }
        else if (name == "nazish" || name == "Nazish")
        {
            for (int i = 0; i < 30; i++)
            {
                if (time2[i] == d)
                {
                    time2[i] = " ";
                    cout << "Time deleted.";
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Time not found";
            }
        }
        else
        {
            cout << "Invalid name.";
        }
    }
    else if (ch == 4)
    {
        cout << "Program going back.";
    }
    else
    {
        cout << "Invalide choice.";
    }
    return found;
}
int updatestockdisplay(int choice)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        cout << stockH[i] << endl;
    }
    cout << "Enter the kind of supply you want to update:" << endl;
    cin >> choice;
    if (choice == 1)
    {
        for (int i = 0; stocks1[i] != "\0"; i++)
        {
            cout << stocks1[i] << endl;
        }
    }
    else if (choice == 2)
    {
        for (int i = 0; stocks2[i] != "\0"; i++)
        {
            cout << stocks2[i] << endl;
        }
    }
    else if (choice == 3)
    {
        for (int i = 0; stocks3[i] != "\0"; i++)
        {
            cout << stocks3[i] << endl;
        }
    }
    else if (choice == 4)
    {
        for (int i = 0; stocks4[i] != "\0"; i++)
        {
            cout << stocks4[i] << endl;
        }
    }
    else if (choice == 5)
    {
        for (int i = 0; stocks5[i] != "\0"; i++)
        {
            cout << stocks5[i] << endl;
        }
    }
    return i;
}
int updatestock()
{
    int ch, i;
    cout << "==Select one option:==" << endl;
    cout << "  1.Add supply." << endl;
    cout << "  2.Delete supply." << endl;
    cin >> ch;
    if (ch == 1)
    {
        string n;
        int m;
        cout << "Enter the desired supply(ensure the spelling are correct):";
        cin >> n;
        cout << "Enter the quantity:";
        cin >> m;
        for (i = 0; i < 100; i++)
        {
            if (stocks1[i] == "" && q1[i] == '\0')
            {
                stocks1[i] = n;
                q1[i] = m;
                cout << "Item added.";
                break;
            }
            else if (stocks2[i] == "" && q2[i] == '\0')
            {
                stocks2[i] = n;
                q2[i] = m;
                cout << "Item added.";
                break;
            }
            else if (stocks3[i] == "" && q3[i] == '\0')
            {
                stocks3[i] = n;
                q3[i] = m;
                cout << "Item added.";
                break;
            }
            else if (stocks4[i] == "" && q4[i] == '\0')
            {
                stocks4[i] = n;
                q4[i] = m;
                cout << "Item added.";
                break;
            }
            else if (stocks5[i] == "" && q5[i] == '\0')
            {
                stocks5[i] = n;
                q5[i] = m;
                cout << "Item added.";
                break;
            }
        }
    }
    else if (ch == 2)
    {
        string d, m;
        cout << "Enter the desired supply(ensure the spelling are correct):";
        cin >> d;
        bool found = false;
        for (i = 0; i < 100; i++)
        {
            if (stocks1[i] == d)
            {
                stocks1[i] = " ";
                q1[i] = 0;
                cout << "Item deleted.";
                found = true;
                break;
            }
            else if (stocks2[i] == d)
            {
                stocks2[i] = " ";
                q2[i] = 0;
                cout << "Item deleted.";
                found = true;
                break;
            }
            else if (stocks3[i] == d)
            {
                stocks3[i] = " ";
                q3[i] = 0;
                cout << "Item deleted.";
                found = true;
                break;
            }
            else if (stocks4[i] == d)
            {
                stocks4[i] = " ";
                q4[i] = 0;
                cout << "Item deleted.";
                found = true;
                break;
            }
            else if (stocks5[i] == d)
            {
                stocks5[i] = " ";
                q5[i] = 0;
                cout << "Item deleted.";
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Item not found";
        }
    }
    else
    {
        cout << "Invalid choice.\n";
    }
    return ch;
}
int addpatient(string n, string p)
{
    int i;
    for (i = 0; i < 100; i++)
    {
        if (user[i] == "\0" && pass[i] == "\0")
        {
            user[i] = n;
            pass[i] = p;
            return i;
            break;
        }
    }
    return -1;
}
int adddoctor(string n, string p)
{
    int i;
    for (i = 0; i < 100; i++)
    {
        if (doc[i] == "\0" && passdoc[i] == "\0")
        {
            doc[i] = n;
            passdoc[i] = p;
            return i;
            break;
        }
    }
    return -1;
}

bool userfind(string usr, string pkey)
{
    for (int i = 0; i < 100; i++)
    {
        if (user[i] == usr && pass[i] == pkey)
        {
            return true;
            break;
        }
    }
    return false;
}
bool docfind(string usr, string pkey)
{
    for (int i = 0; i < 100; i++)
    {
        if (doc[i] == usr && passdoc[i] == pkey)
        {
            return true;
            break;
        }
    }
    return false;
}
bool adminfind(string p, string q)
{
    for (int i = 0; i < 20; i++)
    {
        if (adm[i] == p && passad[i] == q)
        {
            return true;
            break;
        }
    }
    return false;
}
bool validum(string usr)
{
    for (int i = 0; usr[i] != '\0'; i++)
    {
        if (!((usr[i] >= 'a' && usr[i] <= 'z') || (usr[i] >= '0' && usr[i] <= '9') || usr[i] == '_'))
        {
            return false;
        }
    }
    return true;
}
bool validpk(string pkey)
{
    int i;
    for (i = 0; pkey[i] != '\0'; i++)
    {
    }
    if (i <= 8)
    {

        return true;
    }
    return false;
}

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}