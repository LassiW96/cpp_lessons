///////////////////////////////////////////////////////////////////////////////////////////////////////////
// Main script of the 1-D wave to 2-D cicular wave pattern mapping project
//
// This is the interactive QT version main script of the project
// Widget properties are defined in the MainWinsoe class
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

# include <QApplication>
# include "MainWindow.h"

using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow W;
    W.resize(800, 800);             // Wndow size
    W.show();

    return app.exec();
}
