#include <iostream>
#include <string>

#include "circuito.h"

using namespace std;

// Funcao para imprimir as informacoes basicas sobre um Circuito
void imprimir_simples(const string& Nome, const Circuito& C)
{
  cout << Nome << '\t'
       << "NIn=" << C.getNumInputs() << '\t'
       << "NOut=" << C.getNumOutputs() << '\t'
       << "NPort=" << C.getNumPorts();
}

// Funcao para imprimir todas as informacoes sobre um Circuito
void imprimir(const string& Nome, const Circuito& C)
{
  imprimir_simples(Nome,C);
  cout << ": ";
  for (int i=0; i<C.getNumPorts(); ++i)
  {
    cout << C.getNamePort(i+1) << ' ';;
  }
  cout << endl;
}

// Funcao que inicializa e retorna um Circuito
// Ao retornar, pode usar o construtor por movimento
Circuito inicializa()
{
  Circuito prov;

  // Dimensiona o circuito
  prov.resize(2,1,1);
  // Inicializa a porta Id==1 como AND de 2 entradas
  prov.setPort(1,"AN",2);
  // As duas entradas da porta Id==1 veem das entradas -1 e -2 do circuito
  prov.setIdInPort(1, 0, -1);
  prov.setIdInPort(1, 1, -2);
  // A saida Id==1 do circuito vem da porta Id==1
  prov.setIdOutputCirc(1, 1);

  return prov;
}

int main(void)
{
  // Testando o construtor default;
  cout << "1)==========\n";
  Circuito C0;
  try
  {
    C0.setIdOutputCirc(1,1);
    cerr << "ERRO ";
  }
  catch(...)
  {
    cout << "ok ";
  }
  try
  {
    C0.setPort(1,"AN",2);
    cerr << "ERRO ";
  }
  catch(...)
  {
    cout << "ok ";
  }
  cout << endl;
  imprimir("C0",C0);     // Deve imprimir "C0 NIn=0 NOut=0 NPort=0:"

  // Testando o resize
  cout << "2)==========\n";
  C0.resize(2,2,2);
  imprimir_simples("C0",C0);     // Deve imprimir "C0 NIn=2 NOut=2 NPort=2"
  cout << endl;

  // Testando a modificacao de circuito
  cout << "3)==========\n";
  // Inicializa porta inexistente (id invalido)
  try
  {
    C0.setPort(-1,"NO",3);
    cerr << "ERRO 1 ";
  }
  catch(...)
  {
    cout << "ok ";
  }
  try
  {
    C0.setPort(0,"NO",3);
    cerr << "ERRO 2 ";
  }
  catch(...)
  {
    cout << "ok ";
  }
  try
  {
    C0.setPort(3,"NO",3);
    cerr << "ERRO 3 ";
  }
  catch(...)
  {
    cout << "ok ";
  }
  // Inicializa a porta Id==1 (valores invalidos e validos)
  try
  {
    C0.setPort(1,"MX",3);
    cerr << "ERRO 4 ";
  }
  catch(...)
  {
    cout << "ok ";
  }
  try
  {
    C0.setPort(1,"NO",1);
    cerr << "ERRO 5 ";
  }
  catch(...)
  {
    cout << "ok ";
  }
  try
  {
    C0.setPort(1,"NO",3);
    cout << "ok ";
  }
  catch(...)
  {
    cerr << "Nao deveria dar ERRO 6\n";
  }
  // Inicializa a porta Id==2 (valores invalidos e validos)
  try
  {
    C0.setPort(2,"NT",2);
    cerr << "ERRO 7 ";
  }
  catch(...)
  {
    cout << "ok ";
  }
  try
  {
    C0.setPort(2,"NT",1);
    cout << "ok ";
  }
  catch(...)
  {
    cerr << "Nao deveria dar ERRO 8\n";
  }
  // Modifica as origens das entradas das portas
  try
  {
    C0.setIdInPort(-1,0,-1);
    cerr << "ERRO 9 ";
  }
  catch(...)
  {
    cout << "ok ";
  }
  try
  {
    C0.setIdInPort(0,0,-1);
    cerr << "ERRO 10 ";
  }
  catch(...)
  {
    cout << "ok ";
  }
  try
  {
    C0.setIdInPort(1,0,-1);
    cout << "ok ";
  }
  catch(...)
  {
    cerr << "Nao deveria dar ERRO 11\n";
  }
  try
  {
    C0.setIdInPort(1,1,1);
    cout << "ok ";
  }
  catch(...)
  {
    cerr << "Nao deveria dar ERRO 12\n";
  }
  try
  {
    C0.setIdInPort(1,2,2);
    cout << "ok ";
  }
  catch(...)
  {
    cerr << "Nao deveria dar ERRO 13\n";
  }
  try
  {
    C0.setIdInPort(1,3,2);
    cerr << "ERRO 14 ";
  }
  catch(...)
  {
    cout << "ok ";
  }
  try
  {
    C0.setIdInPort(2,0,-2);
    cout << "ok ";
  }
  catch(...)
  {
    cerr << "Nao deveria dar ERRO 15\n";
  }
  try
  {
    C0.setIdInPort(2,-1,-2);
    cerr << "ERRO 16 ";
  }
  catch(...)
  {
    cout << "ok ";
  }
  try
  {
    C0.setIdInPort(3,0,-1);
    cerr << "ERRO 17 ";
  }
  catch(...)
  {
    cout << "ok ";
  }
  // Modifica as origens das saidas
  try
  {
    C0.setIdOutputCirc(-1,1);
    cerr << "ERRO 18 ";
  }
  catch(...)
  {
    cout << "ok ";
  }
  try
  {
    C0.setIdOutputCirc(0,1);
    cerr << "ERRO 19 ";
  }
  catch(...)
  {
    cout << "ok ";
  }
  try
  {
    C0.setIdOutputCirc(1,1);
    cout << "ok ";
  }
  catch(...)
  {
    cerr << "Nao deveria dar ERRO 20\n";
  }
  try
  {
    C0.setIdOutputCirc(1,0);
    cerr << "ERRO 21 ";
  }
  catch(...)
  {
    cout << "ok ";
  }
  try
  {
    C0.setIdOutputCirc(2,-2);
    cout << "ok ";
  }
  catch(...)
  {
    cerr << "Nao deveria dar ERRO 22\n";
  }
  try
  {
    C0.setIdOutputCirc(3,1);
    cerr << "ERRO 23 ";
  }
  catch(...)
  {
    cout << "ok ";
  }
  cout << endl;
  imprimir("C0",C0);     // OK - deve imprimir "C0 NIn=2 NOut=2 NPort=2: NO NT"

  // Testando o construtor por copia e clear
  cout << "4)==========\n";
  Circuito C1(C0);
  C0.clear();
  imprimir("C0",C0);     // OK - deve imprimir "C0 NIn=0 NOut=0 NPort=0:"
  imprimir("C1",C1);     // OK - deve imprimir "C1 NIn=2 NOut=2 NPort=2: NO NT"

  // Testando o construtor por movimento
  // Pode chamar esse construtor 2 vezes:
  // - Para retornar o valor de inicializa() para uma variavel sem nome
  // - Para criar C2 a partir da variavel sem nome
  cout << "5)==========\n";
  Circuito C2(inicializa());
  imprimir("C2",C2);     // OK - deve imprimir "C2 NIn=2 NOut=1 NPort=1: AN"
  // Alterando C2
  // Inicializa a porta Id==1 como NXOR de 2 entradas
  try
  {
    C2.setPort(1,"NX",2);
    cout << "ok ";
  }
  catch(...)
  {
    cerr << "Nao deveria dar ERRO 24\n";
  }
  // As duas entradas da porta Id==1 veem das entradas -1 e -2 do circuito
  try
  {
    C2.setIdInPort(1, 0, -1);
    cout << "ok ";
  }
  catch(...)
  {
    cerr << "Nao deveria dar ERRO 25\n";
  }
  try
  {
    C2.setIdInPort(1, 1, -2);
    cout << "ok ";
  }
  catch(...)
  {
    cerr << "Nao deveria dar ERRO 26\n";
  }
  cout << endl;
  imprimir("C2",C2);     // OK - deve imprimir "C2 NIn=2 NOut=1 NPort=1: NX"

  // Testando o operador de atribuicao por copia
  cout << "6)==========\n";
  C0 = C1 = C2;
  C1.clear();
  imprimir("C0",C0);     // OK - deve imprimir "C0 NIn=2 NOut=1 NPort=1: NX"
  imprimir("C1",C1);     // OK - deve imprimir "C1 NIn=0 NOut=0 NPort=0:"
  imprimir("C2",C2);     // OK - deve imprimir "C2 NIn=2 NOut=1 NPort=1: NX"

  // Testando o operador de atribuicao por movimento
  cout << "7)==========\n";
  C0 = Circuito();
  imprimir("C0",C0);     // OK - deve imprimir "C0 NIn=0 NOut=0 NPort=0:"
  C1 = inicializa();
  imprimir("C1",C1);     // OK - deve imprimir "C1 NIn=2 NOut=1 NPort=1: AN"

  return 0;
}

