//
// Created by timas on 10.08.2021.
//

#include "main_window.h"
#include "commands_pool.hpp"

#include <QApplication>
#include <iostream>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    STaskPool taskPool;
    MainWindow w(&taskPool);
    w.show();

    return a.exec();
}
