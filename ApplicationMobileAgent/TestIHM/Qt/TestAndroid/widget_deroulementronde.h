#ifndef WIDGET_DEROULEMENTRONDE_H
#define WIDGET_DEROULEMENTRONDE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget_DeroulementRonde; }
QT_END_NAMESPACE

class Widget_DeroulementRonde : public QWidget
{
    Q_OBJECT

public:
    Widget_DeroulementRonde(QWidget *parent = nullptr);
    ~Widget_DeroulementRonde();

private:
    Ui::Widget_DeroulementRonde *ui;
};
#endif // WIDGET_DEROULEMENTRONDE_H
