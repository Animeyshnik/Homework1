#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>
#include <cstdlib>

#define BUFFER_SIZE 16

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Please provide source and destination files\n";
        return 1;
    }

    const char* source = argv[1];
    const char* destination = argv[2];

    int sourceFd = open(source, O_RDONLY);
    if (sourceFd == -1) {
        std::cerr << "Error opening source file: " << strerror(errno) << std::endl;
        return errno;
    }

    int destinationFd = open(destination, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP);
    if (destinationFd == -1) {
        std::cerr << "Error opening destination file: " << strerror(errno) << std::endl;
        close(sourceFd);
        return errno;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytesRead = 0;
    ssize_t totalBytes = 0;

    while (true) {
        bytesRead = read(sourceFd, buffer, BUFFER_SIZE);
        if (bytesRead == -1) {
            std::cerr << "Error reading source file: " << strerror(errno) << std::endl;
            close(sourceFd);
            close(destinationFd);
            return errno;
        }

        if (bytesRead == 0) {
            break;
        }

        ssize_t bytesWritten = write(destinationFd, buffer, bytesRead);
        if (bytesWritten == -1) {
            std::cerr << "Error writing to destination file: " << strerror(errno) << std::endl;
            close(sourceFd);
            close(destinationFd);
            return errno;
        }

        totalBytes += bytesRead;
    }

    close(sourceFd);
    close(destinationFd);

    std::cout << "File copied successfully. Total bytes copied: " << totalBytes << std::endl;
    return 0;
}
