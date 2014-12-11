#include "memomodel.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDate>
#include <QDebug>

MemoModel::MemoModel(QObject *parent)
    : QStandardItemModel(parent)
{
    qDebug() << Q_FUNC_INFO;
}

MemoModel::~MemoModel()
{
    qDebug() << Q_FUNC_INFO;

}

void MemoModel::addMemo(const QVariantMap &memo)
{
    QString title = memo["title"].toString();
    QString date = memo["date"].toDate().toString(Qt::ISODate);

    QSqlQuery q;
    q.prepare(QString("insert into memo(title, date) values(:title, :date)"));
    q.bindValue(":title", title);
    q.bindValue(":date", date);
    if (!q.exec())
        throw q.lastError();
}

void MemoModel::initDb()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("24years.sqlite");

    if (!db.open())
        throw db.lastError();

    QStringList tables = db.tables();

    if (tables.contains("info", Qt::CaseInsensitive))
    {
        // check for db change
    }

    if (!tables.contains("info", Qt::CaseInsensitive))
    {
        QSqlQuery q;
        if (!q.exec("create table info(db_version integer)"))
            throw q.lastError();

        if (!q.exec("insert into info(db_version) values(1)"))
            throw q.lastError();
    }

    if (!tables.contains("memo", Qt::CaseInsensitive))
    {
        QSqlQuery q;
        if (!q.exec("create table memo(id integer primary key autoincrement, title text, date text)"))
            throw q.lastError();
    }




    //    if (!q.exec(QLatin1String("create table authors(id integer primary key, name varchar, birthdate date)")))
    //        return q.lastError();
    //    if (!q.exec(QLatin1String("create table genres(id integer primary key, name varchar)")))
    //        return q.lastError();

    //    if (!q.prepare(QLatin1String("insert into authors(name, birthdate) values(?, ?)")))
    //        return q.lastError();
    //    QVariant asimovId = addAuthor(q, QLatin1String("Isaac Asimov"), QDate(1920, 2, 1));
    //    QVariant greeneId = addAuthor(q, QLatin1String("Graham Greene"), QDate(1904, 10, 2));
    //    QVariant pratchettId = addAuthor(q, QLatin1String("Terry Pratchett"), QDate(1948, 4, 28));

    //    if (!q.prepare(QLatin1String("insert into genres(name) values(?)")))
    //        return q.lastError();
    //    QVariant sfiction = addGenre(q, QLatin1String("Science Fiction"));
    //    QVariant fiction = addGenre(q, QLatin1String("Fiction"));
    //    QVariant fantasy = addGenre(q, QLatin1String("Fantasy"));

    //    if (!q.prepare(QLatin1String("insert into books(title, year, author, genre, rating) values(?, ?, ?, ?, ?)")))
    //        return q.lastError();
    //    addBook(q, QLatin1String("Foundation"), 1951, asimovId, sfiction, 3);
    //    addBook(q, QLatin1String("Foundation and Empire"), 1952, asimovId, sfiction, 4);
    //    addBook(q, QLatin1String("Second Foundation"), 1953, asimovId, sfiction, 3);
    //    addBook(q, QLatin1String("Foundation's Edge"), 1982, asimovId, sfiction, 3);
    //    addBook(q, QLatin1String("Foundation and Earth"), 1986, asimovId, sfiction, 4);
    //    addBook(q, QLatin1String("Prelude to Foundation"), 1988, asimovId, sfiction, 3);
    //    addBook(q, QLatin1String("Forward the Foundation"), 1993, asimovId, sfiction, 3);
    //    addBook(q, QLatin1String("The Power and the Glory"), 1940, greeneId, fiction, 4);
    //    addBook(q, QLatin1String("The Third Man"), 1950, greeneId, fiction, 5);
    //    addBook(q, QLatin1String("Our Man in Havana"), 1958, greeneId, fiction, 4);
    //    addBook(q, QLatin1String("Guards! Guards!"), 1989, pratchettId, fantasy, 3);
    //    addBook(q, QLatin1String("Night Watch"), 2002, pratchettId, fantasy, 3);
    //    addBook(q, QLatin1String("Going Postal"), 2004, pratchettId, fantasy, 3);
}
