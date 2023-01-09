#include "DataBaseConnection.h"
#include "FileFormat.h"

Dbconnection::Dbconnection()
{
    if(!db.open())
    {
        db = QSqlDatabase::addDatabase("QPSQL");
        db.setHostName("127.0.0.1");
        db.setDatabaseName("validfile");
        db.setPassword("1190325829");
        db.setUserName("postgres");
        db.setPort(5432);
        if(db.open())
        {
            qDebug() << "DataBase is ready to use";
        }
        else
        {
            qDebug() << "DataBase hasn't been initialized\n";
        }
    }
    QStringList tables = db.tables(QSql::TableType::Tables);
    if(tables.empty())
    {
        QString m_schema = QString( "CREATE TABLE file_list (id serial,name text PRIMARY KEY,date text NOT NULL,type_file text NOT NULL);" );
        QSqlQuery tableQuery( db );
        tableQuery.exec(m_schema);
    }
    else
    {
        //qDebug() << "table has already created\n";
    }
}

QString Dbconnection::insetingAllFilesToDatabase(vector<FileFormat> file)
{
  QString answer = "" ;
  QSqlQuery query(db);
  for (auto iterator = file.begin() ; iterator != file.end()  ;iterator++)
  {
      name = QString::fromStdString(iterator->name);
      date = QString::fromStdString(iterator->date);
      type = QString::fromStdString(iterator->type);
      bool ok = query.exec("insert into file_list (name ,date ,type_file) values ('"+name+"','"+date+"', '"+type+"');" );
      QSqlError error = query.lastError();
      if(error.text().toStdString() != " " && !error.text().contains("duplicate"))
      {
          qDebug() << error.text() ;
      }
   if(ok)
   {
       answer = "success(Query)";
   }
   else
   {
       answer = "Query did not executed : failure";
   }
  }

  return answer;
}

QString Dbconnection::insertingIndiviulFileToDatabase(vector<FileFormat> file)
{
  name = QString::fromStdString(file.at(0).name);
  date = QString::fromStdString(file.at(0).date);
  type = QString::fromStdString(file.at(0).type);
  QString answer = "";
  QSqlQuery query;
  bool ok = query.exec("insert into file_list "
             "(name ,date ,type_file) "
             "values "
             "('"+name+"','"+date+"', '"+type+"')");
  if(ok)
  {
      answer = "success(Query)";
  }
  else
  {
      answer = "Query did not executed : failure";
  }

  return answer ;
}

QString Dbconnection::removingFromDatabase(FileFormat file)
{
    QString answer = "" ;
    name = QString::fromStdString(file.name);
    QSqlQuery query;

    bool ok = query.exec("delete from file_list "
               "where name = '"+name+"'");

    if(ok)
    {
        answer = "success(Query)";
    }
    else
    {
        answer = "Query did not executed : failure";
    }

    return answer ;
}

QString Dbconnection::readingFromDatabase(vector<FileFormat> & file , QString orderby )
{
    QString answer = "" ;
    QSqlQuery query(db);
    if(orderby == "id")
    {
     query.exec("select * from file_list order by id");
    }
    else
    {
        query.exec("select * from file_list order by "+orderby+" ");
    }
    QSqlError error = query.lastError();
    if(error.text().toStdString() != " ")
    {
        qDebug() << error.text() ;
    }
    int iterator = 0 ;
    file.resize(query.size());
    while (query.next())
    {
        file.at(iterator).name = query.value("name").toString().toStdString();
        QSqlError error = query.lastError();
        if(error.text().toStdString() != " ")
        {
            qDebug() << error.text() ;
        }
        file.at(iterator).date = query.value("date").toString().toStdString();
        QSqlError error1 = query.lastError();
        if(error.text().toStdString() != " ")
        {
            qDebug() << error1.text() ;
        }
        file.at(iterator).type = query.value("type_file").toString().toStdString();
        QSqlError error2 = query.lastError();
        if(error.text().toStdString() != " ")
        {
            qDebug() << error2.text() ;
        }
       iterator++;
    }
    if(iterator == query.size())
    {
        answer = "success(Query)";
    }
    return answer ;
}

QString  Dbconnection::ascendingSortBasedOnName(vector<FileFormat> & file, QString user_choice)
{
    QString result = "" ;
    result = readingFromDatabase(file,user_choice);
    return result ;
}

QString Dbconnection::ascendingSortBasedOnDate(vector<FileFormat> & file, QString user_choice)
{
    QString result = "" ;
    result = readingFromDatabase(file,user_choice);
    return result ;
}

QString Dbconnection::ascendingSortBasedOnType(vector<FileFormat> & file, QString user_choice)
{
    QString result = "" ;
    result = readingFromDatabase(file,user_choice);
    return result ;
}

Dbconnection::~Dbconnection()
{
    //Added Dubious
  db.close();
}
