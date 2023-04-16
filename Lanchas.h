#include <iostream>  
class Lanchas {
	//PRIVATE
private:
	std::string Name;
	int Vel;
	int Dis;
	int Nit;

	//PUBLIC
public:
	// constructor
	Lanchas(std::string pName, int pVelocidad, int pDistancia, int pNitro);


	//getters    
	std::string getName();
	int getVelocidad();
	int getDistancia();
	int getNitro();

	//setters    
	void setName(std::string pName);
	void setVelocidad(int Velocidad);
	void setDistancia(int Distancia);
	void setNitro(int Nitro);

	// metodos propios
	void sumaVelocidad(int Dado);
	int nitro(int Dado, int& Vel);
};