#include <iostream>
#include <cstdlib>
#include <string>
#include <limits> // Para usar std::numeric_limits

int main() {

    std::cout << "Password Generator.\n\n";

    // String dos caracteres para serem usados na senha
    const std::string Letters = "abcdefghijklmnopqrstuvwxyz";
    const std::string BigLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string Numbers = "0123456789";
    const std::string Symbols = "!@#$%&*";

    std::string Password = "";

    while (true) {

        // Cria o print das opções de entrada
        std::cout << "[1] - Exit \n";
        std::cout << "[2] - Letters + BigLetters \n";
        std::cout << "[3] - Letters + BigLetters + Numbers \n";
        std::cout << "[4] - Letters + BigLetters + Numbers + Symbols \n";

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
            Password = Letters + BigLetters;
            break;
        case 3:
            Password = Letters + BigLetters + Numbers;
            break;
        case 4:
            Password = Letters + BigLetters + Numbers + Symbols;
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