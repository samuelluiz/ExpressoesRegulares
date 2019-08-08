#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <regex>
#include <string>

using namespace std;

// EXPRESSÕES REGULARES EM C++

int MostraMenu(){
    int aux;
    cout << " - Menu -" << endl;
    cout << " Digite o numero da opcao desejada: " << endl;
    cout << "0 - Validar Telefone" << endl;
    cout << "1 - Validar Email" << endl;
    cout << "2 - Validar URL" << endl;
    cout << "3 - Validar Identificador Simples" << endl;

    scanf("%d", &aux);

    return(aux);
}

auto validarTelefone = [](string &number) ->bool{
    regex reg("[9][1-9]{4}-[0-9]{4}");

    return regex_match(number, reg);
};

auto validarEmail = [](string &email) ->bool{
    regex reg("[a-z0-9_]+@[a-z]+[.][a-z]{2,4}", regex_constants::icase);

    return regex_match(email, reg);
};

auto validarURL = [](string &url) ->bool{
    regex reg("[w]{3}[.][a-z0-9]+[.][a-z]{2,4}", regex_constants::icase);

    return regex_match(url, reg);
};

auto validarIdentificador = [](string &identificador) ->bool{
    regex reg("[a-zA-Z_0-9%]+", regex_constants::icase);

    return regex_match(identificador, reg);
};


int main(int argc, char *argv[]){
    int auxMenu;
    string number, email, url, identificador;

    auxMenu = MostraMenu();

    switch (auxMenu)
    {
    case 0:
        do{
        system("cls");
        cout << "Digite um numero de telefone: " << endl;
        getline(cin, number);

    } while(!validarTelefone(number));

            cout << "O numero eh valido" << endl;
        break;

    case 1:
        do{
        system("cls");
        cout << "Digite um endereco de email: " << endl;
        getline(cin, email);

    } while(!validarEmail(email));

        cout << "O email eh valido" << endl;
        break;

    case 2:
        do{
        system("cls");
        cout << "Digite um endereco de URL: " << endl;
        getline(cin, url);

    } while(!validarURL(url));

        cout << "A URL eh valida" << endl;
        break;

    case 3:
        do{
        system("cls");
        cout << "Digite um identificador simples: " << endl;
        getline(cin, identificador);

    } while(!validarIdentificador(identificador));

        cout << "O Identificador eh valido" << endl;
        break;
    }

    return 0;
}
