#pragma once

#include <QStandardItemModel>
#include <QVariantMap>

class MemoModel : public QStandardItemModel
{
    Q_OBJECT
public:
    explicit MemoModel(QObject *parent = 0);
    ~MemoModel();

    Q_INVOKABLE void addMemo(const QVariantMap& memo);

    static void initDb();

signals:
    void onError(const QString& errorMessage);

public slots:
};


