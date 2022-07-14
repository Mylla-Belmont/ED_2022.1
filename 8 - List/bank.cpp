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
    vector<Client*> tellers;    
    list<Client*> queue_in;    
    list<Client*> queue_out;    
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
        for (auto client : queue_in)
            delete client;
        for (auto client : queue_out)
            delete client; 
    }

    void arrive(std::string name, int docs, int patience) { 
        queue_in.push_back(new Client(name, docs, patience)); 
    }

    bool empty() { 
        for (auto * client : tellers)
            if (client != nullptr)
                return false;
        return queue_in.empty() && queue_out.empty(); 
    }

    void empty_queue_out() { 
        for (auto * client : queue_out) {
            this->docs_lost += client->docs;
            delete client;
        }
        queue_out.clear(); 
    }

    void process_teller(int index) { 
        auto& teller = tellers[index];
        if (teller != nullptr) {
            if (teller->docs > 0) {
                teller->docs -= 1;
                this->docs_gain += 1;
            } else {
                queue_out.push_back(teller);
                teller = nullptr;
            }
        } else {
            if (queue_in.size() > 0) {
                teller = queue_in.front(); 
                queue_in.pop_front();
            }
        }
     }

    void decrease_patience() { 
        for (auto it = queue_in.begin(); it != queue_in.end(); ) {
            if ((*it)->patience > 0) {
                (*it)->patience -= 1;
                it++;
            } else {
                queue_out.push_back(*it);
                it = queue_in.erase(it);
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
        ss << "\nin  :" << fmt(queue_in, "{", "}", " ");
        ss << "\nout :" << fmt(queue_out,  "{", "}", " ");
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