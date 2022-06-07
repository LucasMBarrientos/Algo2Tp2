#include "BatallaCampal.h"
#include <iostream>
using namespace std;

int main(){
	BatallaCampal* juego = new BatallaCampal();
	juego->jugar();
	juego->~BatallaCampal();

	return 0;
}


