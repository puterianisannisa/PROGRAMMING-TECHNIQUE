/*Name : QISTINA BATRISYIA BINTI NOOR MOHD AZLAN (A25CS0340)
         PUTERI ANIS ANNISA BINTI MAT LAZIM (A25CS0339 )
  Date : 25/12/2025*/


  #include <iostream>
  #include <iomanip>
  #include <cmath>
  using namespace std;

  //function prototype
  int ageRange(int& age);
  char genderType(char& gender);
  double calcBMR(int& weight,int& height,int age,char gender);
  void displayOutput(double BMR);


  int main(){
  
    //Variable declaration
    int age,height,weight;
    char gender;
    //For main loop
    char yesOrno;
    do{
    cout<< "Basal Metabolic Rate (BMR) Calculator"<<endl;
    ageRange(age);
    genderType(gender);

    cout<<"Height (cm):";
    cin>>height;


    cout<<"Weight (kg):" ;
    cin>>weight;
    double BMR =calcBMR(weight,height,age,gender);
    displayOutput(BMR);

    cout<<"Do you want to enter another data? [Y @ N]:";
    cin>>yesOrno;

    if(yesOrno=='N'||yesOrno=='n')
        cout<<"\nThank you :)"<<endl;

    }while (yesOrno=='Y'||yesOrno=='y');
    return 0;
  }

   


  int ageRange(int& age)
  {  
    do
    {
        cout<<"Age [15-80]: ";
        cin>>age;
        if(age>=15&&age<=80)
        continue;
    }while(age<15||age>80);
   return age;
}
 


char genderType(char& gender)
{
    do
    {
        cout<<"Gender [F @ M]: ";
        cin>>gender;
        if (gender=='F'||gender=='M'||gender=='f'||gender=='m')
            continue;
    }while(gender!='F'&&gender!='M'&&gender!='f'&&gender!='m');
    return gender;
}


double calcBMR(int& weight,int& height,int age,char gender){
    double BMR;
    if(gender =='M'||gender=='m')
        BMR=(10.0*weight)+ (6.25*height)-(5.0*age) + 5.0;
    else
        BMR=(10.0*weight)+(6.25*height)-(5.0*age)-161.0 ;
    cout<<fixed<<setprecision(2);
    cout<<"BMR = "<<BMR<<" Calories / day (using Mifflin-St Jeor Equation)"<<endl;
    return BMR;
}


void displayOutput(double BMR){
    cout<<endl;
    cout<< "Daily calories needs based on activity level"<<endl<<endl;
    cout<<"Activity level\t\t\t\t\t\t\t"<<"Calories"<<endl;
    cout<<"Sedentary: little or no exercise\t\t\t\t"<<static_cast<int>(round(BMR*1.2))<<endl;
    cout<<"Exercise 1-3 times/week\t\t\t\t\t\t"<<static_cast<int>(round(BMR*1.375))<<endl;
    cout<<"Exercise 4-5 times/week\t\t\t\t\t\t"<<static_cast<int>(round(BMR*1.465))<<endl;
    cout<<"Daily exercise or intense exercise for 3-4 times/week\t\t"<<static_cast<int>(round(BMR*1.55))<<endl;
    cout<<"Intense exercise 6-7 times/week\t\t\t\t\t"<<static_cast<int>(round(BMR*1.725))<<endl;
    cout<<"Very intense exercise daily, or physical job\t\t\t" <<static_cast<int>(round(BMR*1.9))<<endl;
    cout<<endl;
    cout<<"Exercise: 15-30 minutes of elevated heart rate activity."<<endl;
    cout<<"Intense activity: 45-120 minutes of elevated heart rate activity."<<endl;
    cout<<"Very intense activity: 2+ hours of elevated heart rate acitivty."<<endl;
}