/* Name: Puteri Anis Annisa binti Mat Lazim
   Mactric: A25CS0339
   Date : 9/1/2026 */

#include <iostream>
#include <fstream>
#include<iomanip>
#include<cmath>

using namespace std;

const int SIZE =8;

void readFile(const string& ,double f[] ,int&);
void computeC(double f[],double c[],int);
double average(double c[],int);
char grade (double c);
void writeFile (double f[],double c[],int,const string&);

int main(){
   double farenheit [SIZE];
   double celcius [SIZE];

   int d=0;
   readFile("extension.txt", farenheit ,d);
   computeC ( farenheit ,celcius,d);
   double ave=average(celcius,d);
   int Hnum=0,Mnum=0,Lnum=0;
   char ans;
   for ( int i=0;i<d;i++){
      ans = grade (celcius[i]);
       if (ans == 'H')
         Hnum++;
      else if (ans == 'M')
         Mnum++;
      else
         Lnum++;
   }

   cout<<fixed<<setprecision(1)<<"Average of the temperature in Celcius: "<<ave<<endl;
   cout<<"Number of high temperature: "<<Hnum<<endl;
   cout<<"Number of medium temperature: "<<Mnum<<endl;
   cout<<"Number of low temperature: "<<Lnum<<endl;

   writeFile(farenheit,celcius,d,"output.txt");
   return 0;

}

void readFile( const string& file ,double F[],int& D){
   ifstream inputFile(file);

   if(!inputFile){
      cout << "While opening a file an error is encountered" << endl;
      D=0;}

   double value;
   D=0;
   while (D < SIZE){
      inputFile >> value;
      F[D]=value;
      D++;}

      inputFile.close();
   }

void computeC(double f[] ,double c[],int d){
   for (int j =0;j<SIZE;j++){
      c[j]= (5.0/9.0) * (f[j] - 32.0);
   }
}

double average(double c[],int d){
   double total=0;
   for ( int k=0 ;k<d;k++){
      total+=c[k];
   }
   return total/d;
}

char grade (double C){
      if (C>=35)
         return 'H';
      else if (C<35 && C >= 20)
         return 'M';
      else
         return 'L';
}

void writeFile (double f[],double c[], int d , const string& file ){
   ofstream outputFile(file);

   if (!outputFile){
      cout<< "Cannot open output file" <<endl;
   }

   outputFile<<fixed<<setprecision(2);

   outputFile<<setw(15)<<"C(Celcius)"<<setw(20)<<"F(Farenheit)"<<setw(20)<<"Description"<<endl;
   outputFile<<setw(15)<<"=========="<<setw(20)<<"============"<<setw(20)<<"==========="<<endl;

   for ( int i=0;i<d;i++){
      char g = grade(c[i]);
      outputFile<<right<<setw(13)<<c[i]<<setw(19)<<f[i]<<setw(17)<<g<<endl;  
   }
   outputFile.close();
}


