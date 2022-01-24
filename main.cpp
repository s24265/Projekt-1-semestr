#include <iostream>

/*Projekt, Symulator konta bankowego*/

bool anypin(std::string pin){
    bool pass = true;

    if (pin.length() != 4){
        pass = false;
    }
    return pass;
}

void banking(){
    long long action, n, m = 0;

    do {    //główne menu
        std::cout << std::endl;
        std::cout << "==================" << "\n";
        std::cout << "| [1] wpłata     |" << "\n";
        std::cout << "| [2] wypłata    |" << "\n";
        std::cout << "| [3] stan konta |" << "\n";
        std::cout << "| [4] zakończ    |" << "\n";
        std::cout << "==================" << "\n";
        std::cin >> action;

        if (action == 1){   //wpłaty
            std::cout << "-------------" << "\n";
            std::cout << "Kwota wpłaty: ";
            std::cin >> n;

            if (n > 0){
                m = m + n;
            }
            else if (n == 0){
                std::cout << "-------------------" << "\n";
                std::cout << "To by nic nie dało." << "\n";
            }
            else {
                std::cout << "-------------------" << "\n";
                std::cout << "Nieprawidłowa kwota" << "\n";
                std::cout << "spróbuj ponownie..." << "\n";
            }
        }
        if (action == 2){   //wypłaty
            std::cout << "--------------" << "\n";
            std::cout << "Kwota wypłaty: ";
            std::cin >> n;

            if (n > 0){
                std::cout << "-----------------------------" << "\n";
                std::cout << "Brak wystarczających środków." << "\n";
            }
            else if (m < n){
                m = m - n;
            }
            else if (n == 0){
                std::cout << "-------------------" << "\n";
                std::cout << "To by nic nie dało." << "\n";
            }
            else {
                std::cout << "------------------------" << "\n";
                std::cerr << "Błąd nie możesz wypłacić" << "\n";
                std::cerr << "ujemnej kwoty." << "\n";
            }
        }
        if (action == 3){   //stan konta
            if (m > 0){
                std::cout << "------------------" << "\n";
                std::cout << "Stan konta wynosi: " << m << " zł" << "\n";
            }
            else if (m == 0){
                std::cout << "-----------------------" << "\n";
                std::cout << "Brak środków na koncie." << "\n";
            }
            else {
                std::cout << "--------------" << "\n";
                std::cerr << "Wystąpił błąd." << "\n";
            }
        }
        if (action == 4){   //wyjście
            std::cout << "------------" << "\n";
            std::cout << "Do widzenia!" << "\n";
            std::cout << "------------" << "\n";
        }
    }
    while (action != 4);
    return;
}

int main(){
    std::string pin;

    std::cout << "-----------------" << "\n";
    std::cout << "Proszę podać pin: ";
    std::cin >> pin;

    if (anypin(pin) == true){
        std::cout << "-----------------" << "\n";
        std::cout << "Pin prawidłowy" << "\n";
        std::cout << "Logowanie..." << "\n";
        banking();
    }
    else {  //wariant gdy poda się niepoprawny pin
        std::cout << "-----------------------------------" << "\n";
        std::cerr << "Niepoprawny pin..." << "\n";
        std::cout << "pin powinnien składać się z 4 cyfer" << "\n";
        std::cout << "spróbuj ponownie: ";
        std::cin >> pin;
        if (anypin(pin) == true){
            banking();
        }
        else {
            std::cout << "-----------------------------------" << "\n";
            std::cerr << "Niepoprawny pin..." << "\n";
            std::cout << "pin powinnien składać się z 4 cyfer" << "\n";
            std::cout << "spróbuj ponownie: ";
            std::cin >> pin;
            if (anypin(pin) == true){
                banking();
            }
            else {
                std::cout << "--------------------" << "\n";
                std::cerr << "Zbyt wiele niudanych" << "\n";
                std::cerr << "prób logowania" << "\n";
                std::cout << "Zamykanie..." << "\n";
                return 0;
            }
        }
    }
    return 0;
}
