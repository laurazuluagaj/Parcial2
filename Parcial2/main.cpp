#include "disparos.h"

using namespace std;

int main()
{
    Disparos Disparos;
    int opcion;
    cout << "BIENVENIDO" << endl << "Laura Zuluaga              c.c. 1045049175" << endl;
    float dato;
    cout << "Ingrese la distancia que separa los dos canones: ";
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
    cout << endl;
    Disparos.setPosD(dato, 1);
    while(true){
        cout << "1-> Disparos ofensivos que comprometan a defensivo." << endl;
        cout << "2-> Disparos defensivos que comprometan a ofensivo." << endl;
        cout << "3-> Disparo defensivo que impida ser destruido sin importar ofensivo." << endl;
        cout << "4-> Disparo defensivo que impida ser destruido cuidando ofensivo." << endl;
        cout << "6-> Cambiar distancias y posiciones." << endl;
        cout << "Ingrese una de las opciones del menu: ";
        cin >> opcion;
        switch (opcion) {
        case 1:{
            bool impacto=0;
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
            bool impacto=0;
            impacto=Disparos.disparoDefensivo(3);
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
        case 3:{
            bool impacto=0;
            float angle, vel;
            int tiempo;
            impacto=Disparos.disparoCertero(1);
            angle=Disparos.getAngles(0);
            vel=Disparos.getVelocidades(0);
            tiempo=Disparos.getTiempos(0);
            impacto=Disparos.disparoDefensivo2(vel, angle, tiempo);
            if(impacto){
                cout << "Disparo: " << endl;
                cout << "Impacto con un angulo de " << Disparos.getAngles(0) << endl;
                cout << "Impacto con velocidad inicial " << Disparos.getVelocidades(0) << endl;
                cout << "Impacto con posicion x " << Disparos.getPosX(0) << endl;
                cout << "Impacto con posicion y " << Disparos.getPosY(0) << endl;
                cout << "Impacto con tiempo t " << Disparos.getTiempos(0) << endl << endl;
            }
        }
            break;
        case 4:{
            bool impacto=0;
            float angle, vel;
            int tiempo;
            impacto=Disparos.disparoCertero(1);
            angle=Disparos.getAngles(0);
            vel=Disparos.getVelocidades(0);
            tiempo=Disparos.getTiempos(0);
            impacto=Disparos.disparoDefensivo3(vel, angle, tiempo);
            if(impacto){
                cout << "Disparo: " << endl;
                cout << "Impacto con un angulo de " << Disparos.getAngles(0) << endl;
                cout << "Impacto con velocidad inicial " << Disparos.getVelocidades(0) << endl;
                cout << "Impacto con posicion x " << Disparos.getPosX(0) << endl;
                cout << "Impacto con posicion y " << Disparos.getPosY(0) << endl;
                cout << "Impacto con tiempo t " << Disparos.getTiempos(0) << endl << endl;
            }
        }
            break;
        case 6:
            cout << "Ingrese la distancia que separa los dos canones: ";
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
            break;
        }
    }
    return 0;
}
