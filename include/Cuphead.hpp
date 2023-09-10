#include <string>
class Cuphead
{
private:
    std::string nombreUsuario;
    int vida, bala, carta;

public:
    Cuphead(std::string nombreUsuario)
    {
        this->nombreUsuario = nombreUsuario;
        this->3;
        this->10000000;
        this->0;
    }
    ~Cuphead() {}
    void Mover() {}
    void Disparar(/*int danoVillano*/)
    {
       // this->bala -= danoVillano;
    }
    int Colectar(/*int cartaEncontrada*/)
    {
       // this->carta += cartaEncontrada;
       // return this->carta;
    }
    void GolpearCombo()
    {
       // this->carta = 3;
    }
    void ReducirVida(int danoEfectuado)
    {
       // this->vida -= danoEfectuado;
    }
};