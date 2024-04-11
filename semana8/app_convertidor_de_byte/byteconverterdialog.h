#ifndef BYTECONVERTERDIALOG_H
#define BYTECONVERTERDIALOG_H

#include <QDialog>
class QLineEdit;

class ByteConverterDialog : public QDialog
{
    Q_OBJECT
public:
    ByteConverterDialog();

private:
    QLineEdit *decEd;
    QLineEdit *hexEdit;
    QLineEdit *binEdt;
};

#endif // BYTECONVERTERDIALOG_H
