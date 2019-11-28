#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void initial_cond(float *v, int N);
void copia(float *a, float *b, int N);
void escribe(float *v, int N);

int main() {
  float L = 1000.0;
  float rho = 0.01;
  float T = 40.0;
  float c = sqrt(T/rho);
  float c1 = c;
  float ratio = c*c/(c1*c1);
  int Nx = 101;
  int Nt = 100;

  float *pasado = new float [Nx];
  float *presente = new float [Nx];
  float *futuro = new float [Nx];

  initial_cond(pasado, Nx);

  escribe(pasado,Nx);
  presente[0] = 0.0;
  presente[-1] = 0.0;
  for (size_t i = 1; i < Nx-1; i++) {
    presente[i] = pasado[i] + 0.5*ratio*(pasado[i+1] + pasado[i-1] - 2.0*pasado[i]);
  }
  escribe(presente,Nx);

  int t = 1;

  futuro[0] = 0.0;
  futuro[-1] = 0.0;

  while(t < Nt){
    for (size_t i = 1; i < Nx-1; i++) {
      futuro[i] = 2.0*presente[i] - pasado[i] + ratio*(presente[i+1] + presente[i-1] - 2.0*presente[i]);
    }
    escribe(futuro, Nx);

    copia(presente, pasado, Nx);
    copia(futuro, presente, Nx);

    t ++;
  }

  return 0;
}
void initial_cond(float *v, int N){
  for (size_t i = 0; i < N; i++) {
    if(i < int(0.80*N)+1){
      v[i] = 0.00125*i;
    }
    else{
      v[i] = 0.1 - 0.005*(i-int(0.80*N));
    }
  }
}
void escribe(float *v, int N){
  ofstream file;
  file.open("cuerda.dat", fstream::app);
  for (size_t i = 0; i < N; i++) {
    file << v[i]<< " ";
  }
  file << endl;
  file.close();
}
void copia(float *a, float *b, int N){
  for (size_t i = 0; i < N; i++) {
    b[i] = a[i];
  }
}
