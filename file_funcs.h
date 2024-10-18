#ifndef FILE_FUNCS_H
#define FILE_FUNCS_H

#include <QString>

class FileHandler {
public:
    FileHandler();

    // Создание нового файла
    bool createFile(const QString& filePath);


};

#endif // FILEHANDLER_H
