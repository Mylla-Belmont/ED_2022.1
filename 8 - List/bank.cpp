#include <iostream>
#include <sstream>
#include <vector>
#include <list>

using namespace std;

struct Client {
    string nome {""};
    int documentos {0};
    int paciente { 0 };
    Client(string nome, int documentos, int paciente): nome(nome), documentos(documentos), paciente(paciente) { }
    string str() { return nome + ":" + to_string(documentos) + ":" + to_string(paciente); }
};

struct Bank {
    vector<Client*> tellers;    
    list<Client*> entrada;    
    list<Client*> saida;    
    int docs_gain {0};          
    int docs_lost {0};          
    int tics {0};               

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
        for (auto client : entrada)
            delete client;
        for (auto client : saida)
            delete client; 
    }

    void arrive(std::string nome, int documentos, int paciente) { 
        entrada.push_back(new Client(nome, documentos, paciente)); 
    }

    bool empty() { 
        for (auto * client : tellers)
            if (client != nullptr)
                return false;
        return entrada.empty() && saida.empty(); 
    }

    void empty_queue_out() { 
        for (auto * client : saida) {
            this->docs_lost += client->documentos;
            delete client;
        }
        saida.clear(); 
    }

    void process_teller(int index) { 
        auto& teller = tellers[index];
        if (teller != nullptr) {
            if (teller->documentos > 0) {
                teller->documentos -= 1;
                this->docs_gain += 1;
            } else {
                saida.push_back(teller);
                teller = nullptr;
            }
        } else {
            if (entrada.size() > 0) {
                teller = entrada.front(); 
                entrada.pop_front();
            }
        }
     }

    void decrease_patience() { 
        for (auto it = entrada.begin(); it != entrada.end(); ) {
            if ((*it)->paciente > 0) {
                (*it)->paciente -= 1;
                it++;
            } else {
                saida.push_back(*it);
                it = entrada.erase(it);
            }
        } 
    }

    void finish() { 
        while (!this->empty())
            tic();
    }

    std::string str() { 
        std::stringstream ss;
        for (auto client : tellers)
            ss << "[" << (client == nullptr ? "" : client->str()) << "]";
        ss << "\nin  :" << fmt(entrada, "{", "}", " ");
        ss << "\nout :" << fmt(saida,  "{", "}", " ");
        ss << "\ngain:" << docs_gain << " lost:" << docs_lost;
        return ss.str();
    }
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
            string nome { };
            int documentos { }, paciente { };
            ss >> nome >> documentos >> paciente;
            banco.arrive(nome, documentos, paciente);
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