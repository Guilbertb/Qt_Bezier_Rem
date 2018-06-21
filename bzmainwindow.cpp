#include "bzmainwindow.h"
#include "ui_bzmainwindow.h"

BzMainWindow::BzMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BzMainWindow)
{
    ui->setupUi(this);
    statusTxt = new QLabel("X=... Y=...",this);
    ui->statusBar->addWidget(statusTxt);
    connect(ui->bzView ,SIGNAL(mousePos(QPoint)) ,this ,SLOT(updateStatus(QPoint)));


}

BzMainWindow::~BzMainWindow()
{
    delete ui;
}

void BzMainWindow::on_actionNouveau_triggered()
{

}

void BzMainWindow::on_actionCharger_triggered()
{

}

void BzMainWindow::on_actionSauvegarder_triggered()
{

}

void BzMainWindow::on_actionQuitter_triggered()
{

}

void BzMainWindow::on_actionEffacer_triggered()
{

}

void BzMainWindow::on_actionConstruire_toggled(bool arg1)
{

}

void BzMainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.insertAction(0,ui->actionConstruire);
    menu.insertAction(ui->actionConstruire,ui->actionEffacer);
    menu.insertAction(ui->actionEffacer,ui->actionQuitter);
    menu.exec(event->globalPos());

}

void BzMainWindow::updateStatus(QPoint P)
{
    statusTxt->setText(QString("X=%1  Y=%2").arg(P.x()).arg(P.y()));
    //qDebug() << "updateStatus";
}

