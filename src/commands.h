#ifndef COMMANDS_H
#define COMMANDS_H

#include <QObject>

class Commands : public QObject
{
    Q_OBJECT
public:
    explicit Commands(QObject *parent = 0);

signals:

public slots:
    int switchWorld(QString password,QString alias, QString mountpoint);
    bool isInSafeMode();
    bool hasFlash();
};

#endif // COMMANDS_H
