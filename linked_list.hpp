#include <iostream>
#include <string>
#include <algorithm>
#include "client_data.hpp"

class Node{
    private:
        ClientData data;
        Node* next;

        Node(const ClientData& _data) : data(_data), next(nullptr) {}

        friend class ClientList;
};

class ClientList{
    private:
        Node* head;

    public:
        ClientList() : head(nullptr) {}

        // Function to insert a node at the end
        void insertAtEnd(const ClientData& data){
            Node* new_node = new Node(data);

            if(head == nullptr){
                head = new_node;  // If list is empty, make newNode the head
                return;
            }

            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;  // Traverse to the last node
            }
            temp->next = new_node; // Link the last node to newNode
        }

        void insertSorted(const ClientData& data){
            Node* new_node = new Node(data);
            
            // If list is empty or new node should be first
            if(!head || head->data.getFullName() > data.getFullName()){
                new_node->next = head;
                head = new_node;
                return;
            }

            Node* temp = head;
            while(temp->next && temp->next->data.getFullName() < data.getFullName()){
                temp = temp->next;
            }

            new_node->next = temp->next;
            temp->next = new_node;

        }

        // Function to delete a Node by cpf
        bool deleteByCpf(const std::string& cpf){
            if (!head) return false;

            if(head->data.getCpf() == cpf){
                Node* temp = head;
                head = head->next;
                delete temp;
                return true;
            }

            Node* temp = head;
            while(temp->next && temp->next->data.getCpf() != cpf){
                temp = temp->next;
            }

            if (temp->next){
                Node* node_to_delete = temp->next; 
                temp->next = temp->next->next; // Unlink the node
                delete node_to_delete; //Free Memory
                return true;
            }
            return false;
        }

        ClientData* findByCpf(const std::string& cpf){
            Node* temp = head;
            while(temp){
                if(temp->data.getCpf() == cpf){
                    return &(temp->data);
                }
                temp = temp->next;
            }
            return nullptr;
        }

        // Function to display the list
        void display() const {
            if(!head){
                std::cout << "Lista vazia!\n";
                return;
            }


            Node* temp = head;
            int count = 1;
            while(temp != nullptr){
                std::cout << count << ". " << temp->data << std::endl;
                temp = temp->next;
                count++;
            }
            // std::cout << "NULL" << std::endl;
        }

        bool isEmpty() const {
            return head == nullptr;
        }

        // Destructor to free all allocated memory
        ~ClientList(){
            Node* temp;
            while(head){
                temp = head;
                head = head->next;
                delete temp;
            }
        }
};