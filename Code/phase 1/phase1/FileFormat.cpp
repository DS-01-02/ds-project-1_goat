#include "FileFormat.h"


#define TODAY_DATE 2023

FileFormat::FileFormat()
{
   name = "" ;
   date = "" ;
   type = "" ;
}

void FileFormat ::ValiadatingFilesBasedDates(vector<FileFormat> file)
{

    for (auto iterator = file.begin() ; iterator !=file.end() ; iterator++)
    {
        if (QString::fromStdString(iterator->date).toLongLong()> TODAY_DATE )
        {
            file.erase(iterator);
        }
    }
  QString result =  insertToDatabase(file);
  qDebug() << result  <<" ***INSERTING***";

}

//insertToDatabase(file) :

FileFormat::~FileFormat()
{

}

