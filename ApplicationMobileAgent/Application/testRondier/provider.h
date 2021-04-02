#ifndef PROVIDER_H
#define PROVIDER_H

#include <QObject>
#include <QList>

#include "pointeau.h"
#include "qobject_list_model.h"

DECLARE_Q_OBJECT_LIST_MODEL (Pointeau)

class Provider : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QObjectListModel_Pointeau* items READ items CONSTANT)
public:
    explicit Provider(QObject *parent = Q_NULLPTR);

signals:

private :
    QObjectListModel_Pointeau* items();
    QObjectListModel_Pointeau m_items;

};

#endif // PROVIDER_H
