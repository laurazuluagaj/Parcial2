#include "disparos.h"

Disparos::Disparos()
{
    posO[0]=0;
}

void Disparos::setd(float distancia)
{
    d=distancia;
}

void Disparos::setRadioO(float)
{
    radioO=0.05*d;
}

void Disparos::setPosD(float dato, int pos)
{
    posD[pos]=dato;
}

void Disparos::setPosO(float altura)
{
    posO[1]= altura;
}

void Disparos::setRadioD(float)
{
    radioD=0.025*d;
}

bool Disparos::disparoCertero(int cantidad)
{
    bool impacto;
    float vel, angle;
    angle=0;
    int t;
    for(int i=0; i<cantidad; i++){
        impacto=0;
        for(vel=200; vel<=300; vel+=5){
            for(; angle<90; angle++){
                velO[0]=vel*cos(angle*M_PI/180);
                velO[1]=vel*sin(angle*M_PI/180);
                posBala[0]=0.0;
                posBala[1]=posO[1];
                for(t=0;;t++){
                    posBala[0] = velO[0]*t;
                    posBala[1] = posO[1] + velO[1]*t - (0.5*g*t*t);
                    if(sqrt(pow((posD[0]-posBala[0]),2)+pow((posD[1]-posBala[1]),2))<=radioO){
                     impacto = 1;
                     break;
                    }
                    if(posBala[1]<0) break;
                }
                if(impacto){
                    angles[i]=angle;
                    velocidades[i]=vel;
                    posX[i]=posBala[0];
                    posY[i]=posBala[1];
                    tiempos[i]=t;
                    angle++;
                    break;
                }
            }
            if(impacto) break;
        }
    }
    if(impacto) return 1;
    else return 0;
}

float Disparos::getAngles(int pos)
{
    return angles[pos];
}

float Disparos::getVelocidades(int pos)
{
    return velocidades[pos];
}

float Disparos::getPosX(int pos)
{
    return posX[pos];
}

float Disparos::getPosY(int pos)
{
    return posY[pos];
}

int Disparos::getTiempos(int pos)
{
    return tiempos[pos];
}

bool Disparos::disparoDefensivo(int cantidad)
{
    bool impacto;
    float vel, angle;
    angle=0;
    int t;
    for(int i=0; i<cantidad; i++){
        impacto=0;
        for(vel=200; vel<=400; vel++){
            for(; angle<90; angle++){
                velD[0]=(vel*cos(angle*M_PI/180))*-1;
                velD[1]=(vel*sin(angle*M_PI/180));
                posBala[0]=posD[0];
                posBala[1]=posD[1];
                for(t=0;;t++){
                    posBala[0] = posD[0]+velD[0]*t;
                    posBala[1] = posD[1] + velD[1]*t - (0.5*g*t*t);
                    if(sqrt(pow((posO[0]-posBala[0]),2)+pow((posO[1]-posBala[1]),2))<=radioD){
                     impacto = 1;
                     break;
                    }
                    if(posBala[1]<0) break;
                }
                if(impacto){
                    angles[i]=angle;
                    velocidades[i]=vel;
                    posX[i]=posBala[0];
                    posY[i]=posBala[1];
                    tiempos[i]=t;
                    angle++;
                    break;
                }
            }
            if(impacto) break;
        }
    }
    if(impacto) return 1;
    else return 0;
}

Disparos::~Disparos()
{
    delete posO;
    delete posD;
    delete velO;
    delete velD;
    delete posBala;
    delete angles;
    delete velocidades;
    delete posX;
    delete posY;
    delete tiempos;
}
