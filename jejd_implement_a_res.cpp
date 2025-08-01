#include <iostream>
#include <string>
#include <vector>

class CLIToolSimulator {
private:
    std::vector<std::string> commands;
    int screenWidth;

public:
    CLIToolSimulator(int screenWidth) : screenWidth(screenWidth) {}

    void addCommand(const std::string& command) {
        commands.push_back(command);
    }

    void display() {
        for (const auto& command : commands) {
            int screenWidthRemaining = screenWidth;
            for (const auto& c : command) {
                if (screenWidthRemaining > 0) {
                    std::cout << c;
                    screenWidthRemaining--;
                } else {
                    std::cout << "\n";
                    screenWidthRemaining = screenWidth - 1;
                    std::cout << c;
                    screenWidthRemaining--;
                }
            }
            std::cout << "\n";
        }
    }
};

int main() {
    CLIToolSimulator simulator(80);

    simulator.addCommand("help");
    simulator.addCommand("This is a very very very very very very very very very very very long command that will wrap to the next line");
    simulator.addCommand("quit");

    simulator.display();

    return 0;
}