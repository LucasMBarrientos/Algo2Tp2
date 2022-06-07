#ifndef COORDENADAS_H_
#define COORDENADAS_H_

class Coordenada{

	private:

        unsigned int x;
        unsigned int y;
        unsigned int z;

	public:

        Coordenada();

        Coordenada(unsigned int x,unsigned int y,unsigned int z);

        void setX(unsigned int x);

        void setY(unsigned int y);

        void setZ(unsigned int z);

        unsigned int getX();

        unsigned int getY();

        unsigned int getZ();


};

#endif /* Coordenadas_H_ */
