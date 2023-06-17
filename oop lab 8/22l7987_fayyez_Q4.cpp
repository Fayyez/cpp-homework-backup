//#include<iostream>
//#include<windows.h>
//#include<string>
//#include<stdlib.h>
//using namespace std;
//
//class Appointment; // Forward declarations
//class patient;
//class doctor;
//Appointment** temp=nullptr;//global double pointer to appointments to be used as temp
//class person {
//public:
//    string name;
//    string address;
//    string email;
//    person(string name, string address, string email);
//    void displayPerson()
//    {
//        cout << "Name : " << name << "\tAddress : " << address << "\tEmail : " << email<<endl;
//    }
//};
//person::person(string name="", string address = "", string email = "")
//{//person parameterized default constructor
//    this->name = name;
//    this->address = address;
//    this->email = email;
//}
//
//class patient : public person {
//
//    int patientId;
//    Appointment ** appoints;
//    int appointmentCount=0;
//    static int patientIdGenerator;
//public:
//    patient(string name, string address, string email);
//    void addAppointment(Appointment* a)
//    {
//        appointmentCount++;
//     /*   if (temp != nullptr)
//        {
//            delete[] temp;
//        }*/
//        temp = new Appointment * [appointmentCount];
//        for (int i = 0; i < appointmentCount - 1; i++)
//        {
//            temp[i] = appoints[i];
//        }
//        temp[appointmentCount - 1] = a;
//        appoints = temp;
//       /* static int i = 0;
//        appoints[i++] = a;*/
//    }
//    void display()
//    {
//        cout << "PatientId = " << patientId << " :\nCredentials = ";
//        displayPerson();
//    }
//    void displayAppointments()
//    {
//        for (int i = 0; i < appointmentCount; i++)
//        {
//           cout << "\t\t\t**** ("<<i + 1 << ") ****\n";
//          //appoints[i]->displayA();
//        }
//    }
//    ~patient()
//    {
//        delete[]appoints;
//        appoints = nullptr;
//    }
//};
//int patient::patientIdGenerator = 2000;
//patient::patient(string name, string address, string email) : person(name,address,email)
//{
//    this->patientId = patientIdGenerator++;
//    appoints = nullptr;
//    appointmentCount = 0;
//}
//
//class doctor : public person {
//
//    int employeeId;
//    static int emplyeeIdGenerator;
//    Appointment** appoints;
//    int appointmentCount;
//public:
//    doctor(string name, string address, string email);
//    void addAppointment(Appointment* a)
//    {
//        appointmentCount++;
//        if (temp != nullptr)
//        {
//            delete[] temp;
//        }
//        temp = new Appointment * [appointmentCount];
//        for (int i = 0; i < appointmentCount - 1; i++)
//        {
//            temp[i] = appoints[i];
//        }
//        temp[appointmentCount - 1] = a;
//        appoints = temp;
//    }
//    void display()
//    {
//        cout << "EmployeetId = " << employeeId << " :\nCredentials = ";
//        displayPerson();
//        cout << endl;
//    }
//    void displayAppointments()
//    {
//        for (int i = 0; i < appointmentCount-1; i++)
//        {
//            cout << "\t\t\t**** (" << i + 1 << ") ****\n";
//            (appoints[i])->displayA();
//        }
//    }
//    ~doctor()
//    {
//        delete[]appoints;
//        appoints = nullptr;
//    }
//};
//int doctor::emplyeeIdGenerator = 1000;
//doctor::doctor(string name, string address, string email) : person(name, address, email)
//{
//    this->employeeId = emplyeeIdGenerator++;
//    appoints = nullptr;
//    appointmentCount = 0;
//}
//
//class Appointment {
//
//    int appointmentId;
//    static int appointmentIdGenerator;
//    string appointmentDateTime;
//    patient* pat;
//    doctor* doc;
//public:
//    Appointment(string appointmentDateTime, patient* p, doctor* d);
//    void displayA()
//    {
//        cout << "ID : " << appointmentId << " " << appointmentDateTime << endl;
//        cout << "Patient : " << (*pat).name << "\tDoctor : " << (*doc).name;
//    }
//};
//int Appointment::appointmentIdGenerator = 0;
//Appointment::Appointment(string appointmentDateTime, patient* p, doctor* d)
//{
//    appointmentId = appointmentIdGenerator++;
//    this->appointmentDateTime = appointmentDateTime;
//    this->pat = p;
//    this->doc = d;
//   p->addAppointment(this);
//   d->addAppointment(this);
//}
//
//class Department {
//
//    string departmentName;
//    doctor** doctors;
//    int doctorCount;
//
//    Department(string departmentName);
//    void addDoctor(doctor* doctor);
//};
//
//int main()
//{
//    system("color 80");
//    patient p1("fayez", "fsd", "@gmail");
//    patient p2("fayez2", "fsd2", "@gmail");
//    doctor d2("bobo", "fsd", "@gmail");
//    doctor d1("danish", "lhr", "@gmail");
//    p1.display();
//    d1.display();
//    p1.displayAppointments();
//    Appointment a1("(26/03/2023)",&p1,&d1);
//    Appointment a2("(27/03/2023)", &p1, &d2);
//    p1.displayAppointments();
//}