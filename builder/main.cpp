#include <iostream>
#include <string>

class Car {
private:
    std::string _modelo;
    std::string _motor;
    int _assentos;

public:
    void setModelo(const std::string& modelo) {
        _modelo = modelo;
    }
    void setMotor(const std::string& motor) {
        _motor = motor;
    }
    void setAssentos(int qtAssentos ) {
        _assentos = qtAssentos;
    }

    void show() {
        std::cout << "Modelo: " << _modelo << "\n";
        std::cout << "Motor: " << _motor << "\n";
        std::cout << "Assentos: " << _assentos << "\n";
    }
};

class CarBuilder {
public:
    virtual ~CarBuilder() {}
    virtual void buildModelo() = 0;
    virtual void buildMotor() = 0;
    virtual void buildAssentos() = 0;
    virtual Car* getCar() = 0;
};

class SportsCarBuilder : public CarBuilder {
private:
    Car* car;

public:
    SportsCarBuilder() { car = new Car(); }
    void buildModelo() override { car->setModelo("Sports Car"); }
    void buildMotor() override { car->setMotor("V8 Turbo"); }
    void buildAssentos() override { car->setAssentos(2); }
    Car* getCar() override { return car; }
};

class Director {
private:
    CarBuilder* builder;

public:
    void setBuilder(CarBuilder* b) { builder = b; }
    Car* construct() {
        builder->buildModelo();
        builder->buildMotor();
        builder->buildAssentos();
        return builder->getCar();
    }
};

int main() {
    Director director;
    SportsCarBuilder sportsBuilder;

    director.setBuilder(&sportsBuilder);
    Car* sportsCar = director.construct();

    sportsCar->show();

    delete sportsCar;
    return 0;
}