#ifndef DIRECTORYREVISION_H
#define DIRECTORYREVISION_H

#include "FileFormat.h"
#include "QDebug"
#include "QProcess"
#include "QDir"
#include "fstream"
using namespace std ;
class Directory
{
public:
    /**
     * @brief readingFromDatabase
     * @param file
     */
    void readingFromDatabase(vector<FileFormat> &file);
    /**
     * @brief makingNewDirectoryforTree
     * @param file
     */
    void makingNewDirectoryforTree(vector<FileFormat> &file);
    /**
     * @brief makingFilesInNewDirectory
     * @param file
     */
    void makingFilesInNewDirectory(vector<FileFormat> &file);
    /**
     * @brief removingZipFileDirectory
     */
    void removingZipFileDirectory();
    /**
     * @brief removeRecordFromDirectory
     * @param file
     */
    void removeRecordFromDirectory(FileFormat file);
    /**
     * @brief removeDirectoryOfTree
     * @return
     */
    QString removeDirectoryOfTree();
    /**
     * @brief checkDirectoryExistance
     * @return
     */
    bool checkDirectoryExistance();
    /**
     * @brief makingDirectoriesforeachDate_PHASE2
     * making new Directories in root folder for each diffren date
     */
    void makingDirectoriesforeachDate_PHASE2(QString path);
    /**
     * @brief insertingFileIntoFolders_PHASE2
     * @param path
     * @param file_name
     */
    void insertingFileIntoFolders_PHASE2(QString path, QString file_name , QString type);
    /**
     * @brief removingFilesfromRootDirectory
     * @param file
     */
    void removingFilesfromRootDirectory(vector<FileFormat> &file) ;
    /**
     * @brief existanceOfSumfolderBasedOnDate_PHASE2
     * @param file_name_based_on_date
     * @return
     */
    bool existanceOfSubfolderBasedOnDate_PHASE2(QString folder_name_based_on_date);
    void makeSubdirectoryOfDateFolder_PHASE2(QString folder_name_based_on_type);
    /**
     * @brief existanceOfSubfolderBasedOnType_PHASE2
     * @param folder_name_based_on_type
     * @return
     */
    bool existanceOfSubfolderBasedOnType_PHASE2(QString folder_name_based_on_type);

};

#endif // DIRECTORYREVISION_H
