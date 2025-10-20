#pragma once
#include <string>
class FileHandler {
public:
    std::string currentFile;
    FileHandler();
    bool encryptFile(const std::string& inputFile, const std::string& outputFile, int key);
    bool decryptFile(const std::string& inputFile, const std::string& outputFile, int key);
    void showFileContent(const std::string& filename);};