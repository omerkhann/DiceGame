//Muhammad Omer Khan    23I-0650    CS-D  Assignment#2 
#include<iostream>
#include<cmath>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;

int main()
{
    string name1, name2;
    int rollnum1, rollnum2;
    int score1=0, score2=0;
    int diceval1, diceval2;
    int diceval1_2, diceval2_2;
    int lastdigit1, lastdigit2;
    
    cout<<"Enter name (Player 1): ";
    getline(cin,name1); //getline to include full names

    cout<<"Enter name (Player 2): ";
    getline(cin,name2);

    //validation check on roll number
    while(rollnum1>9999)
    {
    cout<<"Enter Roll Number (Player 1): ";
    cin>>rollnum1;
    }


    //validation check on roll number
    while(rollnum2>9999)
    {
    cout<<"Enter Roll Number (Player 2): ";
    cin>>rollnum2;
    }

    //extracting last two digits of each players' roll nums
    lastdigit1 = (rollnum1%10);
    lastdigit2 = (rollnum2%10);

    //for use of random dice value assignment
    srand(time(0));

    cout<<"\n(Scores for BOTH turns are totaled and displayed at the end of each round for EACH player)\n"<<endl;

for (int rounds = 1; rounds<=5; rounds++)
    {
        cout<<"Round "<<rounds<<endl;

for (int turnp1 = 0; turnp1<1; turnp1++)
    {
        diceval1 = 1+(rand()%6);
        diceval1_2= 1+(rand()%6);
        score1 += diceval1 + diceval1_2;
        cout<<"Score (Player 1)= "<<score1<<endl;

        //Implementation of Condition 4 for Player 1
        if (diceval1==diceval1_2)
        {
            int a = diceval1 + diceval1_2;
            int discriminant = pow(a,2) - (4*a);
            if(discriminant==0)
            {   
                srand(time(0));
                cout<<"Player 1 gets another roll!"<<endl;
                        diceval1 = 1+(rand()%6);
                        score1 += diceval1;
                        cout<<"Score (Player 1)= "<<score1<<endl;
            }
        }

        diceval2 = 1+(rand()%6);
        diceval2_2= 1+(rand()%6);
        score2 += diceval2 + diceval2_2;
        cout<<"Score (Player 2)= "<<score2<<endl;

        //Implementation of Condition 4 for Player 2
        if (diceval2==diceval2_2)
        {
            int a = diceval2 + diceval2_2;
            int discriminant = pow(a,2) - (4*a);
            if(discriminant==0)
            {
                srand(time(0));
                cout<<"Player 2 gets another roll!"<<endl;
                        diceval2 = 1+(rand()%6);
                        score1 += diceval2;
                        cout<<"Score (Player 2)= "<<score2<<endl;
            }
        }        
    }
    cout<<endl;

//Condition 2
    if (score1 == lastdigit1)
    {
        score1 += lastdigit1;
    }

    if (score2 == lastdigit2)
    {
        score2 += lastdigit2;
    }

    //Condition 3 
    //adding 1 because if you subtract a=97 from 
    //a case where last character is 'a', this would equate score1 or score2 to 0
    if (score1 == (name1.back() - 'a' + 1))
    {   
    score1 += 5;
    }
    else if (score2 == (name2.back() - 'a' + 1))
    {   
    score2 += 5;
    }
}

//Condition 5
if (score1>score2)
{   
    cout<<"Player 1 Wins!";
}
else if(score2>score1)
{
    cout<<"Player 2 Wins!";
}

//Condition 6
//Conditional structure for case where both scores are equal
else if(score1==score2)
{
    cout<<"The scores are tied! Another round!"<<endl;
    
    bool someonewon = false;
    while(!someonewon)
    {
        for (int turnp1 = 0; turnp1<1; turnp1++)
    {
        diceval1 = 1+(rand()%6);
        score1 += diceval1;
        cout<<score1<<endl;
    }
    for (int turnp2 = 0; turnp2<1; turnp2++)
    {
        diceval2 = 1+(rand()%6);
        score2 += diceval2;
        cout<<score2<<endl;
    }
    if (score1>score2)
    {   
    cout<<"Player 1 Wins!";
    someonewon = true;
    }
    else if(score2>score1)
    {
    cout<<"Player 2 Wins!";
    someonewon = true;
    }
    }
}
    return 0;
}