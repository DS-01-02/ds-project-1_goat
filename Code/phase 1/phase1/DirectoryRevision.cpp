#include "DirectoryRevision.h"
#include "DataBaseConnection.h"

void Directory::removingZipFileDirectory()
{
    fstream file ;
    file.open("ZIPFILE.txt",ios::in);
    string directory_name = "" ;
    if(file.is_open())
    {
        file >> directory_name ;
    }
    else
    {
        qDebug() << "file doesn't exist\n";
    }
    file.close();
    directory_name += "1" ;
    QDir dir ("/home/ali/Downloads/build-Phase1-Desktop_Qt_5_12_12_GCC_64bit-Debug/"+QString::fromStdString(directory_name));
    dir.removeRecursively();


}

void Directory::makingFilesInNewDirectory(vector<FileFormat> &file)
{
    QString command = "touch";
    string path ;
    QProcess process ;
    process.setWorkingDirectory("/home/ali/Downloads/build-Phase1-Desktop_Qt_5_12_12_GCC_64bit-Debug/root");
    QStringList list ;

    for (auto iter = file.begin() ; iter != file.end() ; iter++)
    {
        path += iter->name +"." + iter->date + "."+iter->type ;
        list.append(QString::fromStdString(path));
        path = "";
    }
    process.start(command ,list);
    process.waitForFinished();
    process.close();
    QString StdOut = process.readAllStandardOutput();
    cout<<endl<<StdOut.toStdString();
    removingZipFileDirectory();


}

void Directory::makingNewDirectoryforTree(vector<FileFormat> &file)
{
    QProcess process ;
    QString dirPath = "/home/ali/Downloads/build-Phase1-Desktop_Qt_5_12_12_GCC_64bit-Debug/root";
    process.start("mkdir" , QStringList() << dirPath);
    process.waitForFinished();
    QString StdOut = process.readAllStandardOutput();
    cout<<endl<<StdOut.toStdString();
    if(StdOut.toStdString() == "")
    {
        process.close();
        makingFilesInNewDirectory(file);
    }
    else
    {
        terminate();
    }

}

void Directory::readingFromDatabase(vector<FileFormat> & file)
{
    Dbconnection * db = new Dbconnection ;
    QString result = db->readingFromDatabase(file);
    if (result != "success(Query)")
    {
        cout << "couldn't read from database\n";
    }
    delete db ;
    db = nullptr ;
}

void Directory::removeRecordFromDirectory(FileFormat file)
{
    QProcess process ;
    process.setWorkingDirectory("/home/ali/Downloads/build-Phase1-Desktop_Qt_5_12_12_GCC_64bit-Debug/root");
    process.start("rm" , QStringList() << QString::fromStdString(file.name + "." + file.date + "." + file.type) ) ;
    process.waitForFinished();
    process.kill();

    Dbconnection * db ;
    db = nullptr ;
    db = new Dbconnection ;
    QString result = db->removingFromDatabase(file);
    if(result != "success(Query)")
    {
        cout << "couldn't delete from database\n";
    }

}

QString Directory::removeDirectoryOfTree()
{
    QDir dir ("/home/ali/Downloads/build-Phase1-Desktop_Qt_5_12_12_GCC_64bit-Debug/root");
    dir.removeRecursively();
    QDir dirZip ("/home/ali/Downloads/build-Phase1-Desktop_Qt_5_12_12_GCC_64bit-Debug.zip");
    dir.removeRecursively();
    if(!dir.exists() && !dirZip.exists())
    {
        return "***root and BUILD ZIP REMOVED ***";
    }
    return " >>>>FAILURE ON REMOVING ZIPPING PROPERTY FOR REMOVING THEM <<<<<<";
}

bool Directory::checkDirectoryExistance()
{
    QDir dir("/home/ali/Downloads/build-Phase1-Desktop_Qt_5_12_12_GCC_64bit-Debug/root");
    if(dir.exists())
    {
        return true;
    }
    return false ;
}

void Directory::makingDirectoriesforeachDate_PHASE2(QString path)
{
    QProcess process ;
    QString dirPath = "/home/ali/Downloads/build-Phase1-Desktop_Qt_5_12_12_GCC_64bit-Debug/root/" +path;
    process.start("mkdir" , QStringList() << dirPath);
    process.waitForFinished();
    QString StdOut = process.readAllStandardOutput();
    cout<<endl<<StdOut.toStdString();
    if(StdOut.toStdString() == "")
    {
        process.close();
    }
    else
    {
        terminate();
    }
}

bool Directory::existanceOfSubfolderBasedOnType_PHASE2(QString folder_name_based_on_type)
{
    QDir dir(folder_name_based_on_type);
    if(dir.exists())
    {
        return true;
    }
    return false ;
}

void Directory::makeSubdirectoryOfDateFolder_PHASE2(QString folder_name_based_on_type)
{
    if(!existanceOfSubfolderBasedOnType_PHASE2(folder_name_based_on_type))
    {
        QProcess process ;
        QString dirPath = folder_name_based_on_type;
        process.start("mkdir" , QStringList() << dirPath);
        process.waitForFinished();
        QString StdOut = process.readAllStandardOutput();
        if(StdOut.toStdString() == "")
        {
            process.close();
        }
        else
        {
            terminate();
        }
    }
    else
    {
        return ;
    }
}

void Directory::insertingFileIntoFolders_PHASE2(QString path , QString file_name, QString type)
{
    QString command = "touch";
    QProcess process ;
    QString classification = "";
    if(type == "mp4" || type == "mov" || type == "‫‪avl‬‬" || type == "‫‪mkv"  )
    {
        classification = "video";
    }
    else if (type == "jpeg" || type == "png" || type == "gif" || type == "jpg")
    {
        classification = "photo";
    }
    else if (type == "wav" || type == "aiff")
    {
        classification = "voice";
    }
    else if (type == "txt")
    {
        classification = "text";
    }
    else
    {
        classification = "pdf";
    }
    makeSubdirectoryOfDateFolder_PHASE2("/home/ali/Downloads/build-Phase1-Desktop_Qt_5_12_12_GCC_64bit-Debug/root/"+path+"/"+classification);
    process.setWorkingDirectory("/home/ali/Downloads/build-Phase1-Desktop_Qt_5_12_12_GCC_64bit-Debug/root/"+path+"/"+classification);
    QStringList list ;
    list.append(file_name);
    process.start(command ,list);
    process.waitForFinished();
    process.close();

}

void Directory::removingFilesfromRootDirectory(vector<FileFormat> & file)
{
    QProcess process ;
    process.setWorkingDirectory("/home/ali/Downloads/build-Phase1-Desktop_Qt_5_12_12_GCC_64bit-Debug/root");
    QStringList list;
    for ( auto i = 0 ; i  < int(file.size()); i ++)
    {
        list.append(QString::fromStdString
                    (file.at(i).name
                     + "." +
                     file.at(i).date
                     + "." +
                     file.at(i).type ));
    }
    process.start("rm" , list) ;
    process.waitForFinished();
    process.kill();

    return ;
}

bool Directory::existanceOfSubfolderBasedOnDate_PHASE2(QString folder_name_based_on_date)
{
    QDir dir("/home/ali/Downloads/build-Phase1-Desktop_Qt_5_12_12_GCC_64bit-Debug/root/"+folder_name_based_on_date);
    if(dir.exists())
    {
        return true;
    }
    return false ;
}

