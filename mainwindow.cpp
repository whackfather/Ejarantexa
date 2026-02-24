#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_actionNew_File_triggered() {
    ui->statusbar->setStyleSheet("color: rgb(0, 255, 0);");
    ui->statusbar->showMessage("Hello world!", 3000);
}
