#include <iostream>
#include <fstream> //para ler o arquivo de texto. stream -> fluxo de dados de entrada e saída
#include <map>
#include <locale>
#include <string>
#include <cwctype> //para checar se o caractere é alfabético
#include <vector>
#include <algorithm>
using namespace std;

/*      Aqui tentaremos ordenar ponteiros para map de diferentes formas em um vector*/

int main(){

    wifstream arq; //tipo de arquivo conhecido como WIDE INPUT FILE
    
    auto pt = locale(""); //UTF8
    
    locale::global(pt); //define o padrão dos próximos objetos do tipo locale como UTF8
    
    arq.open("gpl.txt");
    
    arq.imbue(pt); //formata o arquivo de saída para UTF-8
    
    wofstream csv("palavras.csv"); // wide output file: comma separated values
    

    wchar_t ch; //desta vez, vamos ler caractere a caractere do arquivo
    wstring palavra;

    map<wstring, int> ocorrencias; //ajuste o map para wstring

    while(arq.get(ch)){ //lê um wchar_t por vez do arquivo
       if(iswalpha(ch)){ //É uma letra?
        palavra += tolower(ch); //concatenamos em uma wstring o caractere sempre em minusculo
       }
       else if(palavra.size() > 0){
//      cout << palavra << endl;
        ocorrencias[palavra]++; //a palavra é a chave. procura no map a palavra, incrementa o valor acessado pela chave. nos aproveitamos do bug de antes, que caso ele nao exista no map, ele insere com o valor default
        palavra.clear(); //precisamos limpar a palavra após usá-la
       }

    }
    
    
    cout << ocorrencias.size() << endl;

    vector<pair<const wstring, int>*> vetor; //Estrutura pair, faremos um vector de ponteiros para TUPLAS, que recebeão o endereço do map tendo um valor first e second
    //ou seja, percorreremos um mapa e o colocaremos em uma tupla

    for(auto& elementos : ocorrencias){
        vetor.push_back(&elementos);
    }
    
    wcout << vetor[0]->first << " " << vetor[0]->second << endl; //WIDE COUT



    // }
    // csv << "\"Palavra\";\"N\"\n"; //coloca os titulos das colunas do CSV
    // for(auto [k, v] : ocorrencias){
    //     csv << '"' << k << '"' << ';' << v << endl; //mandamos para o csv. a string precisa estar entre aspas
    // }

    // cout << pt.name() << endl; //FORMATADO

}