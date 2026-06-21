#include <iostream>
#include <fstream>
#include <cmath> // Necesario para std::abs
#include <iomanip>

using namespace std;

int main() {
    // 1. Declaración obligatoria de variables según el enunciado
    float datos[100][3];
    int ids[100];
    float galga[100];
    float fuerza_izq[100];
    float fuerza_der[100];
    
    int total_muestras = 0;

    // 2. Apertura con control de errores (Exigido en la rúbrica)
    ifstream archivo_entrada("datos_pinza.txt");
    if (!archivo_entrada.is_open()) {
        cerr << "Error: No se pudo abrir el archivo datos_pinza.txt" << endl;
        return 1;
    }

    // 3. Lectura estructurada
    while (total_muestras < 100 && archivo_entrada >> ids[total_mures] 
           >> datos[total_muestras][0]    // Galga
           >> datos[total_muestras][1]    // Fuerza Izq
           >> datos[total_muestras][2]) { // Fuerza Der
        
        // Separar la información en arrays independientes de forma explícita
        galga[total_muestras] = datos[total_muestras][0];
        fuerza_izq[total_muestras] = datos[total_muestras][1];
        fuerza_der[total_muestras] = datos[total_muestras][2];
        
        total_muestras++;
    }
    archivo_entrada.close();

    if (total_muestras == 0) {
        cerr << "Error: El archivo de datos está vacío." << endl;
        return 1;
    }

    // 4. Cálculo de medias
    float suma_galga = 0, suma_izq = 0, suma_der = 0;
    for (int i = 0; i < total_muestras; i++) {
        suma_galga += galga[i];
        suma_izq += fuerza_izq[i];
        suma_der += fuerza_der[i];
    }
    
    float media_galga = suma_galga / total_muestras;
    float media_izq = suma_izq / total_muestras;
    float media_der = suma_der / total_muestras;

    // 5. Mostrar por pantalla (Salida esperada)
    for (int i = 0; i < total_muestras; i++) {
        cout << "ID: " << ids[i] 
             << " Galga: " << galga[i] 
             << " Izq: " << fuerza_izq[i] 
             << " Der: " << fuerza_der[i] << endl;
    }
    
    cout << fixed << setprecision(3);
    cout << "Media galga: " << media_galga << endl;
    cout << "Media fuerza izquierda: " << media_izq << endl;
    cout << "Media fuerza derecha: " << media_der << endl;

    for (int i = 0; i < total_muestras; i++) {
        float dif = abs(fuerza_izq[i] - fuerza_der[i]);
        cout << "Estado muestra " << ids[i] << ": " 
             << (dif > 0.15 ? "INESTABLE" : "ESTABLE") << endl;
    }

    // 6. Escritura del archivo de salida resultado_pinza.txt
    ofstream archivo_salida("resultado_pinza.txt");
    if (!archivo_salida.is_open()) {
        cerr << "Error: No se pudo crear el archivo de resultados." << endl;
        return 1;
    }

    archivo_salida << "RESULTADOS DEL SISTEMA DE PINZA ROBOTICA\n";
    archivo_salida << "Datos:\n";
    for (int i = 0; i < total_muestras; i++) {
        archivo_salida << ids[i] << " " << galga[i] << " " << fuerza_izq[i] << " " << fuerza_der[i] << "\n";
    }

    archivo_salida << "Medias:\n";
    archivo_salida << "Galga = " << media_galga << "\n";
    archivo_salida << "Fuerza izquierda = " << media_izq << "\n";
    archivo_salida << "Fuerza derecha = " << media_der << "\n";

    archivo_salida << "Clasificacion:\n";
    for (int i = 0; i < total_muestras; i++) {
        float dif = abs(fuerza_izq[i] - fuerza_der[i]);
        archivo_salida << ids[i] << " " << (dif > 0.15 ? "INESTABLE" : "ESTABLE") << "\n";
    }
    
    archivo_salida.close();
    return 0;
}