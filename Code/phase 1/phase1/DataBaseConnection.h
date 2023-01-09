#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include "FileFormat.h"
#include "QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include "QDebug"
#include "QtSql/QSqlQuery"
#include "QtSql/QSqlTableModel"
#include "QtSql/QSqlRelationalTableModel"
#include "QSqlError"
class Dbconnection
{
public :
    /**
     * @brief Dbconnection
     * Initializing database connection
     * base on port name and hostname
     */
    Dbconnection();
    ~Dbconnection();
    /**
     * @brief insetingAllFilesToDatabase
     * we insert all valid files from zip file and insert them into database
     * @param file
     * @return
     */
    QString insetingAllFilesToDatabase(vector<FileFormat> file);
    /**
     * @brief insertingIndiviulFileToDatabase
     * after adding new file to main folder we insert it into database
     * @param file
     * @return
     */
    QString insertingIndiviulFileToDatabase (vector<FileFormat> file);
    /**
     * @brief removingFromDatabase
     * we remove each file from database from user input
     * @param file
     * @return
     */
    QString removingFromDatabase (FileFormat file);
    /**
     * @brief readinFromDatabase
     * reading from database and insert records into vector
     * @param file
     * @return
     */
    QString readingFromDatabase(vector<FileFormat> & file, QString orderby = "id");
    /**
     * @brief ascendingSortBasedOnName
     * we use ascending sort base on name
     */
    QString ascendingSortBasedOnName(vector<FileFormat> & file, QString user_choice) ;
    /**
     * @brief ascendingSortBasedOnDate
     * we use ascending sort base on date
     */
    QString ascendingSortBasedOnDate(vector<FileFormat> & file, QString user_choice) ;
    /**
     * @brief ascendingSortBasedOnType
     * we use ascending sort base on type
     */
    QString ascendingSortBasedOnType(vector<FileFormat> & file, QString user_choice) ;

private:
    QSqlDatabase db ;
    QString name ;
    QString date ;
    QString type ;
};


#endif // DATABASECONNECTION_H
