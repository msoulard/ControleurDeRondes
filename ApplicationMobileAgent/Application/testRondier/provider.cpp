#include "provider.h"

Provider::Provider(QObject *parent) : QObject(parent)
{

}

QObjectListModel_Pointeau *Provider::items()
{
    return &m_items;
}
