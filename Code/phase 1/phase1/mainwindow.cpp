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
    // zip & daata base



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
    //data base

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
//    tr_date_main->setText(0,"Main");
//    setIconForTopLevelItem(tr_date_main);
//    for (int i = 0; i <int(file.size()); ++i)
//    {
//        tr_main_sub_folder->setText(1,QString::fromStdString( file.at(i).name));
//        tr_main_sub_folder->setText(2,QString::fromStdString(file.at(i).date));
//        tr_main_sub_folder->setText(3,QString::fromStdString(file.at(i).type));
//        setIconForPhase1Children(tr_main_sub_folder);
//        items_date.append(tr_main_sub_folder);
//        tr_main_sub_folder = new QTreeWidgetItem() ;
//    }
//    tr_date_main->insertChildren(0,items_date);

}

void MainWindow::sortType()
{
    if(db != nullptr)
    {
        delete db ;
        db = nullptr ;
    }
   // data base
    tr_type_main->setText(0,"Main");
    setIconForTopLevelItem(tr_type_main);
//    for (int i = 0; i <int(file.size()); ++i)
//    {
//        tr_main_sub_folder->setText(1,QString::fromStdString( file.at(i).name));
//        tr_main_sub_folder->setText(2,QString::fromStdString(file.at(i).date));
//        tr_main_sub_folder->setText(3,QString::fromStdString(file.at(i).type));
//        setIconForPhase1Children(tr_main_sub_folder);
//        items_type.append(tr_main_sub_folder);
//        tr_main_sub_folder = new QTreeWidgetItem() ;
//    }
//    tr_type_main->insertChildren(0,items_type);
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
//    for (int i = 0; i <int(file.size()); ++i)
//    {
//        tr_main_sub_folder->setText(1,QString::fromStdString( file.at(i).name));
//        tr_main_sub_folder->setText(2,QString::fromStdString(file.at(i).date));
//        tr_main_sub_folder->setText(3,QString::fromStdString(file.at(i).type));
//        setIconForPhase1Children(tr_main_sub_folder);
//        items_remove.append(tr_main_sub_folder);
//        items_remove.at(i)->setCheckState(0 , Qt::Unchecked);
//        tr_main_sub_folder = new QTreeWidgetItem() ;
//    }
//    tr_remove_main->insertChildren(0,items_remove);
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
   ui->add->hide();
   ui->remove->hide();
   ui->log->hide();
   ui->apply->show();
   ui->cancel->show();
}

void MainWindow::on_cancel_clicked()
{
    hideRemove_Add_Widgets();
}

void MainWindow::removeFromTree()
{
 //remover data base
    ui->apply->hide();
    ui->cancel->hide();
    ui->add->show();
    ui->remove->show();
    ui->log->show();
    on_actionReset_triggered();


}

void MainWindow::on_apply_clicked()
{
  QMessageBox msg ;
  msg.setWindowTitle("Warning");
  msg.setFixedSize(100,100);
  msg.setText("Selected items will be removed.");
  msg.setInformativeText("Do you want to continue ?");
  msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
  msg.setDefaultButton(QMessageBox::Ok);
  msg.setIcon(QMessageBox::Warning);
  int ret = msg.exec();
  switch (ret) {
    case QMessageBox::Ok:
        // Ok was clicked
        removeFromTree();
        break;
    case QMessageBox::Cancel:
        msg.hide();
        break;
    default:
        // should never be reached
        break;
  }
}

void MainWindow::on_add_clicked()
{

}

//bool MainWindow::checkDirectoryExistance();


void MainWindow::Unzipagain()
{
    ui->actionUnizp_file->setEnabled(true);
}


















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
























