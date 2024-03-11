#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_PRODUTOS = 5;

struct Produto {
    int numeroItem;
    string nome;
    float precoCompra;
    float precoVenda;
    int stock;
    int quantidadeComprada;

    float calcularLucro() const {
        return (precoVenda - precoCompra) * quantidadeComprada;
    }

    float custoTotalEstoque() const {
        return precoCompra * stock;
    }

    float valorTotalVendas() const {
        return precoVenda * quantidadeComprada;
    }
};

void imprimirCabecalho() {
    cout << left << setw(10) << "Item"
         << setw(25) << "Nome"
         << setw(15) << "Preco Compra"
         << setw(15) << "Preco Venda"
         << setw(10) << "Stock"
         << setw(20) << "Quant. Comprada"
         << setw(15) << "Lucro"
         << setw(20) << "Custo Estoque"
         << setw(20) << "Valor Vendas" << endl;
    cout << string(150, '-') << endl;
}

int main() {
    Produto produtos[MAX_PRODUTOS] = {
        {1, "Mochila", 15.00, 25.00, 50, 4}, 
        {2, "Calculadora cientifica", 10.00, 20.00, 100, 20}, 
        {3, "Estojos completos", 8.00, 15.00, 80, 5}, 
        {4, "Dicionarios", 20.00, 35.00, 30, 4}, 
        {5, "Computadores", 300.00, 450.00, 10, 50} 
    };

    imprimirCabecalho();

    for (int i = 0; i < MAX_PRODUTOS; i++) {
        cout << left << setw(10) << produtos[i].numeroItem
             << setw(25) << produtos[i].nome
             << setw(15) << produtos[i].precoCompra
             << setw(15) << produtos[i].precoVenda
             << setw(10) << produtos[i].stock
             << setw(20) << produtos[i].quantidadeComprada
             << setw(15) << produtos[i].calcularLucro()
             << setw(20) << produtos[i].custoTotalEstoque()
             << setw(20) << produtos[i].valorTotalVendas() << endl;
    }

    return 0;
}
