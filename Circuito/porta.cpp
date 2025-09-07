#include "porta.h"
#include <exception>

///
/// AS PORTAS
///

/// Porta NOT

void PortaNOT::simular(const std::vector<bool3S> &in_port){
    if(int(in_port.size())<=0 || int(in_port.size())!=this->getNumInputs()){throw std::invalid_argument("Dimensao do vetor in_port inadequada");}
    this->setOutput(~(in_port.at(0)));
}

/// Porta AND

PortaAND::PortaAND(int NI): Porta(NI){
    if(NI<2){throw std::invalid_argument("Numero de entradas invalido");}
}
void PortaAND::simular(const std::vector<bool3S> &in_port){
    if(int(in_port.size())<=0 || int(in_port.size())!=this->getNumInputs()){throw std::invalid_argument("Dimensao do vetor in_port inadequada");}
    this->setOutput(in_port.at(0));
    for(int i = 1; i < this->getNumInputs(); ++i){
        this->setOutput(this->getOutput() & in_port.at(i));
    }
}

/// Porta NAND

PortaNAND::PortaNAND(int NI): Porta(NI){
    if(NI<2){throw std::invalid_argument("Numero de entradas invalido");}
}
void PortaNAND::simular(const std::vector<bool3S> &in_port){
    if(int(in_port.size())<=0 || int(in_port.size())!=this->getNumInputs()){throw std::invalid_argument("Dimensao do vetor in_port inadequada");}
    this->setOutput(in_port.at(0));
    for(int i = 1; i < this->getNumInputs(); ++i){
        this->setOutput(this->getOutput() & in_port.at(i));
    }
    this->setOutput(~(this->getOutput()));
}

/// Porta OR

PortaOR::PortaOR(int NI): Porta(NI){
    if(NI<2){throw std::invalid_argument("Numero de entradas invalido");}
}
void PortaOR::simular(const std::vector<bool3S> &in_port){
    if(int(in_port.size())<=0 || int(in_port.size())!=this->getNumInputs()){throw std::invalid_argument("Dimensao do vetor in_port inadequada");}
    this->setOutput(in_port.at(0));
    for(int i = 1; i < this->getNumInputs(); ++i){
        this->setOutput(this->getOutput() | in_port.at(i));
    }
}

/// Porta NOR

PortaNOR::PortaNOR(int NI): Porta(NI){
    if(NI<2){throw std::invalid_argument("Numero de entradas invalido");}
}
void PortaNOR::simular(const std::vector<bool3S> &in_port){
    if(int(in_port.size())<=0 || int(in_port.size())!=this->getNumInputs()){throw std::invalid_argument("Dimensao do vetor in_port inadequada");}
    this->setOutput(in_port.at(0));
    for(int i = 1; i < this->getNumInputs(); ++i){
        this->setOutput(this->getOutput() | in_port.at(i));
    }
    this->setOutput(~(this->getOutput()));
}

/// Porta XOR

PortaXOR::PortaXOR(int NI): Porta(NI){
    if(NI<2){throw std::invalid_argument("Numero de entradas invalido");}
}
void PortaXOR::simular(const std::vector<bool3S> &in_port){
    if(int(in_port.size())<=0 || int(in_port.size())!=this->getNumInputs()){throw std::invalid_argument("Dimensao do vetor in_port inadequada");}
    this->setOutput(in_port.at(0));
    for(int i = 1; i < this->getNumInputs(); ++i){
        this->setOutput(this->getOutput() ^ in_port.at(i));
    }
}

/// Porta NXOR

PortaNXOR::PortaNXOR(int NI): Porta(NI){
    if(NI<2){throw std::invalid_argument("Numero de entradas invalido");}
}
void PortaNXOR::simular(const std::vector<bool3S> &in_port){
    if(int(in_port.size())<=0 || int(in_port.size())!=this->getNumInputs()){throw std::invalid_argument("Dimensao do vetor in_port inadequada");}
    this->setOutput(in_port.at(0));
    for(int i = 1; i < this->getNumInputs(); ++i){
        this->setOutput(this->getOutput() ^ in_port.at(i));
    }
    this->setOutput(~(this->getOutput()));
}
