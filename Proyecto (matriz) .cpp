#include <iostream>
using namespace std;
 

 int main()
 {
     cout<<" Las posiciones disponibles son: "<<endl; // las posiciones con 0 estan disponibles
     int opcion,F,C, f,c;
     char op;
     
     cout<<"\n";
     
     // Clase ejecutiva.
     int SEJ [2][4];
     int i=0, j=0;
     for(i=0; i<2;i++)
    {
         for(j=0;j<4; j++)
        {
             SEJ [i][j]=0;
        }
    }
      for(i=0; i<2; i++)
    {
         for(j=0;j<4; j++)
        {
             cout<< SEJ [i][j];
        }  
        cout<<" Ejecutiva"<<"\n";
    }
    
     cout<<"\n";
     
    // Clase economica.
     int SEC [6][7];
     int X=0, Y=0;
     for(X=0; X<6;X++)
    {
         for(Y=0;Y<7; Y++)
        {
             SEC [X][Y]=0;
        }
    }
      for(X=0; X<6; X++)
    {
         for(Y=0;Y<7; Y++)
        {
             cout<< SEC [X][Y];
        }  
        cout<<" Economica"<<"\n";
    }
    
       //  Menú para escoger categoria.
      
       cout<<" \n";
      // cuando se registra una silla aparece el número 1.
      
    cout<<" Escoja una clase (1.Ejecutiva 2.Economica): ";
    cin>>opcion;
        switch(opcion)
        {
            case 1:
          // Clase ejecutiva. 
   {
                
            cout<<" Escoja la posicion en i(columna [0-1]):"; // las posiciones van desde 0 hasta 1
            cin>>F;
            cout<<" Escoja la posicion en j(fila [0-3]):";  // las posiciones van desde 0 hasta 3
            cin>>C;
             
      if (F>= 0 && F< 2 && C >= 0 && C< 4) 
    {
        if (SEJ[F][C] == 0) 
        {
            SEJ[F][C] = 1; 
            cout << " Asiento reservado correctamente en clase ejecutiva.\n";
        } 
        else 
        {
            cout << "Ese asiento ya está ocupado.\n";
        }
    } 
        else
         {
        cout << "Posición inválida.\n";
         }
    }
      for(F=0; F<2; F++)
    {
         for(C=0;C<4; C++)
        {
             cout<<SEJ [F][C];
        }  
        cout<<" Ejecutiva"<<"\n";
    }break;
            case 2:
            // Clase económica.
    {
            cout<<" Escoja la posicion en X(columna [0-5]):"; // las posiciones van desde 0 hasta 5
            cin>>f;
            cout<<" Escoja la posicion en Y(fila [0-6]):";  // las posiciones van desde 0 hasta 6
            cin>>c;
           
             
      if (f>= 0 && f< 6 && c>= 0 && c< 7) 
    {
        if (SEC[f][c] == 0) 
        {
            SEC[f][c] = 1; 
            cout << " Asiento reservado correctamente en clase economica.\n";
        } 
        else 
        {
            cout << "Ese asiento ya está ocupado.\n";
        }
    }
        else 
       {
        cout << "Posición inválida.\n";
       }
    }
      for(f=0; f<6; f++)
      {
         for(c=0;c<7; c++)
        {
             cout<<SEC [f][c];
        }  
        cout<<" Economica"<<"\n";
        
      }break;
            default:
            {
                cout<<"Selecciona una opción válida";
            }break;
        }
       return 0;
 }