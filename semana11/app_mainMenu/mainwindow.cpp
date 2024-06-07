#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit_code->setPlaceholderText("INTRODUCIR EL SUPUESTO CODIGO...");
    ui->textEdit_Alexico->setPlaceholderText("IDENTIFICADOR NUMERO REAL TABLA DE SIMBOLOS");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionExit_triggered()
{
    close();
}


void MainWindow::on_actionAnalizar_triggered()
{
    analizadorLexico al;
    char cadC [255];
    strcpy(cadC,ui->textEdit_code->toPlainText().toStdString().c_str());
    al.scanner(cadC);
    ui->textEdit_Alexico->setPlainText(QString::fromStdString(al.contenido));
}


void MainWindow::on_actionAbrir_triggered()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Abrir Archivo"), "", tr("Archivo txt (*.txt)"));
    dirAct=path.toStdString();
    if(!path.isEmpty()){
        QString cont=archivo().leerArchivoQt(path.toStdString());
        ui->textEdit_code->setPlainText(cont);
    }else{
        QMessageBox::critical(this, tr("Error"), tr("No se puede abrir el archivo"));
    }
}


void MainWindow::on_actionSave_triggered()
{
    if(dirAct.empty()){
        ui->actionSave_as->trigger();
    }else{
        QString path = dirAct.c_str();
        if(!path.isEmpty()){
            string cont=ui->textEdit_code->toPlainText().toStdString();
            archivo().guardarArchivoQt(path.toStdString(),cont);
            QMessageBox::information(this,tr("Exito"),tr("Archivo guardado con exito en: ")+tr(path.toStdString().c_str()));
        }else{
            QMessageBox::critical(this, tr("Error"), tr("No se pudo guardar el archivo"));
        }
    }
}


void MainWindow::on_actionSave_as_triggered()
{
    QString path = QFileDialog::getSaveFileName(this, tr("Guardar archivo"), "", tr("Archivo txt (*.txt)"));
    dirAct=path.toStdString();
    if(!path.isEmpty()){
        string cont=ui->textEdit_code->toPlainText().toStdString();
        archivo().guardarArchivoQt(path.toStdString(),cont);
        QMessageBox::information(this,tr("Exito"),tr("Archivo guardado con exito en: ")+tr(path.toStdString().c_str()));
    }else{
        QMessageBox::critical(this, tr("Error"), tr("No se pudo guardar el archivo"));
    }
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this,tr("App info"),tr("Editor de texto que hace uso del analizador lexico y tabla de simbolos para mostrar los contenidos del texto.\nDesarrollado por Luis Ernesto Barranco\nNC: 21130876"));
}


void MainWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this,tr("Qt info"));
}


void MainWindow::on_actionNuevo_triggered()
{
    ui->textEdit_code->clear();
    ui->textEdit_Alexico->clear();
    dirAct.clear();
}

