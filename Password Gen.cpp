#include <iostream>
#include <cstdlib>
#include <string>
#include <limits> // Para usar std::numeric_limits

int main() {

    std::cout << "Password Generator.\n\n";

    // String dos caracteres para serem usados na senha
    const std::string lowerCase = "abcdefghijklmnopqrstuvwxyz";
    const std::string upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string Numbers = "0123456789";
    const std::string Symbols = "!@#$%&*";

    std::string Password = "";

    while (true) {

        // Cria o print das opções de entrada
        std::cout << "[1] - Exit \n";
        std::cout << "[2] - lowerCase + upperCase \n";
        std::cout << "[3] - lowerCase + upperCase + Numbers \n";
        std::cout << "[4] - lowerCase + upperCase + Numbers + Symbols \n";

        int Options;
        std::cout << "\n";
        std::cout << "Select An Option: ";
        std::cin >> Options;
        std::cout << "\n";

        if (Options == 1) {
            std::cout << "You have selected option 1, bye! \n";
            break;
        }

        // Loop pra criar a senha com base nas opções selecionadas
        switch (Options) {
        case 2:
            Password = lowerCase + upperCase;
            break;
        case 3:
            Password = lowerCase + upperCase + Numbers;
            break;
        case 4:
            Password = lowerCase + upperCase + Numbers + Symbols;
            break;
        default:
            std::cout << "Invalid Option. \n";
            continue; // Continue para voltar ao início do loop
        }

        int Length;
        std::cout << "Length Of Password: ";
        std::cin >> Length;

        if (Length <= 0) {
            std::cout << "Invalid password length. \n";
            continue; // Continue para voltar ao início do loop
        }

        std::cout << "\n";

        std::string GeneratedPassword = "";
        for (int i = 0; i < Length; ++i) {
            GeneratedPassword += Password[rand() % Password.length()];
        }

        // Limpa o buffer do cin
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Exibe a senha gerada e da clean no cmd antigo
        system("cls");
        std::cout << "Generated Password: " << GeneratedPassword << '\n';
        std::cout << "\n";
    }

    return 0;
}
