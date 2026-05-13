#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Estructura para representar un producto
struct Producto {
    string codigo;
    string nombre;
    int cantidad;
    double precio;
};

// --- FUNCIONES DE AYUDA ---

// Paso 2: Función de ayuda para buscar un producto (reutilizable)
int buscarProducto(const vector<Producto>& inventario, string codigo) {
    for (int i = 0; i < inventario.size(); i++) {
        if (inventario[i].codigo == codigo) {
            return i; // Retorna el índice si lo encuentra
        }
    }
    return -1; // Retorna -1 si no existe
}

// --- FUNCIONES DE RESPONSABILIDAD ÚNICA ---

void mostrarMenu() {
    cout << "\n--- GESTION DE INVENTARIO GADGETXPRESS ---" << endl;
    cout << "1. Agregar producto" << endl;
    cout << "2. Listar productos" << endl;
    cout << "3. Actualizar cantidad" << endl;
    cout << "4. Reporte bajo inventario" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

void agregarProducto(vector<Producto>& inventario) {
    string cod;
    cout << "Ingrese codigo: "; cin >> cod;

    if (buscarProducto(inventario, cod) != -1) {
        cout << "Error: El codigo ya existe." << endl;
        return;
    }

    Producto p;
    p.codigo = cod;
    cout << "Nombre: "; cin.ignore(); getline(cin, p.nombre);
    cout << "Cantidad: "; cin >> p.cantidad;
    cout << "Precio: "; cin >> p.precio;
    
    inventario.push_back(p);
    cout << "Producto agregado con exito." << endl;
}

void listarProductos(const vector<Producto>& inventario) {
    cout << "\n--- INVENTARIO COMPLETO ---" << endl;
    for (const auto& p : inventario) {
        cout << "Cod: " << p.codigo << " | " << p.nombre << " | Stock: " << p.cantidad << endl;
    }
}

void actualizarCantidad(vector<Producto>& inventario) {
    string cod;
    cout << "Codigo del producto a actualizar: "; cin >> cod;
    
    int indice = buscarProducto(inventario, cod);
    if (indice != -1) {
        cout << "Nueva cantidad: ";
        cin >> inventario[indice].cantidad;
        cout << "Stock actualizado." << endl;
    } else {
        cout << "Producto no encontrado." << endl;
    }
}

void reporteBajoInventario(const vector<Producto>& inventario) {
    int limite = 5;
    cout << "\n--- PRODUCTOS CON BAJO STOCK (< " << limite << ") ---" << endl;
    for (const auto& p : inventario) {
        if (p.cantidad < limite) {
            cout << p.nombre << " (Quedan: " << p.cantidad << ")" << endl;
        }
    }
}

// --- PROGRAMA PRINCIPAL ---

int main() {
    vector<Producto> inventario;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1: agregarProducto(inventario); break;
            case 2: listarProductos(inventario); break;
            case 3: actualizarCantidad(inventario); break;
            case 4: reporteBajoInventario(inventario); break;
            case 5: cout << "Saliendo..." << endl; break;
            default: cout << "Opcion invalida." << endl;
        }
    } while (opcion != 5);

    return 0;
}

