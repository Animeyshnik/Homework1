#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>
#include <cstdlib>
#include <sys/stat.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: Please provide a file path to delete.\n";
        return 1;
    }

    const char* filepath = argv[1];

    struct stat fileInfo;
    if (stat(filepath, &fileInfo) == -1) {
        std::cerr << "Error: Could not access file " << filepath << ". " << strerror(errno) << std::endl;
        return errno;
    }

    int fileFd = open(filepath, O_WRONLY);
    if (fileFd == -1) {
        std::cerr << "Error: Could not open file " << filepath << " for writing. " << strerror(errno) << std::endl;
        return errno;
    }

    off_t fileSize = fileInfo.st_size;
    char nullChar = '\0';

    for (off_t i = 0; i < fileSize; ++i) {
        if (write(fileFd, &nullChar, 1) != 1) {
            std::cerr << "Error: Could not write to file. " << strerror(errno) << std::endl;
            close(fileFd);
            return errno;
        }
    }

    close(fileFd);

    if (unlink(filepath) == -1) {
        std::cerr << "Error: Could not delete file " << filepath << ". " << strerror(errno) << std::endl;
        return errno;
    }

    std::cout << "File " << filepath << " has been securely deleted.\n";
    return 0;
}
