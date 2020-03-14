#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {

    std::ofstream headerOut;
    std::ofstream implOut;
    try {
        headerOut.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        implOut.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        headerOut.open("resources.h");
        implOut.open("resources.cpp");
        implOut << "#include \"resources.h\"\n";
        headerOut << 
        "#ifndef RESOURCES_H_INCLUDED\n"
        "#define RESOURCES_H_INCLUDED\n"
        "#include <rl_file.h>\n"
        ;

        for (int i = 1; i < argc; i++) {
            std::string name(argv[i]);
            for (int f = name.length()-1; f >= 0; f--) {
                if (name[f] == '/' || name[f] == '\\') {
                    name.erase(name.begin()+1, name.begin()+i+1);
                    break;
                } else if (name[f] < '0' || (name[f] > '9' && name[f] < 'A') || (name[f] > 'Z' && name[f] < 'a') || name[f] > 'z') {
                    name[f] = '_';
                }
            }
            if (name[0] >= '0' && name[0] <= '9') {
                name.insert(name.begin(), '_');
            }

            headerOut << "extern rl_file " << name << ";\n";
            implOut << "rl_file " << name << "=rl_file(";

            try {
                std::ifstream target;
                target.exceptions(std::ifstream::failbit | std::ifstream::badbit);
                target.open(argv[i]);

                target.seekg(0, target.end);
                const int length = (int)target.tellg();
                target.seekg(0, target.beg);

                implOut << length << ",new const char[" << length << "]{";

                for (int f = 0;;) {
                    implOut << target.get();
                    f++;
                    if (f >= length) {
                        break;
                    }
                    implOut << ",";
                }
                target.close();
            } catch (std::ifstream::failure &e) {
                std::cout << "ERROR: File read from \"" << argv[i] << "\" failed: " << e.what() << std::endl;
                return 1;
            }
            implOut << "});\n";
        }

        headerOut << "#endif\n";

        headerOut.close();
        implOut.close();
    } catch (std::ofstream::failure &e) {
        std::cout << "ERROR: File write failed: " << e.what() << std::endl;
        return 1;
    }
}

