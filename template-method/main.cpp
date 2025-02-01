#include <iostream>

class FabricaDeCarro {
public:
    void fabricarCarro() {
        montarChassi();
        instalarMotor();
        pintarCarro();
        adicionarDetalhes();
        std::cout << "Carro finalizado!\n";
    }

protected:
    virtual void montarChassi() {
        std::cout << "Montando o chassi padrão.\n";
    }
    virtual void instalarMotor() = 0;
    virtual void pintarCarro() = 0;
    virtual void adicionarDetalhes() {
        std::cout << "Adicionando detalhes padrão ao carro.\n";
    }
};

class FabricaDeCarroEsportivo : public FabricaDeCarro {
protected:
    void instalarMotor() override {
        std::cout << "Instalando motor V8 turbo em carro esportivo.\n";
    }
    void pintarCarro() override {
        std::cout << "Pintando carro esportivo de vermelho brilhante.\n";
    }
    void adicionarDetalhes() override {
        std::cout << "Adicionando aerofólio e rodas esportivas.\n";
    }
};

class FabricaDeCarroPopular : public FabricaDeCarro {
protected:
    void instalarMotor() override {
        std::cout << "Instalando motor 1.0 econômico em carro popular.\n";
    }
    void pintarCarro() override {
        std::cout << "Pintando carro popular de branco.\n";
    }
};

class FabricaDeCarroSUV : public FabricaDeCarro {
protected:
    void instalarMotor() override {
        std::cout << "Instalando motor V6 robusto em carro SUV.\n";
    }
    void pintarCarro() override {
        std::cout << "Pintando carro SUV de preto fosco.\n";
    }
    void adicionarDetalhes() override {
        std::cout << "Adicionando rack de teto e suspensão elevada.\n";
    }
};

int main() {
    std::cout << "Fabricação de Carro Esportivo:\n";
    FabricaDeCarroEsportivo carroEsportivo;
    carroEsportivo.fabricarCarro();

    std::cout << "\nFabricação de Carro Popular:\n";
    FabricaDeCarroPopular carroPopular;
    carroPopular.fabricarCarro();

    std::cout << "\nFabricação de Carro SUV:\n";
    FabricaDeCarroSUV carroSUV;
    carroSUV.fabricarCarro();

    return 0;
}