#ifndef COLLEGE_H
#define COLLEGE_H

#include <QObject>

class college : public QObject
{
    Q_OBJECT
public:
    explicit college(QObject *parent = 0);

signals:

public slots:
};

#endif // COLLEGE_H
