#include <iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <math.h>
#include <set>
#include <random>
#include <typeinfo>
#include <ctype.h>


using namespace std;



/*


 &&&&&&&&&&&&&&     * عملت التدقيق *           &&&&&&&&&&&&&&&&&
 

*/
  



  // function to make uppercase
  string tu(string s){
    string re;
    for(char x :s){
re+=toupper(x);
    }
    return re;
  }

class player
{
private:
    vector <int>cards{};
    vector <int>c {-1,0,1,3,2,2,9,1,0,20,0,1,2,-1,5,7,77,4,2,1,3,6,6,8,10,7,2,77,3,4,5,6,7,8,9,10,20};

public:


string name;
    char swapp;
    int ptsw;
    int cts;
    int ctsw;
    int ctcic;

    char screw='n';
    int scoore=0;         //for final scoore after all rounds

    int rscoore=0; // the scoore for one round           
    int rwinn=0;


//show the cards
void see(){
    for (int i:cards)
    {
cout << i <<",";   

 }
 cout << "\n";
    
}//end show


//function to swap cards with other player
void SwapCard(player& other , int yc , int oc ){
    swap(cards[yc-1],other.cards[oc-1]);
}




//one player raound 
void round(){

char wantCard;
char needCard;    
int exc = c[rand() % size(c)];

cout<< "\n  || " << tu(name) <<" RAOUND ||\n\n";

// player cards
cout <<"       *,"<< cards[1]<< ",*,"<<cards[3]<<"\n";
// ask to take or drowb
cout<< "do you want card ? y/n \n";
cin>>wantCard;
//to handel with new card case
if (wantCard=='y')
{


cout <<  exc << "\ndo you need  this one ? y/n \n";
cin >> needCard;
 if (needCard=='y')
 {
    int ctd;
    cout << "\nwitch card you want to drowb ? \n";
    cin >> ctd;
        cout << "\nyou lost "<<cards.at(ctd-1) << "\n";

if (cards.at(ctd-1)==77) 
{
  

    cout << "\ndo you want swap ? \n"; // ask for swap
cin >> swapp;
if (swapp=='y')
{
    ctcic=cards.at(ctd-1);
    cout << "\nselect player and card to swap : \n your card , witch player , witch card : ";
    cin>>cts >> ptsw >> ctsw;
    
}

    cards.at(ctd-1)=exc;




}else{ cards.at(ctd-1)=exc; }

    



 }

}else{ // to handel with drowb case 

    int ctd;
    cout << "\nwitch card you want to drowb ? \n";
  cin >> ctd;

  // cheek if selected card is avelible  to drowb
  if( cards[ctd-1]>19) {
            cout << "\nyou lost "<<cards.at(ctd-1) << "\n";

    cards.at(ctd-1)=0;

    cout << "\nyour cards : "<< cards[0]<< ",*,*,"<<cards[3]<<"\n";

}else{
        cout << "\nyou lost "<<cards.at(ctd-1) << "\n";

    cards.at(ctd-1)=cards.at(ctd-1)*2;
}
}
// go for next player
cout << "\n NEXT PLAYER /-\\ \n \n";
  
   }//end round for one player


//sum cards
  void SumCards(){
for (int i : cards){
    if(i==77){rscoore+=7;}
    else{rscoore+=i;}
}
}

player();   
};
//add cards to players

player::player(){
   
    for (int i = 0; i < 4; i++)
{
    int rn= c[rand()%size(c)];
        cards.push_back(rn);

}



}// end add




int main(){
    
player player1;
player player2;
player player3;
player player4;


int round=1;


for (int i = 0; i < 6; i++) // to play five game (big round)
{



// to continue the gam raounds untel 5 rounds
while (true)
{




 // if it's more then 3 rounds (to ask about screw)
if (round >3)
{


if (player1.screw=='y')
{ player1.screw='n';
round=2;
break;
}
cout <<  "\n "<<player1.name<<"  SAY screw ? \n";
cin>>player1.screw;
player1.round();
if (player1.swapp=='y')
{
    

switch (player1.ptsw)
{
case 2:
player1.SwapCard(player2 ,player1.cts , player1.ctsw ) ;   
break;
case 3:
player1.SwapCard(player3 ,player1.cts , player1.ctsw ) ;   
break;
default:
player1.SwapCard(player4 ,player1.cts , player1.ctsw ) ;   
    break;
}
}

// player1.see();                                 //////////   for test in one player    ///////////////
// cout << "\n//// round is   "<<round+1;     //////////   for test in one player    ///////////////
if (player2.screw=='y')
{ player2.screw='n';
round=2;
break;
}
cout <<  "\n "<<player2.name<<"  SAY screw ? \n";
cin>>player2.screw;
player2.round();
if (player2.swapp=='y')
{

switch (player2.ptsw)
{
case 1:
player2.SwapCard(player1 ,player2.cts , player2.ctsw ) ;   
break;
case 3:
player2.SwapCard(player3 ,player2.cts , player2.ctsw ) ;   
break;
default:
player2.SwapCard(player4 ,player2.cts , player2.ctsw ) ;   
    break;
}
}

if (player3.screw=='y')
{ player3.screw='n';
round=2;
break;
}
cout <<  "\n "<<player3.name<<"  SAY screw ? \n";
cin>>player3.screw;
player3.round();
if (player3.swapp=='y')
{

switch (player3.ptsw)
{
case 2:
player3.SwapCard(player2 ,player3.cts , player3.ctsw ) ;   
break;
case 1:
player3.SwapCard(player1 ,player3.cts , player3.ctsw ) ;   
break;
default:
player3.SwapCard(player4 ,player3.cts , player3.ctsw ) ;   
    break;
}
}


if (player4.screw=='y')
{
     player4.screw='n';

round=2;
break;
}
cout <<  "\n "<<player4.name<<"  SAY screw ? \n";
cin>>player4.screw;
player4.round();

if (player4.swapp=='y')
{

switch (player4.ptsw)
{
case 2:
player4.SwapCard(player2 ,player4.cts , player4.ctsw ) ;   
break;
case 3:
player4.SwapCard(player3 ,player4.cts , player4.ctsw ) ;   
break;
default:
player4.SwapCard(player1 ,player4.cts , player4.ctsw ) ;   
    break;
}
}


round++;
} // end if its more then 3 rounds

//if it's the first round (to gen names)
else if (round==1)
{
cout<< "plesse inter player name :\n";
cin>>player1.name;
player1.round();
// player1.see();                                 //////////   for test in one player    ///////////////
// cout << "\n//// round is   "<<round+1;     //////////   for test in one player    ///////////////

cout<< "plesse inter player name :\n";
cin>>player2.name;
player2.round();
cout<< "plesse inter player name :\n";
cin>>player3.name;
player3.round();
cout<< "plesse inter player name :\n";
cin>>player4.name;
player4.round();

round++;

}//end if it's first round


else{
player1.round();
if (player1.swapp=='y')
{

switch (player1.ptsw)
{
case 2:
player1.SwapCard(player2 ,player1.cts , player1.ctsw ) ;   
break;
case 3:
player1.SwapCard(player3 ,player1.cts , player1.ctsw ) ;   
break;
default:
player1.SwapCard(player4 ,player1.cts , player1.ctsw ) ;   
    break;
}
}
// player1.see();                                 //////////   for test in one player    ///////////////
// cout << "\n//// round is   "<<round+1;     //////////   for test in one player    ///////////////

player2.round();
if (player2.swapp=='y')
{

switch (player2.ptsw)
{
case 1:
player2.SwapCard(player1 ,player2.cts , player2.ctsw ) ;   
break;
case 3:
player2.SwapCard(player3 ,player2.cts , player2.ctsw ) ;   
break;
default:
player2.SwapCard(player4 ,player2.cts , player2.ctsw ) ;   
    break;
}
}
player3.round();
if (player3.swapp=='y')
{

switch (player3.ptsw)
{
case 2:
player3.SwapCard(player2 ,player3.cts , player3.ctsw ) ;   
break;
case 1:
player3.SwapCard(player1 ,player3.cts , player3.ctsw ) ;   
break;
default:
player3.SwapCard(player4 ,player3.cts , player3.ctsw ) ;   
    break;
}
}
player4.round();
if (player4.swapp=='y')
{

switch (player4.ptsw)
{
case 2:
player4.SwapCard(player2 ,player4.cts , player4.ctsw ) ;   
break;
case 3:
player4.SwapCard(player3 ,player4.cts , player4.ctsw ) ;   
break;
default:
player4.SwapCard(player1 ,player4.cts , player4.ctsw ) ;   
    break;
}
}

round++;
}
}


///////////////////////////////

player1.SumCards();
player2.SumCards();
player3.SumCards();
player4.SumCards();
player1.see();
player2.see();
player3.see();
player4.see();
if (player1.rscoore <player2.rscoore  && player1.rscoore <player3.rscoore && player1.rscoore <player4.rscoore )
{
    cout<<player1.name<<" WINN -_-\n ";
    player1.rscoore=0;
    

}else{cout <<player1.name<<" lose !\n";}

if (player2.rscoore <player1.rscoore  && player2.rscoore<player3.rscoore && player2.rscoore <player4.rscoore  )
{
    cout<<player2.name<<" WINN -_- \n";
    player2.rscoore=0;

}else{ cout <<player2.name<<" lose !\n";}

if (player3.rscoore <player2.rscoore  && player3.rscoore <player1.rscoore && player3.rscoore <player4.rscoore )
{
   cout<<player3.name<<" WINN -_-\n ";
   player3.rscoore=0;

}else{cout <<player3.name<<" lose !\n";}

if (player4.rscoore<player2.rscoore  && player4.rscoore<player3.rscoore && player4.rscoore<player1.rscoore )
{
    cout<<player4.name<<" WINN -_- \n";
    player4.rscoore=0;

}else{ cout <<player4.name<<" lose !\n";}

//add one round scoor to final scoor and rezerro
    player1.scoore+=player1.rscoore;
    player1.rscoore=0;


    player2.scoore+=player2.rscoore;
    player2.rscoore=0;
    player3.scoore+=player3.rscoore;
    player3.rscoore=0;
    player4.scoore+=player4.rscoore;
    player4.rscoore=0;

}

// show the final scoors after all rounds
cout<<"\n\n/////  FINAL SCOORS  \\\\\\\\\\\n\n";
cout<<"\n"<< player1.name <<" = " <<player1.scoore<<"\n";
cout<<"\n"<< player2.name <<" = " <<player2.scoore<<"\n";
cout<<"\n"<< player3.name <<" = " <<player3.scoore<<"\n";
cout<<"\n"<< player4.name <<" = " <<player4.scoore<<"\n";
cout<<"\n\n/////  FINAL SCOORS  \\\\\\\\\\\n\n";


// to say how is the winner for hol game determine
if (player1.scoore <player2.scoore  && player1.scoore <player3.scoore && player1.scoore <player4.scoore )
{
    cout<<"\n"<<player1.name<<" WINN  THE HOLE GAME -_-\n\n ";
    

}else{cout <<"\n"<<player1.name<<" lose !\n";}

if (player2.scoore <player1.scoore  && player2.scoore<player3.scoore && player2.scoore <player4.scoore  )
{
    cout<<"\n"<<player2.name<<" WINN  THE HOLE GAME -_- \n\n";
    player2.rscoore=0;

}else{ cout <<"\n"<<player2.name<<" lose !\n";}

if (player3.scoore <player2.scoore  && player3.scoore <player1.scoore && player3.scoore <player4.scoore )
{
   cout<<"\n"<<player3.name<<" WINN THE HOLE GAME  -_-\n\n ";
   player3.rscoore=0;

}else{cout <<"\n"<<player3.name<<" lose !\n";}

if (player4.scoore<player2.scoore  && player4.scoore<player3.scoore && player4.scoore<player1.scoore )
{
    cout<<"\n"<<player4.name<<" WINN  THE HOLE GAME -_- \n\n";
    player4.rscoore=0;

}else{ cout <<"\n"<<player4.name<<" lose !\n";}


}

