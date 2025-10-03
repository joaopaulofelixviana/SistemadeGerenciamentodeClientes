#include <iostream>
#include <string>
#include "linked_list.hpp"

class ClientManager{
    private:
        ClientList clients;

        void clearScreen() const {
            #ifdef _WIN32
                system("cls");
            #else 
                system("clear");
            #endif
        }

        void pauseScreen() const{
            std::cout << "\nPressione Enter para continuar...";
            std::cin.ignore();
            std::cin.get();
        }

        ClientData inputClientData() const{
            std::string cpf, first_name, last_name, phone, email;

            std::cout << "CPF: ";
            std::getline(std::cin, cpf);

            std::cout << "Nome: ";
            std::getline(std::cin, first_name);

            std::cout << "Sobrenome: ";
            std::getline(std::cin, last_name);

            std::cout << "Telefone: ";
            std::getline(std::cin, phone);

            std::cout << "Email: ";
            std::getline(std::cin, email);

            return ClientData(cpf, first_name, last_name, phone, email);
        }
    public:
        void addClient() {
            clearScreen();
            std::cout << "=== ADICIONAR CLIENTE ===\n\n";

            ClientData new_client = inputClientData();

            if(clients.findByCpf(new_client.getCpf())){
                std::cout << "\nErro: Cliente com CPF " << new_client.getCpf() << " já existe!\n";
            } else {
                clients.insertSorted(new_client);
                std::cout << "\nCliente adicionado com sucesso!\n";
            }

            pauseScreen();
        }


        void removeClient() {
            clearScreen();
            std::cout << "=== REMOVER CLIENTE ===\n\n";

            if(clients.isEmpty()){
                std::cout << "Nenhum cliente cadastrado!\n";
                pauseScreen();
                return;
            }

            std::string cpf;
            std::cout << "CPF do cliente a ser removido: ";
            std::getline(std::cin, cpf);

            if(clients.deleteByCpf(cpf)){
                std::cout << "\nCliente removido com sucesso!\n";
            } else {
                std::cout << "\nCliente com CPF " << cpf << " não encontrado!\n";
            }

            pauseScreen();
        }


        void searchClient(){
            clearScreen();
            std::cout << "=== BUSCAR CLIENTE ===\n\n";

            std::string cpf;
            std::cout << "CPF do cliente: ";
            std::getline(std::cin, cpf);

            ClientData* client = clients.findByCpf(cpf);
            if(client){
                std::cout << "\nCliente encontrado:\n";
                std::cout << *client << std::endl;
            } else {
                std::cout << "\nCliente com CPF " << cpf << " não encontrado!\n";
            }

            pauseScreen();
        }

        void listAllClients() {
            clearScreen();
            std::cout << "=== LISTA DE CLIENTES ===\n\n";
            clients.display();
            pauseScreen();
        }

        void showMenu(){
            int choice;

            do{
                clearScreen();
                std::cout << "=== SISTEMA DE GERENCIAMENTO DE CLIENTES ===\n\n";
                std::cout << "1. Adicionar Cliente\n";
                std::cout << "2. Remover Cliente\n";
                std::cout << "3. Buscar Cliente\n";
                std::cout << "4. Listar Todos os Clientes\n";
                std::cout << "5. Sair\n";
                std::cout << "\nEscolha uma opção: ";

                std::cin >> choice;
                std::cin.ignore(); // Clear the input buffer

                switch(choice) {
                    case 1:
                        addClient();
                        break;
                    case 2:
                        removeClient();
                        break;
                    case 3:
                        searchClient();
                        break;
                    case 4:
                        listAllClients();
                        break;
                    case 5:
                        std::cout << "Encerrando o programa...\n";
                        break;
                    default:
                        std::cout << "Opção inválida! Tente novamente.\n";
                        pauseScreen();
                }
            } while(choice != 5);
        }

        // Method to add sample data for testing
        void loadSampleData() {
            ClientData c1("12345678900", "Alice", "Silva", "9999-0001", "alice@example.com");
            ClientData c2("98765432100", "Bruno", "Costa", "9999-0002", "bruno@example.com");
            ClientData c3("55566677788", "Carla", "Souza", "9999-0003", "carla@example.com");
            ClientData c4("11122233344", "Daniel", "Oliveira", "9999-0004", "daniel@example.com");

            clients.insertSorted(c1);
            clients.insertSorted(c2);
            clients.insertSorted(c3);
            clients.insertSorted(c4);
        }
};





int main(){
    ClientManager manager;

    manager.loadSampleData();

    manager.showMenu();
    return 0;
}