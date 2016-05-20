#include "container.h"
#include <QApplication>
#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QX11Info>
#include <QProcess>
#include <QWindow>
#include <QDebug>

#include <X11/Xlib.h>

static void EmbedWindow(WId cwid, WId pwid, int x, int y) {
    Display* disp = XOpenDisplay(0);
    if (disp == NULL) {
        return;
    }

    XReparentWindow(disp, cwid, pwid, x, y);

    XCloseDisplay(disp);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCommandLineParser parser;
    parser.addHelpOption();

    // An option with a value
    QCommandLineOption widOption(QStringList() << "i" << "wid", "window id", "wid");
    parser.addOption(widOption);

    QCommandLineOption xOption(QStringList() << "x", "x", "x");
    parser.addOption(xOption);

    QCommandLineOption yOption(QStringList() << "y", "y", "y");
    parser.addOption(yOption);

    QCommandLineOption widthOption(QStringList() << "w" << "width", "width", "width");
    parser.addOption(widthOption);

    QCommandLineOption heightOption(QStringList() << "g" << "height", "height", "height");
    parser.addOption(heightOption);

    QCommandLineOption sourceOption(QStringList() << "s" << "source", "source file", "source");
    parser.addOption(sourceOption);

    // Process the actual command line arguments given by the user
    parser.process(a);


    int wid = parser.value(widOption).toInt(0, 16);
    int x = atoi(parser.value(xOption).toUtf8());
    int y = atoi(parser.value(yOption).toUtf8());
    int width = atoi(parser.value(widthOption).toUtf8());
    int height = atoi(parser.value(heightOption).toUtf8());
    QString source = parser.value(sourceOption);

    Container w;
//    w.setFixedSize(width, height);
    w.setGeometry(x, y, width, height);
    w.show();

    QProcess p;
    p.setProgram("mplayer");
    QStringList arguments;
    arguments << "-zoom" << "-wid" << QString::number(w.winId()) << "-vo" << "x11" << source;
    p.setArguments(arguments);
    p.start();

//    EmbedWindow(w.winId(), wid, x, y);

    QObject::connect(&p, SIGNAL(finished(int)), qApp, SLOT(quit()));

    return a.exec();
}
