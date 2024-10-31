#include <iostream>
using namespace std;

int movimientos[10][3] = {
    {4, 6, -1},
    {6, 8, -1},
    {7, 9, -1},
    {4, 8, -1},
    {0, 3, 9},
    {-1, -1, -1},
    {0, 1, 7},
    {2, 6, -1},
    {1, 3, -1},
    {2, 4, -1}
};

int contarMovimientos(int numero, int movimientosRestantes) {
    if (movimientosRestantes == 0) {
        return 1;
    }
    int total = 0;
    for (int i = 0; i < 3; i++) {
        if (movimientos[numero][i] != -1) {
            total += contarMovimientos(movimientos[numero][i], movimientosRestantes - 1);
        }
    }
    return total;
}

int main() {
    int movimientosUsuario;
    cout << "Introduce la cantidad de movimientos a realizar: ";
    cin >> movimientosUsuario;

    int totalMovimientos = 0;
    for (int i = 0; i < 10; i++) {
        totalMovimientos += contarMovimientos(i, movimientosUsuario);
    }

    cout << "Total de movimientos válidos con " << movimientosUsuario << " movimientos: " << totalMovimientos << endl;

    return 0;
}

