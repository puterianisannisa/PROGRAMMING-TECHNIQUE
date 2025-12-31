#include <iostream>
using namespace std;

void dispStatus(int naccases){
    if (naccases>40)
        cout<<"Status:      Red Zone"<<endl;
    else if((naccases>=21) && (naccases<=40))
        cout<<"Status:       Orange Zone"<<endl;
    else if ((naccases>=1) && (naccases<=20))
        cout<<"Status:       Yellow Zone"<<endl;
    else 
        cout<<"Status:       Green Zone"<<endl;
}
void getInput(int &tcases,int &newc,int &d,int &r){
    cout<<"Total cases:    ";
    cin>>tcases;
    cout<<"New cases:      ";
    cin>>newc;
    cout<<"Total death:    ";
    cin>>d;
    cout<<"Total recovered: ";
    cin>>r;
}

void dispOutput(int naccases){
    cout<<"\n<<<<<<<<<<<<<<< SUMMMARY >>>>>>>>>>>>>>"<<endl;
    cout<<"Active cases: "<<naccases<<endl;
    dispStatus(naccases);
}

double calcAverage (int numstates,int taccases){
    double ave = static_cast <double> (taccases/numstates);
    return ave;

}

int main(){
    int i=0;
    
    char enter;
    char statename[25];
    int cases,totalcases=0,newcases,deaths,recovered,activecases=0;
    int highestcases=0;
    char hstates[25]="";


    do{
        i++;
        
        cout<<"<<<<<<<<<<<<<< DATA >>>>>>>>>>>>>>"<<endl;
        cout<<"State name:    ";
    
        cin.getline(statename,25);

        getInput(cases,newcases,deaths,recovered);

        activecases= cases + newcases - deaths - recovered;
        totalcases+=activecases;
        if (activecases>highestcases)
        {
            highestcases=activecases;
            for (int j=0;j<25;j++){
            hstates[j]=statename[j];}
            
        }
        dispOutput(activecases);
        
        cout<<"\nPress <ENTER> to continue ..."<<endl;
        cin.ignore();
        cin.get(enter);

    }while (enter=='\n');

    cout<<"<<<<<<<<<<<<<< ACTIVE CASES : >>>>>>>>>>>>"<<endl;
    cout <<"Total     : "<< totalcases <<endl;
    cout <<"Highest   : "<< highestcases << " ( "<< hstates <<" )"<< endl;
    double average =calcAverage(i,totalcases);
    cout <<"Average for " << i <<" states: "<< average << endl;
    return 0;
}
