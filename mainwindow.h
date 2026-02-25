#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QShortcut>
#include <QKeySequence>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_cmd_CtrlS();

private slots:
    void on_actionNew_File_triggered();

    void on_btn_NewSys_pressed();

    void on_btn_LoadSys_pressed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
