//Maria Jesus Vargas Medrano B98243

#include <iostream>
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include "Python.h"
#include <string>
#include <fstream>
#include <numpy/arrayobject.h>

extern "C" float obtenerNotas(int notasMusicales);
extern "C" float obtenerOnda(int frecuencia);
extern "C" float obtenerDatosOnda(float frecuencia, float linspace);

int main()
{
    std::string notas;

    std::ifstream NotasMusicales;

    NotasMusicales.open("notasMusicales.txt", std::ios::in);
    //NotasMusicales.open("cancion2.txt", std::ios::in);
    
    if (!NotasMusicales.is_open()){
            std::cerr << "El archivo " << "notasMusicales.txt "  << "no se pudo abrir";
            //std::cerr << "El archivo " << "cancion2.txt "  << "no se pudo abrir";
            exit(1);
    }else{

        NotasMusicales >> notas;

        const char* music_notes = notas.c_str();

        int notasAux;
        
        float linspace[22049];
        linspace[0] = 0;
        float resultado[22048];
        int tamanoReal =0;
        int index=0;
        for (int k=0; k<strlen(music_notes); k++)
        {
            if (music_notes[k]!= '-'){
                tamanoReal++;
            }
        }
        int diferencia = strlen(music_notes) - tamanoReal;
        float notasFInales[22048*tamanoReal+diferencia*2];
        float notitas[tamanoReal];

        for (int k=0; k<strlen(music_notes); k++)
        {
            if (music_notes[k]!= '-'){
                if (music_notes[k] == 'C')
                {
                    notasAux = 0;
                }
                if (music_notes[k] == 'c')
                {
                    notasAux = 1;
                }
                if (music_notes[k] == 'D')
                {
                    notasAux = 2;
                }
                if (music_notes[k] == 'd')
                {
                    notasAux = 3;
                }
                if (music_notes[k] == 'E')
                {
                    notasAux = 4;
                }
                if (music_notes[k] == 'F')
                {
                    notasAux = 5;
                }
                if (music_notes[k] == 'f')
                {
                    notasAux = 6;
                }
                if (music_notes[k] == 'G')
                {
                    notasAux = 7;
                }
                if (music_notes[k] == 'g')
                {
                    notasAux = 8;
                }
                if (music_notes[k] == 'A')
                {
                    notasAux = 9;
                }
                if (music_notes[k] == 'a')
                {
                    notasAux = 10;
                }
                if (music_notes[k] == 'B')
                {
                    notasAux = 11;
                }
                notitas[k] = obtenerNotas(notasAux);
                for(int i=1; i<22049; i++)
                {
                    linspace[i] = obtenerOnda(linspace[i-1]);
                    resultado[i-1] = obtenerDatosOnda(notitas[k], linspace[i-1]);
                    notasFInales[index] = resultado[i-1];
                    index++;
                }
                
            }else{ //Esto lo hago para que vayan mas lento las notas y se pueda escuchar mejor
                notasFInales[index] = 0;
                index++;
                notasFInales[index] = 0;
                index++;
            }
        }

//Union con python para reproducir la cancion
        Py_Initialize();
        
        PyObject *pDict, *pModule, *pFunc, *pArray;

        FILE* PScriptFile = fopen("tarMusi.py", "r");

        PyRun_SimpleFile(PScriptFile, "tarMusi.py");

        pModule = PyImport_AddModule("__main__");

        pDict = PyModule_GetDict(pModule);

        pFunc = PyDict_GetItemString(pDict, "main");

        import_array()

        npy_intp dims[1];

        dims[0] = sizeof(notasFInales)/sizeof(notasFInales[0]);

        pArray = PyArray_SimpleNewFromData(1, dims, NPY_FLOAT, notasFInales);

        PyObject_CallFunctionObjArgs(pFunc, pArray, NULL);

        Py_Finalize();
    }
    return 0;
}