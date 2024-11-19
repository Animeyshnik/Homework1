#include <iostream>
#include <fstream>
#include <string>
#include <fcntl.h>
#include <unistd.h>

bool initialize(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input-file>" << std::endl;
        return false;
    }

    const char* inputFile = argv[1];
    int fd = open(inputFile, O_RDONLY);

    if (fd == -1) {
        perror("Error opening file");
        return false;
    }

    if (dup2(fd, STDIN_FILENO) == -1) {
        perror("Error redirecting stdin");
        close(fd);
        return false;
    }

    close(fd);
    return true;
}

int main(int argc, char** argv) {
    if (!initialize(argc, argv)) {
        return 1;
    }

    std::string input;
    std::cin >> input;

    std::string reversed(input.rbegin(), input.rend());

    std::cout << reversed << std::endl;

    return 0;
}

