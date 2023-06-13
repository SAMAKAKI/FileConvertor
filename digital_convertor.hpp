/**
 * @file digital_convertor.hpp
 * @author SAMAKAKI
 * @brief 
 * @version 0.1
 * @date 2023-06-06
 */
#pragma once

#ifndef __DIGITAL_CONVERTOR_
#define __DIGITAL_CONVERTOR_

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <exception>
#include <bitset>
#include <string.h>

/**
 * @brief Convertor decimal to binary
 * 
 * @param dig get int to convertor
 * @return const std::vector<int> 
 */
const std::vector<int> decimal_to_binary(int dig){
    std::vector<int> result;
    int rest;

    while(dig){
        rest = dig % 2;
        result.push_back(rest);
        dig /= 2;
    }

    std::reverse(result.begin(), result.end());

    return result;
}

/**
 * @brief Convertor decimal to octal
 * 
 * @param dig get int to convertor
 * @return const std::vector<int> 
 */
const std::vector<int> decimal_to_oct(int dig){
    std::vector<int> result;
    int rest;

    while(dig){
        rest = dig % 8;
        result.push_back(rest);
        dig /= 8;
    }

    std::reverse(result.begin(), result.end());

    return result;
}

/**
 * @brief Convertor decimal to hex
 * 
 * @param dig get int to convertor
 * @return const std::vector<char> 
 */
const std::vector<char> decimal_to_hex(int dig){
    std::vector<char> result;
    int rest;

    while(dig){
        rest = dig % 16;
        std::map<int, char> hex_number{{10, 'A'}, {11, 'B'}, {12, 'C'}, {13, 'D'}, {14, 'E'}, {15, 'F'}};
        if(hex_number.find(rest) != hex_number.end()){
            result.push_back(hex_number[rest]);
        } else{
            result.push_back(rest + '0');
        }
        dig /= 16;
    }

    std::reverse(result.begin(), result.end());

    return result;
}

const void show_file(std::ifstream *file, const std::string &name, short mode, int visibility, bool is_save){
    file->open(name, std::ios_base::binary);
    if(!file->is_open()){
        printf("[ERROR]: File can not be open!\n");
    }
    if(file->bad()){
        printf("[ERROR]: File has a badbit!\n");
    }
    if(file->fail()){
        printf("[ERROR]: File has a badbit or failbit!\n");
    }

    file->seekg(0, std::ios_base::end);
    unsigned int file_tellg = file->tellg();
    file->seekg(0, std::ios_base::beg);

    std::string file_data;
    file_data.resize(file_tellg);
    file->read(file_data.data(), file_tellg);

    switch (mode){
        case 0:
            if(is_save){
                std::ofstream file_save;

                file_save.open("result.txt");

                if(!file_save.is_open()){
                    printf("[ERROR]: Save file can not be open!\n");
                }
                if(file_save.bad()){
                    printf("[ERROR]: Save file has a badbit!\n");
                }
                if(file_save.fail()){
                    printf("[ERROR]: Save file has a badbit or failbit!\n");
                }

                for(int i = 0; i < file_data.size(); i++){
                    if(i % visibility == 0){
                        printf("\n");
                        file_save << "\n";
                    }
                    printf("0b0%0b\t", std::bitset<8>(file_data.c_str()[i]));
                    file_save << "0b" << std::bitset<8>(file_data.c_str()[i]) << "\t";
                }
                printf("\n");
                file_save << "\n";

                file_save.close();

                break;
            } else{
                for(int i = 0; i < file_data.size(); i++){
                    if(i % visibility == 0){
                        printf("\n");
                    }
                    printf("0b0%0b\t", std::bitset<8>(file_data.c_str()[i]));
                }
                printf("\n");

                break;
            }
        case 1:
            if(is_save){
                std::ofstream file_save;

                file_save.open("result.txt");

                if(!file_save.is_open()){
                    printf("[ERROR]: Save file can not be open!\n");
                }
                if(file_save.bad()){
                    printf("[ERROR]: Save file has a badbit!\n");
                }
                if(file_save.fail()){
                    printf("[ERROR]: Save file has a badbit or failbit!\n");
                }

                for(int i = 0; i < file_data.size(); i++){
                    if(i % visibility == 0){
                        printf("\n");
                        file_save << "\n";
                    }
                    printf("0o%0o\t", (uint8_t)file_data.c_str()[i]);
                    file_save << "0o" << std::oct << (uint32_t)(uint8_t)file_data.c_str()[i] << "\t";
                }
                printf("\n");
                file_save << "\n";

                file_save.close();

                break;
            } else{
                for(int i = 0; i < file_data.size(); i++){
                    if(i % visibility == 0){
                        printf("\n");
                    }
                    printf("0o%0o\t", file_data.c_str()[i]);
                }
                printf("\n");

                break;
            }
        case 3:
            if(is_save){
                std::ofstream file_save;

                file_save.open("result.txt");

                if(!file_save.is_open()){
                    printf("[ERROR]: Save file can not be open!\n");
                }
                if(file_save.bad()){
                    printf("[ERROR]: Save file has a badbit!\n");
                }
                if(file_save.fail()){
                    printf("[ERROR]: Save file has a badbit or failbit!\n");
                }

                for(int i = file_data.size() - 1; i < file_data.size(); --i){
                    printf("0x%0x\t", (uint8_t)file_data.c_str()[i]);
                    file_save << "0x" << std::hex << (uint32_t)(uint8_t)file_data.c_str()[i] << "\t";

                    if(i % visibility == 0){
                        printf("\n");
                        file_save << "\n";
                    }
                }
                printf("\n");
                file_save << "\n";

                file_save.close();

                break;
            } else{
                for(int i = file_data.size() - 1; i < file_data.size(); --i){
                    printf("0x%0x\t", file_data.c_str()[i]);
                    if(i % visibility == 0){
                        printf("\n");
                    }
                }
                printf("\n");

                break;
            }

        case 4:
            if(is_save){
                std::ofstream file_save;

                file_save.open("result.txt");

                if(!file_save.is_open()){
                    printf("[ERROR]: Save file can not be open!\n");
                }
                if(file_save.bad()){
                    printf("[ERROR]: Save file has a badbit!\n");
                }
                if(file_save.fail()){
                    printf("[ERROR]: Save file has a badbit or failbit!\n");
                }

                for(int i = 0; i < file_data.size(); i++){
                    if(i % visibility == 0){
                        printf("\n");
                        file_save << "\n";
                    }
                    printf("0d%0d\t", (int)file_data.c_str()[i]);
                    file_save << "0d" << (uint32_t)(uint8_t)file_data.c_str()[i] << "\t";
                }
                printf("\n");
                file_save << "\n";

                file_save.close();

                break;

            } else{
                for(int i = 0; i < file_data.size(); i++){
                    if(i % visibility == 0){
                        printf("\n");
                    }
                    printf("0d%0d\t", (int)file_data.c_str()[i]);
                }
                printf("\n");

                break;
            }
        default:
            if(is_save){
                std::ofstream file_save;

                file_save.open("result.txt");

                if(!file_save.is_open()){
                    printf("[ERROR]: Save file can not be open!\n");
                }
                if(file_save.bad()){
                    printf("[ERROR]: Save file has a badbit!\n");
                }
                if(file_save.fail()){
                    printf("[ERROR]: Save file has a badbit or failbit!\n");
                }

                for(int i = 0; i < file_data.size(); i++){
                    if(i % visibility == 0){
                        printf("\n");
                        file_save << "\n";
                    }
                    printf("0x%0x\t", (unsigned char)file_data.c_str()[i]);
                    file_save << "0x" << std::hex << (unsigned int)(unsigned char)file_data.c_str()[i] << "\t";
                }
                printf("\n");
                file_save << "\n";

                file_save.close();

                break;
            } else{
                for(int i = 0; i < file_data.size(); i++){
                    if(i % visibility == 0){
                        printf("\n");
                    }
                    printf("0x%0x\t", file_data.c_str()[i]);
                }
                printf("\n");

                break;
            }
    }

    file->close();

}

bool is_digital_my(const char* array, int size){
    for(int i = 0; i < size; i++){
        if(!(array[i] >= '0' && array[i] <= '9')){
            return false;
        }
    }

    return true;
} 

#endif