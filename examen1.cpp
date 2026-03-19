/*
Nombre del estudiante: Alexis Liquinchana
Curso: Bootcamp Programación Cero a POO
Clase: 10 - Examen 1 (C++)
Fecha: 18/03/2026
Una academia desea llevar un control básico de las notas de un grupo de estudiantes
mediante un programa en C++.
Se requiere desarrollar un sistema que permita registrar y analizar las calificaciones
de un grupo pequeño de estudiantes usando arreglos unidimensionales y
funciones.

El programa debe trabajar con un máximo de 20 estudiantes.
Cada estudiante tendrá:
• su nombre
• una nota final
La nota debe manejarse en escala de 0 a 20.
El programa debe presentar un menú repetitivo con varias opciones para que el
usuario pueda trabajar con la información registrada.

Requisitos funcionales
1) Registrar estudiantes y notas
El programa debe permitir ingresar la cantidad de estudiantes a registrar.
Validaciones:
• La cantidad de estudiantes debe estar entre 1 y 20.
• Cada nombre no debe quedar vacío.
• Cada nota debe estar en el rango 0 a 20.
La información debe guardarse en arreglos.

2) Mostrar listado completo
El programa debe permitir mostrar todos los estudiantes registrados junto con su
nota.
Ejemplo de salida:
1. Ana - 18
2. Luis - 12.5
3. Carla - 9
Si aún no se han registrado estudiantes, el programa debe indicarlo con un mensaje
claro.

3) Calcular y mostrar el promedio general
El programa debe calcular el promedio de todas las notas registradas y mostrarlo en
pantalla.
Si no existen estudiantes registrados, debe mostrarse un mensaje adecuado.

4) Mostrar la nota mayor y la nota menor
El programa debe identificar:
• la nota más alta y el nombre del estudiante que la obtuvo,
• la nota más baja y el nombre del estudiante que la obtuvo.
Si no existen estudiantes registrados, debe mostrarse un mensaje adecuado.

5) Mostrar cantidad de aprobados y reprobados
Se considera:
• Aprobado: nota mayor o igual a 14
• Reprobado: nota menor a 14
El programa debe mostrar:
• cantidad de aprobados,
• cantidad de reprobados.
Si no existen estudiantes registrados, debe mostrarse un mensaje adecuado.

6) Buscar estudiante por nombre
El programa debe pedir un nombre y buscarlo dentro del arreglo.
Si lo encuentra, debe mostrar:
• nombre del estudiante,
• nota obtenida,
• si está aprobado o reprobado.
Si no lo encuentra, debe indicarlo claramente.

La búsqueda debe realizarse mediante búsqueda secuencial.

7) Salir
Debe existir una opción para finalizar el programa.

Tema:
Sistema de registro y análisis de notas de estudiantes
Entrada:
- Cantidad de estudiantes
- Nombres de estudiantes
- Nota de cada estudiante
Proceso:
- Validar datos ingresados
- Almacenar información en arreglos
- Calcular promedio general
- Buscar una nota mayor y una nota menor
- Mostrar reporte de aprobados y reprobados
- Permitir consultar un estudiante por nombre
Salida:
- Listado de estudiantes y notas
- Promedio general
- Nota mayor y nota menor
- Cantidad de aprobados y reprobados
- Resultado de búsqueda por nombre
*/

#include <iostream>
#include <string>
using namespace std;

void registrarEstudiantes(string nombres[], double notas[], int &cantidad);
void mostrarListado( string nombres[], double notas[], int cantidad);
void calcularPromedio(double notas[], int cantidad);
void mostrarMayorMenor(string nombres[], double notas[], int cantidad);
void contarAprobadosReprobados(double notas[], int cantidad);


int main(){
// declaracion de variables
string nombres[20];
    double notas[20];
    int cantidadRegistrados = 0;
    int opcion;
// menu bucle do while
    do {
        cout << "\n=========== MENU DE ACADEMIA ===========" << endl;
        cout << "1. Registrar estudiantes y notas" << endl;
        cout << "2. Mostrar listado completo" << endl;
        cout << "3. Mostrar promedio general" << endl;
        cout << "4. Mostrar nota mayor y nota menor" << endl;
        cout << "5. Mostrar aprobados y reprobados" << endl;
        cout << "6. Buscar estudiante por nombre" << endl;
        cout << "7. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        // Validación de existencia de datos
        if (opcion >= 2 && opcion <= 6 && cantidadRegistrados == 0) {
            cout << "\nOpcion invalida = No hay estudiantes. Use la opcion 1 primero." << endl;
        }
        else if (opcion == 1) {
            registrarEstudiantes(nombres, notas, cantidadRegistrados);
        }
        else if (opcion == 2) {
            mostrarListado(nombres, notas, cantidadRegistrados);
        }
        else if (opcion == 3) {
            calcularPromedio(notas, cantidadRegistrados);
        }
        else if (opcion == 4) {
            mostrarMayorMenor(nombres, notas, cantidadRegistrados);
        }
        else if (opcion == 5) {
            contarAprobadosReprobados(notas, cantidadRegistrados);
        }
        
    } while (opcion != 7);

    return 0;
}

//Desarrollo de las funciones

void registrarEstudiantes(string nombres[], double notas[], int &cantidad) {
    cout << "\nIngrese la cantidad de estudiantes que desea registrar(1 a 20): ";
    cin >> cantidad;
    // buscamos que la cantidad de estudiantes este dentro del rango aceptado
    while (cantidad < 1 || cantidad > 20) {
        cout << "Cantidad invalida. Ingrese un numero entre 1 y 20: ";
        cin >> cantidad;
    }
    //Bucle para llenar los arreglos
    for (int i = 0; i < cantidad; i++) {
        cout << "\nEstudiante #" << i + 1 << endl;
        cout << "Nombre: ";
        cin >> nombres[i]; 

        cout << "Nota (0-20): ";
        cin >> notas[i];
        
        // Validación de nota
        while (notas[i] < 0 || notas[i] > 20) {
            cout << "Nota invalida. Ingrese un valor entre 0 y 20: ";
            cin >> notas[i];
        }
    }
    cout << "\n***Registro exitoso***" << endl;
}

//Recorre el arreglo y muestra la informacion
void mostrarListado(string nombres[], double notas[], int cantidad) {
    cout << "\n***Listado final***" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << i + 1 << ". " << nombres[i] << " - Nota: " << notas[i] << endl;
    }
}

//Suma las notas y divide para la cantidad de datos de nombres
void calcularPromedio(double notas[], int cantidad) {
    double suma = 0;
    for (int i = 0; i < cantidad; i++) {
        suma = suma + notas[i];
    }
    cout << "\nPromedio: " << (suma / cantidad) << endl;
}

// Busca el valor más alto y el más bajo dentro del arreglo de notas
void mostrarMayorMenor(string nombres[], double notas[], int cantidad) {
    double mayor = notas[0]; 
    double menor = notas[0]; 
    int posMayor = 0; 
    int posMenor = 0;

    for (int i = 1; i < cantidad; i++) {
        // Encuentra la nota mayor y la guarda
        if (notas[i] > mayor) {
            mayor = notas[i];
            posMayor = i;
        }
        // Encuentra la nota menor y la guarda
        if (notas[i] < menor) {
            menor = notas[i];
            posMenor = i;
        }
    }
    cout << "\nNota mayor: " << mayor << " (Estudiante: " << nombres[posMayor] << ")" << endl;
    cout << "Nota menor: " << menor << " (Estudiante: " << nombres[posMenor] << ")" << endl;
}

// Clasifica a los estudiantes según su nota y cuenta los grupos
void contarAprobadosReprobados(double notas[], int cantidad) {
    int aprobados = 0; // Contador de aprobados
    int reprobados = 0; // Contador de reprobados

    for (int i = 0; i < cantidad; i++) {
        // Condición, 14 o más es aprobado
        if (notas[i] >= 14) {
            aprobados++;
        } else {
            reprobados++;
        }
    }
    cout << "\nCantidad de aprobados (>= 14): " << aprobados << endl;
    cout << "Cantidad de reprobados (< 14): " << reprobados << endl;
}