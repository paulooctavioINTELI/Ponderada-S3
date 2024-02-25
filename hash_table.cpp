#include <iostream>
#include <vector>
#include <list>
#include <string>

class Mercadoria {
public:
    int codigo;
    std::string nome;

    Mercadoria(int codigo, std::string nome) : codigo(codigo), nome(nome) {}
};

class HashTable {
private:
    std::vector<std::list<Mercadoria>> tabela;
    int capacidade;

    int hashFunction(int codigo) {
        return codigo % capacidade;
    }

public:
    HashTable(int capacidade) : capacidade(capacidade) {
        tabela.resize(capacidade);
    }

    void inserir(Mercadoria mercadoria) {
        int index = hashFunction(mercadoria.codigo);
        tabela[index].push_back(mercadoria);
    }

    Mercadoria* buscar(int codigo) {
        int index = hashFunction(codigo);
        for (auto& item : tabela[index]) {
            if (item.codigo == codigo) {
                return &item;
            }
        }
        return nullptr;
    }

    bool remover(int codigo) {
        int index = hashFunction(codigo);
        auto& lista = tabela[index];
        for (auto it = lista.begin(); it != lista.end(); ++it) {
            if (it->codigo == codigo) {
                lista.erase(it);
                return true;
            }
        }
        return false;
    }

    void imprimir() {
        for (int i = 0; i < capacidade; ++i) {
            std::cout << "Slot " << i << ": ";
            for (auto& mercadoria : tabela[i]) {
                std::cout << "[Código: " << mercadoria.codigo << ", Nome: " << mercadoria.nome << "] ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    HashTable ht(10);

    ht.inserir(Mercadoria(101, "Caneta BIC"));
    ht.inserir(Mercadoria(202, "Lápis Faber-Castell"));
    ht.inserir(Mercadoria(303, "Borracha Mercur"));

    std::cout << "Tabela após inserções:" << std::endl;
    ht.imprimir();

    // Busca por uma mercadoria que existe
    int codigoParaBuscar = 202;
    Mercadoria* mercadoriaEncontrada = ht.buscar(codigoParaBuscar);
    if (mercadoriaEncontrada != nullptr) {
        std::cout << "Mercadoria encontrada: [Código: " << mercadoriaEncontrada->codigo << ", Nome: " << mercadoriaEncontrada->nome << "]" << std::endl;
    } else {
        std::cout << "Mercadoria com código " << codigoParaBuscar << " não encontrada." << std::endl;
    }

    // Caso de Teste 4: Busca por uma mercadoria inexistente
    codigoParaBuscar = 404;
    mercadoriaEncontrada = ht.buscar(codigoParaBuscar);
    if (mercadoriaEncontrada == nullptr) {
        std::cout << "Mercadoria com código " << codigoParaBuscar << " não existe." << std::endl;
    }

    // Remove uma mercadoria existente
    ht.remover(202);
    std::cout << "Tabela após remoção da mercadoria existente:" << std::endl;
    ht.imprimir();

    // Caso de Teste 5: Tentativa de remover uma mercadoria inexistente
    bool removido = ht.remover(404);
    if (!removido) {
        std::cout << "Tentativa de remover uma mercadoria inexistente (código 404) falhou, como esperado." << std::endl;
    }

    return 0;
}
