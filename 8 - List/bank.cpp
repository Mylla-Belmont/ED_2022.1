#include <iostream>
#include <sstream>
#include <vector>
#include <list>

using namespace std;

struct Client {
    string name {""};
    int docs {0};
    int patience { 0 };
    Client(string name, int docs, int patience): name(name), docs(docs), patience(patience) { }
    string str() { return name + ":" + to_string(docs) + ":" + to_string(patience); }
};

struct Bank {
    vector<Client*> tellers;    //caixas
    list<Client*> queue_in;     //fila de entrada
    list<Client*> queue_out;    //fila de saida
    int docs_gain {0};          //documentos processados
    int docs_lost {0};          //documentos perdidos
    int tics {0};               //quantidade de tempo que passou

    //  Roda o algoritmo de passagem de tempo
    void tic() {
        tics++;
        empty_queue_out();
        for (int i = 0; i < (int) tellers.size(); i++)
            process_teller(i);
        decrease_patience();
    }

    Bank(int teller_size) { 
        tellers = vector<Client*>(teller_size, nullptr); 
    }

    ~Bank() { 
        for (auto client : tellers)
            delete client;
        for (auto client : queue_in)
            delete client;
        for (auto client : queue_out)
            delete client; 
    }

    void arrive(std::string name, int docs, int patience) { 
        queue_in.push_back(new Client(name, docs, patience)); 
    }

    //  esta vazio se não tem ninguém no banco
    bool empty() { ... }

    //  Retirar todos os clientes da fila de saída
    //
    //  para cada cliente da fila de saida, 
    //      this->docs_lost incrementa dos documentos não processado
    //      chame o delete para cada um deles
    void empty_queue_out() { ... }

    //  Processar caixa
    //
    //  se o caixa tem algum cliente
    //      se o cliente do caixa tiver algum documento para processar
    //          incrementa em um this->docs_gain
    //          decrementa em um os documentos do cliente
    //      senão
    //          move o cliente para fila de saída
    //  senão
    //      se tem alguem na fila de espera
    //          move o primeiro da fila de espera para o caixa
    void process_teller(int index) { ... }


    //  Processar fila de entrada
    //
    //  para cada cliente da fila de entrada
    //      se a paciencia dele for maior que zero
    //          decremente em um o valor da paciencia
    //      senão
    //          mova para fila de saida
    void decrease_patience() { ... }

    //continua chamando tic até todos os clientes terem ido embora
    void finish() { ... }

    //gera uma string com os dados dos banco
    std::string str() { ... }
};

int main() {
    Bank banco(3);

    while(true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << "\n";
        stringstream ss(line);
        ss >> cmd;
        if (cmd == "end") {
            break;
        }else if (cmd == "show") {
            std::cout << banco.str() << "\n";
        } else if (cmd == "in") {
            string name { };
            int docs { }, patience { };
            ss >> name >> docs >> patience;
            banco.arrive(name, docs, patience);
        } else if (cmd == "init") {
            int size { };
            ss >> size;
            banco = Bank(size);
        } else if (cmd == "tic") {
            banco.tic();
        } else if (cmd == "finish") {
            banco.finish();
        } else {
            cout << "fail: command not found\n";
        }
    }
}