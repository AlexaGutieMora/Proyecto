#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <curses.h>
using namespace std;

class Animacion
{
private:
    int x;
    int y;
    fstream archivo;
    string recurso;

public:
    Animacion(int x, int y, string recurso)
    {
        this->recurso = recurso;
        archivo.open("./data/" + this->recurso + ".txt");
        this->x = x;
        this->y = y;
    }
    Animacion(string recurso)
    {
        Animacion(0, 0, recurso);
    }
    void Mover(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void AvanzarEnX(int x)
    {
        this->x += x;
    }
    void RetrocederEnX(int x)
    {
        this->x -= x;
    }
    void SubirEnY(int y)
    {
        this->y -= y;
    }
    void BajarEnY(int y)
    {
        this->y += y;
    }
    void Disparar(int x)
    {
        this->x += x;
    }
    void Mostrar()
    {
        string linea;
        move(this->y, this->x);
        while (getline(archivo, linea))
        {
            int y_linea = getcury(stdscr);
            move(y_linea + 1, this->x);
            mvaddstr(
                y_linea + 1,
                this->x,
                linea.c_str()
                );
        }
        archivo.clear();
        archivo.seekg(0);
    }

    ~Animacion()
    {
        archivo.close();
    }
};