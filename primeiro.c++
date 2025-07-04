#include <iostream>
#include <vector>
#include <string>
#include <limits>

struct Produto {
    std::string nome;
    double precoCompra;
    double precoVenda;
    int estoque;
};

double totalVendas = 0.0;

void limpiarBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void atualizarEstoque(std::vector<Produto>& produtos) {
    int numeroProduto;
    int quantidade;

    std::cout << "Produtos disponíveis:\n";
    for (size_t i = 0; i < produtos.size(); ++i) {
        std::cout << i + 1 << ". " << produtos[i].nome << "\n";
    }
    std::cout << produtos.size() + 1 << ". Adicionar mais produtos\n";

    std::cout << "Digite o número do produto para atualizar o estoque ou adicionar mais produtos: ";
    std::cin >> numeroProduto;
    if (std::cin.fail()) {
        limpiarBuffer();
        std::cout << "Entrada inválida.\n";
        return;
    }

    if (numeroProduto >= 1 && numeroProduto <= produtos.size()) {
        std::cout << "Digite a quantidade a ser adicionada ao estoque: ";
        std::cin >> quantidade;
        if (std::cin.fail()) {
            limpiarBuffer();
            std::cout << "Entrada inválida.\n";
            return;
        }
        limpiarBuffer();
        produtos[numeroProduto - 1].estoque += quantidade;
        std::cout << "Estoque atualizado.\n";
    } else if (numeroProduto == produtos.size() + 1) {
        Produto novoProduto;
        std::cout << "Digite o nome do novo produto: ";
        std::cin >> novoProduto.nome;

        std::cout << "Digite o preço de compra do novo produto: ";
        std::cin >> novoProduto.precoCompra;
        if (std::cin.fail()) {
            limpiarBuffer();
            std::cout << "Entrada inválida.\n";
            return;
        }

        std::cout << "Digite o preço de venda do novo produto: ";
        std::cin >> novoProduto.precoVenda;
        if (std::cin.fail()) {
            limpiarBuffer();
            std::cout << "Entrada inválida.\n";
            return;
        }

        std::cout << "Digite o estoque inicial do novo produto: ";
        std::cin >> novoProduto.estoque;
        if (std::cin.fail()) {
            limpiarBuffer();
            std::cout << "Entrada inválida.\n";
            return;
        }

        limpiarBuffer();
        produtos.push_back(novoProduto);
        std::cout << "Produto adicionado.\n";
    } else {
        std::cout << "Número do produto inválido.\n";
    }
}

void realizarVenda(std::vector<Produto>& produtos) {
    int numeroProduto;
    int quantidade;
    double totalVenda = 0.0;
    bool continuarComprando = true;
    char resposta;

    while (continuarComprando) {
        std::cout << "Produtos disponíveis:\n";
        for (size_t i = 0; i < produtos.size(); ++i) {
            std::cout << i + 1 << ". " << produtos[i].nome << " - Em estoque: " << produtos[i].estoque << "\n";
        }

        std::cout << "Digite o número do produto para realizar uma venda: ";
        std::cin >> numeroProduto;
        if (std::cin.fail()) {
            limpiarBuffer();
            std::cout << "Entrada inválida.\n";
            continue;
        }

        if (numeroProduto < 1 || numeroProduto > produtos.size()) {
            std::cout << "Número inválido. Por favor, tente novamente.\n";
            continue;
        }

        std::cout << "Digite a quantidade a vender: ";
        std::cin >> quantidade;
        if (std::cin.fail()) {
            limpiarBuffer();
            std::cout << "Entrada inválida.\n";
            continue;
        }

        if (quantidade > produtos[numeroProduto - 1].estoque) {
            std::cout << "Não há estoque suficiente. Tente uma quantidade menor.\n";
            continue;
        }

        double totalProduto = quantidade * produtos[numeroProduto - 1].precoVenda;
        totalVenda += totalProduto;
        produtos[numeroProduto - 1].estoque -= quantidade;
        std::cout << "Produto vendido. Total parcial: " << totalVenda << "\n";

        std::cout << "Deseja adicionar outro produto à compra? (S/N): ";
        std::cin >> resposta;
        continuarComprando = (resposta == 'S' || resposta == 's');
    }

    std::cout << "Total a pagar: " << totalVenda << "\n";
    totalVendas += totalVenda;

    double dinheiroRecebido;
    std::cout << "Digite o dinheiro recebido: ";
    std::cin >> dinheiroRecebido;
    if (std::cin.fail()) {
        limpiarBuffer();
        std::cout << "Entrada inválida. Transação cancelada.\n";
        return;
    }

    if (dinheiroRecebido >= totalVenda) {
        double troco = dinheiroRecebido - totalVenda;
        std::cout << "Troco: " << troco << "\n";
    } else {
        std::cout << "Dinheiro insuficiente. Transação cancelada.\n";
        // Poderias devolver ao estoque aqui, se necessário.
    }
}

void resumo(const std::vector<Produto>& produtos) {
    double custoTotalEstoque = 0.0;
    double vendasTotaisEstimadas = 0.0;

    std::cout << "Resumo:\n";
    for (size_t i = 0; i < produtos.size(); ++i) {
        const Produto& produto = produtos[i];
        std::cout << "Produto " << i + 1 << ": " << produto.nome << "\n";
        std::cout << "Preço de compra: " << produto.precoCompra << "\n";
        std::cout << "Preço de venda: " << produto.precoVenda << "\n";
        std::cout << "Estoque: " << produto.estoque << "\n";
        double lucroPorProduto = (produto.precoVenda - produto.precoCompra) * produto.estoque;
        std::cout << "Lucro por produto: " << lucroPorProduto << "\n";
        custoTotalEstoque += produto.precoCompra * produto.estoque;
        vendasTotaisEstimadas += produto.precoVenda * produto.estoque;
        std::cout << "-----------------------------\n";
    }

    std::cout << "Custo total do estoque: " << custoTotalEstoque << "\n";
    std::cout << "Vendas totais estimadas: " << vendasTotaisEstimadas << "\n";
    std::cout << "Total de vendas realizadas: " << totalVendas << "\n";
}

int main() {
    std::vector<Produto> produtos = {
        {"Mochila", 15.00, 25.00, 200},
        {"Calculadora científica", 10.00, 20.00, 200},
        {"Estojo completo", 8.00, 15.00, 200},
        {"Dicionários", 20.00, 35.00, 200},
        {"Computadores", 300.00, 450.00, 200}
    };

    int opcao;
    do {
        std::cout << "\n1. Atualizar estoque\n";
        std::cout << "2. Realizar venda\n";
        std::cout << "3. Mostrar resumo\n";
        std::cout << "4. Sair\n";
        std::cout << "Digite uma opção: ";
        std::cin >> opcao;

        if (std::cin.fail()) {
            limpiarBuffer();
            std::cout << "Entrada inválida. Por favor, digite um número.\n";
            continue;
        }

        switch (opcao) {
            case 1:
                atualizarEstoque(produtos);
                break;
            case 2:
                realizarVenda(produtos);
                break;
            case 3:
                resumo(produtos);
                break;
            case 4:
                std::cout << "Volte sempre com mais dinheiro <3\n";
                break;
            default:
                std::cout << "Opção inválida. Por favor, tente novamente.\n";
        }
    } while (opcao != 4);

    return 0;
}
// Compilação: g++ primeiro.c++ -o primeiro.exe
// Execução: primeiro.exe
// Teste: 1. Atualizar estoque, 2. Realizar venda, 3. Mostrar resumo, 4. Sair
