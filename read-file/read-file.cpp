#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#define BUFFER_SIZE 16

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: File path is required as an argument.\n";
        exit(1);
    }

    const char* filename = argv[1];
    int file = open(filename, O_RDONLY);

    if (file == -1) {
        std::cerr << "Error: Failed to open the file. " << strerror(errno) << std::endl;
        exit(errno);
    }

    char buffer[BUFFER_SIZE + 1];
    ssize_t bytesRead = 0;
    long totalBytes = 0;

    while (true) {
        bytesRead = read(file, buffer, BUFFER_SIZE);

        if (bytesRead == -1) {
            std::cerr << "Error: Failed to read the file. " << strerror(errno) << std::endl;
            close(file);
            exit(errno);
        }

        if (bytesRead == 0) {
            break;
        }

        totalBytes += bytesRead;
        buffer[bytesRead] = '\0';
        printf("%s", buffer);
    }

   int closeStatus =  close(file);

	if(closeStatus == -1){
		std::cerr << "Error: Failed to close the file. " << strerror(errno) << std::endl;
		exit(errno);
	}

    std::cout << "\nCompleted reading file. Total bytes read: " << totalBytes << std::endl;

    return 0;
}
