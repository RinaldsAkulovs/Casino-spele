#include <iostream>
#include <string>
#include <cstdlib> // Random skaitļiem
#include <ctime>
using namespace std;
 
void drawLine(int n, char symbol);
void noteikumi();
 
int main()
{
    string pName;
    int bilance; // tur spēlētāja bilanci
    int bettingAmount; 
    int guess;
    int dice; // tur datora ģenerētus ciparus
    char choice;
 
    srand(time(0)); // "random ģenerators

    drawLine(60,'_');
    cout << "\n\n\n\t\tCASINO SPĒLE\n\n\n\n";
    drawLine(60,'_');
 
    cout << "\n\nIevadi savu vārdu : ";
    getline(cin, pName);
 
    cout << "\n\nIevadi sava maka naudas dzudzumu : $";
    cin >> bilance;
    
    do
    {
        system("cls");
        noteikumi();
        cout << "\n\nTava bilance ir $ " << bilance << "\n";
		
		// Speletaja derešanas summa un pārbaude
        do
        {
            cout <<pName<<", ievadi derēšanas summu : $";
            cin >> bettingAmount;
            if(bettingAmount > bilance)
                cout << "Tava derēšanas summa ir lielāka nekā tev ir makā\n"
                       <<"\nPārvadi datus\n ";
        }while(bettingAmount > bilance);
 
		// Speletajam pieprasa mineto ciparu un pārbauda
        do
        {
            cout << "Mini ciparu no 1 līdz 10 :";
            cin >> guess;
            if(guess <= 0 || guess > 10)
                cout << "Ludzu parbaudi skaitli!! skaitlim jabut no 1 lidz 10\n"
                    <<"\nPārvadi datus\n ";
        }while(guess <= 0 || guess > 10);
 
        dice = rand()%10 + 1; // Patur random ģenerēto ciparu
    
        if(dice == guess)
        {
            cout << "\n\nApveicu!! Tu  uzvareji Rs." << bettingAmount * 10;
            bilance = bilance + bettingAmount * 10;
        }
        else
        {
            cout << "Nepaveicās šoreiz !! Tu zaudēji $ "<< bettingAmount <<"\n";
            bilance = bilance - bettingAmount;
        }
 
        cout << "\nUzvarošais cipars bija : " << dice <<"\n";
        cout << "\n"<<pName<<", Tev ir $ " << bilance << "\n";
        if(bilance == 0)
        {
            cout << "Tev nav naudas ar ko spēlēt ";
            break;
        }
        cout << "\n\n-->Gribi spēlēt velreiz (j/n)? ";		
        cin >> choice;
    }while(choice =='J'|| choice=='j');
    
    cout << "\n\n\n";
    drawLine(70,'=');
    cout << "\n\nPaldies par spēlēšanu. Tava bilance ir $ " << bilance << "\n\n";
    drawLine(70,'=');
 
    return 0;
}
 
void drawLine(int n, char symbol)
{
    for(int i=0; i<n; i++)
        cout << symbol;
    cout << "\n" ;
}
 
void noteikumi()
{
    system("cls");
    cout << "\n\n";
    drawLine(80,'-');
    cout << "\t\tNOTEIKUMI\n";
    drawLine(80,'-');
    cout << "\t1. Izvēlies ciparu no 1 līdz 10\n";
    cout << "\t2. Ja tu uzvari tu dabū 10 reizes tavu derēto naudu\n";
    cout << "\t3. Ja tu izvēlies nepareizo ciparu tad tu zaudēsi derēto summu\n\n";
    drawLine(80,'-');
}
