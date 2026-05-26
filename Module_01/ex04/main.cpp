#include <iostream>
#include <fstream>
#include <string>

static void stt_copyfile(std::ifstream &file,
        std::ofstream &replace_file,
        const std::string& to_find,
        const std::string& to_replace)
{
    size_t      pos;
    std::string line;

    if (to_find.empty())
        return ;

    while (std::getline(file, line))
    {
        pos = 0;
        while ((pos = line.find(to_find, pos)) != std::string::npos)
        {
            line = (line.substr(0, pos)) +
                (to_replace) +
                (line.substr(pos + to_find.length()));
            pos += to_replace.length();
        }
        replace_file << line << "\n";
    }
}

int main(int argc, char **argv)
{
    if (argc != 4){
        std::cerr << "Error: The program takes three parameters.\n";
        return (1);
    }

    std::ifstream file(argv[1]);
    if (!file.is_open()){
        std::cerr << "Error: Could not open the file.\n";
        return (1);
    }

    std::ofstream   replace_file;
    std::string     file_name = argv[1];
    std::string     new_file = file_name + ".replace";

    replace_file.open(new_file.c_str(), std::ios::out);
    if (!replace_file.is_open()){
        std::cerr << "Error: Could not create replace file.\n";

        file.close();
        return (1);
    }

    stt_copyfile(file, replace_file, argv[2], argv[3]);

    file.close();
    replace_file.close();
    return (0);
}
