#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

ofstream Archivo;
ofstream Lectores;
struct Libros{
    string titulo;
    string autor;
    string fecha;
    string editorial;
    int ISBN;
    string paginas;
    int volumen; 
};
struct Lectores{
    int Dni;
    string Nombre;
    string Apellido;

};
vector<Libros> ListaLibros;
bool ExistenteLibro;
int ValorDeIngreso=0, ISBNfinal=0, Volumen;
string LibroEliminar;
void RegistroLibro();
void Buscar();
void Ordenar();
void Mostrar();
//void Devolver();
//void RegistroLectores();
void Eliminar(string LibroEliminar);
bool ComparacionDeLibros(const Libros& a, const Libros& b);




int main(){
    cout<<"Ingrese un valor para continuar"<<endl;
    cout<<"1=Registrar un libro en la biblioteca"<<endl;
    cout<<"2=Buscar un libro"<<endl;
    cout<<"3=Borrar un libro"<<endl;
    cout<<"4=Mostrar libros"<<endl;
    cout<<"5=Terminar el programa"<<endl;
    cin>>ValorDeIngreso;
    cout << "--------------------------" << endl;
    switch (ValorDeIngreso)
    {
    case 1:
        RegistroLibro();
        break;
        ValorDeIngreso=0;
    case 2:
    Buscar();
    ValorDeIngreso=0;
    break;
    case 3:
       Eliminar(LibroEliminar);
        ValorDeIngreso=0;
        break;
    case 4:
    Mostrar();
    ValorDeIngreso=0;
    break;
    case 5:
     cout<<"Gracias por utilizar el programa"<<endl;
        ValorDeIngreso=1;
        return 0;
        break;
    default:
        cout<<"Ingrese un numero valido"<<endl;
        break;
    }
//la puta madre
}

void RegistroLibro(){
Libros LibroNuevo;
bool pregunta=1;
bool ExistenteLibro = false;
char MiSalvador[1000];
using namespace std;
do
{
    cin.getline(MiSalvador, 1000, '\n');
    cout<<"Ingrese el nombre del libro ";
    getline(cin,LibroNuevo.titulo);

    for (auto& Libros : ListaLibros) {
        if (Libros.titulo == LibroNuevo.titulo) {
            cout << "Este libro ya existe. Ingrese el numero de volumenes adicionales: ";
            int VolumenesAdicionales;
            cin >> VolumenesAdicionales;
            Libros.volumen += VolumenesAdicionales;
            cout << "Volumenes actualizados: " << Libros.volumen << endl;
            ExistenteLibro = true;
            break;
        }
    }
    if(!ExistenteLibro){
        cout<<"Ingrese el nombre de su autor ";
        getline(cin,LibroNuevo.autor);
        

        cout<<"Ingrese la fecha (Acuerdese de escribir la fecha en el siguiente formato 'day/month/year') ";
        getline(cin,LibroNuevo.fecha);
        

        cout<<"Ingrese la editorial del libro ";
        getline(cin,LibroNuevo.editorial);
       
        
        cout<<"Ingrese la cantidad de paginas ";
        getline(cin,LibroNuevo.paginas);
       
        cout<<"Ingrese la cantidad de Volumenes a disposicion ";
        cin>>LibroNuevo.volumen;

        LibroNuevo.ISBN= ++ISBNfinal;
        ofstream Archivo("ColeccionDeLibros.txt", ios::app);
        Archivo<<"Codigo ISBN="<<LibroNuevo.ISBN<<endl;
        cin.ignore();
        Archivo<<"Titulo="<<LibroNuevo.titulo<<endl;
        cin.ignore();
        Archivo<<"Autor="<<LibroNuevo.autor<<endl;
        cin.ignore();
        Archivo<<"Fecha de publicacion="<<LibroNuevo.fecha<<endl;
        cin.ignore();
        Archivo<<"Editorial="<<LibroNuevo.editorial<<endl;
        cin.ignore();
        Archivo<<"Numero de paginas="<<LibroNuevo.paginas<<endl;
    }
    Archivo.close();
    ListaLibros.push_back(LibroNuevo);
    sort(ListaLibros.begin(), ListaLibros.end(), ComparacionDeLibros); 
    cout<<"Desea poner un libro mas? (1/0)";
    cin>>pregunta;
     cout << "--------------------------" << endl;
    } while (pregunta =='1');  
}
bool ComparacionDeLibros(const Libros& a, const Libros& b){
    return a.titulo < b.titulo;
}
void Mostrar(){
    for (const auto& Libros : ListaLibros) {
        cout << "ISBN: " << Libros.ISBN << endl;
        cout << "Titulo: " << Libros.titulo << endl;
        cout << "Autor: " << Libros.autor << endl;
        cout << "Fecha de publicacion: " << Libros.fecha << endl;
        cout << "Editorial: " << Libros.editorial << endl;
        cout << "Paginas: " << Libros.paginas << endl;
        cout << "Volumenes disponibles: " << Libros.volumen << endl;
        cout << "--------------------------" << endl;
    }
}
void Buscar(){
    string TituloDelLibro;
    cout << "Ingrese el titulo del libro que desea buscar: ";
    cin.ignore();
    getline(cin, TituloDelLibro);
    bool Busqueda = false;
    for (const auto& Libros : ListaLibros) {
        if (Libros.titulo == TituloDelLibro) {
            cout << "ISBN: " << Libros.ISBN << endl;
            cout << "Titulo: " << Libros.titulo << endl;
            cout << "Autor: " << Libros.autor << endl;
            cout << "Ano de publicacion: " << Libros.fecha<< endl;
            cout << "Editorial: " << Libros.editorial << endl; 
            cout << "Paginas: " << Libros.paginas << endl;
            cout << "Volumenes disponibles: " << Libros.volumen << endl;
            Busqueda = true;
            break;
        }
    }
    if (Busqueda=false) {
        cout << "Libro no encontrado." << endl;
    }
}
void Eliminar(string LibroEliminar){
    cout << "Ingrese el titulo del libro que desea eliminar: ";
    cin >>LibroEliminar;
    cin.ignore();
    auto xc = ListaLibros.begin();
    bool Busqueda = false;
    while (xc != ListaLibros.end()) {
        if (xc->titulo == LibroEliminar) {
            xc = ListaLibros.erase(xc);
            Busqueda = true;
            cout << "Libro \"" << LibroEliminar << "\" eliminado exitosamente de la lista." << endl;
        } else {
            ++xc;
        }
    }
    if (Busqueda) {
        ofstream archivo("ColeccionDeLibros_temp.txt", ios::out);
        for (const auto& Libros : ListaLibros) {
            archivo << Libros.ISBN << endl;
            archivo << Libros.titulo << endl;
            archivo << Libros.autor << endl;
            archivo << Libros.fecha << endl;
            archivo << Libros.editorial << endl;
            archivo << Libros.paginas << endl;
            archivo << Libros.volumen << endl;
        }
        Archivo.close();
        remove("ColeccionDeLibros.txt");
        rename("ColeccionDeLibros_temp.txt", "ColeccionDeLibros.txt");

        cout << "Libro \"" << LibroEliminar << "\" eliminado exitosamente del archivo." << endl;
    } else {
        cout << "Libro \"" << LibroEliminar << "\" no encontrado." << endl;
    }
}
