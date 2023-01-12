#ifndef ZIPPINGPROCESS_H
#define ZIPPINGPROCESS_H
#include <QCoreApplication>
#include "QDebug"
#include "JlCompress.h"
#include "QFile"
#include "SeperatingNameIntoPieces.h"
#include "BinarySearchTree.h"
class ZippingProcess
{
public:
    bool continue_process ;
    /**
     * @brief ZippingProcess
     * Addressing Zip directories
     */
    ZippingProcess();
    /**
     * @brief CompressDir
     * Zipping the whole directory
     * @param ZipFile
     * @param Directory
     */
    ~ZippingProcess();
    void CompressDir ( QString ZipFile , QString Directory);
    /**
     * @brief FindZipFileInDirectory
     * We first Zip build directory
     */
    QString FindZipFileInDirectory();
    /**
     * @brief ListOfContentToFindZipFileInDirectory
     * We search through directory so we find the Zipfile
     * @param directory_zipfile
     * @return
     */
    QString ListOfContentToFindZipFileInDirectory(QString directory_zipfile);
    /**
     * @brief ListOfAllValidFiles
     * We make a list of valid files with valid formats (jpg , png , ... )
     * @param zipFile
     * @return
     */
    QStringList ListOfAllValidFiles(QString zipFile) ;
    /**
     * @brief DecompressDirZipFile
     * We unzip the given zip file
     * @param zipFile
     * @param directory
     * @return
     */
    int DecompressDirZipFile(QString zipFile , QString directory);
    /**
     * @brief createTreeForPhase3
     */
    void createTreeForPhase3(Tree * tree,Node * node , string data );
    /**
     * @brief saveTreeintoFile
     * Saving tree nodes into a file
     * @param tree
     * @param root
     */
    void saveTreeintoFile(Tree * tree, Node *root) ;


    SeperatingNameIntoPieces * SNIP ;
private:

};

#endif // ZIPPINGPROCESS_H
