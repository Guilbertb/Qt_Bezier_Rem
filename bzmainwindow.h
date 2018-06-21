#ifndef BZMAINWINDOW_H
#define BZMAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QLabel>
#include <QDebug>

namespace Ui {
class BzMainWindow;
}

class BzMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BzMainWindow(QWidget *parent = 0);
    ~BzMainWindow();
    QLabel *statusTxt;

private slots:
    void on_actionNouveau_triggered();

    void on_actionCharger_triggered();

    void on_actionSauvegarder_triggered();

    void on_actionQuitter_triggered();

    void on_actionEffacer_triggered();

    void on_actionConstruire_toggled(bool arg1);

    void contextMenuEvent(QContextMenuEvent *event);
    void updateStatus(QPoint P);
private:
    Ui::BzMainWindow *ui;


};

#endif // BZMAINWINDOW_H
