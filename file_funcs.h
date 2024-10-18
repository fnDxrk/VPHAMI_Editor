#ifndef FILE_FUNCS_H
#define FILE_FUNCS_H

#include <QString>

class FileHandler {
public:
    FileHandler();

    // Создание нового файла
    bool createFile(const QString& filePath);

    // Открытие существующего файла
    QString openFile(const QString& filePath);
};

#endif // FILEHANDLER_H
