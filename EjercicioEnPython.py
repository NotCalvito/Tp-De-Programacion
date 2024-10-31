import os

class Libro:
    def __init__(self, titulo, autor, fecha, editorial, ISBN, paginas, volumen):
        self.titulo = titulo
        self.autor = autor
        self.fecha = fecha
        self.editorial = editorial
        self.ISBN = ISBN
        self.paginas = paginas
        self.volumen = volumen

class Lector:
    def __init__(self, Dni, Nombre, Apellido):
        self.Dni = Dni
        self.Nombre = Nombre
        self.Apellido = Apellido

ListaLibros = []
ISBNfinal = 0

def RegistroLibro():
    global ISBNfinal
    titulo = input("Ingrese el nombre del libro: ")
    for libro in ListaLibros:
        if libro.titulo == titulo:
            volumenes_adicionales = int(input("Este libro ya existe. Ingrese el numero de volumenes adicionales: "))
            libro.volumen += volumenes_adicionales
            print(f"Volumenes actualizados: {libro.volumen}")
            return
    autor = input("Ingrese el nombre de su autor: ")
    fecha = input("Ingrese la fecha (Acuerdese de escribir la fecha en el siguiente formato 'day/month/year'): ")
    editorial = input("Ingrese la editorial del libro: ")
    paginas = input("Ingrese la cantidad de paginas: ")
    volumen = int(input("Ingrese la cantidad de Volumenes a disposicion: "))
    ISBNfinal += 1
    nuevo_libro = Libro(titulo, autor, fecha, editorial, ISBNfinal, paginas, volumen)
    ListaLibros.append(nuevo_libro)
    ListaLibros.sort(key=lambda x: x.titulo)
    with open("ColeccionDeLibros.txt", "a") as archivo:
        archivo.write(f"Codigo ISBN={nuevo_libro.ISBN}\n")
        archivo.write(f"Titulo={nuevo_libro.titulo}\n")
        archivo.write(f"Autor={nuevo_libro.autor}\n")
        archivo.write(f"Fecha de publicacion={nuevo_libro.fecha}\n")
        archivo.write(f"Editorial={nuevo_libro.editorial}\n")
        archivo.write(f"Numero de paginas={nuevo_libro.paginas}\n")
    if input("Desea poner un libro mas? (1/0): ") == '1':
        RegistroLibro()

def ComparacionDeLibros(a, b):
    return a.titulo < b.titulo

def Mostrar():
    for libro in ListaLibros:
        print(f"ISBN: {libro.ISBN}")
        print(f"Titulo: {libro.titulo}")
        print(f"Autor: {libro.autor}")
        print(f"Fecha de publicacion: {libro.fecha}")
        print(f"Editorial: {libro.editorial}")
        print(f"Paginas: {libro.paginas}")
        print(f"Volumenes disponibles: {libro.volumen}")
        print("--------------------------")

def Buscar():
    titulo = input("Ingrese el titulo del libro que desea buscar: ")
    for libro in ListaLibros:
        if libro.titulo == titulo:
            print(f"ISBN: {libro.ISBN}")
            print(f"Titulo: {libro.titulo}")
            print(f"Autor: {libro.autor}")
            print(f"Ano de publicacion: {libro.fecha}")
            print(f"Editorial: {libro.editorial}")
            print(f"Paginas: {libro.paginas}")
            print(f"Volumenes disponibles: {libro.volumen}")
            return
    print("Libro no encontrado.")

def Eliminar():
    titulo = input("Ingrese el titulo del libro que desea eliminar: ")
    for libro in ListaLibros:
        if libro.titulo == titulo:
            ListaLibros.remove(libro)
            print(f"Libro \"{titulo}\" eliminado exitosamente de la lista.")
            with open("ColeccionDeLibros_temp.txt", "w") as archivo:
                for libro in ListaLibros:
                    archivo.write(f"{libro.ISBN}\n")
                    archivo.write(f"{libro.titulo}\n")
                    archivo.write(f"{libro.autor}\n")
                    archivo.write(f"{libro.fecha}\n")
                    archivo.write(f"{libro.editorial}\n")
                    archivo.write(f"{libro.paginas}\n")
                    archivo.write(f"{libro.volumen}\n")
            os.remove("ColeccionDeLibros.txt")
            os.rename("ColeccionDeLibros_temp.txt", "ColeccionDeLibros.txt")
            print(f"Libro \"{titulo}\" eliminado exitosamente del archivo.")
            return
    print(f"Libro \"{titulo}\" no encontrado.")

def main():
    while True:
        print("Ingrese un valor para continuar")
        print("1=Registrar un libro en la biblioteca")
        print("2=Buscar un libro")
        print("3=Borrar un libro")
        print("4=Mostrar libros")
        print("5=Terminar el programa")
        valor_de_ingreso = int(input())
        print("--------------------------")
        if valor_de_ingreso == 1:
            RegistroLibro()
        elif valor_de_ingreso == 2:
            Buscar()
        elif valor_de_ingreso == 3:
            Eliminar()
        elif valor_de_ingreso == 4:
            Mostrar()
        elif valor_de_ingreso == 5:
            print("Gracias por utilizar el programa")
            break
        else:
            print("Ingrese un numero valido")

if __name__ == "__main__":
    main()
