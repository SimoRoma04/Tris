#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int i, p, v=0, a, b, giocatore=0, pari;
    char t[3][3]; 
    for(i=0;i<3;i++)
    {
        for(p=0;p<3;p++)
            t[i][p]=' ';
    }
    cout<<"Inizio del gioco:\n[ ][ ][ ]\n[ ][ ][ ]\n[ ][ ][ ]"<<endl; 
    while(v == 0) 
    {
        if(v == 0) 
        {
            giocatore=(giocatore%2)+1;
            cout<<"Giocatore  inserisci le coordinate: "<< giocatore<<endl;
            cout<<"inserire la riga"<<endl;
            cin>> a;
            cout<<"inserire la colonna"<<endl;
            cin>> b;
             while(a<1 || b<1 || a>3 || b>3) 
            {
                cout<<" riprova: "<<endl;
                 cout<<"inserire la riga"<<endl;
            cin>> a;
            cout<<"inserire la colonna"<<endl;
            cin>> b;
            }
            while(t[a-1][b-1]!=' ') 
            {
                printf(" Riprova ");
                  cout<<"inserire la riga"<<endl;
            cin>> a;
            cout<<"inserire la colonna"<<endl;
            cin>> b;
            }
            if (giocatore == 1) 
                t[a-1][b-1]='X';
            else
                t[a-1][b-1]='O';
            giocatore+=2;
        }
            //Nella riga di seguito stampo la matrice di gioco aggiornata
			 printf("Questa è la situazione di gioco:\n\n[%c][%c][%c]\n[%c][%c][%c]\n[%c][%c][%c]\n", t[0][0], t[0][1], t[0][2], t[1][0], t[1][1], t[1][2], t[2][0], t[2][1], t[2][2]);//prof ho cercato su internet un istruzione che mi avrebbe permesso di aggiornare la matrice di gioco cosi da fare molte meno righe di codice
            for(i=0;i<3;i++)
            {
                if(t[i][0] == t[i][1] && t[i][1] == t[i][2] && t[i][0] != ' ')
                {
                    cout<<"C'e' un tris di sulla riga"<< t[i][0]<< i+1<<endl;
                    cout<<"Il giocatore vince"<< giocatore-2<<endl;
                    v=1;
                }
            }
            for(i=0;i<3;i++)
            {
                if(t[0][i] == t[1][i] && t[1][i] == t[2][i] && t[0][i] != ' ')
                {
                    cout<<"C'e' un tris di  sulla colonna "<< t[i][0]<< i+1<<endl;
                    cout<<"Il giocatore  vince"<< giocatore-2<<endl;
                    v=1;
                }
            }
            for(i=0;i<3;i++)
            {
                if((t[i][i] == t[i+1][i+1] && t[i+1][i+1] == t[i+2][i+2] && t[i][i] != ' ') || (t[i][i+2] == t[i+1][i+1] && t[i+1][i+1] == t[i+2][i] && t[i][i+2] != ' '))
                {
                    cout<<"C'e' un tris diagonale di "<< t[1][1]<<endl;
                    cout<<"Il giocatore vince"<< giocatore-2<<endl;
                    v=1;
                }
            }
            pari=0;
            for(i=0;i<3;i++)
            {
                if(t[i][0]!=' ' && t[i][1]!=' ' && t[i][2]!=' ' && v!=1)
                pari++;
                if(pari==3)
                {
                    cout<<"Parita'"<<endl;
                    v=1;
                }
            }
    }
}

