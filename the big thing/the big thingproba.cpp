#include <iostream>
#include <string>

//DEKLARACJE
void quit();
void new_emp();
void del_emp();
void main_menu();


//EMPLOYEE CLASS
//--------------------------------------------------------
class Employee {
private:
    std::string id;
public:
    Employee* next;

    Employee();
    Employee(std::string _new);
    ~Employee();
    void set_id(std::string _new);
    std::string get_id();
};

Employee::~Employee() {
    std::cout << "EMPLOYEES DESTRUCTOR " << std::endl;
    std::cout << this->get_id() << std::endl;
}

void Employee::set_id(std::string _id) {
    this->id = _id;
}

std::string Employee::get_id() {
    return this->id;
}

Employee::Employee() {
    this->set_id(0);
    this->next = NULL;
}

Employee::Employee(std::string _new) {
    this->id = _new;
    this->next = NULL;
}

//LIST CLASS
//--------------------------------------------------------
class List {
public:
    Employee* first;
    Employee* current;

    List();
    ~List();
    void wypisz();
    void add_on_top(Employee* nowy);
    void add_on_top(std::string _new_id);
};

List::List(){
    this->first = NULL;
    this->current = NULL;
}

List::~List() {
    if (this->first != NULL) {
        current = first;
        while (current->next != NULL) {
            current = current->next;
            delete first;
            first = current;
        }
        delete first;
    }
}

void List::add_on_top(std::string _new_id) {
    Employee* E1 = new Employee(_new_id);
    this->add_on_top(E1);
}

void List::add_on_top(Employee* nowy) {
    if (this->first == NULL) {
        this->first = nowy;
        this->current = nowy;
    }
    else {
        nowy->next = this->first;
        this->first = nowy;
        this->current = nowy;
    }
}

void List::wypisz() {
    int i = 1;

    if (this->first == NULL) {
        std::cout << "Lista pracownikow jest pusta! " << std::endl;
        std::cout << "Zatrudnij kogos :D " << std::endl;
    }
    else {
        current = first;
        std::cout << "ID: E" << i << " " << current->get_id() << std::endl;
        while (current->next != NULL) {
            i++;
            current = current->next;
            std::cout << "ID: E" << i << " " << current->get_id() << std::endl;
        }
        std::cout << "---------------------------" << std::endl;
    }
}

//MENU
//--------------------------------------------------------

enum program_status {
    PS_main_menu,
    PS_list,
    PS_edit_list
};

int program_status = PS_main_menu;
bool end_program = false;
void main_menu() {
    int menu_choice = 0;

    std::cout << "Lista pracownikow" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "[1] Wyswietl liste pracownikow " << std::endl;
    std::cout << "[2] Edytuj liste pracownikow " << std::endl;
    std::cout << "[3] Wyjscie " << std::endl;
    std::cin >> menu_choice;

    switch (menu_choice) {
    case 3: {
        end_program = true;
        break;
    }
    case 1: {
        std::system("CLS");
        program_status = PS_list;
        break;
    }
    case 2: {
        std::system("CLS");
        program_status = PS_edit_list;
        break;
    }
    default: {
        std::cout << "Niepoprawny wybor! " << std::endl;
        break;
    }
    }
}

void edit_list() {
    char edit_choice;

    std::cout << "Aby dodać nowego pracownika, wcisnij N" << std::endl;
    std::cout << "Aby usunac jednego z pracownikow wcisnij D" << std::endl;
    std::cin >> edit_choice;

    switch (edit_choice) {
    case 'n': {
        std::system("CLS");
        new_emp();
        break;
    }
    case 'd': {
        std::system("CLS");
        del_emp();
        break;
    }
    default: {
        std::system("CLS");
        std::cout << std::endl;
        std::cout << "Niepoprawny klawisz! " << std::endl;
        std::cout << std::endl;
        break;
    }
    }
    quit();
}

void quit() {
    char quit;

    std::cin >> quit;

    switch(quit) {
    case 'q': {
        std::system("CLS");
        program_status = PS_main_menu;
        break;
    }
    case 'l': {
        std::system("CLS");
        program_status = PS_list;
        break;
    }
    default: {
        std::system("CLS");
        std::cout << std::endl;
        std::cout << "Niepoprawny klawisz! " << std::endl;
        std::cout << std::endl;
        break;
    }
    }
}

//NEW EMPLOYEE
//--------------------------------------------------------

void new_emp() {
    std::cout << "placeholder" << std::endl;
}

void del_emp() {
    std::cout << "placeholder" << std::endl;
}

//MAIN
//--------------------------------------------------------
//List l;

int main()
{   
    List l;
    Employee E1("adam"), E2("pawel");
    E1.set_id("maciek");
    l.add_on_top(&E1);
    l.add_on_top(&E2);

    do {
        switch (program_status) {
        case PS_main_menu: {
            main_menu();
            break;
        }
        case PS_list: {
            //std::cout << "" << std::endl;
            
            l.wypisz();

            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "Aby wrocic do Menu Glownego wcisnij Q " << std::endl;
            quit();
            break;
        }
        case PS_edit_list: {

            edit_list();
            
            break;
        }
        }
        
    } while (!end_program);


}