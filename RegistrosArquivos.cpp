#include<iostream>
#include<fstream>
#include<iomanip>
#include<math.h>
using namespace std;

char sexo, homensFumam, mulheresFumam, pare;
int idade, totalHomem, totalMulher, homensNaoFumantes, mulheresNaoFumantes, homensFumantes,mulheresFumantes, numero, sair; 
float totalPessoas, porcFum, porcNaoFum, porcHomNaoFum, totalFumantes,homens40Fumantes, mulheres40Fumantes, porcMulFum;

int main () {
    
    ofstream arquivoEscrita;
    ofstream arquivoLimpar;
    ifstream arquivoLeitura;
    string linha;

    homensFumantes=0;
	homensNaoFumantes=0;
    mulheresFumantes=0;
	mulheresNaoFumantes=0;
    totalFumantes=0;
    totalPessoas=0;
    mulheres40Fumantes=0;
    homens40Fumantes=0;
    porcFum=0;
    porcNaoFum=0;
    porcHomNaoFum=0;
    porcMulFum=0; 

    while (sair != 6)
    {
        system("cls");
        cout << "\nMenu!!\n\n";

        cout << "1 - Incluir questionarios\n";
        cout << "2 - Reiniciar banco de dados\n";
        cout << "3 - % total de fumantes\n";
        cout << "4 - % de homens nao fumantes\n";
        cout << "5 - % de mulheres fumantes\n";
        cout << "6 - Sair\n";

        cout << "\nEscolha uma das opcoes acima.\n\n";
        cin >> numero;
        switch (numero)
        {
        case 1: //Questionario
        do{
            system("cls");    
            cout << "\nResponda o questionario!\n\n"; //Inicio questionario

            cout << "Sexo:\nDigite [M] para MASCULINO ou [F] para FEMININO.\n";
            cin >> sexo;
            if(sexo=='M'){
                cout << "Idade: ";
                cin >> idade;
                if (idade>=0){
                    totalPessoas++;
                }
               
                cout << "Fumante: \n[S] para SIM e [N] para NAO.\n";
                cin >> homensFumam;
                if(homensFumam=='S'){
                    homensFumantes++;
                }
                if(homensFumam=='N'){
                    homensNaoFumantes++;
                }
                if (idade<40 & homensFumam=='N'){
                    homens40Fumantes++;
                }                
            }else{
                cout << "Idade: ";
                cin >> idade;
                if (idade>=0){
                    totalPessoas++;
                }                
            
                cout << "Fumante: \n[S] para SIM e [N] para NAO.\n";
                cin >> mulheresFumam;
                if(mulheresFumam=='S'){
                    mulheresFumantes++;
                }
                if(mulheresFumam=='N'){
                    mulheresNaoFumantes++;
                }
                if (idade>40 & mulheresFumam=='S'){
                    mulheres40Fumantes++;
                }else{
                    cout << "\n";
                }
                
            }//Fim questionario
    
            totalFumantes = homensFumantes+mulheresFumantes;
            totalHomem = homensFumantes+homensNaoFumantes;
            totalMulher = mulheresFumantes+mulheresNaoFumantes;
            porcFum = totalFumantes/totalPessoas*100;
            porcHomNaoFum = homens40Fumantes/totalHomem*100;
            porcMulFum = mulheres40Fumantes/totalMulher*100;

            arquivoEscrita.open("Dados.bin");

            arquivoEscrita << "Homens fumantes: " << homensFumantes << endl;
            arquivoEscrita << "Homens nao fumantes: " << homensNaoFumantes << endl;
            arquivoEscrita << "Mulheres fumantes: " << mulheresFumantes << endl;
            arquivoEscrita << "Mulheres nao fumante: " << homensNaoFumantes+mulheresNaoFumantes << endl;
            arquivoEscrita << "Total de homens: " << homensFumantes+homensNaoFumantes << endl;
            arquivoEscrita << "Total de mulheres: " << mulheresNaoFumantes+mulheresFumantes << endl;
            arquivoEscrita << "Total de pessoas: " << totalPessoas << endl;
            arquivoEscrita << "Total de pessoas fumantes: " << homensFumantes+mulheresFumantes;
            arquivoEscrita.close();

            arquivoEscrita.open("DadosFumantes.bin");
            arquivoEscrita << setprecision(2) << fixed;
            arquivoEscrita << "Porcentagem de fumantes: " << porcFum << "%";
            arquivoEscrita.close();

            arquivoEscrita.open("DadosHomensNaoFumantes.bin");
            arquivoEscrita << setprecision(2) << fixed;
            arquivoEscrita << "Homens nao fumantes abaixo dos 40 anos: " << porcHomNaoFum << "%";
            arquivoEscrita.close();

            arquivoEscrita.open("DadosMulheresFumantes.bin");
            arquivoEscrita << setprecision(2) << fixed;
            arquivoEscrita << "Mulheres fumantes acima dos 40 anos: " << porcMulFum << "%";
            arquivoEscrita.close();

            cout << "\n\nAdicionado ao bando de dados!\n\n";
            cout << "\nDeseja adicionar outro questionario?\nDigite [S] para SIM e [N] para NAO.\n\n";
            cin >> pare;
        }while (pare!='N');
            break;

        case 2: //Limpar banco de dados
            system("cls");
            cout << "Banco de dados limpo.\n";
            
            arquivoLimpar.open("Dados.bin");
            arquivoLimpar << "";
            arquivoLimpar.close();
                        
            arquivoLimpar.open("DadosFumantes.bin");
            arquivoLimpar << "";
            arquivoLimpar.close();
                        
            arquivoLimpar.open("DadosHomensNaoFumantes.bin");
            arquivoLimpar << "";
            arquivoLimpar.close();
                        
            arquivoLimpar.open("DadosMulheresFumantes.bin");
            arquivoLimpar << "";
            arquivoLimpar.close();
           
            system("pause");
            break;
        case 3: //Porcentagem de fumantes
            system("cls");
                arquivoLeitura.open("DadosFumantes.bin");
                if(arquivoLeitura.is_open()){
                while (getline(arquivoLeitura, linha)){
                cout << linha << endl << endl;
                }
                arquivoLeitura.close();
            }else{
                cout << "Nao foi possivel abrir o arquivo" << endl;
            }
            system("pause");
            break;

        case 4: //Porcentagem de homens nao fumantes
            system("cls");
                arquivoLeitura.open("DadosHomensNaoFumantes.bin");
                if(arquivoLeitura.is_open()){
                while (getline(arquivoLeitura, linha)){
                cout << linha << endl << endl;
                }
                arquivoLeitura.close();
            }else{
                cout << "Nao foi possivel abrir o arquivo" << endl;
            }
            system("pause");
            break;

        case 5: //Porcentagem de mulheres fumantes
            system("cls");
                arquivoLeitura.open("DadosMulheresFumantes.bin");
                if(arquivoLeitura.is_open()){
                while (getline(arquivoLeitura, linha)){
                cout << linha << endl << endl;
                }
                arquivoLeitura.close();
            }else{
                cout << "Nao foi possivel abrir o arquivo" << endl;
            }
            system("pause");
            break;

        case 6: //Sair
            system("cls");
            sair = 6;
            cout << "\nSaindo...\n";
            break;

        default:
            cout << "Opcao invalida\n";
        }
        
    }

    system("pause");
    return 0;

}