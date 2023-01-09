#include "ZippingProcess.h"
#include "string.h"
#include "fstream"

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
	foreach( QString item , list)
	{
		if(
				 item.contains(".jpg") ||  item.contains(".png") ||
				 item.contains(".jpeg")||  item.contains(".gif") ||
				 item.contains(".mp4") ||  item.contains(".mov") ||
				 item.contains(".mkv") ||  item.contains(".avl") ||
				 item.contains(".wav") ||  item.contains(".aiff")||
				 item.contains(".txt") ||  item.contains(".pdf"))


		{
			while(item.contains("/"))
			{
				str = item.toStdString();
				str = str.substr(str.find("/")+1);
				item = QString::fromStdString(str);
			}
		  // qDebug() << item ;
		   Files.append(item) ;
		}
	}

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
