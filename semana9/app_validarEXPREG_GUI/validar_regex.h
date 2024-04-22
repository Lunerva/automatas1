#ifndef VALIDAR_REGEX_H
#define VALIDAR_REGEX_H

#include <QObject>
#include<QLabel>

class validar_regex : public QObject {
    Q_OBJECT
public:
    explicit validar_regex(QObject *parent = nullptr);

signals:
    void resChanged(const QString &resultado);

public slots:
    void setRegex(const QString &regex);
    void validarEntrada(const QString &entrada);

private:
    QString regex;
};


#endif // VALIDAR_REGEX_H
