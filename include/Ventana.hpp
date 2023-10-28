#pragma once
#include <curses.h>
#include <iostream>
#include <unistd.h>
class Ventana
{
private:
    int x;
    int y;
    bool ejecucion;
    int velocidad;
    int contador;
public:
    Ventana()
    {
        initscr();                          // para inicializar pantalla
        getmaxyx(stdscr, this->y, this->x); // tamaño máximo de ventana
        this->ejecucion = false;
        this->velocidad = 10;
        this->contador = 20;
        curs_set(FALSE);
        cbreak();
        timeout(100);
        noecho();
        keypad(stdscr,TRUE);
    }
    void Iniciar()
    {
        this->ejecucion=true;
        while (this->ejecucion)
        {
            this->Actualizar();
            this->Mostrar();
            refresh();
            sleep(this->velocidad);
        }
    }

    void Actualizar()
    {
        this->contador = this->contador-1;
        this->contador = this->contador - 1;
        if (this->contador == 0)
        {
            this->Cerrar();
        }
    }
    void Mostrar()
    {
        box(stdscr, 'o', 'l');
    }
    void Cerrar()
    {
        this->ejecucion = false;
    }
    ~Ventana()
    {
        endwin(); // para cerrar la pantalla
    }
};