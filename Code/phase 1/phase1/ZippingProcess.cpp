#include "ZippingProcess.h"
#include "string.h"
#include "fstream"
#include "BinarySearchTree.h"

using namespace std ;

ZippingProcess::ZippingProcess()
{
    QString zip_file_name = "";
    zip_file_name = FindZipFileInDirectory();
    //Saving ZipFile to remove it later in mainWindow.cpp
    fstream file ;
    file.open("ZIPFILE.txt",ios::out);
    if(file.is_open())
    {
        file << zip_file_name.toStdString() << endl;
    }
    else
    {
        qDebug() << "file has not been created yet\n";
    }
    file.close();
    if (!zip_file_name.contains("Exception"))
    {
        QString zipFile = "/home/ali/Downloads/build-Phase1-Desktop_Qt_5_12_12_GCC_64bit-Debug/"+zip_file_name;
        QString new_directory = "/home/ali/Downloads/build-Phase1-Desktop_Qt_5_12_12_GCC_64bit-Debug/"+zip_file_name+"1";
        QStringList ValidFiles = ListOfAllValidFiles (zipFile);
        int result = DecompressDirZipFile (zipFile , new_directory);
        if (result == 0)
        {
            SNIP = new SeperatingNameIntoPieces (ValidFiles) ;

            continue_process = true ;
        }
        else
        {
            continue_process = false ;
        }


    }
}

void ZippingProcess:: CompressDir (QString ZipFile , QString Directory)
{
    //Compress it to a zip archive
    if (JlCompress::compressDir(ZipFile,Directory))
    {
        qDebug() << "Created: " << ZipFile ;

    }
    else
    {
        qDebug() << "Not Created: " << ZipFile ;
    }

}

QString ZippingProcess::FindZipFileInDirectory()
{
    QString directory_zipfile = "/home/ali/Downloads/build-Phase1-Desktop_Qt_5_12_12_GCC_64bit-Debug.zip";
    QString original_build_directory = "/home/ali/Downloads/build-Phase1-Desktop_Qt_5_12_12_GCC_64bit-Debug";
    CompressDir(directory_zipfile , original_build_directory);
    return ListOfContentToFindZipFileInDirectory (directory_zipfile);
}

QString ZippingProcess::ListOfContentToFindZipFileInDirectory(QString directory_zipfile )
{
    QFile  File(directory_zipfile);
    if(!File.exists())
    {
        qDebug () << "Zip file not found!";
        return "Exception";
    }
    QStringList list = JlCompress::getFileList(directory_zipfile);
    foreach( QString item , list)
    {
        if(item.contains(".zip"))
        {
            return item;
        }
    }
    return "" ;
}

QStringList ZippingProcess::ListOfAllValidFiles(QString zipFile)
{
    QFile  File(zipFile);
    if(!File.exists())
    {
        qDebug () << "Zip file not found!" ;
    }
    QStringList list = JlCompress::getFileList(zipFile);

    QStringList Files ;
    string str ;
   // int level = 0 ;
//    Tree * tree = new Tree();
//     Node *root = nullptr ;
//     Node * sub_folder = nullptr  ;
//      Node * sub_folder_1 = nullptr ;
 //   QString previous ;
    fstream tree ;
    tree.open("tree.txt" , ios::out);
    foreach( QString item , list)
    {
        if(tree.is_open())
        {
           tree << item.toStdString() << endl;
        }
        if(
                item.contains(".jpg") ||  item.contains(".png") ||
                item.contains(".jpeg")||  item.contains(".gif") ||
                item.contains(".mp4") ||  item.contains(".mov") ||
                item.contains(".mkv") ||  item.contains(".avl") ||
                item.contains(".wav") ||  item.contains(".aiff")||
                item.contains(".txt") ||  item.contains(".pdf"))


        {
            int counter = 0 ;
            while(item.contains("/"))
            {
                counter ++ ;
                str = item.toStdString();
                str = str.substr(str.find("/")+1);
                item = QString::fromStdString(str);
            }
            Files.append(item) ;
//            if(counter == 1)
//            {
//                root->child.push_back(tree->newNode(str));
//            }
//            else if (counter == 2)
//            {
//                sub_folder->child.push_back(tree->newNode(str));
//            }
//            else
//            {

//            }
            //if (!check_first_time)
//            {
//                if(level == 1)
//                {
//                  createTreeForPhase3(tree,root , str) ;
//                }
//                else if (level > 1 )
//                {
//                   createTreeForPhase3(tree,sub_folder , str) ;
//                }
//            }

        }
        //For root (main folder and subfolders)
//        else
//        {
//            int counter = 0 ;
//            while(item.contains("/"))
//            {
//                counter ++ ;
//                str = item.toStdString();
//                str = str.substr(str.find("/")+1);
//                item = QString::fromStdString(str);
//            }
//            if(counter==1)
//            {
//                root = tree->newNode(str) ;
//            }
//            else if (counter==2 && root!= nullptr)
//            {
//                sub_folder = tree->newNode(str);
//                root->child.push_back(sub_folder);
//            }
//            else
//            {
//                sub_folder_1 = tree->newNode(str);
//                if(sub_folder != nullptr)
//                sub_folder->child.push_back(sub_folder_1);
//            }
          //  if()
//            if(level==0)
//            {
//             str = item.toStdString();
//             str = str.substr(0,str.find("/"));
//             root =tree->newNode(str);
//             level ++ ;
//            }
//            else if (level == 1 && root != nullptr)
//            {
//                int counter = 0 ;
//                while(item.contains("/"))
//                {
//                    counter = 0 ;
//                    str = item.toStdString();
//                    for ( int i = 0 ; i < int(str.length()) ; i ++ )
//                    {
//                        if (str[i] == '/')
//                        {
//                            counter ++ ;
//                        }
//                    }
//                    if(counter != 1)
//                    {
//                     str = str.substr(str.find("/")+1);
//                     item = QString::fromStdString(str);
//                    }
//                    else if ( counter == 1)
//                    {
//                        break;
//                    }
//                }
//                str = str.substr(0,str.find("/"));
//                sub_folder = tree->addChild(root , str);
//                level ++ ;


//            }
//            else if (level > 1 && root != nullptr)
//            {
//                int counter ;
//                while(item.contains("/"))
//                {
//                    counter = 0 ;
//                    str = item.toStdString();
//                    for ( int i = 0 ; i < int(str.length()) ; i ++ )
//                    {
//                        if (str[i] == '/')
//                        {
//                            counter ++ ;
//                        }
//                    }
//                    if(counter != 1)
//                    {
//                     str = str.substr(str.find("/")+1);
//                     item = QString::fromStdString(str);
//                    }
//                    else if ( counter == 1)
//                    {
//                        break;
//                    }

//                }
//                str = str.substr(0,str.find("/"));
//                sub_folder = tree->addChild(sub_folder , str);
//            }

        }
    //}
  //  saveTreeintoFile(tree , root);
    tree.close();
    return  Files;
}

int ZippingProcess::DecompressDirZipFile(QString zipFile , QString directory)
{
    QStringList list = JlCompress::extractDir(zipFile , directory);
    if(!list.isEmpty())
    {
        return  EXIT_SUCCESS;
    }
    else
    {
        return EXIT_FAILURE ;
    }
}

ZippingProcess::~ZippingProcess()
{
    delete SNIP ;
    SNIP = nullptr ;
}

void ZippingProcess::createTreeForPhase3(Tree *tree, Node *node, string data)
{

  //  tree->addChild(node , data);
}
void ZippingProcess::saveTreeintoFile(Tree *tree , Node * root)
{
   //  tree->LevelOrderTraversal(root,true);
}
