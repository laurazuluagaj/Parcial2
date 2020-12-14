#include "disparos.h"

using namespace std;

int main()
{
    Disparos Disparos;
    int opcion;
    cout << "BIENVENIDO" << endl << "Laura Zuluaga              c.c. 1045049175" << endl;
    while(true){
        cout << "1-> Disparos ofensivos que comprometan a defensivo." << endl;
        cout << "2-> Disparos defensivos que comprometan a ofensivo." << endl;
        cout << "Ingrese una de las opciones del menu: ";
        cin >> opcion;
        switch (opcion) {
        case 1:{
            float dato;
            bool impacto=0;
            cout << "Ingrese la distancia que separa los dos cañones: ";
            cin >> dato;
            Disparos.setd(dato);
            Disparos.setPosD(dato, 0);
            Disparos.setRadioD(dato);
            Disparos.setRadioO(dato);
            cout << "Ingrese la altura del canon ofensivo: ";
            cin >> dato;
            Disparos.setPosO(dato);
            cout << "Ingrese la altura del canon defensivo: ";
            cin >> dato;
            Disparos.setPosD(dato, 1);
            impacto=Disparos.disparoCertero(3);
            if(impacto){
                for(int i=0; i<3; i++){
                    cout << "Disparo " << i+1 << ":" << endl;
                    cout << "Impacto con un angulo de " << Disparos.getAngles(i) << endl;
                    cout << "Impacto con velocidad inicial " << Disparos.getVelocidades(i) << endl;
                    cout << "Impacto con posicion x " << Disparos.getPosX(i) << endl;
                    cout << "Impacto con posicion y " << Disparos.getPosY(i) << endl;
                    cout << "Impacto con tiempo t " << Disparos.getTiempos(i) << endl << endl;
                }
            }
        }
            break;
        case 2:{
            float dato;
        }
            break;
        }
    }
    return 0;
}
