#include "digital_convertor.hpp"

std::string file_name;
std::ifstream file_input;
short mode = 2, visibility = 10;
bool is_save = false;

int main(int argc, char const *argv[]){

    if(argc < 2){
        printf("[ERROR]: Use -h or --help to get info about this program!\n");

        return 0;
    } else {
        for(int i = 0; i < argc; i++){
            if(std::string(argv[i]) == "-h" || std::string(argv[i]) == "--help"){
                printf("Useful info for a program:\n");
                printf("\t -h | --help\t\t\t-\tUseful info for a program\n");
                printf("\t -f | --file\t\t\t-\tInput file which will be convert to hex, bin, oct, dec, little endian or big endian\n");
                printf("\t-sh | --show-line\t\t-\tShow line from input file. Enter mode convertion 0 - bin, 1 - oct, 2 - hex(default), 3 - little endian, 4 - dec\n");
                printf("\t -v | --visibility\t\t-\tEnter how many columns you want to see\n");
                printf("\t -s | --save\t\t-\tSave result to another file also you can enter file name\n");
                printf("\t-nb | --number-to-binary\t-\tEnter number which will be convert to bin\n");
                printf("\t-no | --number-to-octal\t\t-\tEnter number which will be convert to octal\n");
                printf("\t-nh | --number-to-hex\t\t-\tEnter number which will be convert to hex\n");

                return 0;
            } else if(std::string(argv[i]) == "-f" || std::string(argv[i]) == "--file"){
                if(std::string(argv[i + 1]) != ""){
                    file_name = std::string(argv[i + 1]);
                } else{
                    printf("[ERROR]: You need enter a file name!\n");

                    return 0;
                }
            } else if(std::string(argv[i]) == "-sh" || std::string(argv[i]) == "--show-line"){
                if(i + 1 >= argc){
                    mode = 2;
                } else if(atoi(argv[i + 1]) < 0 || atoi(argv[i + 1]) > 5){
                    printf("[ERROR]: Please enter number >= 0 and number <= 5!\n");

                    return 0;
                } else if(atoi(argv[i + 1]) >= 0 && atoi(argv[i + 1]) <= 5){
                    mode = atoi(argv[i + 1]);
                } else{
                    printf("[ERROR]: You entered not a int!\n");

                    return 0;
                }
            } else if((std::string(argv[i]) == "-v" || std::string(argv[i]) == "--visibility") && i < argc){
                if(is_digital_my(argv[i + 1], strlen(argv[i + 1]))){
                    visibility = atoi(argv[i + 1]);
                }
            } else if(std::string(argv[i]) == "-nb" || std::string(argv[i]) == "--number-to-binary"){
                if(is_digital_my(argv[i + 1], strlen(argv[i + 1]))){
                    std::vector<int> result_conv = decimal_to_binary(atoi(argv[i + 1]));
                    for(auto col : result_conv){
                        printf("%d", col);
                    }
                    printf("\n");

                    return 0;
                }
            } else if(std::string(argv[i]) == "-no" || std::string(argv[i]) == "--number-to-octal"){
                if(is_digital_my(argv[i + 1], strlen(argv[i + 1]))){
                    std::vector<int> result_conv = decimal_to_oct(atoi(argv[i + 1]));
                    for(auto col : result_conv){
                        printf("%d", col);
                    }
                    printf("\n");

                    return 0;
                }
            } else if(std::string(argv[i]) == "-nh" || std::string(argv[i]) == "--number-to-hex"){
                if(is_digital_my(argv[i + 1], strlen(argv[i + 1]))){
                    std::vector<char> result_conv = decimal_to_hex(atoi(argv[i + 1]));
                    for(auto col : result_conv){
                        printf("%c", col);
                    }
                    printf("\n");

                    return 0;
                }
            } else if(std::string(argv[i]) == "-s" || std::string(argv[i]) == "--save"){
                is_save = true;
            }
        }

        if(file_name != ""){
            show_file(&file_input, file_name, mode, visibility, is_save);
        }

    }

    return 0;
}
