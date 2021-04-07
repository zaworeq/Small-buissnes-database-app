#include <iostream>
#include <string>
#include <fstream>

//DEKLARACJE
void quit();
std::string new_emp();
void del_emp();
void main_menu();
//std::fstream Lista_Pracownikow;
int iter();
void read_file();
int ilosc_w();
int ilosc_k();
int ilosc_s();

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
    //std::cout << "EMPLOYEES DESTRUCTOR " << std::endl;
    //std::cout << this->get_id() << std::endl;
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
    std::fstream Lista_Pracownikow;


    Lista_Pracownikow.open("Lista_Pracownikow.txt", std::ios::app);
    if (Lista_Pracownikow.is_open()) {

        int j = iter();

        if (this->first == NULL) {
            std::cout << "Lista pracownikow: " << std::endl;
            
        }
        else {
            current = first;
            //std::cout << "ID: E" << j << " " << current->get_id() << std::endl;
            Lista_Pracownikow << "ID: E" << j << " " << current->get_id() << std::endl;
            while (current->next != NULL) {
                j++;
                current = current->next;
                //std::cout << "ID: E" << j << " " << current->get_id() << std::endl;
                Lista_Pracownikow << "ID: E" << j << " " << current->get_id() << std::endl;
            }
            std::cout << "--------------------------------------------------------" << std::endl;
        }
        Lista_Pracownikow.close();
    }
    else
    {
        std::cout << "Blad pliku" << std::endl;
    }
}

//FILE STUFF
//--------------------------------------------------------
int iter() {
    std::fstream licznik;
    int i = 1;
    licznik.open("Lista_Pracownikow.txt", std::ios::in);
    std::string wiersz;
    if (licznik.is_open()) {
        while (std::getline(licznik, wiersz)) {
            i++;
        }
        licznik.close();
    }
    else {
        std::cout << "Blad pliku " << std::endl;
    }
    return i;
}

void read_file() {
    std::fstream reader;
    reader.open("Lista_Pracownikow.txt", std::ios::in);
    std::string wiersz;
    if (reader.is_open()) {
        while (std::getline(reader, wiersz)) {
            std::cout << wiersz << std::endl;
        }
        reader.close();
    }
    else {
        std::cout << "Blad pliku " << std::endl;
    }
}

//MENU
//--------------------------------------------------------

enum program_status {
    PS_main_menu,
    PS_list,
    PS_new_emp,
    PS_del_emp,
    PS_summary
};

int program_status = PS_main_menu;
bool end_program = false;
void main_menu() {
    int menu_choice = 0;

    std::cout << "Lista pracownikow przedsiebiorstwa" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "[1] Wyswietl liste pracownikow " << std::endl;
    std::cout << "[2] Dodaj nowego pracownika " << std::endl;
    std::cout << "[3] Usun pracownika " << std::endl;
    std::cout << "[4] Podsumowanie Wydatkow " << std::endl;
    std::cout << "[5] Wyjscie " << std::endl;
    std::cin >> menu_choice;

    switch (menu_choice) {
    case 5: {
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
        program_status = PS_new_emp;
        break;
    }
    case 3: {
        std::system("CLS");
        program_status = PS_del_emp;
        break;
    }
    case 4: {
        std::system("CLS");
        program_status = PS_summary;
        break;
    }
    default: {
        std::cout << "Niepoprawny wybor! " << std::endl;
        break;
    }
    }
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

//LIST EDIT
//--------------------------------------------------------

std::string new_emp() {
    std::string emp;
    std::cout << "Podaj dane nowego pracownika w formacie: " << std::endl;
    std::cout << "Stanowisko-Imie-Nazwisko-Wynagrodzenie " << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Wynagrodzenia wynosza: " << std::endl;
    std::cout << "Wlasciciel- 15000; Kierownik- 8000; Sprzedawca- 4000" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Imiona, nazwiska oraz stanowiska prosze zaczynac z DUZEJ litery " << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    
    std::cin >> emp;
    return emp;

}

void del_emp() {
    std::cout << "Pracujemy nad tym, zajrzyj pozniej ;D " << std::endl;
}

//OTHER
//--------------------------------------------------------

int ilosc_w(int w){
    std::fstream reader;
    
    reader.open("Lista_Pracownikow.txt", std::ios::in);
    std::string wiersz;

    char a;
    if (reader.is_open()) {
        while (std::getline(reader, wiersz)) {
            a = wiersz.find('W');
            if (a == 'W') {
                w++;
            }
            else {
                
            }
        }
    }
    else {
        std::cout << "Blad pliku " << std::endl;
    }
    reader.close();
    return w;
}

int ilosc_k(int k){
        std::fstream reader;

        reader.open("Lista_Pracownikow.txt", std::ios::in);
        std::string wiersz;

        char a;
        if (reader.is_open()) {
            while (std::getline(reader, wiersz)) {
                a = wiersz.find('K');
                if (a == 'K') {
                    k++;
                }
                else {
                    
                }
            }
        }
        else {
            std::cout << "Blad pliku " << std::endl;
        }
        reader.close();
        return k;
}

int ilosc_s(int s){
        std::fstream reader;

        reader.open("Lista_Pracownikow.txt", std::ios::in);
        std::string wiersz;

        char a;
        if (reader.is_open()) {
            while (std::getline(reader, wiersz)) {
                a = wiersz.find('S');
                if (a == 'S') {
                    s++;
                }
                else {
                    
                }
            }
        }
    else {
        std::cout << "Blad pliku " << std::endl;
    }
    reader.close();
    return s;
}

//MAIN
//--------------------------------------------------------

int main()
{   
    List l;


    do {
        switch (program_status) {
        case PS_main_menu: {
            main_menu();
            break;
        }
        case PS_list: {
            //std::cout << "" << std::endl;
            
            l.wypisz();
            read_file();

            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "Aby wrocic do Menu Glownego wcisnij q " << std::endl;
            quit();
            break;
        }
        case PS_new_emp: {
            char odp;

            l.add_on_top(new_emp());
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "Swietnie, czy chcesz wprowadzic nastepnego? (y/n)" << std::endl;
            std::cin >> odp;
            switch (odp) {
            case 'y': {
                std::system("CLS");
                program_status = PS_new_emp;
                break;
            }
            case 'n': {
                std::system("CLS");
                std::cout << "Aby wrocic do Menu Glownego wcisnij q " << std::endl;
                quit();
                break;
            }
            default: {
                std::system("CLS");
                std::cout << std::endl;
                std::cout << "Niepoprawny klawisz! " << std::endl;
                std::cout << "Wprowadz ponownie " << std::endl;
                std::cout << std::endl;
                break;
            }
            }
            
            break;
        }
        case PS_del_emp: {
            del_emp();

            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "Aby wrocic do Menu Glownego wcisnij q " << std::endl;
            quit();
            break;
        }
        case PS_summary: {
            int w = 0, k = 0, s = 0;

            std::cout << "Suma wydatkow na pracownikow wynosi: " << (ilosc_w(w) * 15000) + (ilosc_k(k) * 8000) + (ilosc_s(s) * 4000) << std::endl;
            std::cout << "Wlasciciel zarabia: " << ilosc_w(w) * 15000 << std::endl;
            std::cout << "Kierownictwo zarabia w sumie: " << ilosc_k(k) * 8000 << std::endl;
            std::cout << "Sprzedawcy zarabiaja w sumie: " << ilosc_s(s) * 4000 << std::endl;

            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "Aby wrocic do Menu Glownego wcisnij q " << std::endl;
            quit();
            break;
        }
        }
        
    } while (!end_program);


}