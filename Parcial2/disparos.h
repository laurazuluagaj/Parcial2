#ifndef DISPAROS_H
#define DISPAROS_H
#include <iostream>
#include <math.h>
#include <vector>

#define g 9.8

class Disparos
{
private:
    float *posO= new float;
    float *posD= new float;
    float *velO= new float;
    float *velD= new float;
    float *posBala= new float;
    float d, radioO, radioD, angleO, angleD;
    //Variables que guardan info de los disparos certeros
    float *angles = new float;
    float *velocidades = new float;
    float *posX = new float;
    float *posY =  new float;
    int *tiempos = new int;


public:
    Disparos();
    void setd(float);
    void setRadioO(float);
    void setPosD(float, int);
    void setPosO(float);
    void setRadioD(float);
    bool disparoCertero(int);
    float getAngles(int);
    float getVelocidades(int);
    float getPosX(int);
    float getPosY(int);
    int getTiempos(int);
    bool disparoDefensivo(int);
    ~Disparos();
};

#endif // DISPAROS_H
