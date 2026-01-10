/* Name : 
   1. Puteri Anis Annisa binti Mat Lazim (A25CS0339)
   2.Qistina Batrisyia binti Noor Mohd Azlan (A25CS0340)
   Date: 9 January 2026
   Assignment 3 (Set 1)*/

#include <iostream>
#include<iomanip>
#include<fstream>
using namespace std;


const int sizerow=12;
const int sizecolumn=7;
const int numteam=3;


void displayLine(ofstream& outFile);
int findIndWinner(int tp[]);
int findTeamWinner(int tt[]);



int main(){
    ifstream inFile;
    int marks [sizerow][sizecolumn];
    inFile.open("input.txt");
    if(!inFile){
      cout << "Sorry, input file does not exist! Press any key to continue . . ." << endl;
      return 0;
      }

    int r,c;
    for ( r=0;r<sizerow;r++){
        for ( c=0;c<sizecolumn;c++){
            inFile >> marks[r][c] ;
        }
    }
    inFile.close();
    int totalp[sizerow]={0},totalt[numteam]={0};
    for ( r=0;r<sizerow;r++){
        for ( c=2;c<sizecolumn;c++){
            totalp[r]+=marks[r][c];
    }}

    int highp=findIndWinner( totalp);

    for(r=0;r<4;r++){
         totalt[0]+=totalp[r];   
        }
    for(r=4;r<8;r++){
         totalt[1]+=totalp[r]; 
        }
    for(r=8;r<12;r++){
         totalt[2]+=totalp[r]; 
        }

    int hight=findTeamWinner(totalt);
    
    ofstream outFile;
    outFile.open("out.txt");

   if (!outFile){
      cout<< "Cannot open output file" <<endl;
      return 0;
   }

   displayLine(outFile);
   outFile<<endl<<"Id"<<setw(9)<<"E1"<<setw(7)<<"E2"<<setw(7)<<"E3"<<setw(7)<<"E4"<<setw(7)<<"E5"<<setw(12)<<"Total"<<endl;
    int i=0;
    while(i<numteam){
        displayLine(outFile);
        outFile<<"\nTEAM "<<(i+1)<<endl;
        int s=i*4;
        int e=s+4;
        for ( r=s;r<e;r++){
            for ( c=1;c<sizecolumn;c++){
            outFile << marks[r][c] <<setw(7);
          
        }
    outFile << "    "<<totalp [r]<<endl ;  
    }
    outFile<<"TOTAL"<<setw(44) << totalt[i] <<endl;          
    i++;  }

    displayLine(outFile);

    outFile<<"\n\nWinner for Individual Category: "<<marks[highp][1]<<" (Team "<<(marks[highp][1]/1000)<<")"<<endl;
    outFile<<"Winner for Group Category: Team "<<hight<<" (Score = "<<totalt[hight]<<")"<<endl;
        
   outFile.close();

    return 0;   
    }
    


void displayLine(ofstream& outFile){
    for (int l=0;l<53;l++){
        outFile<<"-";
    }
}

int findIndWinner(int tp[]){
    int highestin=0;
    int winp =0;
    for(int i=0;i<sizerow;i++){
        if(tp[i]>highestin){
            highestin=tp[i];
            winp=i;}
    }
    return winp;
}

int findTeamWinner(int tt[]){
    int highestteam=0;
    int wint=0;
    for(int i=0;i<3;i++){
        if(tt[i]>highestteam){
            highestteam=tt[i];
            wint=i;}
    }
    return wint;
}
