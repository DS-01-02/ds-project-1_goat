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

    void fillingCompletersLists () ;
    void adjustLayout();

private slots:
    void on_ln_name_editingFinished();

    void on_ln_date_editingFinished();

    void on_ln_type_editingFinished();

    void on_add_clicked();

    void on_discard_clicked();

private:
    Ui::Adding *ui;
    QStringList  date_list ;
    QStringList  type_list ;
    QCompleter * date_completer;
    QCompleter * type_completer;



};

#endif // ADDING_H
