#ifndef FILEFORMAT_H
#define FILEFORMAT_H

#include "iostream"
#include "string.h"
#include "stdlib.h"
#include "vector"
#include "QString"


using namespace std;

class FileFormat
{
public:
    string name ;
    string date ;
    string type ;
    FileFormat();
    ~FileFormat();
    void ValiadatingFilesBasedDates(vector<FileFormat> file);
    QString insertToDatabase(vector<FileFormat> file);

};

#endif // FILEFORMAT_H
