/* #include <iostream>
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
         << setw(15) << "Preço Compra"
         << setw(15) << "Preço Venda"
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
        {4, "Dicionários", 20.00, 35.00, 30, 4}, 
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
 */

/*  #include <iostream>
#include <limits> // Para std::numeric_limits
#include <iomanip> // Para setw, left, etc.
#include <vector>

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
    float lucroTotal = 0;
    float valorTotalVendas = 0;
    for (const auto& produto : produtos) {
        cout << left 
             << setw(25) << produto.nome
             << setw(15) << produto.calcularLucro()
             << setw(20) << produto.valorTotalVendas() << endl;
        lucroTotal += produto.calcularLucro();
        valorTotalVendas += produto.valorTotalVendas();
    }
    cout << "\nLucro Total: " << lucroTotal << endl;
    cout << "Valor Total Vendas: " << valorTotalVendas << endl;
}

void pausa() {
    cout << "\nPressione Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora el resto del buffer de entrada
    cin.get(); // Espera a que el usuario presione Enter
}

int main() {
    vector<Produto> produtos = {
        {"Mochila", 0, 0, 0, 0},
        {"Calculadora científica", 0, 0, 0, 0},
        {"Estojos completos", 0, 0, 0, 0},
        {"Dicionários", 0, 0, 0, 0},
        {"Computadores", 0, 0, 0, 0}
    };

    for (auto& produto : produtos) {
        cout << "Insira os dados para: " << produto.nome << endl;
        cout << "Preço de compra: ";
        cin >> produto.precoCompra;
        cout << "Preço de venda: ";
        cin >> produto.precoVenda;
        cout << "Quantidade comprada: ";
        cin >> produto.quantidadeComprada;
        cout << "Estoque: ";
        cin >> produto.estoque;
        imprimirDetalhesProduto(produto);
    }

    imprimirResumoGeral(produtos);

    return 0; 
}*/

/* #include <iostream>
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
 */
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
