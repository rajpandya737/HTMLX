#include <iostream>
#include <fstream>
#include <deque>
#include <optional>
#include <stack>
#include <regex>


bool valid_python_tag(const std::deque<std::string>& lines) {
    // checks to make sure that there are valid python tags in the HTML file
    // Uses a stack and scans through the HTML file to make sure that the tags are valid
    // Rules for python tags, you cannot have python tags inside of each other
    // One must end before another is open
    // Every open tag must have a closing tag
    // If these rules are not followed, the function will return false    bool in_python_block = false;
    bool in_python_block = false;
    for (const std::string& line : lines) {
        std::cout << line << std::endl;

        if (line.find("<python>") != std::string::npos) {
            if (in_python_block) {
                return false;
            }
            in_python_block = true;
        }

        if (line.find("</python>") != std::string::npos) {
            if (!in_python_block) {
                return false;
            }
            in_python_block = false;
        }
    }

    if (in_python_block) {
        return false;
    }

    return true;
}



int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <HTML Filename>" << std::endl;
        return EXIT_FAILURE;
    }

    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cout << "File not found" << std::endl;
        return EXIT_FAILURE;
    }

    std::deque<std::string> lines;
    std::string line;
    while (getline(file, line)) {  
        lines.push_back(line);
    }


    bool valid = valid_python_tag(lines);
    if (valid) {
        std::cout << "Success" << std::endl;
    }
    else {
        std::cout << "Unclosed Python Tags" << std::endl;
    }
    

    return EXIT_SUCCESS;
}
