#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <cstring>

int copyFile(const char* sourcePath, const char* destPath) {
    int sourceFD = open(sourcePath, O_RDONLY);
    if (sourceFD == -1) {
        perror("Error opening source file");
        return 1;
    }

    int destFD = open(destPath, O_WRONLY | O_CREAT | O_TRUNC);
    if (destFD == -1) {
        perror("Error opening destination file");
        close(sourceFD);
        return 2;
    }

    size_t BUFFER_SIZE = 4096;
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;
    off_t totalBytes = 0, totalData = 0, totalHoles = 0;

    while ((bytesRead = read(sourceFD, buffer, BUFFER_SIZE)) > 0) {
        for (ssize_t i = 0; i < bytesRead; i++) {
            if (buffer[i] == '\0') {
                totalHoles++;
            } else {
                totalData++;
            }
        }

        if (write(destFD, buffer, bytesRead) == -1) {
            perror("Error writing to destination file");
            close(sourceFD);
            close(destFD);
            return 3;
        }

        totalBytes += bytesRead;
    }

    if (bytesRead == -1) {
        perror("Error reading source file");
        close(sourceFD);
        close(destFD);
        return 4;
    }

    close(sourceFD);
    close(destFD);

    std::cout << "Successfully copied " << totalBytes
              << " bytes (data: " << totalData
              << ", hole: " << totalHoles << ")." << std::endl;

    return 0;
}

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <source-file> <destination-file>" << std::endl;
        return 1;
    }

    return copyFile(argv[1], argv[2]);
}

