#include "mainwindow.h"
#include "ui_mainwindow.h"
//data base
#include "QFlag"


MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	this->setWindowTitle("FMS");
	this->setGeometry(700,250,598,488);
	this->setFixedSize(598,488);
	bool check_Directory = checkDirectoryExistance();
	bool check_Zipping = false ;
	if(!check_Directory)
	{
		 zip = new ZippingProcess ();
		 check_Zipping = zip->continue_process ;
	}
	if (check_Zipping || check_Directory)
	{
		tree_header_label_first_column = new QLabel ;
		tr_main  = new QTreeWidgetItem ;
		tr_name_main = new QTreeWidgetItem ;
		tr_date_main = new QTreeWidgetItem ;
		tr_type_main = new QTreeWidgetItem ;
		tr_remove_main = new QTreeWidgetItem ;
		tr_main_sub_folder = new QTreeWidgetItem() ;
		db = new Dbconnection ();
		setSize();
		adjustLayout();
		addingChildrenToTree();
		generalSort();
		removeChildMainList();

	}
	else
	{
		exit(0);
	}


}

void MainWindow::setSize()
{
	tree_header_label_first_column->setText("Folder");
	tr_main->setText(0 , "Main");

}

void MainWindow::adjustLayout()
{
  ui->apply->hide();
  ui->cancel->hide();
  ui->actionUnizp_file->setDisabled(true);
  ui->treeWidget->setHeaderLabel(tree_header_label_first_column->text());
  setIconForTopLevelItem(tr_main);
}

void MainWindow::setIconForTopLevelItem(QTreeWidgetItem * tr)
{
   QIcon ic ("/home/ali/Downloads/Folder Pics/download.png");
   tr->setIcon(0,ic);
}

void MainWindow::setIconForPhase1Children(QTreeWidgetItem *tr)
{
	QIcon ic ("/home/ali/Downloads/Folder Pics/redfile.png");
	tr->setIcon(1,ic);
}

//void MainWindow::addingChildrenToTree();


//void MainWindow::makingNewDirectoryforTree(vector<FileFormat> &file);

//void MainWindow::readingFromDatabase(vector<FileFormat> & file);

MainWindow::~MainWindow()
{
	delete ui;
	delete  zip ;
}

void MainWindow::generalSort()
{
	sortName();
	sortDate();
	sortType();
}

void MainWindow::sortName()
{
	if(db != nullptr)
	{
		delete db ;
		db = nullptr ;
	}
    db = new Dbconnection ();
    vector<FileFormat> file ;
    QString result = db->ascendingSortBasedOnName(file, "name");
    if(result != "success(Query)")
    {
        cerr << "could not source by name\n";
        terminate();
    }
	tr_name_main->setText(0,"Main");
	setIconForTopLevelItem(tr_name_main);
//    for (int i = 0; i <int(file.size()); ++i)
//    {
//        tr_main_sub_folder->setText(1,QString::fromStdString( file.at(i).name));
//        tr_main_sub_folder->setText(2,QString::fromStdString(file.at(i).date));
//        tr_main_sub_folder->setText(3,QString::fromStdString(file.at(i).type));
//        setIconForPhase1Children(tr_main_sub_folder);
//        items_name.append(tr_main_sub_folder);
//        tr_main_sub_folder = new QTreeWidgetItem() ;
//    }
//    tr_name_main->insertChildren(0,items_name);


}

void MainWindow::sortDate()
{
	if(db != nullptr)
	{
		delete db ;
		db = nullptr ;
	}
   //data base
    db = new Dbconnection ();
    vector<FileFormat> file ;
    QString result = db->ascendingSortBasedOnName(file, "date");
    if(result != "success(Query)")
    {
        cerr << "could not source by date\n";
        terminate();
    }
    tr_date_main->setText(0,"Main");
    setIconForTopLevelItem(tr_date_main);
    for (int i = 0; i <int(file.size()); ++i)
    {
        tr_main_sub_folder->setText(1,QString::fromStdString( file.at(i).name));
        tr_main_sub_folder->setText(2,QString::fromStdString(file.at(i).date));
        tr_main_sub_folder->setText(3,QString::fromStdString(file.at(i).type));
        setIconForPhase1Children(tr_main_sub_folder);
        items_date.append(tr_main_sub_folder);
        tr_main_sub_folder = new QTreeWidgetItem() ;
    }
    tr_date_main->insertChildren(0,items_date);

}

void MainWindow::sortType()
{
	if(db != nullptr)
	{
		delete db ;
		db = nullptr ;
	}
    db = new Dbconnection ();
    vector<FileFormat> file ;
    QString result = db->ascendingSortBasedOnName(file, "type_file");
    if(result != "success(Query)")
    {
        cerr << "could not source by type\n";
        terminate();
    }
	tr_type_main->setText(0,"Main");
	setIconForTopLevelItem(tr_type_main);
    for (int i = 0; i <int(file.size()); ++i)
    {
        tr_main_sub_folder->setText(1,QString::fromStdString( file.at(i).name));
        tr_main_sub_folder->setText(2,QString::fromStdString(file.at(i).date));
        tr_main_sub_folder->setText(3,QString::fromStdString(file.at(i).type));
        setIconForPhase1Children(tr_main_sub_folder);
        items_type.append(tr_main_sub_folder);
        tr_main_sub_folder = new QTreeWidgetItem() ;
    }
    tr_type_main->insertChildren(0,items_type);
}

void MainWindow::sortReset(bool flag_phase2)
{
    if(file_reset_action.size() != 0)
    {
        file_reset_action.clear();
    }
    readingFromDatabase(file_reset_action);
    for (int i = 0; i <int(file_reset_action.size()); ++i)
    {
        tr_main_sub_folder->setText(1,QString::fromStdString( file_reset_action.at(i).name));
        tr_main_sub_folder->setText(2,QString::fromStdString(file_reset_action.at(i).date));
        tr_main_sub_folder->setText(3,QString::fromStdString(file_reset_action.at(i).type));
        setIconForPhase1Children(tr_main_sub_folder);
        items.append(tr_main_sub_folder);
        tr_main_sub_folder = new QTreeWidgetItem() ;
    }
    if(!flag_phase2)
    {
        tr_main->insertChildren(0,items);
    }
}

void MainWindow::on_actionName_triggered()
{
   removeWidgets();
   ui->treeWidget->addTopLevelItem(tr_name_main);
}

void MainWindow::on_actionDate_triggered()
{
	removeWidgets();
	ui->treeWidget->addTopLevelItem(tr_date_main);
}

void MainWindow::on_actionType_triggered()
{
	 removeWidgets();
	 ui->treeWidget->addTopLevelItem(tr_type_main);
}

void MainWindow::on_actionReset_triggered()
{
	removeWidgets();
	ui->treeWidget->addTopLevelItem(tr_main);
}

void MainWindow::on_actionPrivacy_policy_triggered()
{
	QMessageBox msg ;
	msg.about(this, "Privacy and Policy" , "This Privacy Policy describes Our policies and procedures on the collection,"
										   " use and disclosure of Your information when You use the Service and"
										   " tells You about Your privacy rights and how the law protects You.\n"
										   "While using Our Service, We may ask You to provide Us with certain personally identifiable information"

										   " that can be used to contact or identify You.");
  msg.setIcon(QMessageBox::Information);

}

void MainWindow::on_actionHelp_triggered()
{
	QMessageBox msg ;
	msg.about(this, "Help" , "We highly respect our privacy and policy");
}

void MainWindow::removeWidgets()
{
	ui->treeWidget->takeTopLevelItem(0);

}

void MainWindow::removeChildMainList()
{
	if(db != nullptr)
	{
		delete db ;
		db = nullptr ;
	}
// data base

	tr_remove_main->setText(0,"Main");
	setIconForTopLevelItem(tr_remove_main);
    for (int i = 0; i <int(file.size()); ++i)
    {
        tr_main_sub_folder->setText(1,QString::fromStdString( file.at(i).name));
        tr_main_sub_folder->setText(2,QString::fromStdString(file.at(i).date));
        tr_main_sub_folder->setText(3,QString::fromStdString(file.at(i).type));
        setIconForPhase1Children(tr_main_sub_folder);
        items_remove.append(tr_main_sub_folder);
        items_remove.at(i)->setCheckState(0 , Qt::Unchecked);
        tr_main_sub_folder = new QTreeWidgetItem() ;
    }
    tr_remove_main->insertChildren(0,items_remove);
}

void MainWindow::hideRemove_Add_Widgets()
{
	ui->add->show();
	ui->remove->show();
	ui->log->show();
	ui->apply->hide();
	ui->cancel->hide();
	on_actionReset_triggered();
}

void MainWindow::on_remove_clicked()
{
   removeWidgets();
   ui->treeWidget->addTopLevelItem(tr_remove_main);
   ui->actionName->setEnabled(false);
   ui->actionDate->setEnabled(false);
   ui->actionType->setEnabled(false);
   ui->actionReset->setEnabled(false);
   ui->add->hide();
   ui->remove->hide();
   ui->log->hide();
   ui->step2->hide();
   ui->step3->hide();
   ui->step4->hide();
   ui->apply->show();
   ui->cancel->show();
}

void MainWindow::on_cancel_clicked()
{
	hideRemove_Add_Widgets();
    hideRemove_Add_Widgets();
    ui->actionName->setEnabled(true);
    ui->actionDate->setEnabled(true);
    ui->actionType->setEnabled(true);
}

void MainWindow::removeFromTree()
{
    FileFormat file ;
    int ChildernCount =tr_remove_main->childCount() ;
    int counter = 0;
    for(int i = 0 ; i < ChildernCount ; i ++)
    {

        if (tr_remove_main->child(i)->checkState(0) == Qt::Checked)
        {
            file.name = tr_remove_main->child(i)->text(1).toStdString();
            file.date = tr_remove_main->child(i)->text(2).toStdString();
            file.type = tr_remove_main->child(i)->text(3).toStdString();
            Directory::removeRecordFromDirectory(file);
            counter ++ ;
        }
    }
    ui->apply->hide();
    ui->cancel->hide();
    ui->add->show();
    ui->remove->show();
    ui->log->show();
    ui->step2->show();
    ui->step3->show();
    ui->step4->show();

    if(counter != ChildernCount )
    {
        reparentingTree();
    }
    else
    {
        QString string = Directory::removeDirectoryOfTree();
        if(string.contains("REMOVED"))
        {
            foreach(auto i, tr_main->takeChildren()) delete i;
            foreach(auto i, tr_name_main->takeChildren()) delete i;
            foreach(auto i, tr_date_main->takeChildren()) delete i;
            foreach(auto i, tr_type_main->takeChildren()) delete i;
            foreach(auto i, tr_remove_main->takeChildren()) delete i;
            items.clear();
            items_name.clear();
            items_date.clear();
            items_type.clear();
            items_remove.clear();
            enableUnzipAction();
            ui->actionName->setEnabled(false);
            ui->actionDate->setEnabled(false);
            ui->actionType->setEnabled(false);
            ui->remove->setEnabled(false);
            ui->actionReset->setEnabled(false);
            ui->step2->setEnabled(false);
            ui->treeWidget->clear();
        }
        else
        {
            cerr << string.toStdString() << endl;
        }

    }


}

bool MainWindow::selectedCheckBoxesToRemove()
{
    int ChildernCount =tr_remove_main->childCount() ;
    for(int i = 0 ; i < ChildernCount ; i ++)
    {

        if (tr_remove_main->child(i)->checkState(0) == Qt::Checked)
        {
            return false ;
        }
    }
    return true ;

}

void MainWindow::on_apply_clicked()
{
    QMessageBox msg ;
    msg.setWindowTitle("Warning");
    msg.setFixedSize(100,100);
    if(selectedCheckBoxesToRemove())
    {
        msg.setText("You must select at least one item.");
        msg.setInformativeText("Tap Ok button to continue!");
        msg.setStandardButtons(QMessageBox::Ok);
        msg.setIcon(QMessageBox::Warning);
        msg.exec();
        return ;
    }
    msg.setText("Selected items will be removed.");
    msg.setInformativeText("Do you want to continue ?");
    msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msg.setDefaultButton(QMessageBox::Ok);
    msg.setIcon(QMessageBox::Warning);
    int ret = msg.exec();
    switch (ret) {
    case QMessageBox::Ok:
        // Ok was clicked
        ui->actionName->setEnabled(true);
        ui->actionDate->setEnabled(true);
        ui->actionType->setEnabled(true);
        ui->actionReset->setEnabled(true);
        removeFromTree();
        break;
    case QMessageBox::Cancel:
        msg.hide();
        break;
    default:
        // should never be reached
        break;
}

void MainWindow::on_add_clicked()
{
    if(tr_main->childCount() == 0)
    {
        QProcess process ;
        QString dirPath = "/home/ali/Downloads/build-Phase1-Desktop_Qt_5_12_12_GCC_64bit-Debug/root";
        process.start("mkdir" , QStringList() << dirPath);
        process.waitForFinished();
        tr_main = new QTreeWidgetItem ;
        tr_name_main = new QTreeWidgetItem ;
        tr_date_main = new QTreeWidgetItem ;
        tr_type_main = new QTreeWidgetItem ;
        tr_remove_main = new QTreeWidgetItem ;
    }
    Adding * add = new Adding ();
    add->show();
    ui->actionRefresh->setEnabled(true);
    ui->treeWidget->collapseAll();
    ui->actionName->setEnabled(false);
    ui->actionDate->setEnabled(false);
    ui->actionType->setEnabled(false);
    ui->actionUnizp_file->setEnabled(false);
    ui->remove->setEnabled(false);
}

bool MainWindow::checkDirectoryExistance()
{
	return Directory::checkDirectoryExistance();
}
void MainWindow::enableUnzipAction()//Unzipagain()
{
	ui->actionUnizp_file->setEnabled(true);
}

bool MainWindow::enableUnzipProcess()
{
    zip = nullptr ;
    zip = new ZippingProcess ();
    return zip->continue_process ;
}

void MainWindow::reparentingTree()
{
    foreach(auto i, tr_main->takeChildren()) delete i;
    foreach(auto i, tr_name_main->takeChildren()) delete i;
    foreach(auto i, tr_date_main->takeChildren()) delete i;
    foreach(auto i, tr_type_main->takeChildren()) delete i;
    foreach(auto i, tr_remove_main->takeChildren()) delete i;
    items.clear();
    items_name.clear();
    items_date.clear();
    items_type.clear();
    items_remove.clear();
    tr_main = new QTreeWidgetItem ;
    tr_main->setText(0 ,"root");
    setIconForTopLevelItem(tr_main);
    sortReset();
    tr_name_main = new QTreeWidgetItem ;
    tr_name_main->setText(0 ,"root");
    setIconForTopLevelItem(tr_name_main);
    sortName();
    tr_date_main = new QTreeWidgetItem ;
    tr_date_main->setText(0 ,"root");
    setIconForTopLevelItem(tr_date_main);
    sortDate();
    tr_type_main = new QTreeWidgetItem ;
    tr_type_main->setText(0 ,"root");
    setIconForTopLevelItem(tr_type_main);
    sortType();
    tr_remove_main = new QTreeWidgetItem ;
    tr_remove_main->setText(0 ,"root");
    setIconForTopLevelItem(tr_remove_main);
    removeChildMainList();
    on_actionReset_triggered();
}





















/*void CompressDir ( QString ZipFile , QString Directory)
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
void DecompressDir ( QString ZipFile , QString Directory)
{
	QStringList list = JlCompress::extractDir(ZipFile , Directory);
	foreach( QString item , list)
	{
		qDebug() << "Extracted:"<<  item ;
	}
}
void CompressFiles ( QString ZipFile , QStringList Files)
{
	if(JlCompress::compressFiles(ZipFile , Files))
	{
		qDebug() << "Created: " << ZipFile ;

	}
	else
	{
		qDebug() << "Not Created: " << ZipFile ;
	}
}
void DecompressFiles ( QString ZipFile , QStringList Files ,QString Dir)
{

	QStringList list = JlCompress::extractFiles(ZipFile , Files , Dir);
	foreach( QString item , list)
	{
		qDebug() << "Extracted:"<<  item ;
	}

}
void ListContents ( QString ZipFile)
{
	QFile  File(ZipFile);
	if(!File.exists())
	{
		qDebug () << "Zip file not found!" ;
		return ;
	}
	QStringList list = JlCompress::getFileList(ZipFile);
	foreach( QString item , list)
	{
	  //  if(item.contains(".jpg") || item.contains(".png"))
			qDebug() << item ;
	}
}*/












//        QString ZipFile = "/home/ali/Downloads/test1.zip";
//        QString OriginalDir = "/home/ali/Downloads/Original";
//        QString NewDir = "/home/ali/Downloads/NewDir1";
//        QString SingleFile = OriginalDir + "/wp3703397.jpg";


//        ///Compress a directory
//        CompressDir(ZipFile , OriginalDir);

//        ///List the contents of a zip file
//         ListContents(ZipFile);
//          //zipFile
//        ///Compress a single file
//        //CompressFiles(ZipFile ,QStringList () << SingleFile);

//        //Decompress an archive to a directory
//        //DecompressDir(ZipFile ,NewDir);

//        //Decompress a single file
//        //DecompressFiles (ZipFile ,QStringList () << "wp3703397.jpg" , NewDir );


















