#include "SeperatingNameIntoPieces.h"



SeperatingNameIntoPieces ::SeperatingNameIntoPieces(QStringList list)
{
    DividingNAmesFromDatesAndFormat(list);
}

void SeperatingNameIntoPieces::DividingNAmesFromDatesAndFormat(QStringList list)
{
    string item_string = "" , append_string = "" ;
    int itr ;
    foreach( QString item , list)
    {
        itr = 0;
        FileFormat file ;
        while (item.contains("."))
        {
            item_string = item.toStdString() ;
            if(itr==0)
            {
                file.name = item_string.substr(0,item_string.find("."));
            }
            else if (itr==1)
            {
                file.date = item_string.substr(0,item_string.find("."));
            }

            item = QString::fromStdString(item_string.substr(item_string.find(".")+1));
            itr++;
        }
        file.type = item.toStdString() ;
        file_format.push_back(file);
    }
    ValiadatingFilesBasedDates(file_format);
}

void SeperatingNameIntoPieces::ValidatingFiles(vector<FileFormat> file)
{
    FileFormat::ValiadatingFilesBasedDates(file);
}

SeperatingNameIntoPieces ::~SeperatingNameIntoPieces()
{
}
