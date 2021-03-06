#include <iostream>

using namespace std;
char A[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='X';
int row,column;
bool draw=false;

void display(){
    system("clear");// to clear the previous grid of game before displaying new one. 
    //so that same box/grid seems to get updated rather than displaying every single updation entered in grid.
    cout<<endl;
    cout<<"\t\t*************************************"<<endl;
    cout<<"\t\t       T.I.C.K  T.O.E   G.A.M.E"<<endl;
    cout<<"\t\t*************************************"<<endl;
    cout<<endl;
    cout<<"\tPlayer-1 [X] \n\tPlayer-2 [O]"<<endl;
    
     cout<<"\t\t\t     |     |     |     \n";
    cout<<"\t\t\t  "<<A[0][0]<<"  |  "<<A[0][1]<<"  |  "<<A[0][2]<<"  |     \n";
    cout<<"\t\t\t     |     |     |     \n";
    cout<<"\t\t\t_____ _____ _____ _____\n";
    cout<<"\t\t\t     |     |     |     \n";
    cout<<"\t\t\t  "<<A[1][0]<<"  |  "<<A[1][1]<<"  |  "<<A[1][2]<<"  |     \n";
    cout<<"\t\t\t     |     |     |     \n";
    cout<<"\t\t\t_____ _____ _____ _____\n";
    cout<<"\t\t\t     |     |     |     \n";
    cout<<"\t\t\t  "<<A[2][0]<<"  |  "<<A[2][1]<<"  |  "<<A[2][2]<<"  |     \n";
    cout<<"\t\t\t     |     |     |     \n";
    
}

void player_turn(){
    int choice;
    if(turn =='X'){
        cout<<"\n\tPlayer1 [X] turn:\t";
    }
    if(turn =='O'){
        cout<<"\n\tPlayer2 [O] turn:\t";
    }
    
    cin>>choice;

    switch(choice){
        
        case 1:
        
           row=0; column=0;
            break;
        
        
        case 2:
        
           row=0; column=1;
            break;
        
        
        case 3:
        
            row=0; column=2;
            break;
        
        
        case 4:
        
           row=1; column=0;
            break;
        
        
        case 5:
        
           row=1; column=1;
            break;
        
        
        case 6:
        
            row=1; column=2;
            break;
        
        
        case 7:
        
            row=2; column=0;
            break;
        
        
        case 8:
        
           row=2; column=1;
            break;
        
        
        case 9:
        
           row=2; column=2;
            break;
        
        
        default:
            cout<<"Invalid Choice"<<endl;
            
        
        
    }//end of Switch.

if(choice==0 || choice>9 ||choice<0){
    cout<<"Kindly enter position between 1-9."<<endl;
}
else{
    if(turn=='X' && A[row][column]!='X' && A[row][column]!='O'){
        A[row][column]='X';
        turn='O';
    }
    else if(turn=='O' && A[row][column]!='X' && A[row][column]!='O'){
        A[row][column]='O';
        turn='X';
    }
    else{
        cout<<"BOX already filled!\nPlease try again\n\n";
        player_turn();
    }
    
    display();
    
}//end of else.

} //end of function player_turn().

bool gameOver(){
    //check win.
    for(int i=0;i<3;i++){
        if(A[i][0]==A[i][1] && A[i][0]==A[i][2] || A[0][i]==A[1][i] && A[0][i]==A[2][i] || A[0][0]==A[1][1] && A[0][0]==A[2][2] || A[0][2]==A[1][1] && A[0][2]==A[2][0]){
            return false;
        }
    }
    
    //if any box empty?
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(A[i][j]!='X' && A[i][j]!='O'){
                return true;
            }
        }
    }
    
    //Draw case.
    draw=true;
    return false;
    
}
int main()
{
    
while(gameOver())
{
    display();
    player_turn();
   // gameOver();
   // display(); already called in Player_turn() function.
}

if(turn=='X' && draw==false){
    cout<<endl;
    cout<<"\t\t*************************************"<<endl;
    cout<<"\t\t\tWOHOO !!"<<endl;
    cout<<"\t\tCONGRATULATIONS !! Player-2 [O] wins!"<<endl; 
    cout<<"\t\t*************************************"<<endl;
    // why?..Reason:-> when choice of any player get entered, turn turns to next player immedieately.
    //i.e if player-1 is actual winner, then as soon as his choice is updated in game, turn changes to Player-2 
    //and since we have Winner display message at last and winner is being decided based on value in turn. 
    //Therefore, we reversely wrote that if turn=='X', then player-2 wins & vice versa.
}
    
   else if(turn=='O' && draw==false){
    cout<<endl;
    cout<<"\t\t*************************************"<<endl;
    cout<<"\t\t\tWOHOO !!"<<endl;
    cout<<"\t\tPlayer-1 [X] wins! CONGRATULATIONS !!"<<endl;
    cout<<"\t\t*************************************"<<endl;
}

else{
    cout<<endl;
    cout<<"\t\t*************************************"<<endl;
    cout<<"\t\tGame Draw!!"<<endl;
    cout<<"\t\t*************************************"<<endl;
}

    return 0;

}