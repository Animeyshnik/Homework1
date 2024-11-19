#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <file-path>" << std::endl;
        return 1;
    }

    const char* filePath = argv[1];

    int fd1 = open(filePath, O_WRONLY | O_CREAT);
    if (fd1 == -1) {
        perror("Error opening file");
        return 2;
    }

    int fd2 = dup(fd1);
    if (fd2 == -1) {
        perror("Error duplicating file descriptor");
        close(fd1);
        return 3;
    }

    const char* line1 = "first line\n";
    const char* line2 = "second line\n";

    if (write(fd1, line1, strlen(line1)) == -1) {
        perror("Error writing first line");
        close(fd1);
        close(fd2);
        return 4;
    }

    if (write(fd2, line2, strlen(line2)) == -1) {
        perror("Error writing second line");
        close(fd1);
        close(fd2);
        return 5;
    }

    close(fd1);
    close(fd2);
    return 0;
}

