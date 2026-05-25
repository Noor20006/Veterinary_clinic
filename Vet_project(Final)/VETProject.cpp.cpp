#include<iostream>
#include<string>
#include<windows.h>
#include<fstream>
using namespace std;
void header();
bool isNumber(string input);  
bool isAlphabet(string input);
                                                 //MAIN INTERFACE
string showMenu();
bool signIn(string signInName, string password, string users[][4], int count);
string signUp(string users[][4], int& count);
                                                          //PASS BY REFERENCE
string signInMenu();
                             //VETERINARIAN 
void veterinarianMenu();
string veterinarianCheckIn();
                             
                             //REGISTER PET
void registerPetMenu(int& count,string name[],string petName[],string specie[],string gender[],string age[],string history[],string food[],string updatedDisease[],string updatedMedicine[]);
                            
                             //UPDATE PET
void updatePetMenu(int& count,string name[],string petName[],string specie[],string gender[],string age[],string history[],string food[],string updatedDisease[],string updatedMedicine[]);
int searchName(int& count,string name[],string updatedDisease[]);   //SEARCH NAME FOR UPDATE AND CHECK REPORT
                             
                             //REPORT OF PET
void checkReport(int& index,string name[],string petName[],string specie[],string gender[],string age[],string history[],string food[],string updatedDisease[],string updatedMedicine[]);
                             
                             //DELETE PET
int searchPetName(int& count,string petName[],string updatedDisease[]);
void deletePetData(int& count,int index,string name[],string petName[],string specie[],string gender[],string age[],string history[],string food[],string updatedDisease[],string updatedMedicine[]);
                             
                             //RECORD VACCINATION STATUS
void recordVaccineStatus(int& count,string petID[],string vaccineType[],string vaccinationDate[],string nextDueDate[],string dosage[],string reactionafterVaccine[]);
                             
                             //CHECK VACCINATION STATUS
int searchID(int& count,string petID[]);
void displayVaccineStatus(int& index,string petID[],string vaccineType[],string vaccinationDate[],string nextDueDate[],string dosage[],string reactionafterVaccine[]);
                             
                             //SCHEDULE
string daySearch();       
void monday();
void tuesday();
void wednesday();
void thursday();
void friday();
void saturday();
void sunday();                      
                             //CLINIC MANAGER
void clinicManagerMenu();
string clinicManagerCheckIn();
                           
                            //ADD NEW STAFF
void newStaffMenu(int& count,string memberName[],string phoneNumber[],string positionHolds[],string department[],string employeeID[],string date[],string location[]);  
                           
                            //UPDATE STAFF DATA 
void updateStaffMenu(int& count,string memberName[],string phoneNumber[],string positionHolds[],string department[],string employeeID[],string date[],string location[]);

int searchStaffID(int& count,string employeeID[]);        //SEARCH BAR FOR UPDATE AND RECORD
                                         
                                         //REPORT OF STAFF DATA
void staffReport(int index,string memberName[],string phoneNumber[],string positionHolds[],string department[],string employeeID[],string date[],string location[]);

                                      //DELETE STAFF DATA
void deleteStaffData(int& count,int index,string memberName[],string phoneNumber[],string positionHolds[],string department[],string employeeID[],string date[],string location[]);
                                       
                                        //SALARY DETAILS
string salaryMenu();
int vetSalary();
int nurseSalary();
int receptionistSalary();
int cleaningStaffSalary();
                             //PET OWNER
void petOwnerMenu();
string petOwnerCheckIn();

                             //SCHEDULE APPOINTMENTS
void scheduleAppointments(int& count,string speciePet[],string vaccinationHistory[],string appointmentType[],string dateAppointment[]);
                           
                            //ADD EMERGENCY CONTACT INFORMATION
void addEmergencyContact(int& count,string ownerName[],string ownerNumber[],string alternateNumber[],string emailAddress[],string homeAddress[]);

                          //SEARCH PHONE NUMBER FOR UPDATE AND DELETE
int searchPhoneNumber(int& count,string ownerNumber[],string alternateNumber[]);
                            
                            //EDIT EMERGENCY CONTACT INFORMATION
void editEmergencyContact(int& count,string ownerName[],string ownerNumber[],string alternateNumber[],string emailAddress[],string homeAddress[]);

                            //REPORT OF EMERGENCY INFORMATION
void emergencyContactReport(int index,string ownerName[],string ownerNumber[],string alternateNumber[],string emailAddress[],string homeAddress[]); 
                            //DELETE DATA
void deleteEmergencyContact(int& count,int index,string ownerName[],string ownerNumber[],string alternateNumber[],string emailAddress[],string homeAddress[]);                    
                            //REMAINDERS CHECK IN
int remainderCheckIn(int& count,string speciePet[],string dateAppointment[]);
     
                           //REMAINDERS
void remaindersReport(int index,string speciePet[],string vaccinationHistory[],string appointmentType[],string dateAppointment[]);


int temp=0;
int count=0;
HANDLE h=
GetStdHandle(STD_OUTPUT_HANDLE);

/*-----------------------------------------------MAIN --------------------------------------------------------*/


int main()
{
    system("cls");
    header();

    int no;
    string option;
    
const int x = 15;           //VALUE NEVER CHANGED BCZ OF CONST
string users[15][4];

                              //FOR VETERINARIAN
string name[x];
string petName[x];
string specie[x];
string gender[x];
string food[x];
string history[x];
string updatedDisease[x];
string updatedMedicine[x];
string age[x];
string petID[x];
string vaccineType[x];
string vaccinationDate[x];
string nextDueDate[x];
string dosage[x];
string reactionafterVaccine[x];
                               //FOR CLINIC MANAGER
string memberName[x];
string phoneNumber[x];
string positionHolds[x];
string department[x];
string employeeID[x];
string date[x];
string location[x];
                             //FOR PET OWNER
string speciePet[x];
string vaccinationHistory[x];
string appointmentType[x];
string dateAppointment[x];
string ownerName[x];
string ownerNumber[x];
string alternateNumber[x];
string emailAddress[x];
string homeAddress[x];
                         //ATTRIBUTES FOR SIGN IN AND SIGN UP
string signInName;     
string password;          //FROM USER
string position[15];
string CNIC[15];
string username[15];
string passwordarray[15];
string day;
bool val;

    while(true)                               //LOOP TO CONTINUE PROCESS
    {
      option=showMenu();
    
    if(option=="1"||option=="2"||option=="3")
    {
      
      
if(option=="1")
    {
      system("cls");
      header();
      SetConsoleTextAttribute(h,2);
      cout <<"\t\t\t\t\t(:Sign in:)"<<endl<<endl;
      SetConsoleTextAttribute(h,1);  
      cout <<"\t\t\tEnter UserName :";
      SetConsoleTextAttribute(h,8);  
      cin >> signInName; 
      if (isAlphabet(signInName)) 
      {
        cout << "Welcome " << signInName << "!" << endl;
      } 
      else
       {
        cout << "Invalid name! Please use alphabets only.\n";
       }
                                                                       //SIGN IN
      SetConsoleTextAttribute(h,1);  
      cout <<"\t\t\tEnter Password :";
      SetConsoleTextAttribute(h,8);  
      cin >>password;
      if (isNumber(password))
       {
        no = stoi(password);                                   // Convert to integer 
        cout << "You entered a valid number: " << no << endl;
       } 
      else 
       {
        cout << "Invalid input! Please enter digits only.\n";
       }
      if(signIn(signInName,password,users,count))
      {
      cout <<"\t\t\t\tSign in successful!"<<endl; 
      system("cls");
      header();
      string signInchoice=signInMenu();
      if(signInchoice=="1")                      //OPTION FOR VETERINARIAN
      {
      system("cls");
      header();
      veterinarianMenu();
      string vetOption=veterinarianCheckIn();
      if(vetOption=="1")
      { 
        system("cls");
        header();
        val=true;
        while(val&&count<15)
        {
            if(count>=x)
            {
              cout <<"\t\t\tMaximum limit reached"<<endl;
            }
        SetConsoleTextAttribute(h,2);    
        cout <<"\t\t\t\t\t(:Veterinarian Menu:)" ;
        cout <<endl<<endl;
                                 //REGISTER PET
        registerPetMenu(count,name,petName,specie,gender,age,history,food,updatedDisease,updatedMedicine);
        SetConsoleTextAttribute(h,13);
        cout <<" Do you want to Register a new pet:   ";          
        SetConsoleTextAttribute(h,11);
        cout << "\t if yes enter 1 \t if no enter 0   :";
        cin >> val;
        cout <<endl;
           if(val==false)
        {
        SetConsoleTextAttribute(h,13);
        cout <<" \t\t\t\tOkay The data is successfully Registered!"<<endl;
        count++;
        }
      } 
    }
 
      else if(vetOption=="2")             //UPDATE PET DATA
      {
        system("cls");
        header();
        val=true;
        while(val&&count<15)
        {
        cout <<"\t\t\t\t\t(:Veterinarian Menu:)";
        cout <<endl<<endl;
        int index=searchName(count,name,updatedDisease);
        if(index!=-1)
        {
          
          updatePetMenu(count,name,petName,specie,gender,age,history,food,updatedDisease,updatedMedicine);
          
          SetConsoleTextAttribute(h,13);
          cout <<" Do you want to Update a new pet:   ";          
          SetConsoleTextAttribute(h,11);
          cout << "\t if yes enter 1 \t if no enter 0   :";
          cin >> val;
          cout <<endl;
           if(val==false)
        {
          SetConsoleTextAttribute(h,13);
          cout <<" \t\t\t\tOkay The data is successfully Updated!"<<endl;
          count++;
      }
    }
  }
 } 
      else if(vetOption=="3")             //DISPLAY REPORT
      {
        system("cls");
        header();
        val=true;
        while(val&&count<15)
        {
        
          SetConsoleTextAttribute(h,2);     
          cout <<"\t\t\t\t\t(:Veterinarian Menu:)" <<endl ;
          cout <<endl<<endl;
        int index=searchName(count,name,updatedDisease);
        if(index!=-1)
        {
          checkReport(index,name,petName,specie,gender,age,history,food,updatedDisease,updatedMedicine);
        }
        else{
          SetConsoleTextAttribute(h,13);
          cout <<"\t\t\t\tNo Report to display ";
        }
          SetConsoleTextAttribute(h,13);
          cout <<" Do you want to check one more report:   ";          
          SetConsoleTextAttribute(h,11);
          cout << "\t if yes enter 1 \t if no enter 0   :";
          cin >> val;
          cout <<endl;
           if(val==false)
        {
          SetConsoleTextAttribute(h,13);
          cout <<" \t\t\t\tOkay The data is successfully Displayed!"<<endl;
          count++;
        }
        
  }
 }
     else if(vetOption=="4")             //DELETE REPORT
      {
        system("cls");
        header();
        val=true;
        while(val)
        {
        
          SetConsoleTextAttribute(h,2);     
          cout <<"\t\t\t\t\t(:Veterinarian Menu:)" <<endl ;
          cout <<endl<<endl;
        int index=searchPetName(count,petName,updatedDisease);
        if(index!=-1)
        {
          deletePetData(count,index,name,petName,specie,gender,age,history,food,updatedDisease,updatedMedicine);
        }
        else{
          SetConsoleTextAttribute(h,13);
          cout <<"\t\t\t\tNo Report to delete "<<endl;
        }
          SetConsoleTextAttribute(h,13);
          cout <<" Do you want to del one more report:   ";          
          SetConsoleTextAttribute(h,11);
          cout << "\tif yes enter 1\t if no enter 0 :";
          cin >> val;
          cout <<endl;
           if(val==false)
        {
          SetConsoleTextAttribute(h,13);
          cout <<" \t\tOkay The data is successfully Deleted!"<<endl;
        }
        
  }
 }  
       else if(vetOption=="5")
      { 
        system("cls");
        header();
        val=true;
        while(val&&count<15)
        {
            if(count>=x)
            {
              cout <<"\t\t\tMaximum limit reached"<<endl;
            }
        SetConsoleTextAttribute(h,2);    
        cout <<"\t\t\t\t\t(:Veterinarian Menu:)" ;
        cout <<endl<<endl;
                                    //RECORD VACCINE STATUS
        recordVaccineStatus(count,petID,vaccineType,vaccinationDate,nextDueDate,dosage,reactionafterVaccine);
        SetConsoleTextAttribute(h,13);
        cout <<" Do you want to check vaccination status of one more pet:   ";          
        SetConsoleTextAttribute(h,11);
        cout << "\t if yes enter 1 \t if no enter 0   :";
        cin >> val;
        cout <<endl;
           if(val==false)
        {
        SetConsoleTextAttribute(h,13);
        cout <<" \t\t\t\tOkay The data is successfully Registered!"<<endl;
        count++;
        }
      } 
    }
     else if(vetOption=="6")             //DISPLAY VACCINE STATUS
      {
        system("cls");
        header();
        val=true;
        while(val&&count<15)
        {
        
          SetConsoleTextAttribute(h,2);     
          cout <<"\t\t\t\t\t(:Veterinarian Menu:)" <<endl ;
          cout <<endl<<endl;
        int index=searchID(count,petID);
        if(index!=-1)
        {
          displayVaccineStatus(index,petID,vaccineType,vaccinationDate,nextDueDate,dosage,reactionafterVaccine);
        }
        else{
          SetConsoleTextAttribute(h,13);
          cout <<"\t\t\t\tNo Report to display ";
        }
          SetConsoleTextAttribute(h,13);
          cout <<" Do you want to check one more report:   ";          
          SetConsoleTextAttribute(h,11);
          cout << "\t if yes enter 1 \t if no enter 0   :";
          cin >> val;
          cout <<endl;
           if(val==false)
        {
          SetConsoleTextAttribute(h,13);
          cout <<" \t\t\t\tOkay The data is successfully Displayed!"<<endl;
          count++;
        }
        
  }
 } 
  else if(vetOption=="7")
  {
    string day=daySearch();
    if(day=="monday")
    {
      monday();
    }
    else if(day=="tuesday")
    {
      tuesday();
    }
    else if(day=="wednesday")
    {
      wednesday();
    }
    else if(day=="thursday")
    {
      thursday();
    }
    else if(day=="friday")
    {
      friday();
    }
    else if(day=="saturday")
    {
      saturday();
    }
    else if(day=="sunday")
    {
      sunday();
    }
    else
    {
      cout<<"\t\tInvalid day or Wrong spelling";
    }
  }
  else if(vetOption=="8")
    {
      system("cls");
      header();
      cout <<"\t\t\t\t\t\tYOU HAVE SUCCESSFULLY EXIT THE PROGRAM";        //EXIT THE PROGRAM
      return 0;
    }

}
      else if(signInchoice=="2")                 //OPTION FOR CLINIC MANAGER
      {
      system("cls");
      header(); 
      clinicManagerMenu();                            
      string managerOption=clinicManagerCheckIn();
      if(managerOption=="1")                              //ADD NEW STAFF
      { 
        system("cls");
        header();
        val=true;
        while(val&&count<15)
        {
            if(count>=x)
            {
              cout <<"\t\t\tMaximum limit reached"<<endl;
            }
        SetConsoleTextAttribute(h,2);    
        cout <<"\t\t\t\t\t(:Clinic Manager Menu:)" ;
        cout <<endl<<endl;
        newStaffMenu(count,memberName,phoneNumber,positionHolds,department,employeeID,date,location);
        SetConsoleTextAttribute(h,13);
        cout <<" Do you want to Register a new staff member: ";          
        SetConsoleTextAttribute(h,11);
        cout << "\tif yes enter 1\tif no enter 0  :";
        cin >> val;
        cout <<endl;
           if(val==false)
        {
        SetConsoleTextAttribute(h,13);
        cout <<" \t\t\t\tOkay The data is successfully Registered!"<<endl;
        count++;
        }
      } 
    }
    else if(managerOption=="2")             //UPDATE STAFF DATA
      {
        system("cls");
        header();
        val=true;
        while(val&&count<15)
        {
        cout <<"\t\t\t\t\t(:Clinic Manager Menu:)";
        cout <<endl<<endl;
        int index=searchStaffID(count,employeeID);
        if(index!=-1)
        {
          
          updateStaffMenu(count,memberName,phoneNumber,positionHolds,department,employeeID,date,location);
          
          SetConsoleTextAttribute(h,13);
          cout <<" Do you want to Update a new pet:   ";          
          SetConsoleTextAttribute(h,11);
          cout << "\t if yes enter 1 \t if no enter 0   :";
          cin >> val;
          cout <<endl;
           if(val==false)
        {
          SetConsoleTextAttribute(h,13);
          cout <<" \t\t\t\tOkay The data is successfully Updated!"<<endl;
          count++;
      }
    }
  }
 } 
 else if(managerOption=="3")             //DISPLAY STAFF REPORT
      {
        system("cls");
        header();
        val=true;
        while(val&&count<15)
        {
        
          SetConsoleTextAttribute(h,2);     
          cout <<"\t\t\t\t\t(:Clinic Manager Menu:)" <<endl ;
          cout <<endl<<endl;
        int index=searchID(count,employeeID);
        if(index!=-1)
        {
         staffReport(index,memberName,phoneNumber,positionHolds,department,employeeID,date,location);
        }
        else{
          SetConsoleTextAttribute(h,13);
          cout <<"\t\t\t\tNo Report to display ";
        }
          SetConsoleTextAttribute(h,13);
          cout <<" Do you want to check one more report:   ";          
          SetConsoleTextAttribute(h,11);
          cout << "\t if yes enter 1 \t if no enter 0   :";
          cin >> val;
          cout <<endl;
           if(val==false)
        {
          SetConsoleTextAttribute(h,13);
          cout <<" \t\t\t\tOkay The data is successfully Displayed!"<<endl;
          count++;
        }
        
  }
 }
 
     else if(managerOption=="4")             //DELETE REPORT
      {
        system("cls");
        header();
        val=true;
        while(val)
        {
        
          SetConsoleTextAttribute(h,2);     
          cout <<"\t\t\t\t\t(:Clinic Manager Menu:)" <<endl ;
          cout <<endl<<endl;
        int index=searchID(count,employeeID);
        if(index!=-1)
        {
         deleteStaffData(count,index,memberName,phoneNumber,positionHolds,department,employeeID,date,location); 
        }
        else{
          SetConsoleTextAttribute(h,13);
          cout <<"\t\t\t\tNo Report to delete "<<endl;
        }
          SetConsoleTextAttribute(h,13);
          cout <<" Do you want to del one more report:   ";          
          SetConsoleTextAttribute(h,11);
          cout << "\tif yes enter 1\t if no enter 0 :";
          cin >> val;
          cout <<endl;
           if(val==false)
        {
          SetConsoleTextAttribute(h,13);
          cout <<" \t\tOkay The data is successfully Deleted!"<<endl;
        }
        
  }
 } 
 else if(managerOption=="5")             //EMERGENCY CONTACT REPORT
      {
        system("cls");
        header();
        val=true;
        while(val&&count<15)
        {
        
          SetConsoleTextAttribute(h,2);     
          cout <<"\t\t\t\t\t(:Clinic Manager Menu:)" <<endl ;
          cout <<endl<<endl;
        int index=searchPhoneNumber(count,ownerNumber,alternateNumber);
        if(index!=-1)
        {
         emergencyContactReport(index,ownerName,ownerNumber,alternateNumber,emailAddress,homeAddress); 
        }
        else{
          SetConsoleTextAttribute(h,13);
          cout <<"\t\t\t\tNo Report to display ";
        }
          SetConsoleTextAttribute(h,13);
          cout <<" Do you want to check one more report:   ";          
          SetConsoleTextAttribute(h,11);
          cout << "\t if yes enter 1 \t if no enter 0   :";
          cin >> val;
          cout <<endl;
           if(val==false)
        {
          SetConsoleTextAttribute(h,13);
          cout <<" \t\t\t\tOkay The data is successfully Displayed!"<<endl;
          count++;
        }
        
  }
 }
     else if(managerOption=="6")                         //SALARY DETAILS
      {
        system("cls");
        header();
        string salaryOption=salaryMenu();
        if(salaryOption=="1")
        {
          vetSalary();            //VET SALARY
        }
        else if(salaryOption=="2")
        {
          nurseSalary();          //NURSE SALARY
        }
        else if(salaryOption=="3")
        {
          receptionistSalary();    //RECEPTIONIST SALARY
        }
        else if(salaryOption=="4")
        {
          cleaningStaffSalary();   //CLEANING STAFF SALARY
        }
        else
        {
          cout <<"\t\tInvalid Option";
        }
      }
       else if(managerOption=="7")
    {
      system("cls");
      header();
      cout <<"\t\t\t\t\t\tYOU HAVE SUCCESSFULLY EXIT THE PROGRAM";        //EXIT THE PROGRAM
      return 0;
    }
     
   }
       else if(signInchoice=="3")                 //OPTION FOR PET OWNER
      {
      system("cls");
      header(); 
      petOwnerMenu();
      string petOption=petOwnerCheckIn();
      if(petOption=="1")                              //ADD SCHEDULE
      { 
        system("cls");
        header();
        val=true;
        while(val&&count<15)
        {
            if(count>=x)
            {
              cout <<"\t\t\tMaximum limit reached"<<endl;
            }
        SetConsoleTextAttribute(h,2);    
        cout <<"\t\t\t\t\t(:Pet Owner Menu:)" ;
        cout <<endl<<endl;
        scheduleAppointments(count,speciePet,vaccinationHistory,appointmentType,dateAppointment);
        SetConsoleTextAttribute(h,13);
        cout <<" Do you want to schedule one more appointment: ";          
        SetConsoleTextAttribute(h,11);
        cout << "\tif yes enter 1\tif no enter 0  :";
        cin >> val;
        cout <<endl;
           if(val==false)
        {
        SetConsoleTextAttribute(h,13);
        cout <<" \t\t\t\tOkay The data is successfully Registered!"<<endl;
        count++;
        }
      } 
    }
    else if(petOption=="2")                              //ADD EMERGENCY CONTACT
      { 
        system("cls");
        header();
        val=true;
        while(val&&count<15)
        {
            if(count>=x)
            {
              cout <<"\t\t\tMaximum limit reached"<<endl;
            }
        SetConsoleTextAttribute(h,2);    
        cout <<"\t\t\t\t\t(:Pet Owner Menu:)" ;
        cout <<endl<<endl;
        addEmergencyContact(count,ownerName,ownerNumber,alternateNumber,emailAddress,homeAddress);
        SetConsoleTextAttribute(h,13);
        cout <<" Do you want to register one more emergency contact: ";          
        SetConsoleTextAttribute(h,11);
        cout << "\tif yes enter 1\tif no enter 0  :";
        cin >> val;
        cout <<endl;
           if(val==false)
        {
        SetConsoleTextAttribute(h,13);
        cout <<" \t\t\t\tOkay The data is successfully Registered!"<<endl;
        count++;
        }
      } 
    }
    else if(petOption=="3")             //UPDATE PET DATA
      {
        system("cls");
        header();
        val=true;
        while(val&&count<15)
        {
        cout <<"\t\t\t\t\t(:Veterinarian Menu:)";
        cout <<endl<<endl;
        int index=searchPhoneNumber(count,ownerNumber,alternateNumber);
        if(index!=-1)
        {
          
          editEmergencyContact(count,ownerName,ownerNumber,alternateNumber,emailAddress,homeAddress);
          SetConsoleTextAttribute(h,13);
          cout <<" Do you want to Update a new pet:   ";          
          SetConsoleTextAttribute(h,11);
          cout << "\t if yes enter 1 \t if no enter 0   :";
          cin >> val;
          cout <<endl;
           if(val==false)
        {
          SetConsoleTextAttribute(h,13);
          cout <<" \t\t\t\tOkay The data is successfully Updated!"<<endl;
          count++;
      }
    }
  }
 } 
      else if(petOption=="5")             //EMERGENCY CONTACT REPORT
      {
        system("cls");
        header();
        val=true;
        while(val&&count<15)
        {
        
          SetConsoleTextAttribute(h,2);     
          cout <<"\t\t\t\t\t(:Pet Owner Menu:)" <<endl ;
          cout <<endl<<endl;
        int index=searchPhoneNumber(count,ownerNumber,alternateNumber);
        if(index!=-1)
        {
         emergencyContactReport(index,ownerName,ownerNumber,alternateNumber,emailAddress,homeAddress); 
        }
        else{
          SetConsoleTextAttribute(h,13);
          cout <<"\t\t\t\tNo Report to display ";
        }
          SetConsoleTextAttribute(h,13);
          cout <<" Do you want to check one more report:   ";          
          SetConsoleTextAttribute(h,11);
          cout << "\t if yes enter 1 \t if no enter 0   :";
          cin >> val;
          cout <<endl;
           if(val==false)
        {
          SetConsoleTextAttribute(h,13);
          cout <<" \t\t\t\tOkay The data is successfully Displayed!"<<endl;
          count++;
        }
        
  }
 }
 else if(petOption=="4")             //DELETE REPORT
      {
        system("cls");
        header();
        val=true;
        while(val)
        {
        
          SetConsoleTextAttribute(h,2);     
          cout <<"\t\t\t\t\t(:Pet Owner Menu:)" <<endl ;
          cout <<endl<<endl;
        int index=searchPhoneNumber(count,ownerNumber,alternateNumber);
        if(index!=-1)
        {
          deleteEmergencyContact(count,index,ownerName,ownerNumber,alternateNumber,emailAddress,homeAddress);
        }
        else{
          SetConsoleTextAttribute(h,13);
          cout <<"\t\t\t\tNo Report to delete "<<endl;
        }
          SetConsoleTextAttribute(h,13);
          cout <<" Do you want to del one more report:   ";          
          SetConsoleTextAttribute(h,11);
          cout << "\tif yes enter 1\t if no enter 0 :";
          cin >> val;
          cout <<endl;
           if(val==false)
        {
          SetConsoleTextAttribute(h,13);
          cout <<" \t\tOkay The data is successfully Deleted!"<<endl;
        }
        
  }
 }  
    else if(petOption=="6")             //DISPLAY REMAINDERS
      {
        system("cls");
        header();
        val=true;
        while(val&&count<15)
        {
        
        SetConsoleTextAttribute(h,2);     
        cout <<"\t\t\t\t\t(:Pet Owner Menu:)" <<endl ;
        cout <<endl<<endl;
        int index=remainderCheckIn(count,speciePet,dateAppointment);
        if(index!=-1)
        {
          SetConsoleTextAttribute(h,13);
          cout <<"\t\tYou entered correct date of Vaccination...Visit soon for Check up.."<<endl<<endl;
          cout <<"\t\tYour data is given below  ..."<<endl;
          remaindersReport(index,speciePet,vaccinationHistory,appointmentType,dateAppointment);
        }
        else{
          SetConsoleTextAttribute(h,13);
          cout <<"\t\t\t\tNo Remainder to display ";
        }
          SetConsoleTextAttribute(h,13);
          cout <<" Do you want to check one more remainder:   ";          
          SetConsoleTextAttribute(h,11);
          cout << "\t if yes enter 1 \t if no enter 0   :";
          cin >> val;
          cout <<endl;
           if(val==false)
        {
          SetConsoleTextAttribute(h,13);
          cout <<" \t\t\t\tOkay The data is successfully Displayed!"<<endl;
          count++;
        }
        
  }
 }
  else if(petOption=="7")             //DISPLAY REPORT
      {
        system("cls");
        header();
        val=true;
        while(val&&count<15)
        {
        
          SetConsoleTextAttribute(h,2);     
          cout <<"\t\t\t\t\t(:Pet Option Menu:)" <<endl ;
          cout <<endl<<endl;
        int index=searchName(count,name,updatedDisease);
        if(index!=-1)
        {
          checkReport(index,name,petName,specie,gender,age,history,food,updatedDisease,updatedMedicine);
        }
        else{
          SetConsoleTextAttribute(h,13);
          cout <<"\t\t\t\tNo Report to display ";
        }
          SetConsoleTextAttribute(h,13);
          cout <<" Do you want to check one more report:   ";          
          SetConsoleTextAttribute(h,11);
          cout << "\t if yes enter 1 \t if no enter 0   :";
          cin >> val;
          cout <<endl;
           if(val==false)
        {
          SetConsoleTextAttribute(h,13);
          cout <<" \t\t\t\tOkay The data is successfully Displayed!"<<endl;
          count++;
        }
        
  }
 }
 else if(petOption=="8")
    {
      system("cls");
      header();
      cout <<"\t\t\t\t\t\tYOU HAVE SUCCESSFULLY EXIT THE PROGRAM";        //EXIT THE PROGRAM
      return 0;
    }
      }
     else
      {
      cout<<"Invalid Credinals"<<endl;
      }
    }
  }

else if(option=="2")
    {
      if(count<15)
      {
        system("cls");
        header();

        SetConsoleTextAttribute(h,2);                        //SIGN UP
        cout <<"\t\t\t\t\t(:Sign Up:)"<<endl<<endl;
        cout << signUp(users, count) << endl;
        system("cls");
        header();
        cout <<"\nPlease sign in now "<<endl;
        continue;                                            //TO CONTINUE THE PROCESS AGAIN AND AGAIN
      }
      else
      {
        cout <<"Sign up limit completed ";
      }
    }
else if(option=="3")
    {
      system("cls");
      header();
      cout <<"\t\t\t\t\t\tYOU HAVE SUCCESSFULLY EXIT THE PROGRAM";        //EXIT THE PROGRAM
      return 0;
    }
else
    {
      cout <<endl<<endl;
      cout <<"\t\t\t\tInvalid option Please try again "<<endl;             //FOR INVALID OPTION
    }
  }
    else
    {
      cout <<endl<<endl;
      cout <<"\t\t\t\tInvalid option try again"<<endl;
    }
  }
}

/*--------------------------------------------------MAIN MENU OF PROGRAM--------------------------------------------*/


string showMenu()
 { 
   
    string option;
    SetConsoleTextAttribute(h,1);  
    cout <<"\t\t\t1:Sign in"<<endl;
    cout <<"\t\t\t2:Sign up"<<endl;
    cout <<"\t\t\t3:Exit"<<endl;
    SetConsoleTextAttribute(h,8);
    cout <<"\t\tEnter Your option :";
    SetConsoleTextAttribute(h,8);
    cin >> option;
    SetConsoleTextAttribute(h,7);

    return option;
    
 }
/* -------------------------------------SIGN IN------------------------------------------------------------*/  


bool signIn(string signInName, string password, string users[][4], int count)
 {
    ifstream inputFile("users.txt"); 
    string fileUsername, filePassword;

    
    while (inputFile >> fileUsername >> filePassword)
     {
        if (fileUsername == signInName && filePassword == password)
         {
            inputFile.close();  
            return true; 
        }
    }

    inputFile.close();  
    return false;
}
/*--------------------------------------SIGN UP--------------------------------------------------------------*/


string signUp(string users[][4], int& count)
 {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 1);
    cout << "\t\t\tEnter your name to sign up :";
    SetConsoleTextAttribute(h, 8);
    cin >> users[count][0];  

    SetConsoleTextAttribute(h, 1);
    cout << "\t\t\tEnter Password :";
    SetConsoleTextAttribute(h, 8);
    cin >> users[count][1]; 

    SetConsoleTextAttribute(h, 1);
    cout << "\t\t\tEnter position :";
    SetConsoleTextAttribute(h, 8);
    cin >> users[count][2];

    bool valid = false;
    while (!valid) 
    {
        SetConsoleTextAttribute(h, 1);
        cout << "\t\t\tEnter CNIC :";
        SetConsoleTextAttribute(h, 8);
        cin >> users[count][3];

        valid = true;
        // CNIC Validation
        if (users[count][3].length() != 13)
         {
            valid = false;
        } else
         {
            for (char c : users[count][3]) 
            {
                if (!isdigit(c)) 
                {  // Check if each character is a digit
                    valid = false;
                    break;
                }
            }
        }

        if (valid) 
        {
            cout << "Invalid CNIC! Please enter a valid 13-digit CNIC.\n";
        } else
         {
            
            ofstream outputFile("users.txt", ios::app); 
            outputFile << users[count][0] << " " << users[count][1] << endl;  
            outputFile.close();  
            count++;  
            SetConsoleTextAttribute(h, 7);
            return "Sign up successful";
        }
    }
}
/*----------------------------------------SIGN IN MENU--------------------------------------------------------*/
string signInMenu()
{
   
    string option;
    SetConsoleTextAttribute(h,13);
    cout <<"\t\tDo you want to Sign in as :"<<endl<<endl;
    SetConsoleTextAttribute(h,1);  
    cout <<"\t\t\t1: Veterinarian"<<endl;
    cout <<"\t\t\t2: Clinic Manager"<<endl;
    cout <<"\t\t\t3: Pet Owner"<<endl;
    SetConsoleTextAttribute(h,13);
    cout <<"\t\tEnter Your Option :";
    SetConsoleTextAttribute(h,8);  
    cin >> option;

    return option;
}


bool isNumber(string input) 
{
    for (int i = 0; i < input.length(); i++)
     {
        if (input[i] < '0' || input[i] > '9') 
        {
            return false;  // Not a number
        }
    }
    return true;  // It's a number
}

bool isAlphabet(string input) 
{
    for (int i = 0; i < input.length(); i++) 
    {
        if (!((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z'))) 
        {
            return false;  // Not an alphabet
        }
    }
    return true;  // All characters are alphabets
}
/*------------------------------------------------VETERINARIAN------------------------------------------------*/

/*------------------------------------------------VETERINARIAN MENU-------------------------------------------*/
void veterinarianMenu()
{
  
  system("cls");
  header();
  SetConsoleTextAttribute(h,2);
  cout <<"\t\t\t\t\t(:Veterinarian LOGIN:)"<<endl;
  cout <<endl<<endl;
  SetConsoleTextAttribute(h,15);
  cout <<"\t\tChoose what you want to do...."<<endl<<endl;
  SetConsoleTextAttribute(h,11);
  cout <<"\t\t\t1:Register new Pet "<<endl;
  cout <<"\t\t\t2:Update Treatment Plan"<<endl;
  cout <<"\t\t\t3:Generate Health Report"<<endl;
  cout <<"\t\t\t4:Delete Report"<<endl;
  cout <<"\t\t\t5:Record Vaccination status"<<endl;
  cout <<"\t\t\t6:Check Vaccination Status"<<endl;
  cout <<"\t\t\t7:Weekly schedule"<<endl;
  cout <<"\t\t\t8:Exit"<<endl<<endl;
        
  SetConsoleTextAttribute(h,7); 
}
/*------------------------------------------------VETERINARIAN CHECKIN----------------------------------------*/

string veterinarianCheckIn()
{
  string option;
  
  SetConsoleTextAttribute(h,15);
  cout <<"\t\tEnter Your Option (1 to 7):";
  SetConsoleTextAttribute(h,8);
  cin >> option;
        
  SetConsoleTextAttribute(h,7); 
  return option;
}
/*-----------------------------------------------REGISTER PET---------------------------------------------------*/

void registerPetMenu(int& count,string name[],string petName[],string specie[],string gender[],string age[],string history[],string food[],string updatedDisease[],string updatedMedicine[])
{
  

            
  SetConsoleTextAttribute(h,11);
  cout <<endl<<"\t\t\tEnter Owner's Full name :";
  SetConsoleTextAttribute(h,8);
  cin.ignore();
  getline(cin,name[count]);

  SetConsoleTextAttribute(h,11);
  cout <<"\t\t\tEnter Pet's name :";
  SetConsoleTextAttribute(h,8);
  getline(cin,petName[count]);

  SetConsoleTextAttribute(h,11);
  cout <<"\t\t\tEnter Pet's Specie :";
  SetConsoleTextAttribute(h,8);
  getline(cin,specie[count]);

  SetConsoleTextAttribute(h,11);
  cout <<"\t\t\tEnter Pet's Gender :";
  SetConsoleTextAttribute(h,8);
  getline(cin,gender[count]);

  SetConsoleTextAttribute(h,11);
  cout <<"\t\t\tEnter Estimated age :";
  SetConsoleTextAttribute(h,8);
  cin >> age[count];
  cin.ignore();

  SetConsoleTextAttribute(h,11);
  cout <<"\t\t\tEnter Vaccination history :";
  SetConsoleTextAttribute(h,8);
  cin.ignore();
  getline(cin,history[count]);

  SetConsoleTextAttribute(h,11);
  cout <<"\t\t\tEnter type of food and feeding schedule :";
  SetConsoleTextAttribute(h,8);
  getline(cin,food[count]);

  SetConsoleTextAttribute(h,11);
  cout <<"\t\t\tEnter the current disease :";
  SetConsoleTextAttribute(h,8);
  getline(cin,updatedDisease[count]);

  SetConsoleTextAttribute(h,11);
  cout <<"\t\t\tEnter the current medicine :";
  SetConsoleTextAttribute(h,8);
  getline(cin,updatedMedicine[count]);
  count++;
}
/*-------------------------------------------------UPDATE MENU------------------------------------------------*/
void updatePetMenu(int& count,string name[],string petName[],string specie[],string gender[],string age[],string history[],string food[],string updatedDisease[],string updatedMedicine[])
{
string updatedName;
string updatedPetName;
string updatedSpecie;
string updatedHistory;
string updatedFood;
string updatedGender;
string updatedDisease1;
string updatedMedicine1;
string updatedAge;
HANDLE h=
GetStdHandle(STD_OUTPUT_HANDLE);

SetConsoleTextAttribute(h,11);
cout <<" please write updated name :";
SetConsoleTextAttribute(h,8);
cin.ignore();
getline(cin,updatedName);

SetConsoleTextAttribute(h,11);
cout <<" please write pet's updated name :";
SetConsoleTextAttribute(h,8);
getline(cin,updatedPetName);

SetConsoleTextAttribute(h,11);
cout <<" please write updated specie :";
SetConsoleTextAttribute(h,8);
getline(cin,updatedSpecie);

SetConsoleTextAttribute(h,11);
cout <<" please write updated age :";
SetConsoleTextAttribute(h,8);
cin >>updatedAge;
cin.ignore();

SetConsoleTextAttribute(h,11);
cout <<" Enter Gender :";
SetConsoleTextAttribute(h,8);
getline(cin,updatedGender);

SetConsoleTextAttribute(h,11);
cout <<" Enter current disease :";
SetConsoleTextAttribute(h,8);
getline(cin,updatedDisease1);

SetConsoleTextAttribute(h,11);
cout <<" Updated food schedule :  ";
SetConsoleTextAttribute(h,8);
getline(cin,updatedFood);

SetConsoleTextAttribute(h,11);
cout <<" Enter current Medicine :";
SetConsoleTextAttribute(h,8);
getline(cin,updatedMedicine1);

SetConsoleTextAttribute(h,11);
cout <<" Enter current Vaccination History :";
SetConsoleTextAttribute(h,8);
getline(cin,updatedHistory);

name[count]=updatedName;
petName[count]=updatedPetName;
specie[count]=updatedSpecie;
age[count]=updatedAge;
gender[count]=updatedGender;
history[count]=updatedHistory;
updatedDisease[count]=updatedDisease1;
food[count]=updatedFood;
updatedMedicine[count]=updatedMedicine1;

SetConsoleTextAttribute(h,11);
}
/*--------------------------------------------SEARCH NAME TO UPDATE DATA---------------------------------------*/
int searchName(int& count,string name[],string updatedDisease[])  
{
  
  string searchName;
  string currentDisease;
  bool found=false; 
  
    SetConsoleTextAttribute(h,11);
    cout <<"\t\t\t Enter the name of owner for furthur process : ";
    SetConsoleTextAttribute(h,8);
    cin>> searchName;
     SetConsoleTextAttribute(h,11);
    cout <<"\t\t\t Enter Disease of your Pet : ";
    SetConsoleTextAttribute(h,8);
    cin >> currentDisease;

      for(int i=0;i<count;i++)
      {
        if(name[i]==searchName && updatedDisease[i]==currentDisease)
          {
            found=true;
            return i;
          }
     }
     return -1;
  }
         
/*-----------------------------------------------CHECK REPORT-------------------------------------------------*/

void checkReport(int& index,string name[],string petName[],string specie[],string gender[],string age[],string history[],string food[],string updatedDisease[],string updatedMedicine[])
{
 
  
    if(index>=0&&index<15)
      {
       SetConsoleTextAttribute(h,15);
       cout <<" \tThe report of Patient is given below :"<<endl<<endl;
       SetConsoleTextAttribute(h,10);
       cout <<"Name of Customer is   :"<<name[index]<<endl;
       cout <<"Name of Pet is   :"<<petName[index]<<endl;
       cout <<"Name of Specie is   :"<<specie[index]<<endl;
       cout <<"Gender of pet is   :"<<gender[index]<<endl;
       cout <<"Age of Pet is   :"<<age[index]<<endl;
       cout <<"Vaccination history of pet    :"<<history[index]<<endl;
       cout <<"Type of food and feeding schedule    :"<<food[index]<<endl;
       cout <<"Current Disease    :"<<updatedDisease[index]<<endl;
       cout <<"Current Vaccination   :"<<updatedMedicine[index]<<endl;
      } 
          
      SetConsoleTextAttribute(h, 7);
}
/*------------------------------------------------DELETE PET RECORD----------------------------------------------*/

int searchPetName(int& count,string petName[],string updatedDisease[])
{
  
  string petNameToDelete;
  string updatedDiseaseFind;
  bool found=false; 
  
    SetConsoleTextAttribute(h,11);
    cout <<"\t\t\t Enter the pet name to delete: ";
    SetConsoleTextAttribute(h,8);
    cin>> petNameToDelete;
    SetConsoleTextAttribute(h,11);
    cout <<"\t\t\t Enter the disease of pet :";
    SetConsoleTextAttribute(h,8);
    cin >> updatedDiseaseFind;

      for(int i=0;i<count;i++)
      {
        if(petName[i]==petNameToDelete && updatedDisease[i]==updatedDiseaseFind)
          {
            found=true;
            return i;
          }
     }
     return -1; 
}

/*---------------------------------------------DELETE DATA------------------------------------------------------*/

void deletePetData(int& count,int index,string name[],string petName[],string specie[],string gender[],string age[],string history[],string food[],string updatedDisease[],string updatedMedicine[])
{
  for(int i=index;i<count-1;i++)
  {
    name[i]=name[i+1];
    petName[i]=petName[i+1];
    specie[i]=specie[i+1];
    gender[i]=gender[i+1];
    age[i]=age[i+1];
    history[i]=history[i+1];
    food[i]=food[i+1];
    updatedDisease[i]=updatedDisease[i+1];
    updatedMedicine[i]=updatedMedicine[i+1];
  }
  count--;
}
/*----------------------------------------------RECORD VACCINATION STATUS------------------------------------*/

void recordVaccineStatus(int& count,string petID[],string vaccineType[],string vaccinationDate[],string nextDueDate[],string dosage[],string reactionafterVaccine[])
{
  
           
  SetConsoleTextAttribute(h,11);
  cout <<"\t\t\tEnter Pet ID :";
  SetConsoleTextAttribute(h,8);
  cin.ignore();
  getline(cin,petID[count]);

  SetConsoleTextAttribute(h,11);
  cout <<"\t\t\tEnter Vaccine type :";
  SetConsoleTextAttribute(h,8);
  getline(cin,vaccineType[count]);

  SetConsoleTextAttribute(h,11);
  cout <<"\t\t\tEnter Vaccination Date :";
  SetConsoleTextAttribute(h,8);
  getline(cin,vaccinationDate[count]);

  SetConsoleTextAttribute(h,11);
  cout <<"\t\t\tEnter Next due date :";
  SetConsoleTextAttribute(h,8);
  getline(cin,nextDueDate[count]);

  SetConsoleTextAttribute(h,11);
  cout <<"\t\t\tEnter Dosage of Vaccine if applicable :";
  SetConsoleTextAttribute(h,8);
  getline(cin,dosage[count]);

  SetConsoleTextAttribute(h,11);
  cout <<"\t\t\tAny reaction after Vaccination :";
  SetConsoleTextAttribute(h,8);
  getline(cin,reactionafterVaccine[count]);
       
  count++;
  SetConsoleTextAttribute(h, 7); 

}
/*------------------------------------------------SEARCH PET ID--------------------------------------------------*/

int searchID(int& count,string petID[])
{
  
  string petIDs;
  bool found=false; 
  
    SetConsoleTextAttribute(h,11);
    cout <<"\t\t\t Enter the pet ID for furthur process: ";
    SetConsoleTextAttribute(h,8);
    cin>> petIDs;

      for(int i=0;i<count;i++)
      {
        if(petID[i]==petIDs)
          {
            found=true;
            return i;
          }
     }
     return -1;
  }


/*-----------------------------------------------DISPLAY VACCINE DATA-----------------------------------------*/

void displayVaccineStatus(int& index,string petID[],string vaccineType[],string vaccinationDate[],string nextDueDate[],string dosage[],string reactionafterVaccine[])
{
  
           if(index>=0&&index<15)
           {
             SetConsoleTextAttribute(h,15);
             cout <<"Vaccination status is given below :"<<endl<<endl;
             SetConsoleTextAttribute(h,10);
             cout <<"The Pet ID is :"<<petID[index]<<endl;
             cout <<"Vaccine Type is :"<<vaccineType[index]<<endl;
             cout <<"Vaccination Date is :"<<vaccinationDate[index]<<endl;
             cout <<"Next Due Date is :"<<nextDueDate[index]<<endl;
             cout <<"Dosage of medicine is :"<<dosage[index]<<endl;
             cout <<"Reaction of medicine is :"<<reactionafterVaccine[index]<<endl;
           }
           SetConsoleTextAttribute(h,7);
}
/*-----------------------------------------------SEARCH DAY------------------------------------------------------ */

string daySearch()
{
  
  string day;
  SetConsoleTextAttribute(h,15);
  cout <<"Enter day to check schedule :";
  SetConsoleTextAttribute(h,8);
  cin >> day;
  SetConsoleTextAttribute(h,7);
  return day;
}
/*-----------------------------------------------MONDAY---------------------------------------------------------*/

void monday()
{
   
  
    SetConsoleTextAttribute(h,13);
    cout <<"\t\t\t\t\t Monday schedule is :";
    cout<< endl<<endl;
    SetConsoleTextAttribute(h,11);
    cout << "\t8:00 AM - 9:00 AM: " ;
    SetConsoleTextAttribute(h,8);
    cout << "Morning briefing with clinic staff :"<<endl;
    SetConsoleTextAttribute(h,11);
    cout << "\t9:00 AM - 12:00 PM: " ;
    SetConsoleTextAttribute(h,8);
    cout << "Consultations (Initial check-ups, routine exams)"<<endl;
    SetConsoleTextAttribute(h,11);
    cout << "\t12:00 PM - 1:00 PM: ";
    SetConsoleTextAttribute(h,8);
    cout << "Lunch break" <<endl;
    SetConsoleTextAttribute(h,11);
    cout << "\t1:00 PM - 3:00 PM: ";
    SetConsoleTextAttribute(h,8);
    cout << "Surgery (Spaying, neutering, etc.)"<<endl;
    SetConsoleTextAttribute(h,11);
    cout << "\t3:00 PM - 5:00 PM: ";
    SetConsoleTextAttribute(h,8);
    cout << "Follow-up consultations and patient check-ins"<<endl;
    SetConsoleTextAttribute(h,11);
    cout << "\t5:00 PM - 6:00 PM: ";
    SetConsoleTextAttribute(h,8);
    cout << "Administrative tasks (update patient records, respond to emails)"<<endl;
    SetConsoleTextAttribute(h,7);
   
}
/*---------------------------------------------------TUESDAY------------------------------------------------*/

void tuesday()
{
   
    SetConsoleTextAttribute(h,13);
    cout <<"\t\t\t\tTuesday schedule is :";
    cout <<endl<<endl;
    SetConsoleTextAttribute(h,11);
    cout <<"\t8:00 AM - 9:00 AM: ";
    SetConsoleTextAttribute(h,8);
    cout <<"Morning briefing and review of urgent cases"<<endl;
    SetConsoleTextAttribute(h,11);
    cout <<"\t9:00 AM - 12:00 PM: ";
    SetConsoleTextAttribute(h,8);
    cout <<"Vaccinations (Routine vaccinations and boosters)"<<endl;
    SetConsoleTextAttribute(h,11);
    cout <<"\t12:00 PM - 1:00 PM: ";
    SetConsoleTextAttribute(h,8);
    cout <<"Lunch break"<<endl;
    SetConsoleTextAttribute(h,11);
    cout <<"\t1:00 PM - 3:00 PM: ";
    SetConsoleTextAttribute(h,8);
    cout <<"Diagnostics (Blood tests, x-rays, ultrasounds)"<<endl;
    SetConsoleTextAttribute(h,11);
    cout <<"\t3:00 PM - 5:00 PM: ";
    SetConsoleTextAttribute(h,8);
    cout << "Emergency consultations"<<endl;
    SetConsoleTextAttribute(h,11);
    cout <<"\t5:00 PM - 6:00 PM: ";
    SetConsoleTextAttribute(h,8);
    cout <<"Team debrief and review of difficult cases"<<endl;
    SetConsoleTextAttribute(h,7);
}
/*------------------------------------------------WEDNESDAY---------------------------------------------------*/

void wednesday()
{
      HANDLE h=
      GetStdHandle(STD_OUTPUT_HANDLE);
      SetConsoleTextAttribute(h,13);
      cout <<"\t\t\t\tSchedule of Wednesday is :";
      cout <<endl<<endl;
      SetConsoleTextAttribute(h,11);
      cout <<"\t8:00 AM - 9:00 AM: ";
      SetConsoleTextAttribute(h,8);
      cout <<"Morning briefing and case review"<<endl;
      SetConsoleTextAttribute(h,11);
      cout <<"\t9:00 AM - 12:00 PM: ";
      SetConsoleTextAttribute(h,8);
      cout <<"Consultations (Chronic illness management)"<<endl;
      SetConsoleTextAttribute(h,11);
      cout <<"\t12:00 PM - 1:00 PM: ";
      SetConsoleTextAttribute(h,8);
      cout <<"Lunch break";
      SetConsoleTextAttribute(h,11);
      cout <<"\t1:00 PM - 3:00 PM: ";
      SetConsoleTextAttribute(h,8);
      cout <<"Surgery (Orthopedic surgeries, dental procedures)"<<endl;
      SetConsoleTextAttribute(h,11);
      cout <<"\t3:00 PM - 5:00 PM: ";
      SetConsoleTextAttribute(h,8);
      cout <<"Follow-up consultations and post-surgery check-ups"<<endl;
      SetConsoleTextAttribute(h,11);
      cout <<"\t5:00 PM - 6:00 PM: ";
      SetConsoleTextAttribute(h,8);
      cout <<"Patient record updating"<<endl;
      SetConsoleTextAttribute(h,7);
}
/*---------------------------------------------THURSDAY------------------------------------------------------*/

void thursday()
{
      HANDLE h=
      GetStdHandle(STD_OUTPUT_HANDLE);
      SetConsoleTextAttribute(h,13);
      cout <<"\t\t\t\tSchedule for Thursday is :";
      cout << endl<<endl;
      SetConsoleTextAttribute(h,11);
      cout <<"\t8:00 AM - 9:00 AM: ";
      SetConsoleTextAttribute(h,8);
      cout <<"Morning briefing with clinic staff"<<endl;
      SetConsoleTextAttribute(h,11);
      cout <<"\t9:00 AM - 12:00 PM: ";
      SetConsoleTextAttribute(h,8);
      cout <<"Wellness exams (Routine check-ups for healthy pets)"<<endl;
      SetConsoleTextAttribute(h,11);
      cout <<"\t12:00 PM - 1:00 PM: ";
      SetConsoleTextAttribute(h,8);
      cout <<"Lunch break"<<endl;
      SetConsoleTextAttribute(h,11);
      cout <<"\t1:00 PM - 3:00 PM: ";
      SetConsoleTextAttribute(h,8);
      cout <<"Diagnostics (Emergency blood work, x-rays)"<<endl;
      SetConsoleTextAttribute(h,11);
      cout <<"\t3:00 PM - 5:00 PM: ";SetConsoleTextAttribute(h,8);
      cout <<"Pet owner consultations (Education on nutrition, behavior)"<<endl;
      SetConsoleTextAttribute(h,11);
      cout <<"\t5:00 PM - 6:00 PM: ";
      SetConsoleTextAttribute(h,8);
      cout <<"Review patient cases and prepare reports"<<endl;
      SetConsoleTextAttribute(h,7);
}
/*------------------------------------------------FRIDAY------------------------------------------------------*/

void friday()
{
      HANDLE h=
      GetStdHandle(STD_OUTPUT_HANDLE);
      SetConsoleTextAttribute(h,13);
      cout <<"\t\t\tSchedule for friday is ";
      cout << endl<<endl;
      SetConsoleTextAttribute(h,11);
      cout <<"\t8:00 AM - 9:00 AM: ";
      SetConsoleTextAttribute(h,8);
      cout <<"Morning briefing and patient update review"<<endl;
      SetConsoleTextAttribute(h,11);
      cout <<"\t9:00 AM - 12:00 PM: ";
      SetConsoleTextAttribute(h,8);
      cout <<"Surgery (Neutering, soft tissue surgeries)"<<endl;
      SetConsoleTextAttribute(h,11);
      cout <<"\t12:00 PM - 1:00 PM: ";
      SetConsoleTextAttribute(h,8);
      cout << "Lunch break"<<endl;
      SetConsoleTextAttribute(h,11);
      cout <<"\t1:00 PM - 3:00 PM: ";
      SetConsoleTextAttribute(h,8);
      cout <<"Pet behavioral consultations (Training and behavioral problems)"<<endl;
      SetConsoleTextAttribute(h,11);
      cout <<"\t3:00 PM - 5:00 PM: ";
      SetConsoleTextAttribute(h,8);
      cout <<"Urgent care and emergency consultations"<<endl;
      SetConsoleTextAttribute(h,11);
      cout <<"\t5:00 PM - 6:00 PM: ";
      SetConsoleTextAttribute(h,8);
      cout <<"Follow-up calls to pet owners"<<endl;
      SetConsoleTextAttribute(h,7);
}
/*--------------------------------------------------SATURDAY--------------------------------------------------*/

void saturday()
{
    
   
    SetConsoleTextAttribute(h,13);
    cout <<"\t\t\t\tSchedule for Saturday is :";
    cout <<endl<<endl;
    SetConsoleTextAttribute(h,11);
    cout <<"\t8:00 AM - 9:00 AM: ";
    SetConsoleTextAttribute(h,8);
    cout <<"Morning briefing with clinic staff"<<endl;
    SetConsoleTextAttribute(h,11);
    cout <<"\t9:00 AM - 12:00 PM: ";
    SetConsoleTextAttribute(h,8);
    cout <<"Routine check-ups and vaccinations"<<endl;
    SetConsoleTextAttribute(h,11);
    cout <<"\t12:00 PM - 1:00 PM: ";
    SetConsoleTextAttribute(h,8);
    cout <<"Lunch break"<<endl;
    SetConsoleTextAttribute(h,11);
    cout <<"\t1:00 PM - 3:00 PM: ";
    SetConsoleTextAttribute(h,8);
    cout <<"Emergency care (Acute conditions)"<<endl;
    SetConsoleTextAttribute(h,11);
    cout <<"\t3:00 PM - 5:00 PM: ";
    SetConsoleTextAttribute(h,8);
    cout <<"Review and follow-up on ongoing treatments"<<endl;
    SetConsoleTextAttribute(h,11);
    cout <<"\t5:00 PM - 6:00 PM: ";
    SetConsoleTextAttribute(h,8); 
    cout << "Administrative tasks and planning for next week"<<endl;
    SetConsoleTextAttribute(h,7);
}
/*-------------------------------------------------SUNDAY-----------------------------------------------------*/

void sunday()
{
  
    HANDLE h=
    GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,13);
    cout <<"\t\t\t\tSchedule for Sunday is ";
    cout <<endl<<endl;
    SetConsoleTextAttribute(h,11);
    cout <<"\t9:00 AM - 12:00 PM: ";
    SetConsoleTextAttribute(h,8);
    cout<< "Emergency on-call services (as needed)"<<endl;
    SetConsoleTextAttribute(h,11);
    cout <<"\t12:00 PM - 1:00 PM: ";
    SetConsoleTextAttribute(h,8);
    cout <<"Lunch break"<<endl;
    SetConsoleTextAttribute(h,11);
    cout <<"\t1:00 PM - 3:00 PM: ";
    SetConsoleTextAttribute(h,8);
    cout <<"Follow-up care and phone consultations (for pets that are recovering)"<<endl;
    SetConsoleTextAttribute(h,11);
    cout <<"\t3:00 PM - 5:00 PM: ";
    SetConsoleTextAttribute(h,8);
    cout <<"Light administrative work (cases review, emails, etc.)"<<endl;
    SetConsoleTextAttribute(h,11);
    cout <<"\t5:00 PM - 6:00 PM: ";
    SetConsoleTextAttribute(h,8);
    cout <<"Clinic cleaning and preparation for the next week"<<endl;
    SetConsoleTextAttribute(h,7);
}
/*----------------------------------------------CLINIC MANAGER----------------------------------------------- */

/*----------------------------------------------CLINIC MANAGER MENU-------------------------------------------*/
void clinicManagerMenu()
{
        HANDLE h=
        GetStdHandle(STD_OUTPUT_HANDLE);
        system("cls");
        header();
        SetConsoleTextAttribute(h,2);
        cout <<"\t\t\t\t\t(:Clinic Manager LOGIN:)"<<endl;
        cout <<endl<<endl;
        SetConsoleTextAttribute(h,15);
        cout <<"\t\tChoose what you want to do...."<<endl<<endl;
        SetConsoleTextAttribute(h,11);
        cout <<"\t\t\t1: Add New staff member"<<endl;
        cout <<"\t\t\t2: Update data of staff"<<endl;
        cout <<"\t\t\t3: Display the data of new staff"<<endl;
        cout <<"\t\t\t4: Remove an Employee"<<endl;
        cout <<"\t\t\t5: List of emergency Contacts"<<endl;
        cout <<"\t\t\t6: Employee Salary details"<<endl;
        cout <<"\t\t\t7: Exit"<<endl<<endl;
        SetConsoleTextAttribute(h,7); 
        
}
/*----------------------------------------CLINIC MANAGER CHECK IN--------------------------------------------*/

string clinicManagerCheckIn()
{      
       string option;
       HANDLE h=
       GetStdHandle(STD_OUTPUT_HANDLE);
       SetConsoleTextAttribute(h,15);
       cout << "\t\tEnter Your Option :" ;
       SetConsoleTextAttribute(h,8);
       cin >> option;
       SetConsoleTextAttribute(h,7); 
       return option;
}
/*-----------------------------------------------ADD NEW STAFF-------------------------------------------------------*/

void newStaffMenu(int& count,string memberName[],string phoneNumber[],string positionHolds[],string department[],string employeeID[],string date[],string location[])
{
  

  SetConsoleTextAttribute(h,11);
  cout <<"\t\t\tEnter the name of new member :";
  SetConsoleTextAttribute(h,8);
  cin.ignore();
  getline(cin,memberName[count]);
  

  SetConsoleTextAttribute(h,11);
  cout <<"\t\t\tEnter member's Phone number :";
  SetConsoleTextAttribute(h,8);
  getline(cin,phoneNumber[count]);

  SetConsoleTextAttribute(h,11);
  cout <<"\t\t\tEnter new member's position in clinic :";
  SetConsoleTextAttribute(h,8);
  getline(cin,positionHolds[count]);

  SetConsoleTextAttribute(h,11);
  cout <<"\t\t\tEnter Department of new member :";
  SetConsoleTextAttribute(h,8);
  getline(cin,department[count]);

  SetConsoleTextAttribute(h,11);
  cout <<"\t\t\tEnter Employee ID :";
  SetConsoleTextAttribute(h,8);
  getline(cin,employeeID[count]);

  SetConsoleTextAttribute(h,11);
  cout <<"\t\t\tEnter Start date :";
  SetConsoleTextAttribute(h,8);
  getline(cin,date[count]);

  SetConsoleTextAttribute(h,11);
  cout <<"\t\t\tEnter Work location :";
  SetConsoleTextAttribute(h,8);
  getline(cin,location[count]);

  count++;
}

/*-------------------------------------------SEARCH STAFF ID--------------------------------------------------------*/

int searchStaffID(int& count,string employeeID[])
{
  
  string staffEmployeeID;
  bool found=false; 
  
    SetConsoleTextAttribute(h,11);
    cout <<"\t\t\t Enter the employee ID : ";
    SetConsoleTextAttribute(h,8);
    cin>> staffEmployeeID;

      for(int i=0;i<count;i++)
      {
        if(employeeID[i]==staffEmployeeID)
          {
            found=true;
            return i;
          }
     }
     return -1; 
}
/*--------------------------------------------UPDATE EMPLOYEE DATA-------------------------------------------------*/
void updateStaffMenu(int& count,string memberName[],string phoneNumber[],string positionHolds[],string department[],string employeeID[],string date[],string location[])
{
string updatedMemberName;
string updatedPhoneNumber;
string updatedPositionHolds;
string updatedDepartment;
string updatedEmployeeID;
string updatedDate;
string updatedLocation;
HANDLE h=
GetStdHandle(STD_OUTPUT_HANDLE);

SetConsoleTextAttribute(h,11);
cout <<" please write updated member name :";
SetConsoleTextAttribute(h,8);
cin.ignore();
getline(cin,updatedMemberName);

SetConsoleTextAttribute(h,11);
cout <<" please write phone number :";
SetConsoleTextAttribute(h,8);
getline(cin,updatedPhoneNumber);

SetConsoleTextAttribute(h,11);
cout <<" please write updated position :";
SetConsoleTextAttribute(h,8);
getline(cin,updatedPositionHolds);

SetConsoleTextAttribute(h,11);
cout <<" please write updated department :";
SetConsoleTextAttribute(h,8);
getline(cin,updatedDepartment);

SetConsoleTextAttribute(h,11);
cout <<" Enter Employee ID :";
SetConsoleTextAttribute(h,8);
getline(cin,updatedEmployeeID);

SetConsoleTextAttribute(h,11);
cout <<" Enter current date :";
SetConsoleTextAttribute(h,8);
getline(cin,updatedDate);

SetConsoleTextAttribute(h,11);
cout <<" Updated location:  ";
SetConsoleTextAttribute(h,8);
getline(cin,updatedLocation);

memberName[count]=updatedMemberName;
phoneNumber[count]=updatedPhoneNumber;
positionHolds[count]=updatedPositionHolds;
department[count]=updatedDepartment;
employeeID[count]=updatedEmployeeID;
date[count]=updatedDate;
location[count]=updatedLocation;

SetConsoleTextAttribute(h,11);
}
/*----------------------------------------------REPORT OF STAFF----------------------------------------------------*/

void staffReport(int index,string memberName[],string phoneNumber[],string positionHolds[],string department[],string employeeID[],string date[],string location[])
{
  
           if(index>=0&&index<15)
           {
             SetConsoleTextAttribute(h,15);
             cout <<" \tThe report of Patient is given below :" <<endl<<endl;
             SetConsoleTextAttribute(h,10);
             cout <<"Name of staff member is   :"<<memberName[index]<<endl;
             cout <<"Phone Number of member is   :"<<phoneNumber[index]<<endl;
             cout <<"Position of member at clinic   :"<<positionHolds[index]<<endl;
             cout <<"Department of member is   :"<<department[index]<<endl;
             cout <<"Employee ID is   :"<<employeeID[index]<<endl;
             cout <<"Date to start work    :"<<date[index]<<endl;
             cout <<"Location of work    :"<<location[index]<<endl;
           
             
           } 
          
          SetConsoleTextAttribute(h, 7);

}
/*---------------------------------------------DELETE STAFF DATA-----------------------------------------------*/

void deleteStaffData(int& count,int index,string memberName[],string phoneNumber[],string positionHolds[],string department[],string employeeID[],string date[],string location[])
{
 for(int i=index;i<count-1;i++)
  {
    memberName[i]=memberName[i+1];
    phoneNumber[i]=phoneNumber[i+1];
    positionHolds[i]=positionHolds[i+1];
    department[i]=department[i+1];
    employeeID[i]=employeeID[i+1];
    date[i]=date[i+1];
    location[i]=location[i+1];
  }
  count--; 
}
/*----------------------------------------------SALARY MENU-------------------------------------------------------------*/


string salaryMenu()
{
  string salaryOption;
  cout <<"Whose Salary you want to check?";
  cout <<endl<<endl;
  cout <<"1: Veterinarian"<<endl;
  cout <<"2: Nurse"<<endl;
  cout <<"3: Receptionist"<<endl;
  cout <<"4: Cleaning staff"<<endl;
  cout << "Enter option :";
  cin >> salaryOption;
  return salaryOption;
}
// /*----------------------------------------VET SALARY-----------------------------------------------------------*/
int vetSalary()
{
  int days;
  cout <<"The actual salary of vet is  60000.00Rs"<<endl<<endl;
  cout <<"How many days have you been absent from your job?";
  cin >> days;
  if(days<=5)
  {
    cout <<"Salary is 60000.00Rs";
  }
  if(days>5&&days<=10)
  {
    cout <<"Salary is 55000.00Rs";
  }
  else if(days>10)
  {
    cout <<"\t\t\tYour off days are more; please contact the owner for salary details.";
  }
}
int nurseSalary()
{
  int days;
  cout <<"The actual salary of vet is  60000.00Rs"<<endl<<endl;
  cout <<"How many days have you been absent from your job?"<<endl;
  cout <<"Enter days :";
  cin >> days;
  if(days<=5)
  {
    cout <<"Salary is 45000.00Rs";
  }
  if(days>5&&days<=10)
  {
    cout <<"Salary is 35000.00Rs";
  }
  else if(days>10)
  {
    cout <<"\t\t\tYour off days are more; please contact the owner for salary details.";
  }
}
int receptionistSalary()
{
  int days;
  cout <<"The actual salary of vet is  60000.00Rs"<<endl<<endl;
  cout <<"How many days have you been absent from your job?";
  cin >> days;
  if(days<=5)
  {
    cout <<"Salary is 30000.00Rs";
  }
  if(days>5&&days<=10)
  {
    cout <<"Salary is 20000.00Rs";
  }
  else if(days>10)
  {
    cout <<"\t\t\tYour off days are more; please contact the owner for salary details.";
  }
}
int cleaningStaffSalary()
{
  int days;
  cout <<"The actual salary of vet is  60000.00Rs"<<endl<<endl;
  cout <<"How many days have you been absent from your job?";
  cin >> days;
  if(days<=5)
  {
    cout <<"Salary is 20000.00Rs";
  }
  if(days>5&&days<=10)
  {
    cout <<"Salary is 15000.00Rs";
  }
  else if(days>10)
  {
    cout <<"\t\t\tYour off days are more; please contact the owner for salary details.";
  }
}
/*---------------------------------------PET OWNER---------------------------------------------------------------*/

/*----------------------------------------PET OWNER MENU----------------------------------------------------------*/
void petOwnerMenu()
{        
        HANDLE h=
        GetStdHandle(STD_OUTPUT_HANDLE);
   
        system("cls");
        header();
        SetConsoleTextAttribute(h,2);
        cout <<"\t\t\t\t\t(:Pet Owner LOGIN:)"<<endl;
        cout <<endl<<endl;
        SetConsoleTextAttribute(h,15);
        cout <<"\t\tChoose what you want to do...."<<endl;
        SetConsoleTextAttribute(h,11);
        cout <<"\t\t\t1:Schedule Appointments"<<endl;
        cout <<"\t\t\t2:Add emergency Contact Information"<<endl;
        cout <<"\t\t\t3:Edit Contact Details"<<endl;
        cout <<"\t\t\t4:Remove outdated Emergency Contact Information"<<endl;
        cout <<"\t\t\t5:View list of saved Emergency Contact Information"<<endl;
        cout <<"\t\t\t6:Set Vaccinations Reminders"<<endl;
        cout <<"\t\t\t7:Access pet medical history"<<endl;
        cout <<"\t\t\t8:Exit"<<endl<<endl;
        SetConsoleTextAttribute(h,7); 
        
}
/*------------------------------------------PET OWNER CHECK IN -----------------------------------------------------*/
string petOwnerCheckIn()
{      
        HANDLE h=
        GetStdHandle(STD_OUTPUT_HANDLE); 
        string option;
        SetConsoleTextAttribute(h,15);
        cout<<"\t\tEnter Your Option :";
        SetConsoleTextAttribute(h,8);
        cin >> option;  
        SetConsoleTextAttribute(h,7); 
        return option;
}

/*------------------------------------------------SCHEDULE APPONINTMENTS------------------------------------------*/

void scheduleAppointments(int& count,string speciePet[],string vaccinationHistory[],string appointmentType[],string dateAppointment[])
{
  SetConsoleTextAttribute(h,11);
  cout <<"\t\t\tEnter specie of Pet :";
  SetConsoleTextAttribute(h,8);
  cin.ignore();
  getline(cin,speciePet[count]);
  

  SetConsoleTextAttribute(h,11);
  cout <<"\t\t\tEnter  vaccination history of pet :";
  SetConsoleTextAttribute(h,8);
  getline(cin,vaccinationHistory[count]);

  SetConsoleTextAttribute(h,11);
  cout <<"\t\t\tEnter appointment type(routine checkup,illness consultation,surgery) :";
  SetConsoleTextAttribute(h,8);
  getline(cin,appointmentType[count]);

  SetConsoleTextAttribute(h,11);
  cout <<"\t\t\tEnter Date of appointment  (7oct(Write in this format)) :";
  SetConsoleTextAttribute(h,8);
  getline(cin,dateAppointment[count]);

  SetConsoleTextAttribute(h,7);
}

/*-----------------------------------------------SEARCH PHONE NUMBER----------------------------------------------*/

int searchPhoneNumber(int& count,string ownerNumber[],string alternateNumber[])  
{
  
  string ownerPhoneNumber;
  string alternatePhoneNumber;
  bool found=false; 
  
    SetConsoleTextAttribute(h,11);
    cout <<"\t\t\t Enter the Phone number of owner for furthur process : ";
    SetConsoleTextAttribute(h,8);
    cin>> ownerPhoneNumber;
     SetConsoleTextAttribute(h,11);
    cout <<"\t\t\t Enter alternate number of owner  : ";
    SetConsoleTextAttribute(h,8);
    cin >> alternatePhoneNumber;

      for(int i=0;i<count;i++)
      {
        if(ownerNumber[i]==ownerPhoneNumber && alternateNumber[i]==alternatePhoneNumber)
          {
            found=true;
            return i;
          }
     }
     return -1;
  }

/*-----------------------------------------------EDIT CONTACT INFORMATION-------------------------------------------*/

void editEmergencyContact(int& count,string ownerName[],string ownerNumber[],string alternateNumber[],string emailAddress[],string homeAddress[])
{
string updatedOwnerName;
string updatedOwnerNumber;
string updatedAlternateNumber;
string updatedEmailAddress;
string updatedHomeAddress;

SetConsoleTextAttribute(h,11);
cout <<" please write updated Owner name :";
SetConsoleTextAttribute(h,8);
cin.ignore();
getline(cin,updatedOwnerName);

SetConsoleTextAttribute(h,11);
cout <<" please write updated phone number :";
SetConsoleTextAttribute(h,8);
getline(cin,updatedOwnerNumber);

SetConsoleTextAttribute(h,11);
cout <<" please write updated alternate number :";
SetConsoleTextAttribute(h,8);
getline(cin,updatedAlternateNumber);

SetConsoleTextAttribute(h,11);
cout <<" please write updated email address :";
SetConsoleTextAttribute(h,8);
getline(cin,updatedEmailAddress);

SetConsoleTextAttribute(h,11);
cout <<" please write updated home address :";
SetConsoleTextAttribute(h,8);
getline(cin,updatedHomeAddress);

ownerName[count]=updatedOwnerName;
ownerNumber[count]=updatedOwnerNumber;
alternateNumber[count]=updatedAlternateNumber;
emailAddress[count]=updatedEmailAddress;
homeAddress[count]=updatedHomeAddress;

SetConsoleTextAttribute(h,11);
}

/*------------------------------------------------REPORT OF EMERGENCY CONTACT-----------------------------------------*/

void emergencyContactReport(int index,string ownerName[],string ownerNumber[],string alternateNumber[],string emailAddress[],string homeAddress[])
{
if(index>=0&&index<15)
           {
             SetConsoleTextAttribute(h,15);
             cout <<" \tThe report of emergency contact is given below :" <<endl<<endl;
             SetConsoleTextAttribute(h,10);
             cout <<"Name of owner is   :"<<ownerName[index]<<endl;
             cout <<"Phone Number of owner is   :"<<ownerNumber[index]<<endl;
             cout <<"Alternate Phone Number is   :"<<alternateNumber[index]<<endl;
             cout <<"Email Address of owner is   :"<<emailAddress[index]<<endl;
             cout <<"Home Address of owner is    :"<<homeAddress[index]<<endl;
           } 
          
          SetConsoleTextAttribute(h, 7);
}

/*---------------------------------------------DELETE EMERGENCY CONTACT------------------------------------------*/

void deleteEmergencyContact(int& count,int index,string ownerName[],string ownerNumber[],string alternateNumber[],string emailAddress[],string homeAddress[])
{
  for(int i=index;i<count-1;i++)
  {
    ownerName[i]=ownerName[i+1];
    ownerNumber[i]=ownerNumber[i+1];
    alternateNumber[i]=alternateNumber[i+1];
    emailAddress[i]=emailAddress[i+1];
    homeAddress[i]=homeAddress[i+1];
  }
  count--; 
}
/*-----------------------------------------------REMAINDERS CHECK IN ---------------------------------------------*/

int remainderCheckIn(int& count,string speciePet[],string dateAppointment[])
{
  
  string speciePetToCheck;
  string dateToCheck;
  bool found=false; 
  
    SetConsoleTextAttribute(h,11);
    cout <<"\t\t\t Enter the specie of pet to see schedule/remainder: ";
    SetConsoleTextAttribute(h,8);
    cin>> speciePetToCheck;
    SetConsoleTextAttribute(h,11);
    cout <<"\t\t\t Enter the date of setting schedule ( 9may(write in this format)):";
    SetConsoleTextAttribute(h,8);
    cin >> dateToCheck;

      for(int i=0;i<count;i++)
      {
        if(speciePet[i]==speciePetToCheck && dateAppointment[i]==dateToCheck)
          {
            found=true;
            return i;
          }
     }
     return -1; 
}
/*------------------------------------------------REMAINDERS REPORT-------------------------------------------*/

void remaindersReport(int index,string speciePet[],string vaccinationHistory[],string appointmentType[],string dateAppointment[])
{
  
           if(index>=0&&index<15)
           {
             SetConsoleTextAttribute(h,15);
             cout <<" \tThe remainder of Patient is given below :" <<endl<<endl;
             SetConsoleTextAttribute(h,10);
             cout <<"Specie of pet is   :"<<speciePet[index]<<endl;
             cout <<"Vaccination History of Pet is   :"<<vaccinationHistory[index]<<endl;
             cout <<"Appointment Type of Pet   :"<<appointmentType[index]<<endl;
             cout <<"Date of Appointment   :"<<dateAppointment[index]<<endl;
           } 
          
          SetConsoleTextAttribute(h, 7);

}

/*----------------------------------------------ADD EMERGENCY CONTACTS-------------------------------------------*/

void addEmergencyContact(int& count,string ownerName[],string ownerNumber[],string alternateNumber[],string emailAddress[],string homeAddress[])
{
  SetConsoleTextAttribute(h,11);
  cout <<"\t\t\tEnter the name of owner :";
  SetConsoleTextAttribute(h,8);
  cin.ignore();
  getline(cin,ownerName[count]);
  

  SetConsoleTextAttribute(h,11);
  cout <<"\t\t\tEnter owner's phone number :";
  SetConsoleTextAttribute(h,8);
  getline(cin,ownerNumber[count]);

  SetConsoleTextAttribute(h,11);
  cout <<"\t\t\tEnter owner's alternate phone number :";
  SetConsoleTextAttribute(h,8);
  getline(cin,alternateNumber[count]);

  SetConsoleTextAttribute(h,11);
  cout <<"\t\t\tEnter email address of owner :";
  SetConsoleTextAttribute(h,8);
  getline(cin,emailAddress[count]);

  SetConsoleTextAttribute(h,11);
  cout <<"\t\t\tEnter home address of owner :";
  SetConsoleTextAttribute(h,8);
  getline(cin,homeAddress[count]);

  SetConsoleTextAttribute(h,7);
}
/*------------------------------------------------HEADER------------------------------------------------------*/


void header()
{
    
  SetConsoleTextAttribute(h,13);
    cout << R"(
             
     
        , __                                             ___  _                            _                     
       /|/  \                                     |     / (_)| |                          | | o          o       
        |___/ __,           ,     __,   _  _    __|    |     | |  __,           ,     __  | |     _  _       __  
        |    /  |  |  |  |_/ \_  /  |  / |/ |  /  |    |     |/  /  |  |  |  |_/ \_  /    |/  |  / |/ |  |  /    
        |    \_/|_/ \/ \/   \/   \_/|_/  |  |_/\_/|_/   \___/|__/\_/|_/ \/ \/   \/   \___/|__/|_/  |  |_/|_/\___/
                                                                                                           
                                                                                                           

 )";
    cout <<endl<<endl;
    SetConsoleTextAttribute(h,7);
}