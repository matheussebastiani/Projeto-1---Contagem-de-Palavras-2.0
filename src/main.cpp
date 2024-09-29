#include "processInputs.hpp"
#include <iostream>
#include "processMap.hpp"
#include <map>

int main(int argc, char* argv[]){

    inp::processInputs entrada;

    std::cout << entrada.get_formato_saida() << std::endl;
    std::cout << entrada.get_modo_ordenacao() << std::endl;

    entrada.processa_argumentos(argc, argv);

    std::cout << entrada.get_formato_saida() << std::endl;
    std::cout << entrada.get_modo_ordenacao() << std::endl;

    std::cout << entrada.get_nome_arquivo() << std::endl;

    entrada.processa_entrada(entrada.get_nome_arquivo());
    std::cout << entrada.get_palavras_distintas() << std::endl;
    std::cout << entrada.get_total_palavras() << std::endl;
    std::cout << entrada.get_qtd_caracteres() << std::endl;

    std::map<std::wstring, int> map_ref = entrada.get_map();

    mid::processMap samuel;
      samuel.pushMap(map_ref);
      //samuel.sort_vector(samuel.get_ordered_vector(), entrada.get_modo_ordenacao());
      for(auto v : samuel.get_ordered_vector()){
        std::wcout << v->first << ", " << v->second << std::endl;
      }
    
    //for(auto [k,v] : entrada.get_map()){
    // std::wcout << "[" << k << ", " << v << "]" << std::endl; //ok, então consigo retornar um map através de uma função e FUNCIONA!
    
    // }

    

}