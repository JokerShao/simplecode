#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include "QNetworkAccessManager"

namespace Ui {
class HomePage;
}

class HomePage : public QWidget
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = 0);
    ~HomePage();

private slots:
    void on_pushButton_clicked();
    void replyFinished(QNetworkReply *);

private:
    Ui::HomePage *ui;
    QNetworkAccessManager *m;
};

#endif // HOMEPAGE_H
