#include <iostream>
#include <chrono>
#include <sys/wait.h>
#include <unistd.h>
#include <cstring>

void do_command(char** argv) {
    pid_t pid = fork();

    if (pid == -1) {
        std::cerr << "Failed to fork a new process.\n";
        return;
    }

    if (pid == 0) {
        execvp(argv[0], argv);
        std::cerr << "Error: Failed to execute command \"" << argv[0] << "\".\n";
        exit(1);
    } else {	:
	int status;
        waitpid(pid, &status, 0);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./doCommand <command> [arguments...]\n";
        return 1;
    }
    do_command(argv + 1);
    return 0;
}

