#ifndef ADDING_H
#define ADDING_H

#include <QMainWindow>
#include "mainwindow.h"
#include "QStringList"
#include "string.h"
#include "QCompleter"
#include "QFileSystemModel"



using namespace std ;

namespace Ui {
class Adding;
}

class Adding : public QMainWindow
{
    Q_OBJECT

public:
    explicit Adding(QWidget *parent = nullptr);
    ~Adding();
    /**
     * @brief fillingCompletersLists
     * fill completer list for date line edit and date line edit
     */
    void fillingCompletersLists () ;
    /**
     * @brief adjustLayout
     * adjust alyout for add window dispaly
     */
    void adjustLayout();

private slots:
    /**
     * @brief on_ln_name_editingFinished
     * line edit for name
     */
    void on_ln_name_editingFinished();
    /**
     * @brief on_ln_date_editingFinished
     * line edit for date slot to enable next line edit
     */
    void on_ln_date_editingFinished();
    /**
     * @brief on_ln_type_editingFinished
     * line edit for type enable add button
     */
    void on_ln_type_editingFinished();
    /**
     * @brief on_add_clicked
     */
    void on_add_clicked();
    /**
     * @brief on_discard_clicked
     */
    void on_discard_clicked();

private:
    Ui::Adding *ui;
    QStringList  date_list ;
    QStringList  type_list ;
    QCompleter * date_completer;
    QCompleter * type_completer;



};

#endif // ADDING_H

