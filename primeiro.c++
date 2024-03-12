 #include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits> // Para std::numeric_limits

using namespace std;

struct Produto {
    string nome;
    float precoCompra;
    float precoVenda;
    int estoque;
    int quantidadeComprada;

    float calcularLucro() const {
        return (precoVenda - precoCompra) * quantidadeComprada;
    }

    float valorTotalVendas() const {
        return precoVenda * quantidadeComprada;
    }

    int totalProdutosEstoque() const {
        return estoque;
    }
};

void imprimirDetalhesProduto(const Produto& produto) {
    cout << "\nResumo para: " << produto.nome << endl;
    cout << left 
         << setw(25) << "Nome"
         << setw(15) << "Preço Compra"
         << setw(15) << "Preço Venda"
         << setw(10) << "Estoque"
         << setw(18) << "Qtd. Comprada"
         << setw(15) << "Lucro Total"
         << setw(20) << "Valor Vendas Total" << endl;
    cout << string(118, '-') << endl;
    cout << left 
         << setw(25) << produto.nome
         << setw(15) << produto.precoCompra
         << setw(15) << produto.precoVenda
         << setw(10) << produto.estoque
         << setw(18) << produto.quantidadeComprada
         << setw(15) << produto.calcularLucro()
         << setw(20) << produto.valorTotalVendas() << endl;
}

void imprimirResumoGeral(const vector<Produto>& produtos) {
    cout << "\nResumo Geral de Todos os Produtos\n";
    cout << left 
         << setw(25) << "Nome"
         << setw(15) << "Lucro Total"
         << setw(20) << "Valor Vendas Total" << endl;
    cout << string(60, '-') << endl;
    for (const auto& produto : produtos) {
        cout << left 
             << setw(25) << produto.nome
             << setw(15) << produto.calcularLucro()
             << setw(20) << produto.valorTotalVendas() << endl;
    }
}

void pausa() {
    cout << "\nPressione Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora el resto del buffer de entrada
    cin.get(); // Espera a que el usuario presione Enter
}

int main() {
    vector<Produto> produtos = {
        {"Mochila"},
        {"Calculadora científica"},
        {"Estojos completos"},
        {"Dicionários"},
        {"Computadores"}
    };

    int opcao;
    for (;;) {
        cout << "\nEscolha um produto:\n";
        for (size_t i = 0; i < produtos.size(); ++i) {
            cout << i + 1 << ". " << produtos[i].nome << endl;
        }
        cout << "0. Sair\n";
        cout << "Opção: ";
        cin >> opcao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer después de leer un entero

        if (opcao == 0) {
            break; // Salir del bucle si se elige la opción 0
        } else if (opcao >= 1 && opcao <= static_cast<int>(produtos.size())) {
            Produto& produto = produtos[opcao - 1];

            cout << "Insira os dados para: " << produto.nome << endl;
            cout << "Preço de compra: ";
            cin >> produto.precoCompra;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer
            cout << "Preço de venda: ";
            cin >> produto.precoVenda;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer
            cout << "Quantidade comprada: ";
            cin >> produto.quantidadeComprada;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer
            cout << "Estoque: ";
            cin >> produto.estoque;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer después de leer un entero

            imprimirDetalhesProduto(produto);
            pausa(); // Pausa después de cada resumen de producto
        } else {
            cout << "Opção inválida. Por favor, escolha uma opção válida.\n";
        }
    }

    imprimirResumoGeral(produtos);

    return 0;
}
