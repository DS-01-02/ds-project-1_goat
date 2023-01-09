#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<stdio.h>
#include "ZippingProcess.h"
#include "DirectoryRevision.h"
#include "adding.h"
#include "tree.h"
#include <QMainWindow>
#include <QCoreApplication>
#include "QDebug"
#include "JlCompress.h"
#include "QFile"
#include <QFileInfo>
#include "QLabel"
#include "QLineEdit"
#include "QTreeWidget"
#include "QTreeWidgetItem"
#include "QIcon"
#include "QPixmap"
#include "QMessageBox"
#include "FileFormat.h"
#include "fstream"
#include "DataBaseConnection.h"
#include "QCheckBox"
#include "QStandardItem"

using namespace std ;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow , public Directory
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    /**
     * @brief adjustLayout
     */
    void adjustLayout();
    /**
     * @brief setSize
     */
    void setSize();
    /**
     * @brief setIconForTopLevelItem
     * @param tr
     */
    void setIconForTopLevelItem(QTreeWidgetItem *tr);
    /**
     * @brief setIconForPhase1Children
     * @param tr
     */
    void setIconForPhase1Children(QTreeWidgetItem *tr);
    /**
     * @brief addingChildrenToTree
     */
    void addingChildrenToTree();
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
     * @brief removeWidgets
     */
    void removeWidgets();
    /**
     * @brief generalSort
     */
    void generalSort();
    /**
     * @brief sortName
     */
    void sortName();
    /**
     * @brief sortDate
     */
    void sortDate();
    /**
     * @brief sortType
     */
    void sortType();
    /**
     * @brief sortReset
     * @param flag_phase2
     */
    void sortReset(bool flag_phase2 = false);
    /**
     * @brief removeChildMainList
     */
    void removeChildMainList();
    /**
     * @brief hideRemove_Add_Widgets
     */
    void hideRemove_Add_Widgets();
    /**
     * @brief removeFromTree
     */
    void removeFromTree();
    /**
     * @brief checkDirectoryExistance
     * @return
     */
    bool checkDirectoryExistance() ;
    /**
     * @brief enableUnzipAction
     */
    void enableUnzipAction();
    /**
     * @brief enableUnzipProcess
     * @return
     */
    bool enableUnzipProcess();
    /**
     * @brief reparentingTree
     */
    void reparentingTree();
    /**
     * @brief selectedCheckBoxesToRemove
     * @return
     */
    bool selectedCheckBoxesToRemove();
    /**
     * @brief rebuildingRootTree
     */
    void rebuildingRootTree();
    /**
     * @brief reviseRootDirectory
     * @param file
     */
    void reviseRootDirectory(FileFormat &file);
    /**
     * @brief checkExistanceOfeachSubFolder_PHASE2
     * @param folder_name_based_on_date
     * @return
     */
    bool checkExistanceOfeachSubFolder_PHASE2(QString folder_name_based_on_date);
    /**
     * @brief removingRootDirectoryFiles
     * @param file
     */
    void removingRootDirectoryFiles(vector<FileFormat> & file);
    void topLevelItemForRootBasedOnDate();
    ZippingProcess * zip ;
    QLabel * tree_header_label_first_column ;
    QTreeWidgetItem * tr_main;
    QTreeWidgetItem * tr_name_main ;
    QTreeWidgetItem * tr_date_main ;
    QTreeWidgetItem * tr_type_main ;
    QTreeWidgetItem * tr_remove_main ;
    QTreeWidgetItem * tr_main_sub_folder ;
    QList<QTreeWidgetItem *> items;
    QList<QTreeWidgetItem *> items_name;
    QList<QTreeWidgetItem *> items_date;
    QList<QTreeWidgetItem *> items_type;
    QList<QTreeWidgetItem *> items_remove ;
    Dbconnection  * db ;
    vector<FileFormat>  file_reset_action ; // It will be needded in phase 3

private slots:
    void on_actionName_triggered();

    void on_actionDate_triggered();

    void on_actionType_triggered();

    void on_actionReset_triggered();

    void on_remove_clicked();

    void on_cancel_clicked();

    void on_add_clicked();

    void on_apply_clicked();

    void on_actionPrivacy_policy_triggered();

    void on_actionHelp_triggered();

    void on_actionUnizp_file_triggered();

    void on_actionRefresh_triggered();

    void on_step2_clicked();

    void on_step3_clicked();

private:
    Ui::MainWindow *ui;



};
#endif // MAINWINDOW_H

