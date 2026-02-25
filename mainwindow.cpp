#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->txt_FileName->setVisible(false);
    ui->btn_SelectFile->setVisible(false);

    QShortcut *shortcut = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_S), this);
    connect(shortcut, &QShortcut::activated, this, &MainWindow::on_cmd_CtrlS);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_cmd_CtrlS() {
    ui->statusbar->setStyleSheet("color: rgb(0, 255, 0);");
    ui->statusbar->showMessage("Test of save successful!", 3000);
}

void MainWindow::on_actionNew_File_triggered() {
    // Test status bar
    ui->statusbar->setStyleSheet("color: rgb(0, 255, 0);");
    ui->statusbar->showMessage("Hello world!", 3000);
}

void MainWindow::on_btn_NewSys_pressed() {
    // Uncheck other button option
    ui->btn_LoadSys->setChecked(false);

    ui->txt_FileName->setVisible(false);
    ui->btn_SelectFile->setVisible(false);
}

void MainWindow::on_btn_LoadSys_pressed() {
    // Uncheck other button option
    ui->btn_NewSys->setChecked(false);

    ui->txt_FileName->setVisible(true);
    ui->btn_SelectFile->setVisible(true);
}
