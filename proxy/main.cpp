#include <iostream>
#include <memory>

class ICarro {
public:
    virtual void exibirInformacoes() = 0;
    virtual ~ICarro() {}
};

class CarroReal : public ICarro {
private:
    std::string modelo;
    std::string motor;

    void carregarDadosDoBanco() {
        std::cout << "Carregando dados do carro do banco de dados...\n";
        modelo = "SUV 4x4";
        motor = "Motor V6 Turbo";
    }

public:
    CarroReal() {
        carregarDadosDoBanco();
    }

    void exibirInformacoes() override {
        std::cout << "Modelo: " << modelo << " | Motor: " << motor << "\n";
    }
};

class ProxyCarro : public ICarro {
private:
    std::unique_ptr<CarroReal> carroReal;

public:
    void exibirInformacoes() override {
        if (!carroReal) {
            carroReal = std::make_unique<CarroReal>();
        }
        carroReal->exibirInformacoes();
    }
};

int main() {
    std::cout << "Criando proxy do carro...\n";
    ProxyCarro carro;

    std::cout << "\nExibindo informações do carro (objeto real ainda não foi criado)...\n";
    carro.exibirInformacoes();

    std::cout << "\nExibindo informações do carro novamente (objeto real já carregado)...\n";
    carro.exibirInformacoes();

    return 0;
}