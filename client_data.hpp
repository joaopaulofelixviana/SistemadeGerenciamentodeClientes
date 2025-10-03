#include <iostream>
#include <string>

class ClientData{
    private:
        std::string cpf;
        std::string first_name;
        std::string last_name;
        std::string phone_number;
        std::string email;

    public:
        ClientData() = default;
        ClientData(const std::string& _cpf, const std::string& _first_name, const std::string& _last_name, const std::string& _phone_number, const std::string& _email) : cpf(_cpf), first_name(_first_name), last_name(_last_name), phone_number(_phone_number), email(_email) {}
        
        std::string getFullName() const{
            return first_name + " " + last_name;
        }
        
        const std::string& getCpf() const {return cpf;}
        const std::string& getFirstName() const {return first_name;}
        const std::string& getLastName() const {return last_name;}
        const std::string& getPhoneNumber() const {return phone_number;}

        friend std::ostream& operator<<(std::ostream& os, const ClientData& c){
            os << "[" << c.cpf << "] " << c.first_name << " " << c.last_name << " | " << c.phone_number << " | " << c.email;
            return os;
        }
};