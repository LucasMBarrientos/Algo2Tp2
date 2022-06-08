#include "BatallaCampal.h"
#include <iostream>
using namespace std;

int main(){

try {
	BatallaCampal* juego = new BatallaCampal();
	juego->jugar();
	juego->~BatallaCampal();

				} catch (std::string mensajeError) {
					std::cout << "Ocurrio un error en la ejecucion: "
							  + mensajeError
							  << std::endl;
				}

	return 0;
}
