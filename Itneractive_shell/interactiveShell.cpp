#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

void execute_command(const std::vector<std::string>& args, bool silent) {
    if (args.empty()) return;

    std::vector<char*> c_args;
    for (const auto& arg : args) {
        c_args.push_back(const_cast<char*>(arg.c_str()));
    }
    c_args.push_back(nullptr);

    pid_t pid = fork();

    if (pid == -1) {
        perror("Fork failed");
        return;
    }

    if (pid == 0) {
        if (silent) {
            std::string log_file = std::to_string(getpid()) + ".log";
            int fd = open(log_file.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fd == -1) {
                perror("Failed to open log file");
                exit(EXIT_FAILURE);
            }
            dup2(fd, STDOUT_FILENO);
            dup2(fd, STDERR_FILENO);
            close(fd);
        }

        char* path = getenv("PATH");
        std::string new_path = "./:" + std::string(path ? path : "");
        setenv("PATH", new_path.c_str(), 1);

        execvp(c_args[0], c_args.data());
        perror("Command execution failed");
        exit(EXIT_FAILURE);
    } else {
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            std::cout << "Command completed with exit code: " << WEXITSTATUS(status) << "\n";
        } else {
            std::cerr << "Command did not complete successfully.\n";
        }
    }
}

int main() {
    std::cout << "Welcome to the interactive shell. Type 'exit' to quit.\n";

    while (true) {
        std::cout << "> ";
        std::string input;
        if (!std::getline(std::cin, input) || input == "exit") {
            break;
        }

        std::istringstream iss(input);
        std::vector<std::string> args;
        std::string word;
        while (iss >> word) {
            args.push_back(word);
        }

        if (args.empty()) continue;

        bool silent = false;
        if (args[0] == "silent") {
            silent = true;
            args.erase(args.begin());
        }

        execute_command(args, silent);
    }

    std::cout << "Exiting interactive shell. Goodbye!\n";
    return 0;
}

