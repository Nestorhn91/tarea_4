#include "NodoArbolBinario.h"
#include "NodoArbolNArio.h"
#include "Evaluador.h"
#include <iostream>       // std::cin, std::cout
#include <list>          // std::list
using namespace std;

int suma(NodoArbolBinario* raiz)
{
    int nums = 0; // verifica si la variable nums es 0

    if(raiz == NULL)// verifica si la raiz es vacia
    {
        return 0; // esto retorna 0 si no hay variable en ella

    }
    if(raiz || NULL)// verifica si la raiz tiene elementos
    {
        nums += raiz->num;// suma los elementos de la raiz
        nums +=suma(raiz->hijo_der) + suma(raiz->hijo_izq);//hacemos una llamada recursiva a los hijos de las raiz para luego sumarlo

    }
    return nums; // retorna 0 el total de la suma de los hijos de la raiz

}

int suma(NodoArbolNArio* raiz)
{

    int nums = 0; // verifica si la variable nums es 0

    if(raiz == NULL)// verifica si la raiz es vacia
    {
        return 0; // esto retorna 0 si no hay variable en ella

    }
    if(raiz || NULL)// verifica si la raiz tiene elementos
    {
        nums += raiz->num;// suma los elementos de la raiz

    }
    list<NodoArbolNArio*>::iterator i = raiz-> hijos.begin();// se declara esta variable iterador para que recorra el arbol
    while (i!= raiz->hijos.end()){//esto verifica si la raiz es diferente a otra variable
        nums+= suma(*i);// se crea esta funcion para extraer y sumar los valores de la raiz
        i++; // se crea una variable contadora para que vaya aumentando por si solo la raiz
    }
    return nums; // retorna 0 el total de la suma despues del ciclo
}

int cantidadNodos(NodoArbolBinario* raiz)
{
    int canti = 0; // verifica si la variable nums es 0

    if(raiz == NULL)// verifica si la raiz es vacia
    {
        return 0; // esto retorna 0 si no hay variable en ella

    }
    if(raiz || NULL)// verifica si la raiz tiene elementos
    {
        canti++;
        canti +=cantidadNodos(raiz->hijo_der) + cantidadNodos(raiz->hijo_izq);// se suma los dos lado para que despues obtener total de los nodos
    }

    return canti; // retorna 0 el total de la suma de la raiz

   // este opcional que tambien funciona
   // que es igual a tener : canti +=cantidadNodos(raiz->hijo_der) + cantidadNodos(raiz->hijo_izq) pero de un solo hace el retorno
    //return canti += cantidadNodos(raiz->hijo_der) + cantidadNodos(raiz->hijo_izq);// retorna la cantidad total de la raiz y luego los suma
}

int cantidadNodos(NodoArbolNArio* raiz)
{
    int canti = 0; // verifica si la variable canti es 0

    if(raiz == NULL)// verifica si la raiz es vacia
    {
        return 0; // esto retorna 0 si no hay variable en ella

    }
    if(raiz || NULL)// verifica si la raiz tiene elementos
    {
        canti++;
    }
    list<NodoArbolNArio*>::iterator i = raiz-> hijos.begin();// se declara esta variable iterador para que recorra el arbol
    while ( i!= raiz->hijos.end()){//esto verifica si la raiz es diferente a otra variable
        canti+= cantidadNodos(*i);// se crea esta funcion para extraer y sumar los valores de la raiz
        i++; // se crea una variable contadora para que vaya aumentando por si solo la raiz
    }


    return canti; // retorna 0 el total de la suma despues del ciclo

}

int promedio(NodoArbolBinario* raiz)
{
    if(raiz==NULL)
    return -1;
    return  suma(raiz) / cantidadNodos(raiz);//se llama una funcion de sobre carga ya que esta una variable que se este utilizando

}

int promedio(NodoArbolNArio* raiz)
{
    if(raiz==NULL)
    return -1;
    return suma(raiz)/ cantidadNodos(raiz);
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 1;
}
