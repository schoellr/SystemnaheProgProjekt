#include <iostream>
#include <sstream>
#include <dirent.h>

// Testeingabe: find Testordner -name pattern -type f -follow -xdev
int main(int argc, char *argv[]){
    std::string pattern, type;
    std::string dirname = argv[1];
    //std::string str;
    bool follow = false;
    bool xdev = false;
    //std::string input_split[8];
    //input = "find Testordner -name pattern -type f -follow";
    //input = argv;
    //std::stringstream ss(input);

    //int i = 0;
    //while (getline(ss, str, ' ')){
    //    input_split[i] = str;
    //    i =i + 1;
    //}
    for (int i = 2; i < argc; i++){
        if(strcmp(argv[i],"-name") == 0){
            pattern = argv[i+1];
        }
        if(strcmp(argv[i],"-type") == 0){
            type = argv[i+1];
        }
        if(strcmp(argv[i],"-follow") == 0){
            follow = true;
        }
        if(strcmp(argv[i], "-xdev") == 0){
            xdev = true;
        }
        std::cout << argv[i] << std::endl;
    }

    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }


    return 0;


}
