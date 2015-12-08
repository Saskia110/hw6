#include<iostream>
#include<fstream>
#include<cmath>


using namespace std;

void lorenz(double* k, const int a, const int b, const double c, double x, double y, double z);

int main(){

    const double tstart=0; // Anzahl der Shritte, wählbar
    const double tmax = 100; // maximale Zeit
    const double dt = 0.1; // Schrittgröße
    int N = (tmax-tstart)/dt+1;
    
    double k1[3]; // haben vier Vektoren mit jeweils drei Einträgen(x,y,z)
    double k2[3];
    double k3[3];
    double k4[3];
    
    // Randbedingungen und Konstanten müssen festgelegt werden
    double x = 1;
    double y = 1;
    double z = 1;
    
    const int a = 10;
    const int b = 28;
    const double c = 8/3;
    // einmal ausgeben für Anfangsbedingungen
    cout <<  0 << "\t" << x << "\t" << y << "\t"<< z << endl;
    
    for(int i=0; i<N; i++){
        lorenz(k1, a, b, c, x, y, z);// jetzt wurde k1 bestimmt, dass nun für alle k1-k4 machen, einzelne        //
        lorenz(k2, a, b, c, x+dt/2*k1[0], y+dt/2*k1[1], z+dt/2*k1[2]); //Abhängikeiten beachten
        lorenz(k3, a, b, c, x+dt/2*k2[0], y+dt/2*k2[1], z+dt/2*k2[2]);
        lorenz(k4, a, b, c, x+dt*k3[0],   y+dt*k3[1],   z+dt*k3[2] );
        
        //neue Werte bestimmen
        x = x + dt*(1/6)*(k1[0]+ 2*k2[0]+2*k3[0]+ k4[0]);
        y = y + dt*(1/6)*(k1[1]+ 2*k2[1]+2*k3[1]+ k4[1]);
        z = z + dt*(1/6)*(k1[2]+ 2*k2[2]+2*k3[2]+ k4[2]);
        
        cout << i*dt << "\t" << x << "\t" << y << "\t"<< z << endl;
    
    }
    
    
    return 0;
}
// Unterfunktion mit den gegeben Einträgen
void lorenz(double* k, const int a, const int b, const double c, double x, double y, double z){
    k[0] = a*(y-x);
    k[1] = x*(b-z)-y;
    k[2] = x*y - c*z;
    }
