#include <iostream>
#include <Animacion.hpp>
#include <Personaje.hpp>
#include <Ventana.hpp>
#include <Nivel.hpp>
#include <curses.h>
#include <unistd.h>
#include <list>
using namespace std;

int main(int argc, char const *argv[])
{
    Ventana v;
    Animacion mapaCagney(70,20,"mapaCagney");
    Animacion mapaCagney2(35,20,"mapaCagney");
    Animacion cuphead(0,15,"cuphead");
   Animacion cagney(100,5,"cagney");
   Animacion bala(0,15,"bala");

    bool ejecucion = true;
    while (ejecucion)
    {
        // ciclo de actualizacion
        v.Actualizar();
        if (getch() == 'q')
        {
            ejecucion = false;
        }
        if (getch() == 'a')
        {
            cuphead.RetrocederEnX(1);
        }
        if (getch() == 'd')
        {
            cuphead.AvanzarEnX(1);
        }
        if (getch() == 'w')
        {
            cuphead.SubirEnY(1);
        }
        if (getch() == 's')
        {
            cuphead.BajarEnY(1);
        }
        if (getch() == KEY_LEFT)
        {
            cagney.RetrocederEnX(1);
        }
        if (getch() == KEY_RIGHT)
        {
            cagney.AvanzarEnX(1);
        }
        if (getch() == 'g')
        {
            bala.Disparar(90);
        }
    

        // ciclo de dibujo
        clear();
        v.Mostrar();
        cuphead.Mostrar();
        bala.Mostrar();
        mapaCagney.Mostrar();
        mapaCagney2.Mostrar();
        cagney.Mostrar();
        refresh();
        usleep(41000); // 24 frames por segundo
    }
    return 0;
}
